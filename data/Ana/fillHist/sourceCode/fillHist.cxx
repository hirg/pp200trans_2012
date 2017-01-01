#define fillHist_cxx
// The class definition in fillHist.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("fillHist.C")
// Root > T->Process("fillHist.C","some options")
// Root > T->Process("fillHist.C+")
//

#include "fillHist.h"
#include "imInfo.h"

#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include <TVecter3.h>


using namespace std;

void fillHist::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   h_pvz0     = new TH1D("h_pvz0","h_pvz0",120,-60,60);   
   h_pvz1     = new TH1D("h_pvz1","h_pvz1",120,-60,60);
   h_spinbit  = new TH1I("h_spinbit","h_spinbit",13,0,13);
   h_bbcrate  = new TH1D("h_bbcrate","h_bbcrate",1100,0,1100);
   h_zdcrate  = new TH1D("h_zdcrate","h_zdcrate",1100,0,1100);

   h_nJet     = new TH1D("h_nJet","h_nJet",10,0,10);
   h_deteta_J = new TH1D("h_deteta_J","h_deteta_J",200,-2,2);
   h_eta_J    = new TH1D("h_eta_J","h_eta_J",200,-2,2);
   h_pt_J     = new TH1D("h_pt_J","h_pt_J",200,0,20);
   h_phi_J    = new TH1D("h_phi_J","h_phi_J",340,-3.2,3.2);
   h_rt_J     = new TH1D("h_rt_J","h_rt_J",100,0.,1.);
   h_charge_J = new TH1D("h_charge_J","h_charge_J",100,0.,1);   

   TString hn;
   for (int kPT = 0; kPT < 6; ++kPT)
   {
      hn = Form("h_fz_L_PT%d", kPT);
      h_fz_L[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_fz_A_PT%d", kPT);
      h_fz_A[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_fz_K_PT%d", kPT);
      h_fz_K[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);

      hn = Form("h_peak_fz_L_PT%d", kPT);
      h_peak_fz_L[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_peak_fz_A_PT%d", kPT);
      h_peak_fz_A[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_bkg_fz_L_PT%d", kPT);
      h_bkg_fz_L[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_bkg_fz_A_PT%d", kPT);
      h_bkg_fz_A[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_peak_fz_K_PT%d", kPT);
      h_peak_fz_K[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_bkg_fz_K_PT%d", kPT);
      h_bkg_fz_K[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);

      for (int kJ = 0; kJ < 2; ++kJ)
      {
         hn = Form("h_im_L_J%d_PT%d", kJ, kPT);
         h_im_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);
         hn = Form("h_pt_Lp_J%d_PT%d", kJ, kPT);
         h_pt_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_eta_Lp_J%d_PT%d", kJ, kPT);
         h_eta_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_phi_Lp_J%d_PT%d", kJ, kPT);
         h_phi_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_pt_Lpi_J%d_PT%d", kJ, kPT);
         h_pt_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_eta_Lpi_J%d_PT%d", kJ, kPT);
         h_eta_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_phi_Lpi_J%d_PT%d", kJ, kPT);
         h_phi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_pt_L_J%d_PT%d", kJ, kPT);
         h_pt_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_eta_L_J%d_PT%d", kJ, kPT);
         h_eta_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_phi_L_J%d_PT%d", kJ, kPT);
         h_phi_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_dr_L_J%d_PT%d", kJ, kPT);
         h_dr_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_dca_Lp_J%d_PT%d", kJ, kPT);
         h_dca_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_dca_Lpi_J%d_PT%d", kJ, kPT);
         h_dca_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_nSigP_Lp_J%d_PT%d", kJ, kPT);
         h_nSigP_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_nSigPi_Lpi_J%d_PT%d", kJ, kPT);
         h_nSigPi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_nFit_Lp_J%d_PT%d", kJ, kPT);
         h_nFit_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_nFit_Lpi_J%d_PT%d", kJ, kPT);
         h_nFit_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_dl_L_J%d_PT%d", kJ, kPT);
         h_dl_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0,100);
         hn = Form("h_dca2_L_J%d_PT%d", kJ, kPT);
         h_dca2_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_dcaV0_L_J%d_PT%d", kJ, kPT);
         h_dcaV0_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_crp_L_J%d_PT%d", kJ, kPT);
         h_crp_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);
         hn = Form("h_cV_yell_L_J%d_PT%d", kJ, kPT);
         h_cV_yell_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cJ_yell_L_J%d_PT%d", kJ, kPT);
         h_cJ_yell_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cN_yell_L_J%d_PT%d", kJ, kPT);
         h_cN_yell_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cY_yell_L_J%d_PT%d", kJ, kPT);
         h_cY_yell_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cV_blue_L_J%d_PT%d", kJ, kPT);
         h_cV_blue_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cJ_blue_L_J%d_PT%d", kJ, kPT);
         h_cJ_blue_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cN_blue_L_J%d_PT%d", kJ, kPT);
         h_cN_blue_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cY_blue_L_J%d_PT%d", kJ, kPT);
         h_cY_blue_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);

         hn = Form("h_peak_pt_Lp_J%d_PT%d", kJ, kPT);
         h_peak_pt_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_peak_eta_Lp_J%d_PT%d", kJ, kPT);
         h_peak_eta_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_peak_phi_Lp_J%d_PT%d", kJ, kPT);
         h_peak_phi_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_peak_pt_Lpi_J%d_PT%d", kJ, kPT);
         h_peak_pt_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_peak_eta_Lpi_J%d_PT%d", kJ, kPT);
         h_peak_eta_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_peak_phi_Lpi_J%d_PT%d", kJ, kPT);
         h_peak_phi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_peak_pt_L_J%d_PT%d", kJ, kPT);
         h_peak_pt_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_peak_eta_L_J%d_PT%d", kJ, kPT);
         h_peak_eta_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_peak_phi_L_J%d_PT%d", kJ, kPT);
         h_peak_phi_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_peak_dr_L_J%d_PT%d", kJ, kPT);
         h_peak_dr_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_peak_dca_Lp_J%d_PT%d", kJ, kPT);
         h_peak_dca_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_peak_dca_Lpi_J%d_PT%d", kJ, kPT);
         h_peak_dca_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_peak_nSigP_Lp_J%d_PT%d", kJ, kPT);
         h_peak_nSigP_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_peak_nSigPi_Lpi_J%d_PT%d", kJ, kPT);
         h_peak_nSigPi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_peak_nFit_Lp_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_nFit_Lpi_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_dl_L_J%d_PT%d", kJ, kPT);
         h_peak_dl_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0,100);
         hn = Form("h_peak_dca2_L_J%d_PT%d", kJ, kPT);
         h_peak_dca2_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_peak_dcaV0_L_J%d_PT%d", kJ, kPT);
         h_peak_dcaV0_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_peak_crp_L_J%d_PT%d", kJ, kPT);
         h_peak_crp_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);

         hn = Form("h_bkg_pt_Lp_J%d_PT%d", kJ, kPT);
         h_bkg_pt_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_bkg_eta_Lp_J%d_PT%d", kJ, kPT);
         h_bkg_eta_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_bkg_phi_Lp_J%d_PT%d", kJ, kPT);
         h_bkg_phi_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_bkg_pt_Lpi_J%d_PT%d", kJ, kPT);
         h_bkg_pt_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_bkg_eta_Lpi_J%d_PT%d", kJ, kPT);
         h_bkg_eta_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_bkg_phi_Lpi_J%d_PT%d", kJ, kPT);
         h_bkg_phi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_bkg_pt_L_J%d_PT%d", kJ, kPT);
         h_bkg_pt_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_bkg_eta_L_J%d_PT%d", kJ, kPT);
         h_bkg_eta_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_bkg_phi_L_J%d_PT%d", kJ, kPT);
         h_bkg_phi_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_bkg_dr_L_J%d_PT%d", kJ, kPT);
         h_bkg_dr_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_bkg_dca_Lp_J%d_PT%d", kJ, kPT);
         h_bkg_dca_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_bkg_dca_Lpi_J%d_PT%d", kJ, kPT);
         h_bkg_dca_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_bkg_nSigP_Lp_J%d_PT%d", kJ, kPT);
         h_bkg_nSigP_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_bkg_nSigPi_Lpi_J%d_PT%d", kJ, kPT);
         h_bkg_nSigPi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_bkg_nFit_Lp_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_nFit_Lpi_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_dl_L_J%d_PT%d", kJ, kPT);
         h_bkg_dl_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0,100);
         hn = Form("h_bkg_dca2_L_J%d_PT%d", kJ, kPT);
         h_bkg_dca2_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_dcaV0_L_J%d_PT%d", kJ, kPT);
         h_bkg_dcaV0_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_crp_L_J%d_PT%d", kJ, kPT);
         h_bkg_crp_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);

         hn = Form("h_im_A_J%d_PT%d", kJ, kPT);
         h_im_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);
         hn = Form("h_pt_Ap_J%d_PT%d", kJ, kPT);
         h_pt_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_eta_Ap_J%d_PT%d", kJ, kPT);
         h_eta_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_phi_Ap_J%d_PT%d", kJ, kPT);
         h_phi_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_pt_Api_J%d_PT%d", kJ, kPT);
         h_pt_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_eta_Api_J%d_PT%d", kJ, kPT);
         h_eta_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_phi_Api_J%d_PT%d", kJ, kPT);
         h_phi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_pt_A_J%d_PT%d", kJ, kPT);
         h_pt_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_eta_A_J%d_PT%d", kJ, kPT);
         h_eta_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_phi_A_J%d_PT%d", kJ, kPT);
         h_phi_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_dr_A_J%d_PT%d", kJ, kPT);
         h_dr_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_dca_Ap_J%d_PT%d", kJ, kPT);
         h_dca_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_dca_Api_J%d_PT%d", kJ, kPT);
         h_dca_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_nSigP_Ap_J%d_PT%d", kJ, kPT);
         h_nSigP_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_nSigPi_Api_J%d_PT%d", kJ, kPT);
         h_nSigPi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_nFit_Ap_J%d_PT%d", kJ, kPT);
         h_nFit_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_nFit_Api_J%d_PT%d", kJ, kPT);
         h_nFit_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_dl_A_J%d_PT%d", kJ, kPT);
         h_dl_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0,100);
         hn = Form("h_dca2_A_J%d_PT%d", kJ, kPT);
         h_dca2_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_dcaV0_A_J%d_PT%d", kJ, kPT);
         h_dcaV0_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_crp_A_J%d_PT%d", kJ, kPT);
         h_crp_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);
         hn = Form("h_cV_yell_A_J%d_PT%d", kJ, kPT);
         h_cV_yell_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cJ_yell_A_J%d_PT%d", kJ, kPT);
         h_cJ_yell_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cN_yell_A_J%d_PT%d", kJ, kPT);
         h_cN_yell_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cY_yell_A_J%d_PT%d", kJ, kPT);
         h_cY_yell_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cV_blue_A_J%d_PT%d", kJ, kPT);
         h_cV_blue_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cJ_blue_A_J%d_PT%d", kJ, kPT);
         h_cJ_blue_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cN_blue_A_J%d_PT%d", kJ, kPT);
         h_cN_blue_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);
         hn = Form("h_cY_blue_A_J%d_PT%d", kJ, kPT);
         h_cY_blue_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),80,1.08,1.16,100,-1,1);

         hn = Form("h_peak_pt_Ap_J%d_PT%d", kJ, kPT);
         h_peak_pt_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_peak_eta_Ap_J%d_PT%d", kJ, kPT);
         h_peak_eta_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_peak_phi_Ap_J%d_PT%d", kJ, kPT);
         h_peak_phi_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_peak_pt_Api_J%d_PT%d", kJ, kPT);
         h_peak_pt_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_peak_eta_Api_J%d_PT%d", kJ, kPT);
         h_peak_eta_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_peak_phi_Api_J%d_PT%d", kJ, kPT);
         h_peak_phi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_peak_pt_A_J%d_PT%d", kJ, kPT);
         h_peak_pt_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_peak_eta_A_J%d_PT%d", kJ, kPT);
         h_peak_eta_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_peak_phi_A_J%d_PT%d", kJ, kPT);
         h_peak_phi_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_peak_dr_A_J%d_PT%d", kJ, kPT);
         h_peak_dr_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_peak_dca_Ap_J%d_PT%d", kJ, kPT);
         h_peak_dca_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_peak_dca_Api_J%d_PT%d", kJ, kPT);
         h_peak_dca_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_peak_nSigP_Ap_J%d_PT%d", kJ, kPT);
         h_peak_nSigP_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_peak_nSigPi_Api_J%d_PT%d", kJ, kPT);
         h_peak_nSigPi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_peak_nFit_Ap_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_nFit_Api_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_dl_A_J%d_PT%d", kJ, kPT);
         h_peak_dl_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0,100);
         hn = Form("h_peak_dca2_A_J%d_PT%d", kJ, kPT);
         h_peak_dca2_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_peak_dcaV0_A_J%d_PT%d", kJ, kPT);
         h_peak_dcaV0_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_peak_crp_A_J%d_PT%d", kJ, kPT);
         h_peak_crp_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);

         hn = Form("h_bkg_pt_Ap_J%d_PT%d", kJ, kPT);
         h_bkg_pt_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_bkg_eta_Ap_J%d_PT%d", kJ, kPT);
         h_bkg_eta_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_bkg_phi_Ap_J%d_PT%d", kJ, kPT);
         h_bkg_phi_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_bkg_pt_Api_J%d_PT%d", kJ, kPT);
         h_bkg_pt_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_bkg_eta_Api_J%d_PT%d", kJ, kPT);
         h_bkg_eta_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_bkg_phi_Api_J%d_PT%d", kJ, kPT);
         h_bkg_phi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_bkg_pt_A_J%d_PT%d", kJ, kPT);
         h_bkg_pt_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_bkg_eta_A_J%d_PT%d", kJ, kPT);
         h_bkg_eta_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_bkg_phi_A_J%d_PT%d", kJ, kPT);
         h_bkg_phi_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_bkg_dr_A_J%d_PT%d", kJ, kPT);
         h_bkg_dr_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_bkg_dca_Ap_J%d_PT%d", kJ, kPT);
         h_bkg_dca_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_bkg_dca_Api_J%d_PT%d", kJ, kPT);
         h_bkg_dca_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_bkg_nSigP_Ap_J%d_PT%d", kJ, kPT);
         h_bkg_nSigP_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_bkg_nSigPi_Api_J%d_PT%d", kJ, kPT);
         h_bkg_nSigPi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_bkg_nFit_Ap_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_nFit_Api_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_dl_A_J%d_PT%d", kJ, kPT);
         h_bkg_dl_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0,100);
         hn = Form("h_bkg_dca2_A_J%d_PT%d", kJ, kPT);
         h_bkg_dca2_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_dcaV0_A_J%d_PT%d", kJ, kPT);
         h_bkg_dcaV0_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_crp_A_J%d_PT%d", kJ, kPT);
         h_bkg_crp_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);

         hn = Form("h_im_K_J%d_PT%d", kJ, kPT);
         h_im_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),160,0.42,0.58);
         hn = Form("h_pt_Kp_J%d_PT%d", kJ, kPT);
         h_pt_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_eta_Kp_J%d_PT%d", kJ, kPT);
         h_eta_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_phi_Kp_J%d_PT%d", kJ, kPT);
         h_phi_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_pt_Kpi_J%d_PT%d", kJ, kPT);
         h_pt_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_eta_Kpi_J%d_PT%d", kJ, kPT);
         h_eta_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_phi_Kpi_J%d_PT%d", kJ, kPT);
         h_phi_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_pt_K_J%d_PT%d", kJ, kPT);
         h_pt_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_eta_K_J%d_PT%d", kJ, kPT);
         h_eta_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_phi_K_J%d_PT%d", kJ, kPT);
         h_phi_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_dr_K_J%d_PT%d", kJ, kPT);
         h_dr_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_dca_Kp_J%d_PT%d", kJ, kPT);
         h_dca_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_dca_Kpi_J%d_PT%d", kJ, kPT);
         h_dca_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_nSigP_Kp_J%d_PT%d", kJ, kPT);
         h_nSigP_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_nSigPi_Kpi_J%d_PT%d", kJ, kPT);
         h_nSigPi_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_nFit_Kp_J%d_PT%d", kJ, kPT);
         h_nFit_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_nFit_Kpi_J%d_PT%d", kJ, kPT);
         h_nFit_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_dl_K_J%d_PT%d", kJ, kPT);
         h_dl_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0,100);
         hn = Form("h_dca2_K_J%d_PT%d", kJ, kPT);
         h_dca2_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_dcaV0_K_J%d_PT%d", kJ, kPT);
         h_dcaV0_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_crp_K_J%d_PT%d", kJ, kPT);
         h_crp_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);
         hn = Form("h_cV_yell_K_J%d_PT%d", kJ, kPT);
         h_cV_yell_K[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),160,0.42,0.58,100,-1,1);
         hn = Form("h_cJ_yell_K_J%d_PT%d", kJ, kPT);
         h_cJ_yell_K[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),160,0.42,0.58,100,-1,1);
         hn = Form("h_cN_yell_K_J%d_PT%d", kJ, kPT);
         h_cN_yell_K[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),160,0.42,0.58,100,-1,1);
         hn = Form("h_cY_yell_K_J%d_PT%d", kJ, kPT);
         h_cY_yell_K[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),160,0.42,0.58,100,-1,1);
         hn = Form("h_cV_blue_K_J%d_PT%d", kJ, kPT);
         h_cV_blue_K[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),160,0.42,0.58,100,-1,1);
         hn = Form("h_cJ_blue_K_J%d_PT%d", kJ, kPT);
         h_cJ_blue_K[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),160,0.42,0.58,100,-1,1);
         hn = Form("h_cN_blue_K_J%d_PT%d", kJ, kPT);
         h_cN_blue_K[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),160,0.42,0.58,100,-1,1);
         hn = Form("h_cY_blue_K_J%d_PT%d", kJ, kPT);
         h_cY_blue_K[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),160,0.42,0.58,100,-1,1);

         hn = Form("h_peak_pt_Kp_J%d_PT%d", kJ, kPT);
         h_peak_pt_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_peak_eta_Kp_J%d_PT%d", kJ, kPT);
         h_peak_eta_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_peak_phi_Kp_J%d_PT%d", kJ, kPT);
         h_peak_phi_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_peak_pt_Kpi_J%d_PT%d", kJ, kPT);
         h_peak_pt_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_peak_eta_Kpi_J%d_PT%d", kJ, kPT);
         h_peak_eta_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_peak_phi_Kpi_J%d_PT%d", kJ, kPT);
         h_peak_phi_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_peak_pt_K_J%d_PT%d", kJ, kPT);
         h_peak_pt_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_peak_eta_K_J%d_PT%d", kJ, kPT);
         h_peak_eta_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_peak_phi_K_J%d_PT%d", kJ, kPT);
         h_peak_phi_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_peak_dr_K_J%d_PT%d", kJ, kPT);
         h_peak_dr_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_peak_dca_Kp_J%d_PT%d", kJ, kPT);
         h_peak_dca_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_peak_dca_Kpi_J%d_PT%d", kJ, kPT);
         h_peak_dca_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_peak_nSigP_Kp_J%d_PT%d", kJ, kPT);
         h_peak_nSigP_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_peak_nSigPi_Kpi_J%d_PT%d", kJ, kPT);
         h_peak_nSigPi_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_peak_nFit_Kp_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_nFit_Kpi_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_dl_K_J%d_PT%d", kJ, kPT);
         h_peak_dl_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0,100);
         hn = Form("h_peak_dca2_K_J%d_PT%d", kJ, kPT);
         h_peak_dca2_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_peak_dcaV0_K_J%d_PT%d", kJ, kPT);
         h_peak_dcaV0_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_peak_crp_K_J%d_PT%d", kJ, kPT);
         h_peak_crp_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);

         hn = Form("h_bkg_pt_Kp_J%d_PT%d", kJ, kPT);
         h_bkg_pt_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_bkg_eta_Kp_J%d_PT%d", kJ, kPT);
         h_bkg_eta_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_bkg_phi_Kp_J%d_PT%d", kJ, kPT);
         h_bkg_phi_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_bkg_pt_Kpi_J%d_PT%d", kJ, kPT);
         h_bkg_pt_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_bkg_eta_Kpi_J%d_PT%d", kJ, kPT);
         h_bkg_eta_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_bkg_phi_Kpi_J%d_PT%d", kJ, kPT);
         h_bkg_phi_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_bkg_pt_K_J%d_PT%d", kJ, kPT);
         h_bkg_pt_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_bkg_eta_K_J%d_PT%d", kJ, kPT);
         h_bkg_eta_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_bkg_phi_K_J%d_PT%d", kJ, kPT);
         h_bkg_phi_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_bkg_dr_K_J%d_PT%d", kJ, kPT);
         h_bkg_dr_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_bkg_dca_Kp_J%d_PT%d", kJ, kPT);
         h_bkg_dca_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_bkg_dca_Kpi_J%d_PT%d", kJ, kPT);
         h_bkg_dca_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_bkg_nSigP_Kp_J%d_PT%d", kJ, kPT);
         h_bkg_nSigP_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_bkg_nSigPi_Kpi_J%d_PT%d", kJ, kPT);
         h_bkg_nSigPi_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);
         hn = Form("h_bkg_nFit_Kp_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Kp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_nFit_Kpi_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Kpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_dl_K_J%d_PT%d", kJ, kPT);
         h_bkg_dl_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0,100);
         hn = Form("h_bkg_dca2_K_J%d_PT%d", kJ, kPT);
         h_bkg_dca2_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_dcaV0_K_J%d_PT%d", kJ, kPT);
         h_bkg_dcaV0_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_crp_K_J%d_PT%d", kJ, kPT);
         h_bkg_crp_K[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);
      }
   }
   cout << "histograms declare over" << endl;
}

