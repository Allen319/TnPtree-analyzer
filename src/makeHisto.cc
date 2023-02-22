#include <iostream>
#include <boost/program_options.hpp>
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
  std::string tree = "fitter_tree";
  tree = Options::NodeAs<std::string>(config, {"tree_name"});
  
  // open the TnP file
  //TFile *inputFile = new TFile(TString(filename));
  //TTree *ttr = (TTree *)inputFile->Get(tree);
  // create the output file 
  //TFile *outputFile = new TFile(options.GetAs<std::string>("output").c_str(),"recreate");
  EnableImplicitMT();
  //initiate the dataframe
  RDataFrame d(tree,filename);
  
  std::vector<std::string> tag_cuts = Options::GetStrings(config, {"tag-selections"});
  
  return 0;
}
