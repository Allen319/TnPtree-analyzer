#include <iostream>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TTree.h>
#include <TRandom.h>

#include <PhotonPrescales.h>
#include <Options.h>

/* Options cms input:
  --config (required) /path/to/config : configuration file
  --input /path/to/the/tree : input tree
  --output /path/to/output : output path & name
  --isMC 1 or 0 : is simulation or not
*/
int main(int argc, char **argv) {
  Options options(argc, argv);
  YAML::Node const config = options.GetConfig();
  std::string year = options.GetAs<std::string>("year");
  //bool isMC = options.GetAs<bool>("isMC");
  std::string treePath = Options::NodeAs<std::string>(config, {"tree_path"});
  std::string dirName = Options::NodeAs<std::string>(config, {"output_dir"});
  std::string prescaleConfig = "config/"+ year + ".yaml";

  //input file name
  std::string filename;
  if  (options.Exists("input")) filename = options.GetAs<std::string>("input");
  //output file name
  std::string outputName = "output.root";
  if  (options.Exists("output")) outputName = options.GetAs<std::string>("output");
  //load TFile and the tree
  std::cout << "open file:" << filename << std::endl;
  TFile *oldFile = new TFile(filename.c_str());
  std::cout << "get tree:" << treePath << std::endl;
  auto oldTree = oldFile->Get<TTree>(treePath.c_str());
  //create output file
  TFile *newFile = new TFile(outputName.c_str(),"recreate");
  TDirectory *dir = newFile->mkdir(dirName.c_str());
  dir->cd();
  TBranch *b_el_pt;
  TBranch *b_el_eta;
  TBranch *b_el_phi;
  TBranch *b_tag_Ele_pt;
  TBranch *b_tag_Ele_eta;
  TBranch *b_tag_Ele_phi;
  float el_pt, el_eta, el_phi;
  float tag_Ele_pt, tag_Ele_eta, tag_Ele_phi;
  oldTree->SetBranchAddress("el_eta", &el_pt, &b_el_pt);
  oldTree->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
  oldTree->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
  oldTree->SetBranchAddress("tag_Ele_pt", &tag_Ele_pt, &b_tag_Ele_pt);
  oldTree->SetBranchAddress("tag_Ele_eta", &tag_Ele_eta, &b_tag_Ele_eta);
  oldTree->SetBranchAddress("tag_Ele_phi", &tag_Ele_phi, &b_tag_Ele_phi);
  float deltaR;
  bool deltaR03, deltaR04;
  auto deltaRBranch = oldTree->Branch("tag_probe_deltaR", &deltaR, "deltaR/F");
  auto deltaR03Branch = oldTree->Branch("deltaR03", &deltaR03, "deltaR03/B");
  auto deltaR04Branch = oldTree->Branch("deltaR04", &deltaR04, "deltaR04/B");
  Long64_t nentries = oldTree->GetEntriesFast();
  for (int i = 0; i < nentries; ++i) {
    auto nb = oldTree->GetEntry(i);
    if (nb < 0) {std::cout << "no entries" <<std::endl; break;}
    TLorentzVector tag_vector;
    tag_vector.SetPtEtaPhiM(tag_Ele_pt, tag_Ele_eta, tag_Ele_phi, 0.0);

    TLorentzVector probe_vector;
    probe_vector.SetPtEtaPhiM(el_pt, el_eta, el_phi, 0.0);

    //Calculate the delta R between the tag and probe
    deltaR = tag_vector.DeltaR(probe_vector);
    deltaR04 = (deltaR > 0.4);
    deltaR03 = (deltaR > 0.3);

    deltaRBranch->Fill();
    deltaR03Branch->Fill();
    deltaR04Branch->Fill();
  }
  auto newTree = oldTree->CloneTree();
  newTree->Write(Options::NodeAs<std::string>(config, {"output_tree_name"}).c_str());
  newFile->Close();
  oldFile->Close();
  return 0;
}
