#include <iostream>
#include <filesystem>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <ROOT/RDataFrame.hxx>
#include <TEfficiency.h>
#include <TString.h>

#include <Options.h>

namespace po = boost::program_options;

using namespace ROOT;

int main (int argc, char** argv) {
  
  Options options(argc, argv);
  YAML::Node const config = options.GetConfig();
  // input file name
  std::string filename = "input.root";
  if  (options.Exists("input")) filename = options.GetAs<std::string>("input");
  // output file name
  std::string outputName = "";
  if  (options.Exists("output")) outputName = options.GetAs<std::string>("output");
  // tree name (or path)
  std::string tree = "tnpPhoIDs/photon_tree";
  tree = Options::NodeAs<std::string>(config, {"tree_name"});
  
  std::string ptUpper = "200.";
  std::string ptLower = "50.";
  if  (options.Exists("right-edge")) ptUpper = options.GetAs<std::string>("right-edge");
  if  (options.Exists("left-edge")) ptLower = options.GetAs<std::string>("left-edge");
  // open the TnP file
  //TFile *inputFile = new TFile(TString(filename));
  //TTree *ttr = (TTree *)inputFile->Get(tree);
  // create the output file 
  TFile *outputFile = new TFile((outputName).c_str(), "recreate");
  EnableImplicitMT();
  //initiate the dataframe
  std::cout << filename << std::endl;
  TFile *inputFile = new TFile(filename.c_str());
  TTree *tnpTree = (TTree*) (inputFile->Get(tree.c_str()));
  TDirectory* directory = outputFile->mkdir("test");
  directory->cd();
  
  std::vector<std::string> tag_cuts = Options::GetStrings(config, {"tag-selections"});
  std::string ptRange = " ph_et > " + ptLower + " && ph_et < " + ptUpper + " ";
  auto tag_allcuts = boost::join(tag_cuts, " && " );
  std::vector<std::string> photonPtPoints = Options::GetStrings(config, {"photon-pt-points"});
  for (unsigned int i = 0; i < photonPtPoints.size(); i++) {
     std::vector<std::string> probe_flags = Options::GetStrings(config, {"photon" + photonPtPoints[i], "flag"});
     auto hist_pass = new TH1F("histPass","histPass",30, 91. -15., 91. +15. );
     auto hist_passNP = new TH1F("histPassNP","histPassNP",30, 91. -15., 91. +15. );
     auto hist_fail = new TH1F("histFail","histFail",30, 91. - 15., 91. +15. );
     std::string passCut = " " + (boost::join(probe_flags, " && ")) + " ";
     std::string failCut =  " !(" + boost::join(probe_flags, " && ") + ") ";
     tnpTree->Draw("mass>>histPass",(Options::NodeAs<std::string>(config, {"photon" + photonPtPoints[i], "prescale"}) +"*( " + ptRange + " && " + tag_allcuts +" && "+ passCut +")").c_str());
     tnpTree->Draw("mass>>histPassNP",(ptRange + " && " +tag_allcuts + " && "+ passCut).c_str());
     tnpTree->Draw("mass>>histFail",(ptRange + " && " +tag_allcuts +" && "+ failCut).c_str());
     hist_pass->SetName(TString("pass_photon" + photonPtPoints[i] + "_pt" + ptLower + "-" + ptUpper));
     hist_passNP->SetName(TString("passNP_photon" + photonPtPoints[i] + "_pt" + ptLower + "-" + ptUpper));
     hist_fail->SetName(TString("fail_photon" + photonPtPoints[i] + "_pt" + ptLower + "-" + ptUpper));
     double pass_events = hist_pass->Integral();
     double fail_events = hist_fail->Integral() + hist_passNP->Integral();
     std::cout << "pass : " << pass_events << " fail:" << fail_events <<std::endl;
     auto eff = new TEfficiency(("eff_photon" + photonPtPoints[i] + "_pt" +ptLower +"-" + ptUpper).c_str(), "", 1, 0, 1);
     eff->SetTotalEvents(0, fail_events);
     eff->SetPassedEvents(0, pass_events);
     auto eff_value = eff->GetEfficiency(0);
     auto eff_errlow = eff->GetEfficiencyErrorLow(0);
     auto eff_errUp = eff->GetEfficiencyErrorUp(0);
     std::cout << "eff : " << eff_value << " + " << eff_errUp << " - " << eff_errlow << std::endl;
     eff->Write();
  }
  outputFile->Close();
  return 0;
}
