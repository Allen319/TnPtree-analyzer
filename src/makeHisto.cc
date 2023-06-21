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
  std::filesystem::path filepath(filename);
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
  RDataFrame d(tree,filename);
  
  std::vector<std::string> tag_cuts = Options::GetStrings(config, {"tag-selections"});
  auto d_inter = d.Filter("ph_et > " + ptLower + " && ph_et < " + ptUpper);
  auto d_new = d_inter.Filter(boost::join(tag_cuts, " &&  " ));
  std::vector<std::string> photonPtPoints = Options::GetStrings(config, {"photon-pt-points"});
  for (unsigned int i = 0; i < photonPtPoints.size(); i++) {
     std::vector<std::string> probe_flags = Options::GetStrings(config, {"photon" + photonPtPoints[i], "flag"});
     auto hist_model = RDF::TH1DModel("","",35, 60.,130. );
     auto d_pass = d_new.Filter(boost::join(probe_flags, " && "));
     auto d_fail = d_new.Filter( "!(" + boost::join(probe_flags, " && ") + ")");
     std::cout<< "!(" + boost::join(probe_flags, " && ") + ")" <<std::endl;
     auto proxy_fail = d_fail.Histo1D(hist_model, "mass");
     auto proxy_pass = d_pass.Histo1D(hist_model, "mass", Options::NodeAs<std::string>(config, {"photon" + photonPtPoints[i], "prescale"}));
     auto hist_pass = (TH1D *)proxy_pass.GetValue().Clone();
     auto hist_fail = (TH1D *)proxy_fail.GetValue().Clone();
     hist_pass->SetName(TString("pass_photon" + photonPtPoints[i] + "_pt" + ptLower + "-" + ptUpper));
     hist_fail->SetName(TString("fail_photon" + photonPtPoints[i] + "_pt" + ptLower + "-" + ptUpper));
     hist_pass->Write();
     hist_fail->Write();
     auto d_pass_mass = d_pass.Filter("pair_mass > 91. - 15 && pair_mass < 91. +15");
     auto d_fail_mass = d_fail.Filter("pair_mass > 91. - 15 && pair_mass < 91. +15");
     auto proxy_pass_mass = d_pass_mass.Histo1D(hist_model, "mass", Options::NodeAs<std::string>(config, {"photon" + photonPtPoints[i], "prescale"}));
     auto proxy_fail_mass = d_fail_mass.Histo1D(hist_model, "mass");
     double pass_events = (double) proxy_pass_mass.GetValue().Integral();
     double fail_events = (double) proxy_fail_mass.GetValue().Integral();
     std::cout << "pass : " << pass_events << " fail:" << fail_events <<std::endl;
     auto eff = new TEfficiency(("eff_photon" + photonPtPoints[i]).c_str(), "", 1, 0, 1);
     eff->SetTotalEvents(0, pass_events + fail_events);
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
