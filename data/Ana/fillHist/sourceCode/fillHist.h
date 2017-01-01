//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Dec  8 21:50:35 2016 by ROOT version 5.34/30
// from TTree Tree_SelectLAK/Tree_SelectLAK
// found on file: ../../Select/data/13044126.select.root
//////////////////////////////////////////////////////////

#ifndef fillHist_h
#define fillHist_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
class TH1D;
class TH2D;
class TH1I;

// Fixed size dimensions of array or collections stored in the TTree if any.
const int kMax = 100;

class fillHist : public TSelector {
private :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Cut Variables
   double        c_nSigma_protect;
   double        c_nSigma_proton;
   double        c_nSigma_pion;
   double        c_dca_min_proton;
   double        c_dca_min_pion;
   double        c_crp_min;
   double        c_dca2_max;
   double        c_dcaV0_max;
   double        c_dl_min;
   double        c_dl_max;
   double        c_P_min_pion;

   double        K_c_dca_min_pion;
   double        K_c_crp_min;
   double        K_c_dcaV0_max;
   double        K_c_dl_min;

   // Declaration of leaf types
   int           runID;
   int           eventID;
   int           spin;
   int           spinbit;
   int           spinbit8;
   int           bx7;
   int           bx48;
   double        magn;
   double        bbcrate;
   double        zdcrate;
   int           bbcTimebin;
   double        pvx;
   double        pvy;
   double        pvz;
   int           trig[4];
   int           IsJP1;
   int           IsJP0;
   int           IsJP2;
   int           IsAJP;
   int           npv;
   int           npvrank;
   double        npvx;
   double        npvy;
   double        npvz;
   int           ngtr;
   int           nptr;
   int           spin4skim;
   int           njet;
   int           IsJP0h;
   int           IsJP0s;
   int           IsJP1h;
   int           IsJP1s;
   int           IsJP2h;
   int           IsJP2s;
   int           IsAJPh;
   int           IsAJPs;
   int           Jmatch;
   int           J_sv[kMax];   //[njet]
   double        J_deteta[kMax];   //[njet]
   double        J_eta[kMax];   //[njet]
   double        J_pt[kMax];   //[njet]
   double        J_phi[kMax];   //[njet]
   double        J_rt[kMax];   //[njet]
   double        J_E[kMax];   //[njet]
   double        J_btowEt[kMax];   //[njet]
   double        J_tpcEt[kMax];   //[njet]
   double        J_charge[kMax];   //[njet]
   double        J_ncell[kMax];   //[njet]
   double        J_ntrac[kMax];   //[njet]
   int           snlam;
   int           snlbr;
   int           snk0s;
   int           sLp_nHit[kMax];   //[snlam]
   int           sLp_nHitPos[kMax];   //[snlam]
   double        sLp_dca[kMax];   //[snlam]
   double        sLp_nSigmaP[kMax];   //[snlam]
   double        sLp_nSigmaPi[kMax];   //[snlam]
   double        sLp_pt[kMax];   //[snlam]
   double        sLp_phi[kMax];   //[snlam]
   double        sLp_eta[kMax];   //[snlam]
   double        sLp_beta[kMax];   //[snlam]
   double        sLp_btofm2[kMax];   //[snlam]
   double        sLp_ID[kMax];   //[snlam]
   int           sLp_Charge[kMax];   //[snlam]
   int           sLpi_nHit[kMax];   //[snlam]
   int           sLpi_nHitPos[kMax];   //[snlam]
   double        sLpi_dca[kMax];   //[snlam]
   double        sLpi_nSigmaP[kMax];   //[snlam]
   double        sLpi_nSigmaPi[kMax];   //[snlam]
   double        sLpi_pt[kMax];   //[snlam]
   double        sLpi_phi[kMax];   //[snlam]
   double        sLpi_eta[kMax];   //[snlam]
   double        sLpi_beta[kMax];   //[snlam]
   double        sLpi_btofm2[kMax];   //[snlam]
   double        sLpi_ID[kMax];   //[snlam]
   int           sLpi_Charge[kMax];   //[snlam]
   double        sL_V0x[kMax];   //[snlam]
   double        sL_V0y[kMax];   //[snlam]
   double        sL_V0z[kMax];   //[snlam]
   double        sL_pt[kMax];   //[snlam]
   double        sL_phi[kMax];   //[snlam]
   double        sL_eta[kMax];   //[snlam]
   double        sL_im[kMax];   //[snlam]
   double        sL_dca2[kMax];   //[snlam]
   double        sL_dcaV0[kMax];   //[snlam]
   double        sL_dl[kMax];   //[snlam]
   double        sL_crp[kMax];   //[snlam]
   int           sL_index[kMax];   //[snlam]
   double        sL_dr[kMax];   //[snlam]
   double        sL_dphi[kMax];   //[snlam]
   double        sL_deta[kMax];   //[snlam]
   double        sL_cosTv_yell[kMax];   //[snlam]
   double        sL_cosTv_blue[kMax];   //[snlam]
   double        sL_cosTj_yell[kMax];   //[snlam]
   double        sL_cosTj_blue[kMax];   //[snlam]
   double        sL_cosN_yell[kMax];   //[snlam]
   double        sL_cosN_blue[kMax];   //[snlam]
   double        sL_cosY_yell[kMax];   //[snlam]
   double        sL_cosY_blue[kMax];   //[snlam]
   int           sAp_nHit[kMax];   //[snlbr]
   int           sAp_nHitPos[kMax];   //[snlbr]
   double        sAp_dca[kMax];   //[snlbr]
   double        sAp_nSigmaP[kMax];   //[snlbr]
   double        sAp_nSigmaPi[kMax];   //[snlbr]
   double        sAp_pt[kMax];   //[snlbr]
   double        sAp_phi[kMax];   //[snlbr]
   double        sAp_eta[kMax];   //[snlbr]
   double        sAp_beta[kMax];   //[snlbr]
   double        sAp_btofm2[kMax];   //[snlbr]
   double        sAp_ID[kMax];   //[snlbr]
   int           sAp_Charge[kMax];   //[snlbr]
   int           sApi_nHit[kMax];   //[snlbr]
   int           sApi_nHitPos[kMax];   //[snlbr]
   double        sApi_dca[kMax];   //[snlbr]
   double        sApi_nSigmaP[kMax];   //[snlbr]
   double        sApi_nSigmaPi[kMax];   //[snlbr]
   double        sApi_pt[kMax];   //[snlbr]
   double        sApi_phi[kMax];   //[snlbr]
   double        sApi_eta[kMax];   //[snlbr]
   double        sApi_beta[kMax];   //[snlbr]
   double        sApi_btofm2[kMax];   //[snlbr]
   double        sApi_ID[kMax];   //[snlbr]
   int           sApi_Charge[kMax];   //[snlbr]
   double        sA_V0x[kMax];   //[snlbr]
   double        sA_V0y[kMax];   //[snlbr]
   double        sA_V0z[kMax];   //[snlbr]
   double        sA_pt[kMax];   //[snlbr]
   double        sA_phi[kMax];   //[snlbr]
   double        sA_eta[kMax];   //[snlbr]
   double        sA_im[kMax];   //[snlbr]
   double        sA_dca2[kMax];   //[snlbr]
   double        sA_dcaV0[kMax];   //[snlbr]
   double        sA_dl[kMax];   //[snlbr]
   double        sA_crp[kMax];   //[snlbr]
   int           sA_index[kMax];   //[snlbr]
   double        sA_dr[kMax];   //[snlbr]
   double        sA_dphi[kMax];   //[snlbr]
   double        sA_deta[kMax];   //[snlbr]
   double        sA_cosTv_yell[kMax];   //[snlbr]
   double        sA_cosTv_blue[kMax];   //[snlbr]
   double        sA_cosTj_yell[kMax];   //[snlbr]
   double        sA_cosTj_blue[kMax];   //[snlbr]
   double        sA_cosN_yell[kMax];   //[snlbr]
   double        sA_cosN_blue[kMax];   //[snlbr]
   double        sA_cosY_yell[kMax];   //[snlbr]
   double        sA_cosY_blue[kMax];   //[snlbr]
   int           sKp_nHit[kMax];   //[snk0s]
   int           sKp_nHitPos[kMax];   //[snk0s]
   double        sKp_dca[kMax];   //[snk0s]
   double        sKp_nSigmaP[kMax];   //[snk0s]
   double        sKp_nSigmaPi[kMax];   //[snk0s]
   double        sKp_pt[kMax];   //[snk0s]
   double        sKp_phi[kMax];   //[snk0s]
   double        sKp_eta[kMax];   //[snk0s]
   double        sKp_beta[kMax];   //[snk0s]
   double        sKp_btofm2[kMax];   //[snk0s]
   double        sKp_ID[kMax];   //[snk0s]
   int           sKp_Charge[kMax];   //[snk0s]
   int           sKpi_nHit[kMax];   //[snk0s]
   int           sKpi_nHitPos[kMax];   //[snk0s]
   double        sKpi_dca[kMax];   //[snk0s]
   double        sKpi_nSigmaP[kMax];   //[snk0s]
   double        sKpi_nSigmaPi[kMax];   //[snk0s]
   double        sKpi_pt[kMax];   //[snk0s]
   double        sKpi_phi[kMax];   //[snk0s]
   double        sKpi_eta[kMax];   //[snk0s]
   double        sKpi_beta[kMax];   //[snk0s]
   double        sKpi_btofm2[kMax];   //[snk0s]
   double        sKpi_ID[kMax];   //[snk0s]
   int           sKpi_Charge[kMax];   //[snk0s]
   double        sK_V0x[kMax];   //[snk0s]
   double        sK_V0y[kMax];   //[snk0s]
   double        sK_V0z[kMax];   //[snk0s]
   double        sK_pt[kMax];   //[snk0s]
   double        sK_phi[kMax];   //[snk0s]
   double        sK_eta[kMax];   //[snk0s]
   double        sK_im[kMax];   //[snk0s]
   double        sK_dca2[kMax];   //[snk0s]
   double        sK_dcaV0[kMax];   //[snk0s]
   double        sK_dl[kMax];   //[snk0s]
   double        sK_crp[kMax];   //[snk0s]
   int           sK_index[kMax];   //[snk0s]
   double        sK_dr[kMax];   //[snk0s]
   double        sK_dphi[kMax];   //[snk0s]
   double        sK_deta[kMax];   //[snk0s]
   double        sK_cosTv_yell[kMax];   //[snk0s]
   double        sK_cosTv_blue[kMax];   //[snk0s]
   double        sK_cosTj_yell[kMax];   //[snk0s]
   double        sK_cosTj_blue[kMax];   //[snk0s]
   double        sK_cosN_yell[kMax];   //[snk0s]
   double        sK_cosN_blue[kMax];   //[snk0s]
   double        sK_cosY_yell[kMax];   //[snk0s]
   double        sK_cosY_blue[kMax];   //[snk0s]

