//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Feb 16 21:10:16 2023 by ROOT version 6.29/01
// from TTree fitter_tree/fitter_tree
// found on file: TnPTree_data_426.root
//////////////////////////////////////////////////////////

#ifndef fitter_tree_h
#define fitter_tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class fitter_tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         ph_ESsigma;
   Float_t         ph_abseta;
   Float_t         ph_chIso;
   Float_t         ph_chWorIso;
   Float_t         ph_e;
   Float_t         ph_eleveto;
   Float_t         ph_et;
   Float_t         ph_eta;
   Float_t         ph_full5x5x_r9;
   Float_t         ph_haspixelseed;
   Float_t         ph_hoe;
   Float_t         ph_neuIso;
   Float_t         ph_phoIso;
   Float_t         ph_preshower_energy_plane1;
   Float_t         ph_preshower_energy_plane2;
   Float_t         ph_r9;
   Float_t         ph_s4;
   Float_t         ph_sc_abseta;
   Float_t         ph_sc_energy;
   Float_t         ph_sc_et;
   Float_t         ph_sc_eta;
   Float_t         ph_sc_etaWidth;
   Float_t         ph_sc_phiWidth;
   Float_t         ph_sc_rawEnergy;
   Float_t         ph_sieie;
   Float_t         ph_sieip;
   Float_t         Photon120passTrigger;
   Float_t         Photon120prescale;
   Float_t         Photon165passTrigger;
   Float_t         Photon165prescale;
   Float_t         Photon200passTrigger;
   Float_t         Photon200prescale;
   Float_t         Photon50passTrigger;
   Float_t         Photon50prescale;
   Float_t         Photon75passTrigger;
   Float_t         Photon75prescale;
   Float_t         Photon90passTrigger;
   Float_t         Photon90prescale;
   Float_t         ph_mva80X;
   Float_t         ph_mva94X;
   Float_t         ph_mva94XV2;
   Int_t           passHltPhoton120;
   Int_t           passHltPhoton165;
   Int_t           passHltPhoton200;
   Int_t           passHltPhoton50;
   Int_t           passHltPhoton75;
   Int_t           passHltPhoton90;
   Int_t           passingCutBasedLoose80X;
   Int_t           passingCutBasedLoose94X;
   Int_t           passingCutBasedLoose94XV2;
   Int_t           passingCutBasedLoose94XV2MinPtCut;
   Int_t           passingCutBasedLoose94XV2PhoFull5x5SigmaIEtaIEtaCut;
   Int_t           passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut;
   Int_t           passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut1;
   Int_t           passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut2;
   Int_t           passingCutBasedLoose94XV2PhoSCEtaMultiRangeCut;
   Int_t           passingCutBasedLoose94XV2PhoSingleTowerHadOverEmCut;
   Int_t           passingCutBasedMedium80X;
   Int_t           passingCutBasedMedium94X;
   Int_t           passingCutBasedMedium94XV2;
   Int_t           passingCutBasedMedium94XV2MinPtCut;
   Int_t           passingCutBasedMedium94XV2PhoFull5x5SigmaIEtaIEtaCut;
   Int_t           passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut;
   Int_t           passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut1;
   Int_t           passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut2;
   Int_t           passingCutBasedMedium94XV2PhoSCEtaMultiRangeCut;
   Int_t           passingCutBasedMedium94XV2PhoSingleTowerHadOverEmCut;
   Int_t           passingCutBasedTight80X;
   Int_t           passingCutBasedTight94X;
   Int_t           passingCutBasedTight94XV2;
   Int_t           passingCutBasedTight94XV2MinPtCut;
   Int_t           passingCutBasedTight94XV2PhoFull5x5SigmaIEtaIEtaCut;
   Int_t           passingCutBasedTight94XV2PhoGenericRhoPtScaledCut;
   Int_t           passingCutBasedTight94XV2PhoGenericRhoPtScaledCut1;
   Int_t           passingCutBasedTight94XV2PhoGenericRhoPtScaledCut2;
   Int_t           passingCutBasedTight94XV2PhoSCEtaMultiRangeCut;
   Int_t           passingCutBasedTight94XV2PhoSingleTowerHadOverEmCut;
   Int_t           passingMVA80Xwp80;
   Int_t           passingMVA80Xwp90;
   Int_t           passingMVA94XV2wp80;
   Int_t           passingMVA94XV2wp90;
   UInt_t          run;
   UInt_t          lumi;
   ULong64_t       event;
   Int_t           truePU;
   Int_t           event_nPV;
   Float_t         event_met_pfmet;
   Float_t         event_met_pfphi;
   Float_t         event_met_pfsumet;
   Float_t         event_met_pfmetsignificance;
   Float_t         event_PrimaryVertex_x;
   Float_t         event_PrimaryVertex_y;
   Float_t         event_PrimaryVertex_z;
   Float_t         event_BeamSpot_x;
   Float_t         event_BeamSpot_y;
   Float_t         event_BeamSpot_z;
   Float_t         event_rho;
   Float_t         mass;
   Float_t         tag_Ele_3charge;
   Float_t         tag_Ele_abseta;
   Float_t         tag_Ele_e;
   Float_t         tag_Ele_et;
   Float_t         tag_Ele_eta;
   Float_t         tag_Ele_phi;
   Float_t         tag_Ele_pt;
   Float_t         tag_Ele_q;
   Float_t         tag_sc_abseta;
   Float_t         tag_sc_e;
   Float_t         tag_sc_et;
   Float_t         tag_sc_eta;
   Float_t         tag_Ele_IsoMVA94X;
   Float_t         tag_Ele_IsoMVA94XV2;
   Float_t         tag_Ele_dxy;
   Float_t         tag_Ele_dz;
   Float_t         tag_Ele_hzzMVA80X;
   Float_t         tag_Ele_noIsoMVA94X;
   Float_t         tag_Ele_noIsoMVA94XV2;
   Float_t         tag_Ele_nonTrigMVA80X;
   Float_t         tag_Ele_trigMVA;
   Float_t         tag_el_sip;
   Float_t         pair_abseta;
   Float_t         pair_eta;
   Float_t         pair_mass;
   Float_t         pair_pt;

   // List of branches
   TBranch        *b_ph_ESsigma;   //!
   TBranch        *b_ph_abseta;   //!
   TBranch        *b_ph_chIso;   //!
   TBranch        *b_ph_chWorIso;   //!
   TBranch        *b_ph_e;   //!
   TBranch        *b_ph_eleveto;   //!
   TBranch        *b_ph_et;   //!
   TBranch        *b_ph_eta;   //!
   TBranch        *b_ph_full5x5x_r9;   //!
   TBranch        *b_ph_haspixelseed;   //!
   TBranch        *b_ph_hoe;   //!
   TBranch        *b_ph_neuIso;   //!
   TBranch        *b_ph_phoIso;   //!
   TBranch        *b_ph_preshower_energy_plane1;   //!
   TBranch        *b_ph_preshower_energy_plane2;   //!
   TBranch        *b_ph_r9;   //!
   TBranch        *b_ph_s4;   //!
   TBranch        *b_ph_sc_abseta;   //!
   TBranch        *b_ph_sc_energy;   //!
   TBranch        *b_ph_sc_et;   //!
   TBranch        *b_ph_sc_eta;   //!
   TBranch        *b_ph_sc_etaWidth;   //!
   TBranch        *b_ph_sc_phiWidth;   //!
   TBranch        *b_ph_sc_rawEnergy;   //!
   TBranch        *b_ph_sieie;   //!
   TBranch        *b_ph_sieip;   //!
   TBranch        *b_Photon120passTrigger;   //!
   TBranch        *b_Photon120prescale;   //!
   TBranch        *b_Photon165passTrigger;   //!
   TBranch        *b_Photon165prescale;   //!
   TBranch        *b_Photon200passTrigger;   //!
   TBranch        *b_Photon200prescale;   //!
   TBranch        *b_Photon50passTrigger;   //!
   TBranch        *b_Photon50prescale;   //!
   TBranch        *b_Photon75passTrigger;   //!
   TBranch        *b_Photon75prescale;   //!
   TBranch        *b_Photon90passTrigger;   //!
   TBranch        *b_Photon90prescale;   //!
   TBranch        *b_ph_mva80X;   //!
   TBranch        *b_ph_mva94X;   //!
   TBranch        *b_ph_mva94XV2;   //!
   TBranch        *b_passHltPhoton120;   //!
   TBranch        *b_passHltPhoton165;   //!
   TBranch        *b_passHltPhoton200;   //!
   TBranch        *b_passHltPhoton50;   //!
   TBranch        *b_passHltPhoton75;   //!
   TBranch        *b_passHltPhoton90;   //!
   TBranch        *b_passingCutBasedLoose80X;   //!
   TBranch        *b_passingCutBasedLoose94X;   //!
   TBranch        *b_passingCutBasedLoose94XV2;   //!
   TBranch        *b_passingCutBasedLoose94XV2MinPtCut;   //!
   TBranch        *b_passingCutBasedLoose94XV2PhoFull5x5SigmaIEtaIEtaCut;   //!
   TBranch        *b_passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut;   //!
   TBranch        *b_passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut1;   //!
   TBranch        *b_passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut2;   //!
   TBranch        *b_passingCutBasedLoose94XV2PhoSCEtaMultiRangeCut;   //!
   TBranch        *b_passingCutBasedLoose94XV2PhoSingleTowerHadOverEmCut;   //!
   TBranch        *b_passingCutBasedMedium80X;   //!
   TBranch        *b_passingCutBasedMedium94X;   //!
   TBranch        *b_passingCutBasedMedium94XV2;   //!
   TBranch        *b_passingCutBasedMedium94XV2MinPtCut;   //!
   TBranch        *b_passingCutBasedMedium94XV2PhoFull5x5SigmaIEtaIEtaCut;   //!
   TBranch        *b_passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut;   //!
   TBranch        *b_passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut1;   //!
   TBranch        *b_passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut2;   //!
   TBranch        *b_passingCutBasedMedium94XV2PhoSCEtaMultiRangeCut;   //!
   TBranch        *b_passingCutBasedMedium94XV2PhoSingleTowerHadOverEmCut;   //!
   TBranch        *b_passingCutBasedTight80X;   //!
   TBranch        *b_passingCutBasedTight94X;   //!
   TBranch        *b_passingCutBasedTight94XV2;   //!
   TBranch        *b_passingCutBasedTight94XV2MinPtCut;   //!
   TBranch        *b_passingCutBasedTight94XV2PhoFull5x5SigmaIEtaIEtaCut;   //!
   TBranch        *b_passingCutBasedTight94XV2PhoGenericRhoPtScaledCut;   //!
   TBranch        *b_passingCutBasedTight94XV2PhoGenericRhoPtScaledCut1;   //!
   TBranch        *b_passingCutBasedTight94XV2PhoGenericRhoPtScaledCut2;   //!
   TBranch        *b_passingCutBasedTight94XV2PhoSCEtaMultiRangeCut;   //!
   TBranch        *b_passingCutBasedTight94XV2PhoSingleTowerHadOverEmCut;   //!
   TBranch        *b_passingMVA80Xwp80;   //!
   TBranch        *b_passingMVA80Xwp90;   //!
   TBranch        *b_passingMVA94XV2wp80;   //!
   TBranch        *b_passingMVA94XV2wp90;   //!
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_truePU;   //!
   TBranch        *b_mNPV;   //!
   TBranch        *b_mpfMET;   //!
   TBranch        *b_mpfPhi;   //!
   TBranch        *b_mpfSumET;   //!
   TBranch        *b_mpfMETSign;   //!
   TBranch        *b_mPVx;   //!
   TBranch        *b_mPVy;   //!
   TBranch        *b_mPVz;   //!
   TBranch        *b_mBSx;   //!
   TBranch        *b_mBSy;   //!
   TBranch        *b_mBSz;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_mass;   //!
   TBranch        *b_tag_Ele_3charge;   //!
   TBranch        *b_tag_Ele_abseta;   //!
   TBranch        *b_tag_Ele_e;   //!
   TBranch        *b_tag_Ele_et;   //!
   TBranch        *b_tag_Ele_eta;   //!
   TBranch        *b_tag_Ele_phi;   //!
   TBranch        *b_tag_Ele_pt;   //!
   TBranch        *b_tag_Ele_q;   //!
   TBranch        *b_tag_sc_abseta;   //!
   TBranch        *b_tag_sc_e;   //!
   TBranch        *b_tag_sc_et;   //!
   TBranch        *b_tag_sc_eta;   //!
   TBranch        *b_tag_Ele_IsoMVA94X;   //!
   TBranch        *b_tag_Ele_IsoMVA94XV2;   //!
   TBranch        *b_tag_Ele_dxy;   //!
   TBranch        *b_tag_Ele_dz;   //!
   TBranch        *b_tag_Ele_hzzMVA80X;   //!
   TBranch        *b_tag_Ele_noIsoMVA94X;   //!
   TBranch        *b_tag_Ele_noIsoMVA94XV2;   //!
   TBranch        *b_tag_Ele_nonTrigMVA80X;   //!
   TBranch        *b_tag_Ele_trigMVA;   //!
   TBranch        *b_tag_el_sip;   //!
   TBranch        *b_pair_abseta;   //!
   TBranch        *b_pair_eta;   //!
   TBranch        *b_pair_mass;   //!
   TBranch        *b_pair_pt;   //!

   fitter_tree(TString input, TString output, bool isMC);
   virtual ~fitter_tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
 private:
   TString outputFile_;
   bool isMC_;
};

