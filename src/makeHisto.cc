#include <iostream>
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
  std::string outputName = "output.root";
  if  (options.Exists("output")) outputName = options.GetAs<std::string>("output");
  // tree name (or path)
  std::string tree = "tnpPhoIDs/fitter_tree";
  tree = Options::NodeAs<std::string>(config, {"tree_name"});
  
  std::string ptUpper = "200.";
  std::string ptLower = "50.";
  if  (options.Exists("right-edge")) ptUpper = options.GetAs<std::string>("right-edge");
  if  (options.Exists("left-edge")) ptLower = options.GetAs<std::string>("left-edge");
  // open the TnP file
  //TFile *inputFile = new TFile(TString(filename));
  //TTree *ttr = (TTree *)inputFile->Get(tree);
  // create the output file 
  TFile *outputFile = new TFile(options.GetAs<std::string>("output").c_str(),"recreate");
  EnableImplicitMT();
  //initiate the dataframe
  RDataFrame d(tree,filename);
  
  std::vector<std::string> tag_cuts = Options::GetStrings(config, {"tag-selections"});
  auto d_inter = d.Filter("ph_et > " + ptLower + " && ph_et < " + ptUpper);
  auto d_new = d_inter.Filter(boost::join(tag_cuts, " &&  " ));
  std::vector<std::string> photonPtPoints = Options::GetStrings(config, {"photon-pt-points"});
  for (int i = 0; i < photonPtPoints.size(); i++) {
     std::vector<std::string> probe_flags = Options::GetStrings(config, {"photon" + photonPtPoints[i], "flag"});
     auto hist_model = RDF::TH1DModel("","",35, 60.,130. );
     auto d_pass = d_new.Filter(boost::join(probe_flags, " && "));
     auto d_fail = d_new.Filter( "!(" + boost::join(probe_flags, " && ") + ")");
     std::cout<< "!(" + boost::join(probe_flags, " && ") + ")" <<std::endl;
     auto proxy_pass = d_pass.Histo1D(hist_model, "mass", Options::NodeAs<std::string>(config, {"photon" + photonPtPoints[i], "prescale"}));
     auto proxy_fail = d_fail.Histo1D(hist_model, "mass");
     auto hist_pass = (TH1D *)proxy_pass.GetValue().Clone();
     auto hist_fail = (TH1D *)proxy_fail.GetValue().Clone();
     hist_pass->SetName(TString("pass_photon" + photonPtPoints[i] + "_pt" + ptLower + "-" + ptUpper));
     hist_fail->SetName(TString("fail_photon" + photonPtPoints[i] + "_pt" + ptLower + "-" + ptUpper));
     hist_pass->Write();
     hist_fail->Write();
  }
  return 0;
}