   // List of branches
   TBranch        *b_runID;   //!
   TBranch        *b_eventID;   //!
   TBranch        *b_spin;   //!
   TBranch        *b_spinbit;   //!
   TBranch        *b_spinbit8;   //!
   TBranch        *b_bx7;   //!
   TBranch        *b_bx48;   //!
   TBranch        *b_magn;   //!
   TBranch        *b_bbcrate;   //!
   TBranch        *b_zdcrate;   //!
   TBranch        *b_bbcTimebin;   //!
   TBranch        *b_pvx;   //!
   TBranch        *b_pvy;   //!
   TBranch        *b_pvz;   //!
   TBranch        *b_trig;   //!
   TBranch        *b_IsJP1;   //!
   TBranch        *b_IsJP0;   //!
   TBranch        *b_IsJP2;   //!
   TBranch        *b_IsAJP;   //!
   TBranch        *b_npv;   //!
   TBranch        *b_npvrank;   //!
   TBranch        *b_npvx;   //!
   TBranch        *b_npvy;   //!
   TBranch        *b_npvz;   //!
   TBranch        *b_ngtr;   //!
   TBranch        *b_nptr;   //!
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
   TBranch        *b_Jmatch;   //!
   TBranch        *b_J_sv;   //!
   TBranch        *b_J_deteta;   //!
   TBranch        *b_J_eta;   //!
   TBranch        *b_J_pt;   //!
   TBranch        *b_J_phi;   //!
   TBranch        *b_J_rt;   //!
   TBranch        *b_J_E;   //!
   TBranch        *b_J_btowEt;   //!
   TBranch        *b_J_tpcEt;   //!
   TBranch        *b_J_charge;   //!
   TBranch        *b_J_ncell;   //!
   TBranch        *b_J_ntrac;   //!
   TBranch        *b_snlam;   //!
   TBranch        *b_snlbr;   //!
   TBranch        *b_snk0s;   //!
   TBranch        *b_sLp_nHit;   //!
   TBranch        *b_sLp_nHitPos;   //!
   TBranch        *b_sLp_dca;   //!
   TBranch        *b_sLp_nSigmaP;   //!
   TBranch        *b_sLp_nSigmaPi;   //!
   TBranch        *b_sLp_pt;   //!
   TBranch        *b_sLp_phi;   //!
   TBranch        *b_sLp_eta;   //!
   TBranch        *b_sLp_beta;   //!
   TBranch        *b_sLp_btofm2;   //!
   TBranch        *b_sLp_ID;   //!
   TBranch        *b_sLp_Charge;   //!
   TBranch        *b_sLpi_nHit;   //!
   TBranch        *b_sLpi_nHitPos;   //!
   TBranch        *b_sLpi_dca;   //!
   TBranch        *b_sLpi_nSigmaP;   //!
   TBranch        *b_sLpi_nSigmaPi;   //!
   TBranch        *b_sLpi_pt;   //!
   TBranch        *b_sLpi_phi;   //!
   TBranch        *b_sLpi_eta;   //!
   TBranch        *b_sLpi_beta;   //!
   TBranch        *b_sLpi_btofm2;   //!
   TBranch        *b_sLpi_ID;   //!
   TBranch        *b_sLpi_Charge;   //!
   TBranch        *b_sL_V0x;   //!
   TBranch        *b_sL_V0y;   //!
   TBranch        *b_sL_V0z;   //!
   TBranch        *b_sL_pt;   //!
   TBranch        *b_sL_phi;   //!
   TBranch        *b_sL_eta;   //!
   TBranch        *b_sL_im;   //!
   TBranch        *b_sL_dca2;   //!
   TBranch        *b_sL_dcaV0;   //!
   TBranch        *b_sL_dl;   //!
   TBranch        *b_sL_crp;   //!
   TBranch        *b_sL_index;   //!
   TBranch        *b_sL_dr;   //!
   TBranch        *b_sL_dphi;   //!
   TBranch        *b_sL_deta;   //!
   TBranch        *b_sL_cosTv_yell;   //!
   TBranch        *b_sL_cosTv_blue;   //!
   TBranch        *b_sL_cosTj_yell;   //!
   TBranch        *b_sL_cosTj_blue;   //!
   TBranch        *b_sL_cosN_yell;   //!
   TBranch        *b_sL_cosN_blue;   //!
   TBranch        *b_sL_cosY_yell;   //!
   TBranch        *b_sL_cosY_blue;   //!
   TBranch        *b_sAp_nHit;   //!
   TBranch        *b_sAp_nHitPos;   //!
   TBranch        *b_sAp_dca;   //!
   TBranch        *b_sAp_nSigmaP;   //!
   TBranch        *b_sAp_nSigmaPi;   //!
   TBranch        *b_sAp_pt;   //!
   TBranch        *b_sAp_phi;   //!
   TBranch        *b_sAp_eta;   //!
   TBranch        *b_sAp_beta;   //!
   TBranch        *b_sAp_btofm2;   //!
   TBranch        *b_sAp_ID;   //!
   TBranch        *b_sAp_Charge;   //!
   TBranch        *b_sApi_nHit;   //!
   TBranch        *b_sApi_nHitPos;   //!
   TBranch        *b_sApi_dca;   //!
   TBranch        *b_sApi_nSigmaP;   //!
   TBranch        *b_sApi_nSigmaPi;   //!
   TBranch        *b_sApi_pt;   //!
   TBranch        *b_sApi_phi;   //!
   TBranch        *b_sApi_eta;   //!
   TBranch        *b_sApi_beta;   //!
   TBranch        *b_sApi_btofm2;   //!
   TBranch        *b_sApi_ID;   //!
   TBranch        *b_sApi_Charge;   //!
   TBranch        *b_sA_V0x;   //!
   TBranch        *b_sA_V0y;   //!
   TBranch        *b_sA_V0z;   //!
   TBranch        *b_sA_pt;   //!
   TBranch        *b_sA_phi;   //!
   TBranch        *b_sA_eta;   //!
   TBranch        *b_sA_im;   //!
   TBranch        *b_sA_dca2;   //!
   TBranch        *b_sA_dcaV0;   //!
   TBranch        *b_sA_dl;   //!
   TBranch        *b_sA_crp;   //!
   TBranch        *b_sA_index;   //!
   TBranch        *b_sA_dr;   //!
   TBranch        *b_sA_dphi;   //!
   TBranch        *b_sA_deta;   //!
   TBranch        *b_sA_cosTv_yell;   //!
   TBranch        *b_sA_cosTv_blue;   //!
   TBranch        *b_sA_cosTj_yell;   //!
   TBranch        *b_sA_cosTj_blue;   //!
   TBranch        *b_sA_cosN_yell;   //!
   TBranch        *b_sA_cosN_blue;   //!
   TBranch        *b_sA_cosY_yell;   //!
   TBranch        *b_sA_cosY_blue;   //!
   TBranch        *b_sKp_nHit;   //!
   TBranch        *b_sKp_nHitPos;   //!
   TBranch        *b_sKp_dca;   //!
   TBranch        *b_sKp_nSigmaP;   //!
   TBranch        *b_sKp_nSigmaPi;   //!
   TBranch        *b_sKp_pt;   //!
   TBranch        *b_sKp_phi;   //!
   TBranch        *b_sKp_eta;   //!
   TBranch        *b_sKp_beta;   //!
   TBranch        *b_sKp_btofm2;   //!
   TBranch        *b_sKp_ID;   //!
   TBranch        *b_sKp_Charge;   //!
   TBranch        *b_sKpi_nHit;   //!
   TBranch        *b_sKpi_nHitPos;   //!
   TBranch        *b_sKpi_dca;   //!
   TBranch        *b_sKpi_nSigmaP;   //!
   TBranch        *b_sKpi_nSigmaPi;   //!
   TBranch        *b_sKpi_pt;   //!
   TBranch        *b_sKpi_phi;   //!
   TBranch        *b_sKpi_eta;   //!
   TBranch        *b_sKpi_beta;   //!
   TBranch        *b_sKpi_btofm2;   //!
   TBranch        *b_sKpi_ID;   //!
   TBranch        *b_sKpi_Charge;   //!
   TBranch        *b_sK_V0x;   //!
   TBranch        *b_sK_V0y;   //!
   TBranch        *b_sK_V0z;   //!
   TBranch        *b_sK_pt;   //!
   TBranch        *b_sK_phi;   //!
   TBranch        *b_sK_eta;   //!
   TBranch        *b_sK_im;   //!
   TBranch        *b_sK_dca2;   //!
   TBranch        *b_sK_dcaV0;   //!
   TBranch        *b_sK_dl;   //!
   TBranch        *b_sK_crp;   //!
   TBranch        *b_sK_index;   //!
   TBranch        *b_sK_dr;   //!
   TBranch        *b_sK_dphi;   //!
   TBranch        *b_sK_deta;   //!
   TBranch        *b_sK_cosTv_yell;   //!
   TBranch        *b_sK_cosTv_blue;   //!
   TBranch        *b_sK_cosTj_yell;   //!
   TBranch        *b_sK_cosTj_blue;   //!
   TBranch        *b_sK_cosN_yell;   //!
   TBranch        *b_sK_cosN_blue;   //!
   TBranch        *b_sK_cosY_yell;   //!
   TBranch        *b_sK_cosY_blue;   //!

public:

   fillHist(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~fillHist() { }
   virtual int     Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual bool    Notify();
   virtual bool    Process(Long64_t entry);
   virtual int     GetEntry(Long64_t entry, int getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

           bool    checkSpin();
           bool    checkTrig();
           int     getPTbin(double apt);
           void    ReadCutTable(int apt);

   // Declare histograms
   TH1D           *h_pvz0;
   TH1D           *h_pvz1;
   TH1I           *h_spinbit;
   TH1D           *h_bbcrate;
   TH1D           *h_zdcrate;

   TH1D           *h_nJet;
   TH1D           *h_deteta_J;
   TH1D           *h_eta_J;
   TH1D           *h_pt_J;
   TH1D           *h_phi_J;
   TH1D           *h_rt_J;
   TH1D           *h_charge_J;

   TH1D           *h_im_L[2][6];
   TH1D           *h_pt_Lp[2][6];
   TH1D           *h_eta_Lp[2][6];  
   TH1D           *h_phi_Lp[2][6];   
   TH1D           *h_pt_Lpi[2][6];  
   TH1D           *h_eta_Lpi[2][6]; 
   TH1D           *h_phi_Lpi[2][6]; 
   TH1D           *h_pt_L[2][6];   
   TH1D           *h_eta_L[2][6];   
   TH1D           *h_phi_L[2][6];   
   TH1D           *h_dca_Lp[2][6];   
   TH1D           *h_dca_Lpi[2][6];   
   TH1D           *h_nFit_Lp[2][6];   
   TH1D           *h_nFit_Lpi[2][6];  
   TH1D           *h_nSigP_Lp[2][6];
   TH1D           *h_nSigPi_Lpi[2][6];
   TH1D           *h_dl_L[2][6];   
   TH1D           *h_dca2_L[2][6];   
   TH1D           *h_dcaV0_L[2][6];   
   TH1D           *h_crp_L[2][6];
   TH1D           *h_dr_L[2][6];   
   TH1D           *h_deta_L[2][6]; 
   TH1D           *h_dphi_L[2][6];
   TH2D           *h_cV_yell_L[2][6];
   TH2D           *h_cJ_yell_L[2][6];
   TH2D           *h_cN_yell_L[2][6];
   TH2D           *h_cY_yell_L[2][6];
   TH2D           *h_cV_blue_L[2][6];
   TH2D           *h_cJ_blue_L[2][6];
   TH2D           *h_cN_blue_L[2][6];
   TH2D           *h_cY_blue_L[2][6];
   TH1D           *h_fz_L[6];

   TH1D           *h_im_A[2][6];
   TH1D           *h_pt_Ap[2][6];
   TH1D           *h_eta_Ap[2][6];  
   TH1D           *h_phi_Ap[2][6];   
   TH1D           *h_pt_Api[2][6];  
   TH1D           *h_eta_Api[2][6]; 
   TH1D           *h_phi_Api[2][6]; 
   TH1D           *h_pt_A[2][6];   
   TH1D           *h_eta_A[2][6];   
   TH1D           *h_phi_A[2][6];   
   TH1D           *h_dca_Ap[2][6];   
   TH1D           *h_dca_Api[2][6];   
   TH1D           *h_nFit_Ap[2][6];   
   TH1D           *h_nFit_Api[2][6];  
   TH1D           *h_nSigP_Ap[2][6];
   TH1D           *h_nSigPi_Api[2][6];
   TH1D           *h_dl_A[2][6];   
   TH1D           *h_dca2_A[2][6];   
   TH1D           *h_dcaV0_A[2][6];   
   TH1D           *h_crp_A[2][6];
   TH1D           *h_dr_A[2][6];   
   TH1D           *h_deta_A[2][6]; 
   TH1D           *h_dphi_A[2][6];
   TH2D           *h_cV_yell_A[2][6];
   TH2D           *h_cJ_yell_A[2][6];
   TH2D           *h_cN_yell_A[2][6];
   TH2D           *h_cY_yell_A[2][6];
   TH2D           *h_cV_blue_A[2][6];
   TH2D           *h_cJ_blue_A[2][6];
   TH2D           *h_cN_blue_A[2][6];
   TH2D           *h_cY_blue_A[2][6];
   TH1D           *h_fz_A[6];

   TH1D           *h_im_K[2][6];
   TH1D           *h_pt_Kp[2][6];
   TH1D           *h_eta_Kp[2][6];  
   TH1D           *h_phi_Kp[2][6];   
   TH1D           *h_pt_Kpi[2][6];  
   TH1D           *h_eta_Kpi[2][6]; 
   TH1D           *h_phi_Kpi[2][6]; 
   TH1D           *h_pt_K[2][6];   
   TH1D           *h_eta_K[2][6];   
   TH1D           *h_phi_K[2][6];   
   TH1D           *h_dca_Kp[2][6];   
   TH1D           *h_dca_Kpi[2][6];   
   TH1D           *h_nFit_Kp[2][6];   
   TH1D           *h_nFit_Kpi[2][6];  
   TH1D           *h_nSigP_Kp[2][6];
   TH1D           *h_nSigPi_Kpi[2][6];
   TH1D           *h_dl_K[2][6];   
   TH1D           *h_dca2_K[2][6];   
   TH1D           *h_dcaV0_K[2][6];   
   TH1D           *h_crp_K[2][6];
   TH1D           *h_dr_K[2][6];   
   TH1D           *h_deta_K[2][6]; 
   TH1D           *h_dphi_K[2][6];
   TH2D           *h_cV_yell_K[2][6];
   TH2D           *h_cJ_yell_K[2][6];
   TH2D           *h_cN_yell_K[2][6];
   TH2D           *h_cY_yell_K[2][6];
   TH2D           *h_cV_blue_K[2][6];
   TH2D           *h_cJ_blue_K[2][6];
   TH2D           *h_cN_blue_K[2][6];
   TH2D           *h_cY_blue_K[2][6];
   TH1D           *h_fz_K[6];

   TH1D           *h_peak_pt_Lp[2][6];
   TH1D           *h_peak_eta_Lp[2][6];  
   TH1D           *h_peak_phi_Lp[2][6];   
   TH1D           *h_peak_pt_Lpi[2][6];  
   TH1D           *h_peak_eta_Lpi[2][6]; 
   TH1D           *h_peak_phi_Lpi[2][6]; 
   TH1D           *h_peak_pt_L[2][6];   
   TH1D           *h_peak_eta_L[2][6];   
   TH1D           *h_peak_phi_L[2][6];      
   TH1D           *h_peak_dca_Lp[2][6];   
   TH1D           *h_peak_dca_Lpi[2][6];   
   TH1D           *h_peak_nFit_Lp[2][6];   
   TH1D           *h_peak_nFit_Lpi[2][6];  
   TH1D           *h_peak_nSigP_Lp[2][6];
   TH1D           *h_peak_nSigPi_Lpi[2][6];
   TH1D           *h_peak_dl_L[2][6];   
   TH1D           *h_peak_dca2_L[2][6];   
   TH1D           *h_peak_dcaV0_L[2][6];   
   TH1D           *h_peak_crp_L[2][6];
   TH1D           *h_peak_dr_L[2][6];   
   TH1D           *h_peak_deta_L[2][6]; 
   TH1D           *h_peak_dphi_L[2][6];
   TH1D           *h_peak_fz_L[6];

   TH1D           *h_peak_pt_Ap[2][6];
   TH1D           *h_peak_eta_Ap[2][6];  
   TH1D           *h_peak_phi_Ap[2][6];    
   TH1D           *h_peak_pt_Api[2][6];  
   TH1D           *h_peak_eta_Api[2][6]; 
   TH1D           *h_peak_phi_Api[2][6]; 
   TH1D           *h_peak_x_stop_A[2][6];
   TH1D           *h_peak_y_stop_A[2][6];
   TH1D           *h_peak_z_stop_A[2][6];
   TH1D           *h_peak_pt_A[2][6];   
   TH1D           *h_peak_eta_A[2][6];   
   TH1D           *h_peak_phi_A[2][6];   
   TH1D           *h_peak_dca_Ap[2][6];   
   TH1D           *h_peak_dca_Api[2][6];   
   TH1D           *h_peak_nFit_Ap[2][6];   
   TH1D           *h_peak_nFit_Api[2][6];  
   TH1D           *h_peak_nSigP_Ap[2][6];
   TH1D           *h_peak_nSigPi_Api[2][6];
   TH1D           *h_peak_dl_A[2][6];   
   TH1D           *h_peak_dca2_A[2][6];   
   TH1D           *h_peak_dcaV0_A[2][6];   
   TH1D           *h_peak_crp_A[2][6];
   TH1D           *h_peak_dr_A[2][6];   
   TH1D           *h_peak_deta_A[2][6]; 
   TH1D           *h_peak_dphi_A[2][6];
   TH1D           *h_peak_fz_A[6];

   TH1D           *h_peak_pt_Kp[2][6];
   TH1D           *h_peak_eta_Kp[2][6];  
   TH1D           *h_peak_phi_Kp[2][6];    
   TH1D           *h_peak_pt_Kpi[2][6];  
   TH1D           *h_peak_eta_Kpi[2][6]; 
   TH1D           *h_peak_phi_Kpi[2][6]; 
   TH1D           *h_peak_x_stop_K[2][6];
   TH1D           *h_peak_y_stop_K[2][6];
   TH1D           *h_peak_z_stop_K[2][6];
   TH1D           *h_peak_pt_K[2][6];   
   TH1D           *h_peak_eta_K[2][6];   
   TH1D           *h_peak_phi_K[2][6];   
   TH1D           *h_peak_dca_Kp[2][6];   
   TH1D           *h_peak_dca_Kpi[2][6];   
   TH1D           *h_peak_nFit_Kp[2][6];   
   TH1D           *h_peak_nFit_Kpi[2][6];  
   TH1D           *h_peak_nSigP_Kp[2][6];
   TH1D           *h_peak_nSigPi_Kpi[2][6];
   TH1D           *h_peak_dl_K[2][6];   
   TH1D           *h_peak_dca2_K[2][6];   
   TH1D           *h_peak_dcaV0_K[2][6];   
   TH1D           *h_peak_crp_K[2][6];
   TH1D           *h_peak_dr_K[2][6];   
   TH1D           *h_peak_deta_K[2][6]; 
   TH1D           *h_peak_dphi_K[2][6];
   TH1D           *h_peak_fz_K[6];
 
   TH1D           *h_bkg_pt_Lp[2][6];
   TH1D           *h_bkg_eta_Lp[2][6];  
   TH1D           *h_bkg_phi_Lp[2][6];   
   TH1D           *h_bkg_pt_Lpi[2][6];  
   TH1D           *h_bkg_eta_Lpi[2][6]; 
   TH1D           *h_bkg_phi_Lpi[2][6]; 
   TH1D           *h_bkg_pt_L[2][6];   
   TH1D           *h_bkg_eta_L[2][6];   
   TH1D           *h_bkg_phi_L[2][6];      
   TH1D           *h_bkg_dca_Lp[2][6];   
   TH1D           *h_bkg_dca_Lpi[2][6];   
   TH1D           *h_bkg_nFit_Lp[2][6];   
   TH1D           *h_bkg_nFit_Lpi[2][6];  
   TH1D           *h_bkg_nSigP_Lp[2][6];
   TH1D           *h_bkg_nSigPi_Lpi[2][6];
   TH1D           *h_bkg_dl_L[2][6];   
   TH1D           *h_bkg_dca2_L[2][6];   
   TH1D           *h_bkg_dcaV0_L[2][6];   
   TH1D           *h_bkg_crp_L[2][6];
   TH1D           *h_bkg_dr_L[2][6];   
   TH1D           *h_bkg_deta_L[2][6]; 
   TH1D           *h_bkg_dphi_L[2][6];
   TH1D           *h_bkg_fz_L[6];

   TH1D           *h_bkg_pt_Ap[2][6];
   TH1D           *h_bkg_eta_Ap[2][6];  
   TH1D           *h_bkg_phi_Ap[2][6];    
   TH1D           *h_bkg_pt_Api[2][6];  
   TH1D           *h_bkg_eta_Api[2][6]; 
   TH1D           *h_bkg_phi_Api[2][6]; 
   TH1D           *h_bkg_x_stop_A[2][6];
   TH1D           *h_bkg_y_stop_A[2][6];
   TH1D           *h_bkg_z_stop_A[2][6];
   TH1D           *h_bkg_pt_A[2][6];   
   TH1D           *h_bkg_eta_A[2][6];   
   TH1D           *h_bkg_phi_A[2][6];   
   TH1D           *h_bkg_dca_Ap[2][6];   
   TH1D           *h_bkg_dca_Api[2][6];   
   TH1D           *h_bkg_nFit_Ap[2][6];   
   TH1D           *h_bkg_nFit_Api[2][6];  
   TH1D           *h_bkg_nSigP_Ap[2][6];
   TH1D           *h_bkg_nSigPi_Api[2][6];
   TH1D           *h_bkg_dl_A[2][6];   
   TH1D           *h_bkg_dca2_A[2][6];   
   TH1D           *h_bkg_dcaV0_A[2][6];   
   TH1D           *h_bkg_crp_A[2][6];
   TH1D           *h_bkg_dr_A[2][6];   
   TH1D           *h_bkg_deta_A[2][6]; 
   TH1D           *h_bkg_dphi_A[2][6];
   TH1D           *h_bkg_fz_A[6];

   TH1D           *h_bkg_pt_Kp[2][6];
   TH1D           *h_bkg_eta_Kp[2][6];  
   TH1D           *h_bkg_phi_Kp[2][6];    
   TH1D           *h_bkg_pt_Kpi[2][6];  
   TH1D           *h_bkg_eta_Kpi[2][6]; 
   TH1D           *h_bkg_phi_Kpi[2][6]; 
   TH1D           *h_bkg_x_stop_K[2][6];
   TH1D           *h_bkg_y_stop_K[2][6];
   TH1D           *h_bkg_z_stop_K[2][6];
   TH1D           *h_bkg_pt_K[2][6];   
   TH1D           *h_bkg_eta_K[2][6];   
   TH1D           *h_bkg_phi_K[2][6];   
   TH1D           *h_bkg_dca_Kp[2][6];   
   TH1D           *h_bkg_dca_Kpi[2][6];   
   TH1D           *h_bkg_nFit_Kp[2][6];   
   TH1D           *h_bkg_nFit_Kpi[2][6];  
   TH1D           *h_bkg_nSigP_Kp[2][6];
   TH1D           *h_bkg_nSigPi_Kpi[2][6];
   TH1D           *h_bkg_dl_K[2][6];   
   TH1D           *h_bkg_dca2_K[2][6];   
   TH1D           *h_bkg_dcaV0_K[2][6];   
   TH1D           *h_bkg_crp_K[2][6];
   TH1D           *h_bkg_dr_K[2][6];
   TH1D           *h_bkg_deta_K[2][6]; 
   TH1D           *h_bkg_dphi_K[2][6];
   TH1D           *h_bkg_fz_K[6];

   ClassDef(fillHist,0);
};

#endif

#ifdef fillHist_cxx
void fillHist::Init(TTree *tree)
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
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runID", &runID, &b_runID);
   fChain->SetBranchAddress("eventID", &eventID, &b_eventID);
   fChain->SetBranchAddress("spin", &spin, &b_spin);
   fChain->SetBranchAddress("spinbit", &spinbit, &b_spinbit);
   fChain->SetBranchAddress("spinbit8", &spinbit8, &b_spinbit8);
   fChain->SetBranchAddress("bx7", &bx7, &b_bx7);
   fChain->SetBranchAddress("bx48", &bx48, &b_bx48);
   fChain->SetBranchAddress("magn", &magn, &b_magn);
   fChain->SetBranchAddress("bbcrate", &bbcrate, &b_bbcrate);
   fChain->SetBranchAddress("zdcrate", &zdcrate, &b_zdcrate);
   fChain->SetBranchAddress("bbcTimebin", &bbcTimebin, &b_bbcTimebin);
   fChain->SetBranchAddress("pvx", &pvx, &b_pvx);
   fChain->SetBranchAddress("pvy", &pvy, &b_pvy);
   fChain->SetBranchAddress("pvz", &pvz, &b_pvz);
   fChain->SetBranchAddress("trig", trig, &b_trig);
   fChain->SetBranchAddress("IsJP1", &IsJP1, &b_IsJP1);
   fChain->SetBranchAddress("IsJP0", &IsJP0, &b_IsJP0);
   fChain->SetBranchAddress("IsJP2", &IsJP2, &b_IsJP2);
   fChain->SetBranchAddress("IsAJP", &IsAJP, &b_IsAJP);
   fChain->SetBranchAddress("npv", &npv, &b_npv);
   fChain->SetBranchAddress("npvrank", &npvrank, &b_npvrank);
   fChain->SetBranchAddress("npvx", &npvx, &b_npvx);
   fChain->SetBranchAddress("npvy", &npvy, &b_npvy);
   fChain->SetBranchAddress("npvz", &npvz, &b_npvz);
   fChain->SetBranchAddress("ngtr", &ngtr, &b_ngtr);
   fChain->SetBranchAddress("nptr", &nptr, &b_nptr);
   fChain->SetBranchAddress("spin4skim", &spin4skim, &b_spin4skim);
   fChain->SetBranchAddress("njet", &njet, &b_njet);
   fChain->SetBranchAddress("IsJP0h", &IsJP0h, &b_IsJP0h);
   fChain->SetBranchAddress("IsJP0s", &IsJP0s, &b_IsJP0s);
   fChain->SetBranchAddress("IsJP1h", &IsJP1h, &b_IsJP1h);
   fChain->SetBranchAddress("IsJP1s", &IsJP1s, &b_IsJP1s);
   fChain->SetBranchAddress("IsJP2h", &IsJP2h, &b_IsJP2h);
   fChain->SetBranchAddress("IsJP2s", &IsJP2s, &b_IsJP2s);
   fChain->SetBranchAddress("IsAJPh", &IsAJPh, &b_IsAJPh);
   fChain->SetBranchAddress("IsAJPs", &IsAJPs, &b_IsAJPs);
   fChain->SetBranchAddress("Jmatch", &Jmatch, &b_Jmatch);
   fChain->SetBranchAddress("J_sv", J_sv, &b_J_sv);
   fChain->SetBranchAddress("J_deteta", J_deteta, &b_J_deteta);
   fChain->SetBranchAddress("J_eta", J_eta, &b_J_eta);
   fChain->SetBranchAddress("J_pt", J_pt, &b_J_pt);
   fChain->SetBranchAddress("J_phi", J_phi, &b_J_phi);
   fChain->SetBranchAddress("J_rt", J_rt, &b_J_rt);
   fChain->SetBranchAddress("J_E", J_E, &b_J_E);
   fChain->SetBranchAddress("J_btowEt", J_btowEt, &b_J_btowEt);
   fChain->SetBranchAddress("J_tpcEt", J_tpcEt, &b_J_tpcEt);
   fChain->SetBranchAddress("J_charge", J_charge, &b_J_charge);
   fChain->SetBranchAddress("J_ncell", J_ncell, &b_J_ncell);
   fChain->SetBranchAddress("J_ntrac", J_ntrac, &b_J_ntrac);
   fChain->SetBranchAddress("snlam", &snlam, &b_snlam);
   fChain->SetBranchAddress("snlbr", &snlbr, &b_snlbr);
   fChain->SetBranchAddress("snk0s", &snk0s, &b_snk0s);
   fChain->SetBranchAddress("sLp_nHit", sLp_nHit, &b_sLp_nHit);
   fChain->SetBranchAddress("sLp_nHitPos", sLp_nHitPos, &b_sLp_nHitPos);
   fChain->SetBranchAddress("sLp_dca", sLp_dca, &b_sLp_dca);
   fChain->SetBranchAddress("sLp_nSigmaP", sLp_nSigmaP, &b_sLp_nSigmaP);
   fChain->SetBranchAddress("sLp_nSigmaPi", sLp_nSigmaPi, &b_sLp_nSigmaPi);
   fChain->SetBranchAddress("sLp_pt", sLp_pt, &b_sLp_pt);
   fChain->SetBranchAddress("sLp_phi", sLp_phi, &b_sLp_phi);
   fChain->SetBranchAddress("sLp_eta", sLp_eta, &b_sLp_eta);
   fChain->SetBranchAddress("sLp_beta", sLp_beta, &b_sLp_beta);
   fChain->SetBranchAddress("sLp_btofm2", sLp_btofm2, &b_sLp_btofm2);
   fChain->SetBranchAddress("sLp_ID", sLp_ID, &b_sLp_ID);
   fChain->SetBranchAddress("sLp_Charge", sLp_Charge, &b_sLp_Charge);
   fChain->SetBranchAddress("sLpi_nHit", sLpi_nHit, &b_sLpi_nHit);
   fChain->SetBranchAddress("sLpi_nHitPos", sLpi_nHitPos, &b_sLpi_nHitPos);
   fChain->SetBranchAddress("sLpi_dca", sLpi_dca, &b_sLpi_dca);
   fChain->SetBranchAddress("sLpi_nSigmaP", sLpi_nSigmaP, &b_sLpi_nSigmaP);
   fChain->SetBranchAddress("sLpi_nSigmaPi", sLpi_nSigmaPi, &b_sLpi_nSigmaPi);
   fChain->SetBranchAddress("sLpi_pt", sLpi_pt, &b_sLpi_pt);
   fChain->SetBranchAddress("sLpi_phi", sLpi_phi, &b_sLpi_phi);
   fChain->SetBranchAddress("sLpi_eta", sLpi_eta, &b_sLpi_eta);
   fChain->SetBranchAddress("sLpi_beta", sLpi_beta, &b_sLpi_beta);
   fChain->SetBranchAddress("sLpi_btofm2", sLpi_btofm2, &b_sLpi_btofm2);
   fChain->SetBranchAddress("sLpi_ID", sLpi_ID, &b_sLpi_ID);
   fChain->SetBranchAddress("sLpi_Charge", sLpi_Charge, &b_sLpi_Charge);
   fChain->SetBranchAddress("sL_V0x", sL_V0x, &b_sL_V0x);
   fChain->SetBranchAddress("sL_V0y", sL_V0y, &b_sL_V0y);
   fChain->SetBranchAddress("sL_V0z", sL_V0z, &b_sL_V0z);
   fChain->SetBranchAddress("sL_pt", sL_pt, &b_sL_pt);
   fChain->SetBranchAddress("sL_phi", sL_phi, &b_sL_phi);
   fChain->SetBranchAddress("sL_eta", sL_eta, &b_sL_eta);
   fChain->SetBranchAddress("sL_im", sL_im, &b_sL_im);
   fChain->SetBranchAddress("sL_dca2", sL_dca2, &b_sL_dca2);
   fChain->SetBranchAddress("sL_dcaV0", sL_dcaV0, &b_sL_dcaV0);
   fChain->SetBranchAddress("sL_dl", sL_dl, &b_sL_dl);
   fChain->SetBranchAddress("sL_crp", sL_crp, &b_sL_crp);
   fChain->SetBranchAddress("sL_index", sL_index, &b_sL_index);
   fChain->SetBranchAddress("sL_dr", sL_dr, &b_sL_dr);
   fChain->SetBranchAddress("sL_dphi", sL_dphi, &b_sL_dphi);
   fChain->SetBranchAddress("sL_deta", sL_deta, &b_sL_deta);
   fChain->SetBranchAddress("sL_cosTv_yell", sL_cosTv_yell, &b_sL_cosTv_yell);
   fChain->SetBranchAddress("sL_cosTv_blue", sL_cosTv_blue, &b_sL_cosTv_blue);
   fChain->SetBranchAddress("sL_cosTj_yell", sL_cosTj_yell, &b_sL_cosTj_yell);
   fChain->SetBranchAddress("sL_cosTj_blue", sL_cosTj_blue, &b_sL_cosTj_blue);
   fChain->SetBranchAddress("sL_cosN_yell", sL_cosN_yell, &b_sL_cosN_yell);
   fChain->SetBranchAddress("sL_cosN_blue", sL_cosN_blue, &b_sL_cosN_blue);
   fChain->SetBranchAddress("sL_cosY_yell", sL_cosY_yell, &b_sL_cosY_yell);
   fChain->SetBranchAddress("sL_cosY_blue", sL_cosY_blue, &b_sL_cosY_blue);
   fChain->SetBranchAddress("sAp_nHit", sAp_nHit, &b_sAp_nHit);
   fChain->SetBranchAddress("sAp_nHitPos", sAp_nHitPos, &b_sAp_nHitPos);
   fChain->SetBranchAddress("sAp_dca", sAp_dca, &b_sAp_dca);
   fChain->SetBranchAddress("sAp_nSigmaP", sAp_nSigmaP, &b_sAp_nSigmaP);
   fChain->SetBranchAddress("sAp_nSigmaPi", sAp_nSigmaPi, &b_sAp_nSigmaPi);
   fChain->SetBranchAddress("sAp_pt", sAp_pt, &b_sAp_pt);
   fChain->SetBranchAddress("sAp_phi", sAp_phi, &b_sAp_phi);
   fChain->SetBranchAddress("sAp_eta", sAp_eta, &b_sAp_eta);
   fChain->SetBranchAddress("sAp_beta", sAp_beta, &b_sAp_beta);
   fChain->SetBranchAddress("sAp_btofm2", sAp_btofm2, &b_sAp_btofm2);
   fChain->SetBranchAddress("sAp_ID", sAp_ID, &b_sAp_ID);
   fChain->SetBranchAddress("sAp_Charge", sAp_Charge, &b_sAp_Charge);
   fChain->SetBranchAddress("sApi_nHit", sApi_nHit, &b_sApi_nHit);
   fChain->SetBranchAddress("sApi_nHitPos", sApi_nHitPos, &b_sApi_nHitPos);
   fChain->SetBranchAddress("sApi_dca", sApi_dca, &b_sApi_dca);
   fChain->SetBranchAddress("sApi_nSigmaP", sApi_nSigmaP, &b_sApi_nSigmaP);
   fChain->SetBranchAddress("sApi_nSigmaPi", sApi_nSigmaPi, &b_sApi_nSigmaPi);
   fChain->SetBranchAddress("sApi_pt", sApi_pt, &b_sApi_pt);
   fChain->SetBranchAddress("sApi_phi", sApi_phi, &b_sApi_phi);
   fChain->SetBranchAddress("sApi_eta", sApi_eta, &b_sApi_eta);
   fChain->SetBranchAddress("sApi_beta", sApi_beta, &b_sApi_beta);
   fChain->SetBranchAddress("sApi_btofm2", sApi_btofm2, &b_sApi_btofm2);
   fChain->SetBranchAddress("sApi_ID", sApi_ID, &b_sApi_ID);
   fChain->SetBranchAddress("sApi_Charge", sApi_Charge, &b_sApi_Charge);
   fChain->SetBranchAddress("sA_V0x", sA_V0x, &b_sA_V0x);
   fChain->SetBranchAddress("sA_V0y", sA_V0y, &b_sA_V0y);
   fChain->SetBranchAddress("sA_V0z", sA_V0z, &b_sA_V0z);
   fChain->SetBranchAddress("sA_pt", sA_pt, &b_sA_pt);
   fChain->SetBranchAddress("sA_phi", sA_phi, &b_sA_phi);
   fChain->SetBranchAddress("sA_eta", sA_eta, &b_sA_eta);
   fChain->SetBranchAddress("sA_im", sA_im, &b_sA_im);
   fChain->SetBranchAddress("sA_dca2", sA_dca2, &b_sA_dca2);
   fChain->SetBranchAddress("sA_dcaV0", sA_dcaV0, &b_sA_dcaV0);
   fChain->SetBranchAddress("sA_dl", sA_dl, &b_sA_dl);
   fChain->SetBranchAddress("sA_crp", sA_crp, &b_sA_crp);
   fChain->SetBranchAddress("sA_index", sA_index, &b_sA_index);
   fChain->SetBranchAddress("sA_dr", sA_dr, &b_sA_dr);
   fChain->SetBranchAddress("sA_dphi", sA_dphi, &b_sA_dphi);
   fChain->SetBranchAddress("sA_deta", sA_deta, &b_sA_deta);
   fChain->SetBranchAddress("sA_cosTv_yell", sA_cosTv_yell, &b_sA_cosTv_yell);
   fChain->SetBranchAddress("sA_cosTv_blue", sA_cosTv_blue, &b_sA_cosTv_blue);
   fChain->SetBranchAddress("sA_cosTj_yell", sA_cosTj_yell, &b_sA_cosTj_yell);
   fChain->SetBranchAddress("sA_cosTj_blue", sA_cosTj_blue, &b_sA_cosTj_blue);
   fChain->SetBranchAddress("sA_cosN_yell", sA_cosN_yell, &b_sA_cosN_yell);
   fChain->SetBranchAddress("sA_cosN_blue", sA_cosN_blue, &b_sA_cosN_blue);
   fChain->SetBranchAddress("sA_cosY_yell", sA_cosY_yell, &b_sA_cosY_yell);
   fChain->SetBranchAddress("sA_cosY_blue", sA_cosY_blue, &b_sA_cosY_blue);
   fChain->SetBranchAddress("sKp_nHit", sKp_nHit, &b_sKp_nHit);
   fChain->SetBranchAddress("sKp_nHitPos", sKp_nHitPos, &b_sKp_nHitPos);
   fChain->SetBranchAddress("sKp_dca", sKp_dca, &b_sKp_dca);
   fChain->SetBranchAddress("sKp_nSigmaP", sKp_nSigmaP, &b_sKp_nSigmaP);
   fChain->SetBranchAddress("sKp_nSigmaPi", sKp_nSigmaPi, &b_sKp_nSigmaPi);
   fChain->SetBranchAddress("sKp_pt", sKp_pt, &b_sKp_pt);
   fChain->SetBranchAddress("sKp_phi", sKp_phi, &b_sKp_phi);
   fChain->SetBranchAddress("sKp_eta", sKp_eta, &b_sKp_eta);
   fChain->SetBranchAddress("sKp_beta", sKp_beta, &b_sKp_beta);
   fChain->SetBranchAddress("sKp_btofm2", sKp_btofm2, &b_sKp_btofm2);
   fChain->SetBranchAddress("sKp_ID", sKp_ID, &b_sKp_ID);
   fChain->SetBranchAddress("sKp_Charge", sKp_Charge, &b_sKp_Charge);
   fChain->SetBranchAddress("sKpi_nHit", sKpi_nHit, &b_sKpi_nHit);
   fChain->SetBranchAddress("sKpi_nHitPos", sKpi_nHitPos, &b_sKpi_nHitPos);
   fChain->SetBranchAddress("sKpi_dca", sKpi_dca, &b_sKpi_dca);
   fChain->SetBranchAddress("sKpi_nSigmaP", sKpi_nSigmaP, &b_sKpi_nSigmaP);
   fChain->SetBranchAddress("sKpi_nSigmaPi", sKpi_nSigmaPi, &b_sKpi_nSigmaPi);
   fChain->SetBranchAddress("sKpi_pt", sKpi_pt, &b_sKpi_pt);
   fChain->SetBranchAddress("sKpi_phi", sKpi_phi, &b_sKpi_phi);
   fChain->SetBranchAddress("sKpi_eta", sKpi_eta, &b_sKpi_eta);
   fChain->SetBranchAddress("sKpi_beta", sKpi_beta, &b_sKpi_beta);
   fChain->SetBranchAddress("sKpi_btofm2", sKpi_btofm2, &b_sKpi_btofm2);
   fChain->SetBranchAddress("sKpi_ID", sKpi_ID, &b_sKpi_ID);
   fChain->SetBranchAddress("sKpi_Charge", sKpi_Charge, &b_sKpi_Charge);
   fChain->SetBranchAddress("sK_V0x", sK_V0x, &b_sK_V0x);
   fChain->SetBranchAddress("sK_V0y", sK_V0y, &b_sK_V0y);
   fChain->SetBranchAddress("sK_V0z", sK_V0z, &b_sK_V0z);
   fChain->SetBranchAddress("sK_pt", sK_pt, &b_sK_pt);
   fChain->SetBranchAddress("sK_phi", sK_phi, &b_sK_phi);
   fChain->SetBranchAddress("sK_eta", sK_eta, &b_sK_eta);
   fChain->SetBranchAddress("sK_im", sK_im, &b_sK_im);
   fChain->SetBranchAddress("sK_dca2", sK_dca2, &b_sK_dca2);
   fChain->SetBranchAddress("sK_dcaV0", sK_dcaV0, &b_sK_dcaV0);
   fChain->SetBranchAddress("sK_dl", sK_dl, &b_sK_dl);
   fChain->SetBranchAddress("sK_crp", sK_crp, &b_sK_crp);
   fChain->SetBranchAddress("sK_index", sK_index, &b_sK_index);
   fChain->SetBranchAddress("sK_dr", sK_dr, &b_sK_dr);
   fChain->SetBranchAddress("sK_dphi", sK_dphi, &b_sK_dphi);
   fChain->SetBranchAddress("sK_deta", sK_deta, &b_sK_deta);
   fChain->SetBranchAddress("sK_cosTv_yell", sK_cosTv_yell, &b_sK_cosTv_yell);
   fChain->SetBranchAddress("sK_cosTv_blue", sK_cosTv_blue, &b_sK_cosTv_blue);
   fChain->SetBranchAddress("sK_cosTj_yell", sK_cosTj_yell, &b_sK_cosTj_yell);
   fChain->SetBranchAddress("sK_cosTj_blue", sK_cosTj_blue, &b_sK_cosTj_blue);
   fChain->SetBranchAddress("sK_cosN_yell", sK_cosN_yell, &b_sK_cosN_yell);
   fChain->SetBranchAddress("sK_cosN_blue", sK_cosN_blue, &b_sK_cosN_blue);
   fChain->SetBranchAddress("sK_cosY_yell", sK_cosY_yell, &b_sK_cosY_yell);
   fChain->SetBranchAddress("sK_cosY_blue", sK_cosY_blue, &b_sK_cosY_blue);
}

bool fillHist::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

bool fillHist::checkSpin()
{
   // Spin filter
   if( spinbit!=5 && spinbit!=6 && spinbit!=9 && spinbit!=10 ) return false;
   return true;
}

bool fillHist::checkTrig()
{
   int trigZ = 0;
   int trigF = 0;
   if( fOption == "ALL" ) {
      trigZ = trig[0]+trig[1]+trig[2]+trig[3];
      trigF = trig[0]*IsJP0+trig[1]*IsJP1+trig[2]*IsJP2+trig[3]*IsAJP;
   }
   if( fOption == "JP0" ) {
      trigZ = trig[0];
      trigF = (trig[0]*IsJP0);
   }
   if( fOption == "JP1" ) {
      trigZ = trig[1]*(!trig[0]);
      trigF = (trig[1]*IsJP1)*(!(trig[0]*IsJP0));
   }
   if( fOption == "JP2" ) {
      trigZ = trig[2]*(!trig[0])*(!trig[1]);
      trigF = (trig[2]*IsJP2)*(!(trig[0]*IsJP0))*(!(trig[1]*IsJP1));
   }
   if( fOption == "AJP" ) {
      trigZ = trig[3]*(!trig[0])*(!trig[1])*(!trig[2]);
      trigF = (trig[3]*IsAJP)*(!(trig[0]*IsJP0))*(!(trig[1]*IsJP1))*(!(trig[2]*IsJP2));
   }
   return trigZ;
}

int fillHist::getPTbin(double apt)
{
   int PTbin = -1;
   if (apt<1.0 || apt>=8.0) return PTbin;
   PTbin = floor(apt)-1;
   if (PTbin==6) PTbin=5;

   return PTbin; 
}

void ReadCutTable(int pT)
{
   // new
   const double cut_nSigma_protect[6]   = { 0.50, 0.50, 0.60, 0.80, 1.00, 1.00 };
   const double cut_nSigma_proton[6]    = { 3.00, 3.00, 3.00, 3.00, 3.00, 3.00 };
   const double cut_nSigma_pion[6]      = { 3.00, 3.00, 3.00, 3.00, 3.00, 3.00 };
   const double cut_dca_min_pion[6]     = { 0.60, 0.55, 0.50, 0.50, 0.50, 0.50 };
   const double cut_dca_min_proton[6]   = { 0.25, 0.20, 0.10, 0.05, 0.05, 0.05 };
   const double cut_crp_min[6]          = { 0.95, 0.95, 0.95, 0.95, 0.95, 0.95 };
   const double cut_dca2_max[6]         = { 0.80, 0.70, 0.60, 0.50, 0.45, 0.45 };
   const double cut_dcaV0_max[6]        = { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00 };
   const double cut_dl_min[6]           = { 3.50, 4.00, 4.00, 4.50, 5.00, 5.50 };
   const double cut_dl_max[6]           = { 1.3e02, 1.4e02, 1.5e02, 1.6e02, 1.7e02, 1.8e02 };
   const double cut_P_min_pion[6]       = { 0.15, 0.15, 0.20, 0.25, 0.30, 0.40 };

   const double K_cut_dca_min_pion[6]    = { 0.60, 0.55, 0.50, 0.45, 0.40, 0.35 };
   const double K_cut_dca_min_proton[6]  = { 0.60, 0.55, 0.50, 0.45, 0.40, 0.35 };
   const double K_cut_crp_min[6]         = { 0.99, 0.99, 0.99, 0.99, 0.99, 0.99 };
   const double K_cut_dca2_max[6]        = { 0.70, 0.65, 0.55, 0.45, 0.40, 0.35 };
   const double K_cut_dcaV0_max[6]       = { 0.60, 0.70, 0.80, 0.80, 0.80, 0.80 };
   const double K_cut_dl_min[6]          = { 1.20, 1.40, 1.50, 1.60, 1.80, 2.00 };

   c_nSigma_protect   = cut_nSigma_protect[pT];
   c_nSigma_proton    = cut_nSigma_proton[pT];
   c_nSigma_pion      = cut_nSigma_pion[pT];
   c_dca_min_proton   = cut_dca_min_proton[pT];
   c_dca_min_pion     = cut_dca_min_pion[pT];
   c_crp_min          = cut_crp_min[pT];
   c_dca2_max         = cut_dca2_max[pT];
   c_dcaV0_max        = cut_dcaV0_max[pT];
   c_dl_min           = cut_dl_min[pT];
   c_dl_max           = cut_dl_max[pT];
   c_P_min_pion       = cut_P_min_pion[pT];

   K_c_dca_min_pion   = K_cut_dca_min_pion[pT];
   K_c_crp_min        = K_cut_crp_min[pT];
   K_c_dca2_max       = K_cut_dca2_max[pT];
   K_c_dcaV0_max      = K_cut_dcaV0_max[pT];
   K_c_dl_min         = K_cut_dl_min[pT];
}

#endif // #ifdef fillHist_cxx