#endif

#ifdef fitter_tree_cxx
fitter_tree::fitter_tree(TString inputFile, TString outputFile, bool isMC) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   outputFile_ = outputFile;
   isMC_ = isMC;
   TChain *chain = new TChain("tnpPhoIDs/fitter_tree", "");
   chain->Add(inputFile);
   TTree *tree = chain;

   Init(tree);
}

fitter_tree::~fitter_tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t fitter_tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t fitter_tree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void fitter_tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ph_ESsigma", &ph_ESsigma, &b_ph_ESsigma);
   fChain->SetBranchAddress("ph_abseta", &ph_abseta, &b_ph_abseta);
   fChain->SetBranchAddress("ph_chIso", &ph_chIso, &b_ph_chIso);
   fChain->SetBranchAddress("ph_chWorIso", &ph_chWorIso, &b_ph_chWorIso);
   fChain->SetBranchAddress("ph_e", &ph_e, &b_ph_e);
   fChain->SetBranchAddress("ph_eleveto", &ph_eleveto, &b_ph_eleveto);
   fChain->SetBranchAddress("ph_et", &ph_et, &b_ph_et);
   fChain->SetBranchAddress("ph_eta", &ph_eta, &b_ph_eta);
   fChain->SetBranchAddress("ph_full5x5x_r9", &ph_full5x5x_r9, &b_ph_full5x5x_r9);
   fChain->SetBranchAddress("ph_haspixelseed", &ph_haspixelseed, &b_ph_haspixelseed);
   fChain->SetBranchAddress("ph_hoe", &ph_hoe, &b_ph_hoe);
   fChain->SetBranchAddress("ph_neuIso", &ph_neuIso, &b_ph_neuIso);
   fChain->SetBranchAddress("ph_phoIso", &ph_phoIso, &b_ph_phoIso);
   fChain->SetBranchAddress("ph_preshower_energy_plane1", &ph_preshower_energy_plane1, &b_ph_preshower_energy_plane1);
   fChain->SetBranchAddress("ph_preshower_energy_plane2", &ph_preshower_energy_plane2, &b_ph_preshower_energy_plane2);
   fChain->SetBranchAddress("ph_r9", &ph_r9, &b_ph_r9);
   fChain->SetBranchAddress("ph_s4", &ph_s4, &b_ph_s4);
   fChain->SetBranchAddress("ph_sc_abseta", &ph_sc_abseta, &b_ph_sc_abseta);
   fChain->SetBranchAddress("ph_sc_energy", &ph_sc_energy, &b_ph_sc_energy);
   fChain->SetBranchAddress("ph_sc_et", &ph_sc_et, &b_ph_sc_et);
   fChain->SetBranchAddress("ph_sc_eta", &ph_sc_eta, &b_ph_sc_eta);
   fChain->SetBranchAddress("ph_sc_etaWidth", &ph_sc_etaWidth, &b_ph_sc_etaWidth);
   fChain->SetBranchAddress("ph_sc_phiWidth", &ph_sc_phiWidth, &b_ph_sc_phiWidth);
   fChain->SetBranchAddress("ph_sc_rawEnergy", &ph_sc_rawEnergy, &b_ph_sc_rawEnergy);
   fChain->SetBranchAddress("ph_sieie", &ph_sieie, &b_ph_sieie);
   fChain->SetBranchAddress("ph_sieip", &ph_sieip, &b_ph_sieip);
   fChain->SetBranchAddress("Photon120passTrigger", &Photon120passTrigger, &b_Photon120passTrigger);
   fChain->SetBranchAddress("Photon120prescale", &Photon120prescale, &b_Photon120prescale);
   fChain->SetBranchAddress("Photon165passTrigger", &Photon165passTrigger, &b_Photon165passTrigger);
   fChain->SetBranchAddress("Photon165prescale", &Photon165prescale, &b_Photon165prescale);
   fChain->SetBranchAddress("Photon200passTrigger", &Photon200passTrigger, &b_Photon200passTrigger);
   fChain->SetBranchAddress("Photon200prescale", &Photon200prescale, &b_Photon200prescale);
   fChain->SetBranchAddress("Photon50passTrigger", &Photon50passTrigger, &b_Photon50passTrigger);
   fChain->SetBranchAddress("Photon50prescale", &Photon50prescale, &b_Photon50prescale);
   fChain->SetBranchAddress("Photon75passTrigger", &Photon75passTrigger, &b_Photon75passTrigger);
   fChain->SetBranchAddress("Photon75prescale", &Photon75prescale, &b_Photon75prescale);
   fChain->SetBranchAddress("Photon90passTrigger", &Photon90passTrigger, &b_Photon90passTrigger);
   fChain->SetBranchAddress("Photon90prescale", &Photon90prescale, &b_Photon90prescale);
   fChain->SetBranchAddress("ph_mva80X", &ph_mva80X, &b_ph_mva80X);
   fChain->SetBranchAddress("ph_mva94X", &ph_mva94X, &b_ph_mva94X);
   fChain->SetBranchAddress("ph_mva94XV2", &ph_mva94XV2, &b_ph_mva94XV2);
   fChain->SetBranchAddress("passHltPhoton120", &passHltPhoton120, &b_passHltPhoton120);
   fChain->SetBranchAddress("passHltPhoton165", &passHltPhoton165, &b_passHltPhoton165);
   fChain->SetBranchAddress("passHltPhoton200", &passHltPhoton200, &b_passHltPhoton200);
   fChain->SetBranchAddress("passHltPhoton50", &passHltPhoton50, &b_passHltPhoton50);
   fChain->SetBranchAddress("passHltPhoton75", &passHltPhoton75, &b_passHltPhoton75);
   fChain->SetBranchAddress("passHltPhoton90", &passHltPhoton90, &b_passHltPhoton90);
   fChain->SetBranchAddress("passingCutBasedLoose80X", &passingCutBasedLoose80X, &b_passingCutBasedLoose80X);
   fChain->SetBranchAddress("passingCutBasedLoose94X", &passingCutBasedLoose94X, &b_passingCutBasedLoose94X);
   fChain->SetBranchAddress("passingCutBasedLoose94XV2", &passingCutBasedLoose94XV2, &b_passingCutBasedLoose94XV2);
   fChain->SetBranchAddress("passingCutBasedLoose94XV2MinPtCut", &passingCutBasedLoose94XV2MinPtCut, &b_passingCutBasedLoose94XV2MinPtCut);
   fChain->SetBranchAddress("passingCutBasedLoose94XV2PhoFull5x5SigmaIEtaIEtaCut", &passingCutBasedLoose94XV2PhoFull5x5SigmaIEtaIEtaCut, &b_passingCutBasedLoose94XV2PhoFull5x5SigmaIEtaIEtaCut);
   fChain->SetBranchAddress("passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut", &passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut, &b_passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut);
   fChain->SetBranchAddress("passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut1", &passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut1, &b_passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut1);
   fChain->SetBranchAddress("passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut2", &passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut2, &b_passingCutBasedLoose94XV2PhoGenericRhoPtScaledCut2);
   fChain->SetBranchAddress("passingCutBasedLoose94XV2PhoSCEtaMultiRangeCut", &passingCutBasedLoose94XV2PhoSCEtaMultiRangeCut, &b_passingCutBasedLoose94XV2PhoSCEtaMultiRangeCut);
   fChain->SetBranchAddress("passingCutBasedLoose94XV2PhoSingleTowerHadOverEmCut", &passingCutBasedLoose94XV2PhoSingleTowerHadOverEmCut, &b_passingCutBasedLoose94XV2PhoSingleTowerHadOverEmCut);
   fChain->SetBranchAddress("passingCutBasedMedium80X", &passingCutBasedMedium80X, &b_passingCutBasedMedium80X);
   fChain->SetBranchAddress("passingCutBasedMedium94X", &passingCutBasedMedium94X, &b_passingCutBasedMedium94X);
   fChain->SetBranchAddress("passingCutBasedMedium94XV2", &passingCutBasedMedium94XV2, &b_passingCutBasedMedium94XV2);
   fChain->SetBranchAddress("passingCutBasedMedium94XV2MinPtCut", &passingCutBasedMedium94XV2MinPtCut, &b_passingCutBasedMedium94XV2MinPtCut);
   fChain->SetBranchAddress("passingCutBasedMedium94XV2PhoFull5x5SigmaIEtaIEtaCut", &passingCutBasedMedium94XV2PhoFull5x5SigmaIEtaIEtaCut, &b_passingCutBasedMedium94XV2PhoFull5x5SigmaIEtaIEtaCut);
   fChain->SetBranchAddress("passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut", &passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut, &b_passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut);
   fChain->SetBranchAddress("passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut1", &passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut1, &b_passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut1);
   fChain->SetBranchAddress("passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut2", &passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut2, &b_passingCutBasedMedium94XV2PhoGenericRhoPtScaledCut2);
   fChain->SetBranchAddress("passingCutBasedMedium94XV2PhoSCEtaMultiRangeCut", &passingCutBasedMedium94XV2PhoSCEtaMultiRangeCut, &b_passingCutBasedMedium94XV2PhoSCEtaMultiRangeCut);
   fChain->SetBranchAddress("passingCutBasedMedium94XV2PhoSingleTowerHadOverEmCut", &passingCutBasedMedium94XV2PhoSingleTowerHadOverEmCut, &b_passingCutBasedMedium94XV2PhoSingleTowerHadOverEmCut);
   fChain->SetBranchAddress("passingCutBasedTight80X", &passingCutBasedTight80X, &b_passingCutBasedTight80X);
   fChain->SetBranchAddress("passingCutBasedTight94X", &passingCutBasedTight94X, &b_passingCutBasedTight94X);
   fChain->SetBranchAddress("passingCutBasedTight94XV2", &passingCutBasedTight94XV2, &b_passingCutBasedTight94XV2);
   fChain->SetBranchAddress("passingCutBasedTight94XV2MinPtCut", &passingCutBasedTight94XV2MinPtCut, &b_passingCutBasedTight94XV2MinPtCut);
   fChain->SetBranchAddress("passingCutBasedTight94XV2PhoFull5x5SigmaIEtaIEtaCut", &passingCutBasedTight94XV2PhoFull5x5SigmaIEtaIEtaCut, &b_passingCutBasedTight94XV2PhoFull5x5SigmaIEtaIEtaCut);
   fChain->SetBranchAddress("passingCutBasedTight94XV2PhoGenericRhoPtScaledCut", &passingCutBasedTight94XV2PhoGenericRhoPtScaledCut, &b_passingCutBasedTight94XV2PhoGenericRhoPtScaledCut);
   fChain->SetBranchAddress("passingCutBasedTight94XV2PhoGenericRhoPtScaledCut1", &passingCutBasedTight94XV2PhoGenericRhoPtScaledCut1, &b_passingCutBasedTight94XV2PhoGenericRhoPtScaledCut1);
   fChain->SetBranchAddress("passingCutBasedTight94XV2PhoGenericRhoPtScaledCut2", &passingCutBasedTight94XV2PhoGenericRhoPtScaledCut2, &b_passingCutBasedTight94XV2PhoGenericRhoPtScaledCut2);
   fChain->SetBranchAddress("passingCutBasedTight94XV2PhoSCEtaMultiRangeCut", &passingCutBasedTight94XV2PhoSCEtaMultiRangeCut, &b_passingCutBasedTight94XV2PhoSCEtaMultiRangeCut);
   fChain->SetBranchAddress("passingCutBasedTight94XV2PhoSingleTowerHadOverEmCut", &passingCutBasedTight94XV2PhoSingleTowerHadOverEmCut, &b_passingCutBasedTight94XV2PhoSingleTowerHadOverEmCut);
   fChain->SetBranchAddress("passingMVA80Xwp80", &passingMVA80Xwp80, &b_passingMVA80Xwp80);
   fChain->SetBranchAddress("passingMVA80Xwp90", &passingMVA80Xwp90, &b_passingMVA80Xwp90);
   fChain->SetBranchAddress("passingMVA94XV2wp80", &passingMVA94XV2wp80, &b_passingMVA94XV2wp80);
   fChain->SetBranchAddress("passingMVA94XV2wp90", &passingMVA94XV2wp90, &b_passingMVA94XV2wp90);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("truePU", &truePU, &b_truePU);
   fChain->SetBranchAddress("event_nPV", &event_nPV, &b_mNPV);
   fChain->SetBranchAddress("event_met_pfmet", &event_met_pfmet, &b_mpfMET);
   fChain->SetBranchAddress("event_met_pfphi", &event_met_pfphi, &b_mpfPhi);
   fChain->SetBranchAddress("event_met_pfsumet", &event_met_pfsumet, &b_mpfSumET);
   fChain->SetBranchAddress("event_met_pfmetsignificance", &event_met_pfmetsignificance, &b_mpfMETSign);
   fChain->SetBranchAddress("event_PrimaryVertex_x", &event_PrimaryVertex_x, &b_mPVx);
   fChain->SetBranchAddress("event_PrimaryVertex_y", &event_PrimaryVertex_y, &b_mPVy);
   fChain->SetBranchAddress("event_PrimaryVertex_z", &event_PrimaryVertex_z, &b_mPVz);
   fChain->SetBranchAddress("event_BeamSpot_x", &event_BeamSpot_x, &b_mBSx);
   fChain->SetBranchAddress("event_BeamSpot_y", &event_BeamSpot_y, &b_mBSy);
   fChain->SetBranchAddress("event_BeamSpot_z", &event_BeamSpot_z, &b_mBSz);
   fChain->SetBranchAddress("event_rho", &event_rho, &b_rho);
   fChain->SetBranchAddress("mass", &mass, &b_mass);
   fChain->SetBranchAddress("tag_Ele_3charge", &tag_Ele_3charge, &b_tag_Ele_3charge);
   fChain->SetBranchAddress("tag_Ele_abseta", &tag_Ele_abseta, &b_tag_Ele_abseta);
   fChain->SetBranchAddress("tag_Ele_e", &tag_Ele_e, &b_tag_Ele_e);
   fChain->SetBranchAddress("tag_Ele_et", &tag_Ele_et, &b_tag_Ele_et);
   fChain->SetBranchAddress("tag_Ele_eta", &tag_Ele_eta, &b_tag_Ele_eta);
   fChain->SetBranchAddress("tag_Ele_phi", &tag_Ele_phi, &b_tag_Ele_phi);
   fChain->SetBranchAddress("tag_Ele_pt", &tag_Ele_pt, &b_tag_Ele_pt);
   fChain->SetBranchAddress("tag_Ele_q", &tag_Ele_q, &b_tag_Ele_q);
   fChain->SetBranchAddress("tag_sc_abseta", &tag_sc_abseta, &b_tag_sc_abseta);
   fChain->SetBranchAddress("tag_sc_e", &tag_sc_e, &b_tag_sc_e);
   fChain->SetBranchAddress("tag_sc_et", &tag_sc_et, &b_tag_sc_et);
   fChain->SetBranchAddress("tag_sc_eta", &tag_sc_eta, &b_tag_sc_eta);
   fChain->SetBranchAddress("tag_Ele_IsoMVA94X", &tag_Ele_IsoMVA94X, &b_tag_Ele_IsoMVA94X);
   fChain->SetBranchAddress("tag_Ele_IsoMVA94XV2", &tag_Ele_IsoMVA94XV2, &b_tag_Ele_IsoMVA94XV2);
   fChain->SetBranchAddress("tag_Ele_dxy", &tag_Ele_dxy, &b_tag_Ele_dxy);
   fChain->SetBranchAddress("tag_Ele_dz", &tag_Ele_dz, &b_tag_Ele_dz);
   fChain->SetBranchAddress("tag_Ele_hzzMVA80X", &tag_Ele_hzzMVA80X, &b_tag_Ele_hzzMVA80X);
   fChain->SetBranchAddress("tag_Ele_noIsoMVA94X", &tag_Ele_noIsoMVA94X, &b_tag_Ele_noIsoMVA94X);
   fChain->SetBranchAddress("tag_Ele_noIsoMVA94XV2", &tag_Ele_noIsoMVA94XV2, &b_tag_Ele_noIsoMVA94XV2);
   fChain->SetBranchAddress("tag_Ele_nonTrigMVA80X", &tag_Ele_nonTrigMVA80X, &b_tag_Ele_nonTrigMVA80X);
   fChain->SetBranchAddress("tag_Ele_trigMVA", &tag_Ele_trigMVA, &b_tag_Ele_trigMVA);
   fChain->SetBranchAddress("tag_el_sip", &tag_el_sip, &b_tag_el_sip);
   fChain->SetBranchAddress("pair_abseta", &pair_abseta, &b_pair_abseta);
   fChain->SetBranchAddress("pair_eta", &pair_eta, &b_pair_eta);
   fChain->SetBranchAddress("pair_mass", &pair_mass, &b_pair_mass);
   fChain->SetBranchAddress("pair_pt", &pair_pt, &b_pair_pt);
   Notify();
}

Bool_t fitter_tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void fitter_tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t fitter_tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef fitter_tree_cxx
