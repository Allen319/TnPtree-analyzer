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
  bool isMC = options.GetAs<bool>("isMC");
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
  TBranch *b_ph_et;
  //TBranch *b_ph_eta;
  //TBranch *b_ph_phi;
  //TBranch *b_tag_Ele_pt;
  //TBranch *b_tag_Ele_eta;
  //TBranch *b_tag_Ele_phi;
  TBranch *b_run;
  TBranch *b_lumi;
  float ph_et;
  //float ph_et, ph_eta, ph_phi;
  //float tag_Ele_pt, tag_Ele_eta, tag_Ele_phi;
  unsigned int run;
  unsigned int lumi;
  oldTree->SetBranchAddress("run", &run, &b_run);
  oldTree->SetBranchAddress("lumi", &lumi, &b_lumi);
  oldTree->SetBranchAddress("ph_et", &ph_et, &b_ph_et);
  //oldTree->SetBranchAddress("ph_eta", &ph_eta, &b_ph_eta);
  //oldTree->SetBranchAddress("ph_phi", &ph_phi, &b_ph_phi);
  //oldTree->SetBranchAddress("tag_Ele_pt", &tag_Ele_pt, &b_tag_Ele_pt);
  //oldTree->SetBranchAddress("tag_Ele_eta", &tag_Ele_eta, &b_tag_Ele_eta);
  //oldTree->SetBranchAddress("tag_Ele_phi", &tag_Ele_phi, &b_tag_Ele_phi);
  int photon50, photon75, photon90, photon120, photon165;
  //float deltaR;
  auto ph50Branch = oldTree->Branch("photon50prescale", &photon50, "photon50/I");
  auto ph75Branch = oldTree->Branch("photon75prescale", &photon75, "photon75/I");
  auto ph90Branch = oldTree->Branch("photon90prescale", &photon90, "photon90/I");
  auto ph120Branch = oldTree->Branch("photon120prescale", &photon120, "photon120/I");
  auto ph165Branch = oldTree->Branch("photon165prescale", &photon165, "photon165/I");
  ph50Branch->SetBasketSize(32 * 1024 * 1024);
  ph75Branch->SetBasketSize(32 * 1024 * 1024);
  ph90Branch->SetBasketSize(32 * 1024 * 1024);
  ph120Branch->SetBasketSize(32 * 1024 * 1024);
  ph165Branch->SetBasketSize(32 * 1024 * 1024);
  //auto deltaRBranch = oldTree->Branch("tag_probe_deltaR", &deltaR, "deltaR/F");
  PhotonPrescales php(prescaleConfig.c_str(), isMC);
  Long64_t counter = 0;
  Long64_t nentries = oldTree->GetEntriesFast();
  std::cout << " Will process " << nentries << " events in total" << std::endl;
  for (int i = 0; i < nentries; ++i) {
    auto nb = oldTree->GetEntry(i);
    if (nb < 0) {std::cout << "no entries" <<std::endl; break;}
    counter++;
    if (counter % 100000 == 0) {
        std::cout << "Processed " << counter << " events" << std::endl;
    }
    //std::cout << "photon pt" << ph_et << std::endl;
    if (ph_et < 50.) continue;
    //TLorentzVector e_vector;
    //e_vector.SetPtEtaPhiM(tag_Ele_pt, tag_Ele_eta, tag_Ele_phi, 0.0);

    //TLorentzVector ph_vector;
    //ph_vector.SetPtEtaPhiM(ph_et, ph_eta, ph_phi, 0.0);

    // Calculate the delta R between the electron and photon
    //deltaR = e_vector.DeltaR(ph_vector);

    php.Update(run,lumi);
    photon50 = php.GetPhotonPrescale(50);
    //std::cout << photon50 <<std::endl;
    photon75 = php.GetPhotonPrescale(75);
    photon90 = php.GetPhotonPrescale(90);
    photon120 = php.GetPhotonPrescale(120);
    photon165 = php.GetPhotonPrescale(165);
    ph50Branch->Fill(); 
    ph75Branch->Fill(); 
    ph90Branch->Fill(); 
    ph120Branch->Fill();
    ph165Branch->Fill();
    //deltaRBranch->Fill();
  }
  auto newTree = oldTree->CloneTree();
  newTree->Write(Options::NodeAs<std::string>(config, {"output_tree_name"}).c_str());
  newFile->Close();
  oldFile->Close();
  return 0;
}