void fillHist::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t fillHist::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either fillHist::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   GetEntry(entry);

   if (entry%10000==0) cout << "current entry: " << entry << endl;

   if (!checkSpin()) return kTRUE;
   h_pvz0->Fill(pvz);

   if (!checkTrig()) return kTRUE;
   h_pvz1->Fill(pvz);

   h_spinbit->Fill(spinbit);
   h_bbcrate->Fill(bbcrate);
   h_zdcrate->Fill(zdcrate);

   for (int i = 0; i < njet; ++i)  {
      h_deteta_J->Fill(J_deteta[i]);
      h_eta_J->Fill(J_eta[i]);
      h_pt_J->Fill(J_pt[i]);
      h_phi_J->Fill(J_phi[i]); 
      h_rt_J->Fill(J_rt[i]);
      h_charge_J->Fill(J_charge[i]);
   }

   for (int kJ=0; kJ<2; ++kJ)
   {
      for (int i = 0; i < snlam; ++i)
      {
         int kPT=getPTbin(sL_pt[i]);
         //cout << "L PTbin: " << kPT << endl;
         if (kPT<0)
         {
            continue;
         }

         if (kJ)
         {
            if( sL_index[i]<0 ) continue;
            if( sL_dr[i]<0 || sL_dr[i]>0.6 ) continue;
         }
         
         ReadCutTable(kPT);

         if( sLp_dca[i] < c_dca_min_proton ) continue;
         if( sLpi_dca[i] < c_dca_min_pion ) continue;
         if( sL_dca2[i] > c_dca2_max ) continue;
         if( sL_dcaV0[i] > c_dcaV0_max ) continue;
         if( sL_crp[i] < c_crp_min ) continue;
         if( sL_dl[i] < c_dl_min ) continue;
         if( fabs(sLp_nSigmaP[i]) > c_nSigma_proton ) continue;
         if( fabs(sLpi_nSigmaPi[i]) > c_nSigma_pion ) continue;
         if( (fabs(sLp_nSigmaP[i]) > c_nSigma_protect) && (fabs(sLp_nSigmaP[i])>fabs(sLp_nSigmaPi[i])) ) continue;

         TVector3 tPi;
         tPi.SetPtEtaPhi( sLpi_pt[i], sLpi_eta[i], sLpi_phi[i] );
         if( tPi.Mag() < c_P_min_pion ) continue;

         if( sLp_dca[i] > 200.0 ) continue;
         if( sLpi_dca[i] > 200.0 ) continue;
         if( sLpi_dca[i] > 16 && sLp_dca[i] < 0.8 ) continue;
         if( sLpi_dca[i] > 45 ) continue;

         h_im_L[kJ][kPT]->Fill(sL_im[i]);
         if (kJ)
         {
            int iJ = sL_index[i];
            h_fz_L[kPT]->Fill(sL_pt[i]/J_pt[iJ]);
            h_cJ_yell_L[kJ][kPT]->Fill(sL_im[i],sL_cosTj_yell[i]);
            h_cJ_blue_L[kJ][kPT]->Fill(sL_im[i],sL_cosTj_blue[i]);
         }
         h_pt_Lp[kJ][kPT]->Fill(sLp_pt[i]);
         h_eta_Lp[kJ][kPT]->Fill(sLp_eta[i]); 
         h_phi_Lp[kJ][kPT]->Fill(sLp_phi[i]); 
         h_pt_Lpi[kJ][kPT]->Fill(sLpi_pt[i]);
         h_eta_Lpi[kJ][kPT]->Fill(sLpi_eta[i]);
         h_phi_Lpi[kJ][kPT]->Fill(sLpi_phi[i]);
         h_pt_L[kJ][kPT]->Fill(sL_pt[i]);
         h_eta_L[kJ][kPT]->Fill(sL_eta[i]);
         h_phi_L[kJ][kPT]->Fill(sL_phi[i]);
         h_dca_Lp[kJ][kPT]->Fill(sLp_dca[i]);   
         h_dca_Lpi[kJ][kPT]->Fill(sLpi_dca[i]);   
         h_nFit_Lp[kJ][kPT]->Fill(sLp_nHit[i]);
         h_nFit_Lpi[kJ][kPT]->Fill(sLpi_nHit[i]);  
         h_nSigP_Lp[kJ][kPT]->Fill(sLp_nSigmaP[i]);
         h_nSigPi_Lpi[kJ][kPT]->Fill(sLpi_nSigmaPi[i]);
         h_dl_L[kJ][kPT]->Fill(sL_dl[i]);   
         h_dca2_L[kJ][kPT]->Fill(sL_dca2[i]);
         h_dcaV0_L[kJ][kPT]->Fill(sL_dcaV0[i]);
         h_crp_L[kJ][kPT]->Fill(sL_crp[i]);
         h_dr_L[kJ][kPT]->Fill(sL_dr[i]);
         //h_deta_L[kJ][kPT]->Fill(sL_deta[i]);
         //h_dphi_L[kJ][kPT]->Fill(sL_dphi[i]);
         h_cV_yell_L[kJ][kPT]->Fill(sL_im[i],sL_cosTv_yell[i]);
         h_cN_yell_L[kJ][kPT]->Fill(sL_im[i],sL_cosN_yell[i]);
         h_cY_yell_L[kJ][kPT]->Fill(sL_im[i],sL_cosY_yell[i]);
         h_cV_blue_L[kJ][kPT]->Fill(sL_im[i],sL_cosTv_blue[i]);
         h_cN_blue_L[kJ][kPT]->Fill(sL_im[i],sL_cosN_blue[i]);
         h_cY_blue_L[kJ][kPT]->Fill(sL_im[i],sL_cosY_blue[i]);

         if (sL_im[i]>=kIM3[kPT] && sL_im[i]<kIM4[kPT])
         {
            if (kJ)
            {
               int iJ = sL_index[i];
               h_peak_fz_L[kPT]->Fill(sL_pt[i]/J_pt[iJ]);
            }
            h_peak_pt_Lp[kJ][kPT]->Fill(sLp_pt[i]);
            h_peak_eta_Lp[kJ][kPT]->Fill(sLp_eta[i]); 
            h_peak_phi_Lp[kJ][kPT]->Fill(sLp_phi[i]); 
            h_peak_pt_Lpi[kJ][kPT]->Fill(sLpi_pt[i]);
            h_peak_eta_Lpi[kJ][kPT]->Fill(sLpi_eta[i]);
            h_peak_phi_Lpi[kJ][kPT]->Fill(sLpi_phi[i]);
            h_peak_pt_L[kJ][kPT]->Fill(sL_pt[i]);
            h_peak_eta_L[kJ][kPT]->Fill(sL_eta[i]);
            h_peak_phi_L[kJ][kPT]->Fill(sL_phi[i]);

            h_peak_dca_Lp[kJ][kPT]->Fill(sLp_dca[i]);   
            h_peak_dca_Lpi[kJ][kPT]->Fill(sLpi_dca[i]);   
            h_peak_nFit_Lp[kJ][kPT]->Fill(sLp_nHit[i]);
            h_peak_nFit_Lpi[kJ][kPT]->Fill(sLpi_nHit[i]);  
            h_peak_nSigP_Lp[kJ][kPT]->Fill(sLp_nSigmaP[i]);
            h_peak_nSigPi_Lpi[kJ][kPT]->Fill(sLpi_nSigmaPi[i]);
            h_peak_dl_L[kJ][kPT]->Fill(sL_dl[i]);   
            h_peak_dca2_L[kJ][kPT]->Fill(sL_dca2[i]);
            h_peak_dcaV0_L[kJ][kPT]->Fill(sL_dcaV0[i]);
            h_peak_crp_L[kJ][kPT]->Fill(sL_crp[i]);

            h_peak_dr_L[kJ][kPT]->Fill(sL_dr[i]);
            //h_peak_deta_L[kJ][kPT]->Fill(sL_deta[i]);
            //h_peak_dphi_L[kJ][kPT]->Fill(sL_dphi[i]);
         }

         if ( (sL_im[i]>=kIM1[kPT] && sL_im[i]<kIM2[kPT]) || (sL_im[i]>=kIM5[kPT] && sL_im[i]<kIM6[kPT]) )
         {
            if (kJ)
            {
               int iJ = sL_index[i];
               h_bkg_fz_L[kPT]->Fill(sL_pt[i]/J_pt[iJ]);
            }
            h_bkg_pt_Lp[kJ][kPT]->Fill(sLp_pt[i]);
            h_bkg_eta_Lp[kJ][kPT]->Fill(sLp_eta[i]); 
            h_bkg_phi_Lp[kJ][kPT]->Fill(sLp_phi[i]); 
            h_bkg_pt_Lpi[kJ][kPT]->Fill(sLpi_pt[i]);
            h_bkg_eta_Lpi[kJ][kPT]->Fill(sLpi_eta[i]);
            h_bkg_phi_Lpi[kJ][kPT]->Fill(sLpi_phi[i]);
            h_bkg_pt_L[kJ][kPT]->Fill(sL_pt[i]);
            h_bkg_eta_L[kJ][kPT]->Fill(sL_eta[i]);
            h_bkg_phi_L[kJ][kPT]->Fill(sL_phi[i]);

            h_bkg_dca_Lp[kJ][kPT]->Fill(sLp_dca[i]);   
            h_bkg_dca_Lpi[kJ][kPT]->Fill(sLpi_dca[i]);   
            h_bkg_nFit_Lp[kJ][kPT]->Fill(sLp_nHit[i]);
            h_bkg_nFit_Lpi[kJ][kPT]->Fill(sLpi_nHit[i]);  
            h_bkg_nSigP_Lp[kJ][kPT]->Fill(sLp_nSigmaP[i]);
            h_bkg_nSigPi_Lpi[kJ][kPT]->Fill(sLpi_nSigmaPi[i]);
            h_bkg_dl_L[kJ][kPT]->Fill(sL_dl[i]);   
            h_bkg_dca2_L[kJ][kPT]->Fill(sL_dca2[i]);
            h_bkg_dcaV0_L[kJ][kPT]->Fill(sL_dcaV0[i]);
            h_bkg_crp_L[kJ][kPT]->Fill(sL_crp[i]);

            h_bkg_dr_L[kJ][kPT]->Fill(sL_dr[i]);
            //h_bkg_deta_L[kJ][kPT]->Fill(sL_deta[i]);
            //h_bkg_dphi_L[kJ][kPT]->Fill(sL_dphi[i]);
         }
      }

      for (int i = 0; i < snlbr; ++i)
      {
         int kPT=getPTbin(sA_pt[i]);
         //cout << "A PTbin: " << kPT << endl;
         if (kPT<0)
         {
            continue;
         }
         //cout << "Filling A_0 " << entry << endl;
         if (kJ)
         {
            if( sA_index[i]<0 ) continue;
            if( sA_dr[i]<0 || sA_dr[i]>0.6 ) continue;
         }
         
         ReadCutTable(kPT);

         if( sAp_dca[i] < c_dca_min_proton ) continue;
         if( sApi_dca[i] < c_dca_min_pion ) continue;
         if( sA_dca2[i] > c_dca2_max ) continue;
         if( sA_dcaV0[i] > c_dcaV0_max ) continue;
         if( sA_crp[i] < c_crp_min ) continue;
         if( sA_dl[i] < c_dl_min ) continue;
         if( fabs(sAp_nSigmaP[i]) > c_nSigma_proton ) continue;
         if( fabs(sApi_nSigmaPi[i]) > c_nSigma_pion ) continue;
         if( (fabs(sAp_nSigmaP[i]) > c_nSigma_protect) && (fabs(sAp_nSigmaP[i])>fabs(sAp_nSigmaPi[i])) ) continue;

         TVector3 tPi;
         tPi.SetPtEtaPhi( sApi_pt[i], sApi_eta[i], sApi_phi[i] );
         if( tPi.Mag() < c_P_min_pion ) continue;

         if( sAp_dca[i] > 200.0 ) continue;
         if( sApi_dca[i] > 200.0 ) continue;
         if( sAp_dca[i] > 20 ) continue;
         if( sApi_dca[i] > 20 && sAp_dca[i] < 0.8 ) continue;
         if( sApi_dca[i] < 2 && sAp_dca[i] > 3 ) continue;
         
         h_im_A[kJ][kPT]->Fill(sA_im[i]);
         if (kJ)
         {
            int iJ = sA_index[i];
            h_fz_A[kPT]->Fill(sA_pt[i]/J_pt[iJ]);
            h_cJ_yell_A[kJ][kPT]->Fill(sA_im[i],sA_cosTj_yell[i]);
            h_cJ_blue_A[kJ][kPT]->Fill(sA_im[i],sA_cosTj_blue[i]);
         }
         //cout << "Filling A_1 " << entry << endl;
         h_pt_Ap[kJ][kPT]->Fill(sAp_pt[i]);
         h_eta_Ap[kJ][kPT]->Fill(sAp_eta[i]); 
         h_phi_Ap[kJ][kPT]->Fill(sAp_phi[i]); 
         h_pt_Api[kJ][kPT]->Fill(sApi_pt[i]);
         h_eta_Api[kJ][kPT]->Fill(sApi_eta[i]);
         h_phi_Api[kJ][kPT]->Fill(sApi_phi[i]);
         h_pt_A[kJ][kPT]->Fill(sA_pt[i]);
         h_eta_A[kJ][kPT]->Fill(sA_eta[i]);
         h_phi_A[kJ][kPT]->Fill(sA_phi[i]);
         h_dca_Ap[kJ][kPT]->Fill(sAp_dca[i]);   
         h_dca_Api[kJ][kPT]->Fill(sApi_dca[i]);   
         h_nFit_Ap[kJ][kPT]->Fill(sAp_nHit[i]);
         h_nFit_Api[kJ][kPT]->Fill(sApi_nHit[i]);  
         h_nSigP_Ap[kJ][kPT]->Fill(sAp_nSigmaP[i]);
         h_nSigPi_Api[kJ][kPT]->Fill(sApi_nSigmaPi[i]);
         h_dl_A[kJ][kPT]->Fill(sA_dl[i]);   
         h_dca2_A[kJ][kPT]->Fill(sA_dca2[i]);
         h_dcaV0_A[kJ][kPT]->Fill(sA_dcaV0[i]);
         h_crp_A[kJ][kPT]->Fill(sA_crp[i]);
         h_dr_A[kJ][kPT]->Fill(sA_dr[i]);
         //cout << "Filling A_2 " << entry << endl;
         //h_deta_A[kJ][kPT]->Fill(sA_deta[i]);
         //h_dphi_A[kJ][kPT]->Fill(sA_dphi[i]);
         //cout << "Filling A_3 " << entry << endl;
         h_cV_yell_A[kJ][kPT]->Fill(sA_im[i],sA_cosTv_yell[i]);
         h_cN_yell_A[kJ][kPT]->Fill(sA_im[i],sA_cosN_yell[i]);
         h_cY_yell_A[kJ][kPT]->Fill(sA_im[i],sA_cosY_yell[i]);
         h_cV_blue_A[kJ][kPT]->Fill(sA_im[i],sA_cosTv_blue[i]);
         h_cN_blue_A[kJ][kPT]->Fill(sA_im[i],sA_cosN_blue[i]);
         h_cY_blue_A[kJ][kPT]->Fill(sA_im[i],sA_cosY_blue[i]);
         //cout << "Filling A_4 " << entry << endl;


         if (sA_im[i]>=kIM3[kPT] && sA_im[i]<kIM4[kPT])
         {
            if (kJ)
            {
               int iJ = sA_index[i];
               h_peak_fz_A[kPT]->Fill(sA_pt[i]/J_pt[iJ]);
            }
            h_peak_pt_Ap[kJ][kPT]->Fill(sAp_pt[i]);
            h_peak_eta_Ap[kJ][kPT]->Fill(sAp_eta[i]); 
            h_peak_phi_Ap[kJ][kPT]->Fill(sAp_phi[i]); 
            h_peak_pt_Api[kJ][kPT]->Fill(sApi_pt[i]);
            h_peak_eta_Api[kJ][kPT]->Fill(sApi_eta[i]);
            h_peak_phi_Api[kJ][kPT]->Fill(sApi_phi[i]);
            h_peak_pt_A[kJ][kPT]->Fill(sA_pt[i]);
            h_peak_eta_A[kJ][kPT]->Fill(sA_eta[i]);
            h_peak_phi_A[kJ][kPT]->Fill(sA_phi[i]);

            h_peak_dca_Ap[kJ][kPT]->Fill(sAp_dca[i]);   
            h_peak_dca_Api[kJ][kPT]->Fill(sApi_dca[i]);   
            h_peak_nFit_Ap[kJ][kPT]->Fill(sAp_nHit[i]);
            h_peak_nFit_Api[kJ][kPT]->Fill(sApi_nHit[i]);  
            h_peak_nSigP_Ap[kJ][kPT]->Fill(sAp_nSigmaP[i]);
            h_peak_nSigPi_Api[kJ][kPT]->Fill(sApi_nSigmaPi[i]);
            h_peak_dl_A[kJ][kPT]->Fill(sA_dl[i]);   
            h_peak_dca2_A[kJ][kPT]->Fill(sA_dca2[i]);
            h_peak_dcaV0_A[kJ][kPT]->Fill(sA_dcaV0[i]);
            h_peak_crp_A[kJ][kPT]->Fill(sA_crp[i]);

            h_peak_dr_A[kJ][kPT]->Fill(sA_dr[i]);
            //h_peak_deta_A[kJ][kPT]->Fill(sA_deta[i]);
            //h_peak_dphi_A[kJ][kPT]->Fill(sA_dphi[i]);
         }

         if ( (sA_im[i]>=kIM1[kPT] && sA_im[i]<kIM2[kPT]) || (sA_im[i]>=kIM5[kPT] && sA_im[i]<kIM6[kPT]) )
         {
            if (kJ)
            {
               int iJ = sA_index[i];
               h_bkg_fz_A[kPT]->Fill(sA_pt[i]/J_pt[iJ]);
            }
            h_bkg_pt_Ap[kJ][kPT]->Fill(sAp_pt[i]);
            h_bkg_eta_Ap[kJ][kPT]->Fill(sAp_eta[i]); 
            h_bkg_phi_Ap[kJ][kPT]->Fill(sAp_phi[i]); 
            h_bkg_pt_Api[kJ][kPT]->Fill(sApi_pt[i]);
            h_bkg_eta_Api[kJ][kPT]->Fill(sApi_eta[i]);
            h_bkg_phi_Api[kJ][kPT]->Fill(sApi_phi[i]);
            h_bkg_pt_A[kJ][kPT]->Fill(sA_pt[i]);
            h_bkg_eta_A[kJ][kPT]->Fill(sA_eta[i]);
            h_bkg_phi_A[kJ][kPT]->Fill(sA_phi[i]);

            h_bkg_dca_Ap[kJ][kPT]->Fill(sAp_dca[i]);   
            h_bkg_dca_Api[kJ][kPT]->Fill(sApi_dca[i]);   
            h_bkg_nFit_Ap[kJ][kPT]->Fill(sAp_nHit[i]);
            h_bkg_nFit_Api[kJ][kPT]->Fill(sApi_nHit[i]);  
            h_bkg_nSigP_Ap[kJ][kPT]->Fill(sAp_nSigmaP[i]);
            h_bkg_nSigPi_Api[kJ][kPT]->Fill(sApi_nSigmaPi[i]);
            h_bkg_dl_A[kJ][kPT]->Fill(sA_dl[i]);   
            h_bkg_dca2_A[kJ][kPT]->Fill(sA_dca2[i]);
            h_bkg_dcaV0_A[kJ][kPT]->Fill(sA_dcaV0[i]);
            h_bkg_crp_A[kJ][kPT]->Fill(sA_crp[i]);

            h_bkg_dr_A[kJ][kPT]->Fill(sA_dr[i]);
            //h_bkg_deta_A[kJ][kPT]->Fill(sA_deta[i]);
            //h_bkg_dphi_A[kJ][kPT]->Fill(sA_dphi[i]);
         }
      }

      for (int i = 0; i < snk0s; ++i)
      {
         int kPT=getPTbin(sK_pt[i]);
         //cout << "K PTbin: " << kPT << endl;
         if (kPT<0)
         {
            continue;
         }

         if (kJ)
         {
            if( sK_index[i]<0 ) continue;
            if( sK_dr[i]<0 || sK_dr[i]>0.6 ) continue;
         }
         
         ReadCutTable(kPT);

         if( sKp_dca[i] < K_c_dca_min_pion ) continue;
         if( sKpi_dca[i] < K_c_dca_min_pion ) continue;
         if( sK_dca2[i] > K_c_dca2_max ) continue;
         if( sK_dcaV0[i] > K_c_dcaV0_max ) continue;
         if( sK_crp[i] < K_c_crp_min ) continue;
         if( sK_dl[i] < K_c_dl_min ) continue;
         if( fabs(sKp_nSigmaP[i]) > c_nSigma_proton ) continue;
         if( fabs(sKpi_nSigmaPi[i]) > c_nSigma_pion ) continue;
         if( (fabs(sKp_nSigmaPi[i]) > c_nSigma_protect) && (fabs(sKp_nSigmaPi[i])>fabs(sKp_nSigmaP[i])) ) continue;
         if( (fabs(sKpi_nSigmaPi[i]) > c_nSigma_protect) && (fabs(sKpi_nSigmaPi[i])>fabs(sKpi_nSigmaP[i])) ) continue;

         TVector3 tPi;
         tPi.SetPtEtaPhi( sKp_pt[i], sKp_eta[i], sKp_phi[i] );
         if( tPi.Mag() < c_P_min_pion ) continue;
         tPi.SetPtEtaPhi( sKpi_pt[i], sKpi_eta[i], sKpi_phi[i] );
         if( tPi.Mag() < c_P_min_pion ) continue;
         
         h_im_K[kJ][kPT]->Fill(sK_im[i]);
         if (kJ)
         {
            int iJ = sK_index[i];
            h_fz_K[kPT]->Fill(sK_pt[i]/J_pt[iJ]);
            h_cJ_yell_K[kJ][kPT]->Fill(sK_im[i],sK_cosTj_yell[i]);
            h_cJ_blue_K[kJ][kPT]->Fill(sK_im[i],sK_cosTj_blue[i]);
         }
         h_pt_Kp[kJ][kPT]->Fill(sKp_pt[i]);
         h_eta_Kp[kJ][kPT]->Fill(sKp_eta[i]); 
         h_phi_Kp[kJ][kPT]->Fill(sKp_phi[i]); 
         h_pt_Kpi[kJ][kPT]->Fill(sKpi_pt[i]);
         h_eta_Kpi[kJ][kPT]->Fill(sKpi_eta[i]);
         h_phi_Kpi[kJ][kPT]->Fill(sKpi_phi[i]);
         h_pt_K[kJ][kPT]->Fill(sK_pt[i]);
         h_eta_K[kJ][kPT]->Fill(sK_eta[i]);
         h_phi_K[kJ][kPT]->Fill(sK_phi[i]);
         h_dca_Kp[kJ][kPT]->Fill(sKp_dca[i]);   
         h_dca_Kpi[kJ][kPT]->Fill(sKpi_dca[i]);   
         h_nFit_Kp[kJ][kPT]->Fill(sKp_nHit[i]);
         h_nFit_Kpi[kJ][kPT]->Fill(sKpi_nHit[i]);  
         h_nSigP_Kp[kJ][kPT]->Fill(sKp_nSigmaP[i]);
         h_nSigPi_Kpi[kJ][kPT]->Fill(sKpi_nSigmaPi[i]);
         h_dl_K[kJ][kPT]->Fill(sK_dl[i]);   
         h_dca2_K[kJ][kPT]->Fill(sK_dca2[i]);
         h_dcaV0_K[kJ][kPT]->Fill(sK_dcaV0[i]);
         h_crp_K[kJ][kPT]->Fill(sK_crp[i]);
         h_dr_K[kJ][kPT]->Fill(sK_dr[i]);
         //h_deta_K[kJ][kPT]->Fill(sK_deta[i]);
         //h_dphi_K[kJ][kPT]->Fill(sK_dphi[i]);
         h_cV_yell_K[kJ][kPT]->Fill(sK_im[i],sK_cosTv_yell[i]);
         h_cN_yell_K[kJ][kPT]->Fill(sK_im[i],sK_cosN_yell[i]);
         h_cY_yell_K[kJ][kPT]->Fill(sK_im[i],sK_cosY_yell[i]);
         h_cV_blue_K[kJ][kPT]->Fill(sK_im[i],sK_cosTv_blue[i]);
         h_cN_blue_K[kJ][kPT]->Fill(sK_im[i],sK_cosN_blue[i]);
         h_cY_blue_K[kJ][kPT]->Fill(sK_im[i],sK_cosY_blue[i]);

         if (sK_im[i]>=kIMK3[kPT] && sK_im[i]<kIMK4[kPT])
         {
            if (kJ)
            {
               int iJ = sK_index[i];
               h_peak_fz_K[kPT]->Fill(sK_pt[i]/J_pt[iJ]);
            }
            h_peak_pt_Kp[kJ][kPT]->Fill(sKp_pt[i]);
            h_peak_eta_Kp[kJ][kPT]->Fill(sKp_eta[i]); 
            h_peak_phi_Kp[kJ][kPT]->Fill(sKp_phi[i]); 
            h_peak_pt_Kpi[kJ][kPT]->Fill(sKpi_pt[i]);
            h_peak_eta_Kpi[kJ][kPT]->Fill(sKpi_eta[i]);
            h_peak_phi_Kpi[kJ][kPT]->Fill(sKpi_phi[i]);
            h_peak_pt_K[kJ][kPT]->Fill(sK_pt[i]);
            h_peak_eta_K[kJ][kPT]->Fill(sK_eta[i]);
            h_peak_phi_K[kJ][kPT]->Fill(sK_phi[i]);

            h_peak_dca_Kp[kJ][kPT]->Fill(sKp_dca[i]);   
            h_peak_dca_Kpi[kJ][kPT]->Fill(sKpi_dca[i]);   
            h_peak_nFit_Kp[kJ][kPT]->Fill(sKp_nHit[i]);
            h_peak_nFit_Kpi[kJ][kPT]->Fill(sKpi_nHit[i]);  
            h_peak_nSigP_Kp[kJ][kPT]->Fill(sKp_nSigmaP[i]);
            h_peak_nSigPi_Kpi[kJ][kPT]->Fill(sKpi_nSigmaPi[i]);
            h_peak_dl_K[kJ][kPT]->Fill(sK_dl[i]);   
            h_peak_dca2_K[kJ][kPT]->Fill(sK_dca2[i]);
            h_peak_dcaV0_K[kJ][kPT]->Fill(sK_dcaV0[i]);
            h_peak_crp_K[kJ][kPT]->Fill(sK_crp[i]);

            h_peak_dr_K[kJ][kPT]->Fill(sK_dr[i]);
            //h_peak_deta_K[kJ][kPT]->Fill(sK_deta[i]);
            //h_peak_dphi_K[kJ][kPT]->Fill(sK_dphi[i]);
         }

         if ( (sK_im[i]>=kIMK1[kPT] && sK_im[i]<kIMK2[kPT]) || (sK_im[i]>=kIMK5[kPT] && sK_im[i]<kIMK6[kPT]) )
         {
            if (kJ)
            {
               int iJ = sK_index[i];
               h_bkg_fz_K[kPT]->Fill(sK_pt[i]/J_pt[iJ]);
            }
            h_bkg_pt_Kp[kJ][kPT]->Fill(sKp_pt[i]);
            h_bkg_eta_Kp[kJ][kPT]->Fill(sKp_eta[i]); 
            h_bkg_phi_Kp[kJ][kPT]->Fill(sKp_phi[i]); 
            h_bkg_pt_Kpi[kJ][kPT]->Fill(sKpi_pt[i]);
            h_bkg_eta_Kpi[kJ][kPT]->Fill(sKpi_eta[i]);
            h_bkg_phi_Kpi[kJ][kPT]->Fill(sKpi_phi[i]);
            h_bkg_pt_K[kJ][kPT]->Fill(sK_pt[i]);
            h_bkg_eta_K[kJ][kPT]->Fill(sK_eta[i]);
            h_bkg_phi_K[kJ][kPT]->Fill(sK_phi[i]);

            h_bkg_dca_Kp[kJ][kPT]->Fill(sKp_dca[i]);   
            h_bkg_dca_Kpi[kJ][kPT]->Fill(sKpi_dca[i]);   
            h_bkg_nFit_Kp[kJ][kPT]->Fill(sKp_nHit[i]);
            h_bkg_nFit_Kpi[kJ][kPT]->Fill(sKpi_nHit[i]);  
            h_bkg_nSigP_Kp[kJ][kPT]->Fill(sKp_nSigmaP[i]);
            h_bkg_nSigPi_Kpi[kJ][kPT]->Fill(sKpi_nSigmaPi[i]);
            h_bkg_dl_K[kJ][kPT]->Fill(sK_dl[i]);   
            h_bkg_dca2_K[kJ][kPT]->Fill(sK_dca2[i]);
            h_bkg_dcaV0_K[kJ][kPT]->Fill(sK_dcaV0[i]);
            h_bkg_crp_K[kJ][kPT]->Fill(sK_crp[i]);

            h_bkg_dr_K[kJ][kPT]->Fill(sK_dr[i]);
            //h_bkg_deta_K[kJ][kPT]->Fill(sK_deta[i]);
            //h_bkg_dphi_K[kJ][kPT]->Fill(sK_dphi[i]);
         }
      }      
   }

   if (entry%100000==0) cout << "Filling histograms over for entry: " << entry << endl;

   return kTRUE;
}

void fillHist::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void fillHist::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
