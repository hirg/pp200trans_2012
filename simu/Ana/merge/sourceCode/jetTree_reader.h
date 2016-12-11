//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 27 17:57:50 2016 by ROOT version 5.34/30
// from TTree simple_Jet/Simple Jets Tree
// found on file: ptH_4_5/test_sjet.root
//////////////////////////////////////////////////////////

#ifndef jetTree_reader_h
#define jetTree_reader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class jetTree_reader {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           runID;
   Int_t           evtID;
   Int_t           spin4skim;
   Int_t           njet;
   Int_t           IsJP0s;
   Int_t           IsJP1s;
   Int_t           IsJP2s;
   Int_t           IsAJPs;
   Int_t           J_sv[100];   //[njet]
   Double_t        J_deteta[100];   //[njet]
   Double_t        J_eta[100];   //[njet]
   Double_t        J_pt[100];   //[njet]
   Double_t        J_phi[100];   //[njet]
   Double_t        J_px[100];   //[njet]
   Double_t        J_py[100];   //[njet]
   Double_t        J_pz[100];   //[njet]
   Double_t        J_rt[100];   //[njet]
   Double_t        J_E[100];   //[njet]
   Double_t        J_btowEt[100];   //[njet]
   Double_t        J_tpcEt[100];   //[njet]
   Double_t        J_charge[100];   //[njet]
   Int_t           J_ncell[100];   //[njet]
   Int_t           J_ntra[100];   //[njet]
   Int_t           J_trackID[100][50];   //[njet]

   // List of branches
   TBranch        *b_runID;   //!
   TBranch        *b_evtID;   //!
   TBranch        *b_spin4skim;   //!
   TBranch        *b_njet;   //!
   TBranch        *b_IsJP0h;   //!
   TBranch        *b_IsJP0s;   //!
   TBranch        *b_IsJP1h;   //!
   TBranch        *b_IsJP1s;   //!
   TBranch        *b_IsJP2h;   //!
   TBranch        *b_IsJP2s;   //!
   TBranch        *b_IsAJPh;   //!
   TBranch        *b_IsAJPs;   //!
   TBranch        *b_J_sv;   //!
   TBranch        *b_J_deteta;   //!
   TBranch        *b_J_eta;   //!
   TBranch        *b_J_pt;   //!
   TBranch        *b_J_phi;   //!
   TBranch        *b_J_px;   //!
   TBranch        *b_J_py;   //!
   TBranch        *b_J_pz;   //!
   TBranch        *b_J_rt;   //!
   TBranch        *b_J_E;   //!
   TBranch        *b_J_btowEt;   //!
   TBranch        *b_J_tpcEt;   //!
   TBranch        *b_J_charge;   //!
   TBranch        *b_J_ncell;   //!
   TBranch        *b_J_ntra;   //!
   TBranch        *b_J_trackID;   //!

   jetTree_reader(TTree *tree=0);
   virtual ~jetTree_reader();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Int_t    GetEntryWithIndex(Int_t major, Int_t minor=0);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef jetTree_reader_cxx
jetTree_reader::jetTree_reader(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ptH_4_5/test_sjet.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("ptH_4_5/test_sjet.root");
      }
      f->GetObject("simple_Jet",tree);

   }
   Init(tree);
}

jetTree_reader::~jetTree_reader()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t jetTree_reader::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Int_t jetTree_reader::GetEntryWithIndex(Int_t major, Int_t minor)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntryWithIndex(major, minor);
}

Long64_t jetTree_reader::LoadTree(Long64_t entry)
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

void jetTree_reader::Init(TTree *tree)
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

   fChain->SetBranchAddress("runID", &runID, &b_runID);
   fChain->SetBranchAddress("evtID", &evtID, &b_evtID);
   fChain->SetBranchAddress("spin4skim", &spin4skim, &b_spin4skim);
   fChain->SetBranchAddress("njet", &njet, &b_njet);
   fChain->SetBranchAddress("IsJP0s", &IsJP0s, &b_IsJP0s);
   fChain->SetBranchAddress("IsJP1s", &IsJP1s, &b_IsJP1s);
   fChain->SetBranchAddress("IsJP2s", &IsJP2s, &b_IsJP2s);
   fChain->SetBranchAddress("IsAJPs", &IsAJPs, &b_IsAJPs);
   fChain->SetBranchAddress("J_sv", J_sv, &b_J_sv);
   fChain->SetBranchAddress("J_deteta", J_deteta, &b_J_deteta);
   fChain->SetBranchAddress("J_eta", J_eta, &b_J_eta);
   fChain->SetBranchAddress("J_pt", J_pt, &b_J_pt);
   fChain->SetBranchAddress("J_phi", J_phi, &b_J_phi);
   fChain->SetBranchAddress("J_px", J_px, &b_J_px);
   fChain->SetBranchAddress("J_py", J_py, &b_J_py);
   fChain->SetBranchAddress("J_pz", J_pz, &b_J_pz);
   fChain->SetBranchAddress("J_rt", J_rt, &b_J_rt);
   fChain->SetBranchAddress("J_E", J_E, &b_J_E);
   fChain->SetBranchAddress("J_btowEt", J_btowEt, &b_J_btowEt);
   fChain->SetBranchAddress("J_tpcEt", J_tpcEt, &b_J_tpcEt);
   fChain->SetBranchAddress("J_charge", J_charge, &b_J_charge);
   fChain->SetBranchAddress("J_ncell", J_ncell, &b_J_ncell);
   fChain->SetBranchAddress("J_ntra", J_ntra, &b_J_ntra);
   fChain->SetBranchAddress("J_trackID", J_trackID, &b_J_trackID);

   Notify();
}

Bool_t jetTree_reader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void jetTree_reader::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t jetTree_reader::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef jetTree_reader_cxx
