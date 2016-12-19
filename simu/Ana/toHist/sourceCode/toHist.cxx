#define toHist_cxx
// The class definition in toHist.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SEL.CTOR or the ROOT User Manual.

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
// Root > T->Process("toHist.cxx")
// Root > T->Process("toHist.cxx","some options")
// Root > T->Process("toHist.cxx+")
//

#include "toHist.h"
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TVector3.h>
#include <iostream>

using namespace std;

void toHist::ReadCutTable( int pT )
{
   c_nSigma_protect  = cut_nSigma_protect[pT];
   c_nSigma_proton   = cut_nSigma_proton[pT];
   c_nSigma_pion     = cut_nSigma_pion[pT];
   c_dca_min_proton  = cut_dca_min_proton[pT];
   c_dca_min_pion    = cut_dca_min_pion[pT];
   Kc_dca_min_pion   = Kcut_dca_min_pion[pT];
   c_crp_min         = cut_crp_min[pT];
   Kc_crp_min        = Kcut_crp_min[pT];
   c_dca2_max        = cut_dca2_max[pT];
   Kc_dca2_max       = Kcut_dca2_max[pT];
   c_dcaV0_max       = cut_dcaV0_max[pT];
   Kc_dcaV0_max      = Kcut_dcaV0_max[pT];
   c_dl_min          = cut_dl_min[pT];
   Kc_dl_min         = Kcut_dl_min[pT];
   c_dl_max          = cut_dl_max[pT];
   c_P_min_pion      = cut_P_min_pion[pT];
}

void toHist::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   h_trig = new TH1D("h_trig","h_trig",5,0,5);
   h_trig->Sumw2();

   h_g_idSubproc        = new TH1D("h_g_idSubproc","h_g_idSubproc",100,0,100);   
   h_g_pvz              = new TH1D("h_g_pvz","h_g_pvz",120,-60,60);   
   h_m_pvz              = new TH1D("h_m_pvz","h_m_pvz",120,-60,60);   
   h_g_pv_geantProc     = new TH1D("h_g_pv_geantProc","h_g_pv_geantProc",100,0,100);   
   h_g_pv_geantMedium   = new TH1D("h_g_pv_geantMedium","h_g_pv_geantMedium",100,0,100);   
   h_g_pv_generatorProc = new TH1D("h_g_pv_generatorProc","h_g_pv_generatorProc",100,0,100);

   h_g_idSubproc->Sumw2();   
   h_g_pvz->Sumw2();
   h_m_pvz->Sumw2();
   h_g_pv_geantProc->Sumw2();
   h_g_pv_geantMedium->Sumw2();
   h_g_pv_generatorProc->Sumw2();

   h_p_ptHard0 = new TH1D("h_p_ptHard0","h_p_ptHard0",30,0,30);
   h_p_ptHard1 = new TH1D("h_p_ptHard1","h_p_ptHard1",30,0,30);
   h_p_cosTheta = new TH1D("h_p_cosTheta","h_p_cosTheta",200,-1,1);
   h_p_ptHard0->Sumw2();
   h_p_ptHard1->Sumw2();
   h_p_cosTheta->Sumw2();

   h_nJet     = new TH1D("h_nJet","h_nJet",10,0,10);
   h_deteta_J = new TH1D("h_deteta_J","h_deteta_J",200,-2,2);
   h_eta_J    = new TH1D("h_eta_J","h_eta_J",200,-2,2);
   h_pt_J     = new TH1D("h_pt_J","h_pt_J",200,0,20);
   h_phi_J    = new TH1D("h_phi_J","h_phi_J",340,-3.2,3.2);
   h_rt_J     = new TH1D("h_rt_J","h_rt_J",100,0.,1.);
   h_charge_J = new TH1D("h_charge_J","h_charge_J",100,0.,1);
   h_drParton_J = new TH2D("h_drParton_J","h_drParton_J",200,0,10,200,0,10);
   h_fParton_J = new TH1D("h_fParton_J","h_fParton_J",35,-10,25);
   h_fPartonS_J = new TH1D("h_fPartonS_J","h_fPartonS_J",35,-10,25);

   h_nJet->Sumw2();
   h_deteta_J->Sumw2();
   h_eta_J->Sumw2();
   h_pt_J->Sumw2();
   h_phi_J->Sumw2();
   h_rt_J->Sumw2();
   h_charge_J->Sumw2();
   h_drParton_J->Sumw2();
   h_fParton_J->Sumw2();
   h_fPartonS_J->Sumw2();

   h_p_ptHard0 = new TH1D("h_p_ptHard0","h_p_ptHard0",250,0,25);
   h_p_ptHard1 = new TH1D("h_p_ptHard1","h_p_ptHard1",250,0,25);
   h_p_cosTheta = new TH1D("h_p_cosTheta","h_p_cosTheta",200,-1,1);

   h_p_ptHard0->Sumw2();
   h_p_ptHard1->Sumw2();
   h_p_cosTheta->Sumw2();

   TString hn;
   for(int kPT=0; kPT<6; ++kPT) {
      hn = Form("h_g_fz_L_PT%d", kPT);
      h_g_fz_L[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_g_fz_A_PT%d", kPT);
      h_g_fz_A[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_a_fz_L_PT%d", kPT);
      h_a_fz_L[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_a_fz_A_PT%d", kPT);
      h_a_fz_A[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_m_fz_L_PT%d", kPT);
      h_m_fz_L[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_m_fz_A_PT%d", kPT);
      h_m_fz_A[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_t_fz_L_PT%d", kPT);
      h_t_fz_L[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_t_fz_A_PT%d", kPT);
      h_t_fz_A[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);

      h_g_fz_L[kPT]->Sumw2();
      h_g_fz_A[kPT]->Sumw2();
      h_a_fz_L[kPT]->Sumw2();
      h_a_fz_A[kPT]->Sumw2();
      h_m_fz_L[kPT]->Sumw2();
      h_m_fz_A[kPT]->Sumw2();
      h_t_fz_L[kPT]->Sumw2();
      h_t_fz_A[kPT]->Sumw2();

      for( int kJ=0; kJ<2; ++kJ) {
         hn = Form("h_g_e_Lp_J%d_PT%d", kJ, kPT);
         h_g_e_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_pt_Lp_J%d_PT%d", kJ, kPT);
         h_g_pt_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_eta_Lp_J%d_PT%d", kJ, kPT);
         h_g_eta_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_g_phi_Lp_J%d_PT%d", kJ, kPT);
         h_g_phi_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         h_g_e_Lp[kJ][kPT]->Sumw2();
         h_g_pt_Lp[kJ][kPT]->Sumw2();
         h_g_eta_Lp[kJ][kPT]->Sumw2();
         h_g_phi_Lp[kJ][kPT]->Sumw2();

         hn = Form("h_g_e_Lpi_J%d_PT%d", kJ, kPT);
         h_g_e_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_pt_Lpi_J%d_PT%d", kJ, kPT);
         h_g_pt_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_eta_Lpi_J%d_PT%d", kJ, kPT);
         h_g_eta_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_g_phi_Lpi_J%d_PT%d", kJ, kPT);
         h_g_phi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         h_g_e_Lpi[kJ][kPT]->Sumw2();
         h_g_pt_Lpi[kJ][kPT]->Sumw2();
         h_g_eta_Lpi[kJ][kPT]->Sumw2();
         h_g_phi_Lpi[kJ][kPT]->Sumw2();

         hn = Form("h_g_e_L_J%d_PT%d", kJ, kPT);
         h_g_e_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_pt_L_J%d_PT%d", kJ, kPT);
         h_g_pt_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_eta_L_J%d_PT%d", kJ, kPT);
         h_g_eta_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_g_phi_L_J%d_PT%d", kJ, kPT);
         h_g_phi_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_g_im_L_J%d_PT%d", kJ, kPT);
         h_g_im_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);
         hn = Form("h_g_pid_parent_L_J%d_PT%d", kJ, kPT);
         h_g_pid_parent_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),10000,-5000,5000);
         hn = Form("h_g_dr_L_J%d_PT%d", kJ, kPT);
         h_g_dr_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_g_idSubproc_L_J%d_PT%d", kJ, kPT);
         h_g_idSubproc_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,100);
         hn = Form("h_g_drParton_L_J%d_PT%d", kJ, kPT);
         h_g_drParton_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),200,0,10,200,0,10);
         hn = Form("h_g_fParton_L_J%d_PT%d", kJ, kPT);
         h_g_fParton_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);
         hn = Form("h_g_fPartonS_L_J%d_PT%d", kJ, kPT);
         h_g_fPartonS_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);

         h_g_e_L[kJ][kPT]->Sumw2();
         h_g_pt_L[kJ][kPT]->Sumw2();
         h_g_eta_L[kJ][kPT]->Sumw2();
         h_g_phi_L[kJ][kPT]->Sumw2();
         h_g_im_L[kJ][kPT]->Sumw2();
         h_g_pid_parent_L[kJ][kPT]->Sumw2();
         h_g_dr_L[kJ][kPT]->Sumw2();
         h_g_idSubproc_L[kJ][kPT]->Sumw2();
         h_g_drParton_L[kJ][kPT]->Sumw2();
         h_g_fParton_L[kJ][kPT]->Sumw2();
         h_g_fPartonS_L[kJ][kPT]->Sumw2();

         hn = Form("h_g_e_Ap_J%d_PT%d", kJ, kPT);
         h_g_e_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_pt_Ap_J%d_PT%d", kJ, kPT);
         h_g_pt_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_eta_Ap_J%d_PT%d", kJ, kPT);
         h_g_eta_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_g_phi_Ap_J%d_PT%d", kJ, kPT);
         h_g_phi_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);

         hn = Form("h_g_e_Api_J%d_PT%d", kJ, kPT);
         h_g_e_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_pt_Api_J%d_PT%d", kJ, kPT);
         h_g_pt_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_eta_Api_J%d_PT%d", kJ, kPT);
         h_g_eta_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_g_phi_Api_J%d_PT%d", kJ, kPT);
         h_g_phi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);

         hn = Form("h_g_e_A_J%d_PT%d", kJ, kPT);
         h_g_e_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_pt_A_J%d_PT%d", kJ, kPT);
         h_g_pt_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_g_eta_A_J%d_PT%d", kJ, kPT);
         h_g_eta_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_g_phi_A_J%d_PT%d", kJ, kPT);
         h_g_phi_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_g_im_A_J%d_PT%d", kJ, kPT);
         h_g_im_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);
         hn = Form("h_g_pid_parent_A_J%d_PT%d", kJ, kPT);
         h_g_pid_parent_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),10000,-5000,5000);
         hn = Form("h_g_dr_A_J%d_PT%d", kJ, kPT);
         h_g_dr_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_g_idSubproc_A_J%d_PT%d", kJ, kPT);
         h_g_idSubproc_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,100);
         hn = Form("h_g_drParton_A_J%d_PT%d", kJ, kPT);
         h_g_drParton_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),200,0,10,200,0,10);
         hn = Form("h_g_fParton_A_J%d_PT%d", kJ, kPT);
         h_g_fParton_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);
         hn = Form("h_g_fPartonS_A_J%d_PT%d", kJ, kPT);
         h_g_fPartonS_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);

         h_g_e_Ap[kJ][kPT]->Sumw2();
         h_g_pt_Ap[kJ][kPT]->Sumw2();
         h_g_eta_Ap[kJ][kPT]->Sumw2();
         h_g_phi_Ap[kJ][kPT]->Sumw2();
         h_g_e_Api[kJ][kPT]->Sumw2();
         h_g_pt_Api[kJ][kPT]->Sumw2();
         h_g_eta_Api[kJ][kPT]->Sumw2();
         h_g_phi_Api[kJ][kPT]->Sumw2();
         h_g_e_A[kJ][kPT]->Sumw2();
         h_g_pt_A[kJ][kPT]->Sumw2();
         h_g_eta_A[kJ][kPT]->Sumw2();
         h_g_phi_A[kJ][kPT]->Sumw2();
         h_g_im_A[kJ][kPT]->Sumw2();
         h_g_pid_parent_A[kJ][kPT]->Sumw2();
         h_g_dr_A[kJ][kPT]->Sumw2();
         h_g_idSubproc_A[kJ][kPT]->Sumw2();
         h_g_drParton_A[kJ][kPT]->Sumw2();
         h_g_fParton_A[kJ][kPT]->Sumw2();
         h_g_fPartonS_A[kJ][kPT]->Sumw2();

         hn = Form("h_a_e_Lp_J%d_PT%d", kJ, kPT);
         h_a_e_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_pt_Lp_J%d_PT%d", kJ, kPT);
         h_a_pt_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_eta_Lp_J%d_PT%d", kJ, kPT);
         h_a_eta_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_a_phi_Lp_J%d_PT%d", kJ, kPT);
         h_a_phi_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_a_dca_Lp_J%d_PT%d", kJ, kPT);
         h_a_dca_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_a_flag_Lp_J%d_PT%d", kJ, kPT);
         h_a_flag_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,200);
         hn = Form("h_a_nFit_Lp_J%d_PT%d", kJ, kPT);
         h_a_nFit_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_a_ratio_Lp_J%d_PT%d", kJ, kPT);
         h_a_ratio_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,1);

         h_a_e_Lp[kJ][kPT]->Sumw2();
         h_a_pt_Lp[kJ][kPT]->Sumw2();
         h_a_eta_Lp[kJ][kPT]->Sumw2();
         h_a_phi_Lp[kJ][kPT]->Sumw2();
         h_a_dca_Lp[kJ][kPT]->Sumw2();
         h_a_flag_Lp[kJ][kPT]->Sumw2();
         h_a_nFit_Lp[kJ][kPT]->Sumw2();
         h_a_ratio_Lp[kJ][kPT]->Sumw2();

         hn = Form("h_a_e_Lpi_J%d_PT%d", kJ, kPT);
         h_a_e_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_pt_Lpi_J%d_PT%d", kJ, kPT);
         h_a_pt_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_eta_Lpi_J%d_PT%d", kJ, kPT);
         h_a_eta_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_a_phi_Lpi_J%d_PT%d", kJ, kPT);
         h_a_phi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_a_dca_Lpi_J%d_PT%d", kJ, kPT);
         h_a_dca_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_a_flag_Lpi_J%d_PT%d", kJ, kPT);
         h_a_flag_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,200);
         hn = Form("h_a_nFit_Lpi_J%d_PT%d", kJ, kPT);
         h_a_nFit_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_a_ratio_Lpi_J%d_PT%d", kJ, kPT);
         h_a_ratio_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,1);

         h_a_e_Lpi[kJ][kPT]->Sumw2();
         h_a_pt_Lpi[kJ][kPT]->Sumw2();
         h_a_eta_Lpi[kJ][kPT]->Sumw2();
         h_a_phi_Lpi[kJ][kPT]->Sumw2();
         h_a_dca_Lpi[kJ][kPT]->Sumw2();
         h_a_flag_Lpi[kJ][kPT]->Sumw2();
         h_a_nFit_Lpi[kJ][kPT]->Sumw2();
         h_a_ratio_Lpi[kJ][kPT]->Sumw2();

         hn = Form("h_a_pt_L_J%d_PT%d", kJ, kPT);
         h_a_pt_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_eta_L_J%d_PT%d", kJ, kPT);
         h_a_eta_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_a_phi_L_J%d_PT%d", kJ, kPT);
         h_a_phi_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_a_im_L_J%d_PT%d", kJ, kPT);
         h_a_im_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);

         h_a_pt_L[kJ][kPT]->Sumw2();
         h_a_eta_L[kJ][kPT]->Sumw2();
         h_a_phi_L[kJ][kPT]->Sumw2();
         h_a_im_L[kJ][kPT]->Sumw2();

         hn = Form("h_a_pid_parent_L_J%d_PT%d", kJ, kPT);
         h_a_pid_parent_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),10000,-5000,5000);
         hn = Form("h_a_dr_L_J%d_PT%d", kJ, kPT);
         h_a_dr_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_a_dl_L_J%d_PT%d", kJ, kPT);
         h_a_dl_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
         hn = Form("h_a_dca2_L_J%d_PT%d", kJ, kPT);
         h_a_dca2_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_a_dcaV0_L_J%d_PT%d", kJ, kPT);
         h_a_dcaV0_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_a_idSubproc_L_J%d_PT%d", kJ, kPT);
         h_a_idSubproc_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,100);
         hn = Form("h_a_drParton_L_J%d_PT%d", kJ, kPT);
         h_a_drParton_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),200,0,10,200,0,10);
         hn = Form("h_a_fParton_L_J%d_PT%d", kJ, kPT);
         h_a_fParton_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);
         hn = Form("h_a_fPartonS_L_J%d_PT%d", kJ, kPT);
         h_a_fPartonS_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);

         h_a_pid_parent_L[kJ][kPT]->Sumw2();
         h_a_dr_L[kJ][kPT]->Sumw2();
         h_a_dl_L[kJ][kPT]->Sumw2();
         h_a_dca2_L[kJ][kPT]->Sumw2();
         h_a_dcaV0_L[kJ][kPT]->Sumw2();
         h_a_idSubproc_L[kJ][kPT]->Sumw2();
         h_a_drParton_L[kJ][kPT]->Sumw2();
         h_a_fParton_L[kJ][kPT]->Sumw2();
         h_a_fPartonS_L[kJ][kPT]->Sumw2();

         hn = Form("h_a_e_Ap_J%d_PT%d", kJ, kPT);
         h_a_e_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_pt_Ap_J%d_PT%d", kJ, kPT);
         h_a_pt_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_eta_Ap_J%d_PT%d", kJ, kPT);
         h_a_eta_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_a_phi_Ap_J%d_PT%d", kJ, kPT);
         h_a_phi_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_a_dca_Ap_J%d_PT%d", kJ, kPT);
         h_a_dca_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_a_flag_Ap_J%d_PT%d", kJ, kPT);
         h_a_flag_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,200);
         hn = Form("h_a_nFit_Ap_J%d_PT%d", kJ, kPT);
         h_a_nFit_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_a_ratio_Ap_J%d_PT%d", kJ, kPT);
         h_a_ratio_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,1);

         hn = Form("h_a_e_Api_J%d_PT%d", kJ, kPT);
         h_a_e_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_pt_Api_J%d_PT%d", kJ, kPT);
         h_a_pt_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_eta_Api_J%d_PT%d", kJ, kPT);
         h_a_eta_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_a_phi_Api_J%d_PT%d", kJ, kPT);
         h_a_phi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_a_dca_Api_J%d_PT%d", kJ, kPT);
         h_a_dca_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_a_flag_Api_J%d_PT%d", kJ, kPT);
         h_a_flag_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,200);
         hn = Form("h_a_nFit_Api_J%d_PT%d", kJ, kPT);
         h_a_nFit_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_a_ratio_Api_J%d_PT%d", kJ, kPT);
         h_a_ratio_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,1);

         hn = Form("h_a_pt_A_J%d_PT%d", kJ, kPT);
         h_a_pt_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_a_eta_A_J%d_PT%d", kJ, kPT);
         h_a_eta_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_a_phi_A_J%d_PT%d", kJ, kPT);
         h_a_phi_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_a_im_A_J%d_PT%d", kJ, kPT);
         h_a_im_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);

         hn = Form("h_a_pid_parent_A_J%d_PT%d", kJ, kPT);
         h_a_pid_parent_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),10000,-5000,5000);
         hn = Form("h_a_dr_A_J%d_PT%d", kJ, kPT);
         h_a_dr_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_a_dl_A_J%d_PT%d", kJ, kPT);
         h_a_dl_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
         hn = Form("h_a_dca2_A_J%d_PT%d", kJ, kPT);
         h_a_dca2_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_a_dcaV0_A_J%d_PT%d", kJ, kPT);
         h_a_dcaV0_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_a_idSubproc_A_J%d_PT%d", kJ, kPT);
         h_a_idSubproc_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,100);
         hn = Form("h_a_drParton_A_J%d_PT%d", kJ, kPT);
         h_a_drParton_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),200,0,10,200,0,10);
         hn = Form("h_a_fParton_A_J%d_PT%d", kJ, kPT);
         h_a_fParton_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);
         hn = Form("h_a_fPartonS_A_J%d_PT%d", kJ, kPT);
         h_a_fPartonS_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);

         h_a_e_Ap[kJ][kPT]->Sumw2();
         h_a_pt_Ap[kJ][kPT]->Sumw2();
         h_a_eta_Ap[kJ][kPT]->Sumw2();
         h_a_phi_Ap[kJ][kPT]->Sumw2();
         h_a_dca_Ap[kJ][kPT]->Sumw2();
         h_a_flag_Ap[kJ][kPT]->Sumw2();
         h_a_nFit_Ap[kJ][kPT]->Sumw2();
         h_a_ratio_Ap[kJ][kPT]->Sumw2();
         h_a_e_Api[kJ][kPT]->Sumw2();
         h_a_pt_Api[kJ][kPT]->Sumw2();
         h_a_eta_Api[kJ][kPT]->Sumw2();
         h_a_phi_Api[kJ][kPT]->Sumw2();
         h_a_dca_Api[kJ][kPT]->Sumw2();
         h_a_flag_Api[kJ][kPT]->Sumw2();
         h_a_nFit_Api[kJ][kPT]->Sumw2();
         h_a_ratio_Api[kJ][kPT]->Sumw2();
         h_a_pt_A[kJ][kPT]->Sumw2();
         h_a_eta_A[kJ][kPT]->Sumw2();
         h_a_phi_A[kJ][kPT]->Sumw2();
         h_a_im_A[kJ][kPT]->Sumw2();
         h_a_pid_parent_A[kJ][kPT]->Sumw2();
         h_a_dr_A[kJ][kPT]->Sumw2();
         h_a_dl_A[kJ][kPT]->Sumw2();
         h_a_dca2_A[kJ][kPT]->Sumw2();
         h_a_dcaV0_A[kJ][kPT]->Sumw2();
         h_a_idSubproc_A[kJ][kPT]->Sumw2();
         h_a_drParton_A[kJ][kPT]->Sumw2();
         h_a_fParton_A[kJ][kPT]->Sumw2();
         h_a_fPartonS_A[kJ][kPT]->Sumw2();

         hn = Form("h_m_pt_Lp_J%d_PT%d", kJ, kPT);
         h_m_pt_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_m_eta_Lp_J%d_PT%d", kJ, kPT);
         h_m_eta_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_m_phi_Lp_J%d_PT%d", kJ, kPT);
         h_m_phi_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_m_dca_Lp_J%d_PT%d", kJ, kPT);
         h_m_dca_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_m_nSig_Lp_J%d_PT%d", kJ, kPT);
         h_m_nSig_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);

         hn = Form("h_m_pt_Lpi_J%d_PT%d", kJ, kPT);
         h_m_pt_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_m_eta_Lpi_J%d_PT%d", kJ, kPT);
         h_m_eta_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_m_phi_Lpi_J%d_PT%d", kJ, kPT);
         h_m_phi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_m_dca_Lpi_J%d_PT%d", kJ, kPT);
         h_m_dca_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_m_nSig_Lpi_J%d_PT%d", kJ, kPT);
         h_m_nSig_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);

         hn = Form("h_m_pt_L_J%d_PT%d", kJ, kPT);
         h_m_pt_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_m_eta_L_J%d_PT%d", kJ, kPT);
         h_m_eta_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_m_phi_L_J%d_PT%d", kJ, kPT);
         h_m_phi_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_m_im_L_J%d_PT%d", kJ, kPT);
         h_m_im_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);

         hn = Form("h_m_dr_L_J%d_PT%d", kJ, kPT);
         h_m_dr_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_m_dl_L_J%d_PT%d", kJ, kPT);
         h_m_dl_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
         hn = Form("h_m_dca2_L_J%d_PT%d", kJ, kPT);
         h_m_dca2_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_m_dcaV0_L_J%d_PT%d", kJ, kPT);
         h_m_dcaV0_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_m_idSubproc_L_J%d_PT%d", kJ, kPT);
         h_m_idSubproc_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,100);
         hn = Form("h_m_drParton_L_J%d_PT%d", kJ, kPT);
         h_m_drParton_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),200,0,10,200,0,10);
         hn = Form("h_m_fParton_L_J%d_PT%d", kJ, kPT);
         h_m_fParton_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);
         hn = Form("h_m_fPartonS_L_J%d_PT%d", kJ, kPT);
         h_m_fPartonS_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);

         h_m_pt_Lp[kJ][kPT]->Sumw2();
         h_m_eta_Lp[kJ][kPT]->Sumw2();
         h_m_phi_Lp[kJ][kPT]->Sumw2();
         h_m_dca_Lp[kJ][kPT]->Sumw2();
         h_m_nSig_Lp[kJ][kPT]->Sumw2();
         h_m_pt_Lpi[kJ][kPT]->Sumw2();
         h_m_eta_Lpi[kJ][kPT]->Sumw2();
         h_m_phi_Lpi[kJ][kPT]->Sumw2();
         h_m_dca_Lpi[kJ][kPT]->Sumw2();
         h_m_nSig_Lpi[kJ][kPT]->Sumw2();
         h_m_pt_L[kJ][kPT]->Sumw2();
         h_m_eta_L[kJ][kPT]->Sumw2();
         h_m_phi_L[kJ][kPT]->Sumw2();
         h_m_im_L[kJ][kPT]->Sumw2();
         h_m_dr_L[kJ][kPT]->Sumw2();
         h_m_dl_L[kJ][kPT]->Sumw2();
         h_m_dca2_L[kJ][kPT]->Sumw2();
         h_m_dcaV0_L[kJ][kPT]->Sumw2();
         h_m_idSubproc_L[kJ][kPT]->Sumw2();
         h_m_drParton_L[kJ][kPT]->Sumw2();
         h_m_fParton_L[kJ][kPT]->Sumw2();
         h_m_fPartonS_L[kJ][kPT]->Sumw2();

         hn = Form("h_m_pt_Ap_J%d_PT%d", kJ, kPT);
         h_m_pt_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_m_eta_Ap_J%d_PT%d", kJ, kPT);
         h_m_eta_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_m_phi_Ap_J%d_PT%d", kJ, kPT);
         h_m_phi_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_m_dca_Ap_J%d_PT%d", kJ, kPT);
         h_m_dca_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_m_nSig_Ap_J%d_PT%d", kJ, kPT);
         h_m_nSig_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);

         hn = Form("h_m_pt_Api_J%d_PT%d", kJ, kPT);
         h_m_pt_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_m_eta_Api_J%d_PT%d", kJ, kPT);
         h_m_eta_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_m_phi_Api_J%d_PT%d", kJ, kPT);
         h_m_phi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_m_dca_Api_J%d_PT%d", kJ, kPT);
         h_m_dca_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_m_nSig_Api_J%d_PT%d", kJ, kPT);
         h_m_nSig_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);

         hn = Form("h_m_pt_A_J%d_PT%d", kJ, kPT);
         h_m_pt_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_m_eta_A_J%d_PT%d", kJ, kPT);
         h_m_eta_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_m_phi_A_J%d_PT%d", kJ, kPT);
         h_m_phi_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_m_im_A_J%d_PT%d", kJ, kPT);
         h_m_im_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);

         hn = Form("h_m_dr_A_J%d_PT%d", kJ, kPT);
         h_m_dr_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_m_dl_A_J%d_PT%d", kJ, kPT);
         h_m_dl_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
         hn = Form("h_m_dca2_A_J%d_PT%d", kJ, kPT);
         h_m_dca2_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_m_dcaV0_A_J%d_PT%d", kJ, kPT);
         h_m_dcaV0_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_m_idSubproc_A_J%d_PT%d", kJ, kPT);
         h_m_idSubproc_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,100);
         hn = Form("h_m_drParton_A_J%d_PT%d", kJ, kPT);
         h_m_drParton_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),200,0,10,200,0,10);
         hn = Form("h_m_fParton_A_J%d_PT%d", kJ, kPT);
         h_m_fParton_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);
         hn = Form("h_m_fPartonS_A_J%d_PT%d", kJ, kPT);
         h_m_fPartonS_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);


         h_m_pt_Ap[kJ][kPT]->Sumw2();
         h_m_eta_Ap[kJ][kPT]->Sumw2();
         h_m_phi_Ap[kJ][kPT]->Sumw2();
         h_m_dca_Ap[kJ][kPT]->Sumw2();
         h_m_nSig_Ap[kJ][kPT]->Sumw2();
         h_m_pt_Api[kJ][kPT]->Sumw2();
         h_m_eta_Api[kJ][kPT]->Sumw2();
         h_m_phi_Api[kJ][kPT]->Sumw2();
         h_m_dca_Api[kJ][kPT]->Sumw2();
         h_m_nSig_Api[kJ][kPT]->Sumw2();
         h_m_pt_A[kJ][kPT]->Sumw2();
         h_m_eta_A[kJ][kPT]->Sumw2();
         h_m_phi_A[kJ][kPT]->Sumw2();
         h_m_im_A[kJ][kPT]->Sumw2();
         h_m_dr_A[kJ][kPT]->Sumw2();
         h_m_dl_A[kJ][kPT]->Sumw2();
         h_m_dca2_A[kJ][kPT]->Sumw2();
         h_m_dcaV0_A[kJ][kPT]->Sumw2();
         h_m_idSubproc_A[kJ][kPT]->Sumw2();
         h_m_drParton_A[kJ][kPT]->Sumw2();
         h_m_fParton_A[kJ][kPT]->Sumw2();
         h_m_fPartonS_A[kJ][kPT]->Sumw2();

         hn = Form("h_t_pt_Lp_J%d_PT%d", kJ, kPT);
         h_t_pt_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_t_eta_Lp_J%d_PT%d", kJ, kPT);
         h_t_eta_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_t_phi_Lp_J%d_PT%d", kJ, kPT);
         h_t_phi_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_t_dca_Lp_J%d_PT%d", kJ, kPT);
         h_t_dca_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_t_nSig_Lp_J%d_PT%d", kJ, kPT);
         h_t_nSig_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);

         hn = Form("h_t_pt_Lpi_J%d_PT%d", kJ, kPT);
         h_t_pt_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_t_eta_Lpi_J%d_PT%d", kJ, kPT);
         h_t_eta_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_t_phi_Lpi_J%d_PT%d", kJ, kPT);
         h_t_phi_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_t_dca_Lpi_J%d_PT%d", kJ, kPT);
         h_t_dca_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_t_nSig_Lpi_J%d_PT%d", kJ, kPT);
         h_t_nSig_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);

         hn = Form("h_t_pt_L_J%d_PT%d", kJ, kPT);
         h_t_pt_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_t_eta_L_J%d_PT%d", kJ, kPT);
         h_t_eta_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_t_phi_L_J%d_PT%d", kJ, kPT);
         h_t_phi_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_t_im_L_J%d_PT%d", kJ, kPT);
         h_t_im_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);

         hn = Form("h_t_dr_L_J%d_PT%d", kJ, kPT);
         h_t_dr_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_t_dl_L_J%d_PT%d", kJ, kPT);
         h_t_dl_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
         hn = Form("h_t_dca2_L_J%d_PT%d", kJ, kPT);
         h_t_dca2_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_t_dcaV0_L_J%d_PT%d", kJ, kPT);
         h_t_dcaV0_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_t_idSubproc_L_J%d_PT%d", kJ, kPT);
         h_t_idSubproc_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,100);
         hn = Form("h_t_drParton_L_J%d_PT%d", kJ, kPT);
         h_t_drParton_L[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),200,0,10,200,0,10);
         hn = Form("h_t_fParton_L_J%d_PT%d", kJ, kPT);
         h_t_fParton_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);
         hn = Form("h_t_fPartonS_L_J%d_PT%d", kJ, kPT);
         h_t_fPartonS_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);

         h_t_pt_Lp[kJ][kPT]->Sumw2();
         h_t_eta_Lp[kJ][kPT]->Sumw2();
         h_t_phi_Lp[kJ][kPT]->Sumw2();
         h_t_dca_Lp[kJ][kPT]->Sumw2();
         h_t_nSig_Lp[kJ][kPT]->Sumw2();
         h_t_pt_Lpi[kJ][kPT]->Sumw2();
         h_t_eta_Lpi[kJ][kPT]->Sumw2();
         h_t_phi_Lpi[kJ][kPT]->Sumw2();
         h_t_dca_Lpi[kJ][kPT]->Sumw2();
         h_t_nSig_Lpi[kJ][kPT]->Sumw2();
         h_t_pt_L[kJ][kPT]->Sumw2();
         h_t_eta_L[kJ][kPT]->Sumw2();
         h_t_phi_L[kJ][kPT]->Sumw2();
         h_t_im_L[kJ][kPT]->Sumw2();
         h_t_dr_L[kJ][kPT]->Sumw2();
         h_t_dl_L[kJ][kPT]->Sumw2();
         h_t_dca2_L[kJ][kPT]->Sumw2();
         h_t_dcaV0_L[kJ][kPT]->Sumw2();
         h_t_idSubproc_L[kJ][kPT]->Sumw2();
         h_t_drParton_L[kJ][kPT]->Sumw2();
         h_t_fParton_L[kJ][kPT]->Sumw2();
         h_t_fPartonS_L[kJ][kPT]->Sumw2();

         hn = Form("h_t_pt_Ap_J%d_PT%d", kJ, kPT);
         h_t_pt_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_t_eta_Ap_J%d_PT%d", kJ, kPT);
         h_t_eta_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_t_phi_Ap_J%d_PT%d", kJ, kPT);
         h_t_phi_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_t_dca_Ap_J%d_PT%d", kJ, kPT);
         h_t_dca_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_t_nSig_Ap_J%d_PT%d", kJ, kPT);
         h_t_nSig_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);

         hn = Form("h_t_pt_Api_J%d_PT%d", kJ, kPT);
         h_t_pt_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_t_eta_Api_J%d_PT%d", kJ, kPT);
         h_t_eta_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_t_phi_Api_J%d_PT%d", kJ, kPT);
         h_t_phi_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_t_dca_Api_J%d_PT%d", kJ, kPT);
         h_t_dca_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),50,0,5);
         hn = Form("h_t_nSig_Api_J%d_PT%d", kJ, kPT);
         h_t_nSig_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),120,-3,3);

         hn = Form("h_t_pt_A_J%d_PT%d", kJ, kPT);
         h_t_pt_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,10);
         hn = Form("h_t_eta_A_J%d_PT%d", kJ, kPT);
         h_t_eta_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),300,-1.5,1.5);
         hn = Form("h_t_phi_A_J%d_PT%d", kJ, kPT);
         h_t_phi_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),340,-3.2,3.2);
         hn = Form("h_t_im_A_J%d_PT%d", kJ, kPT);
         h_t_im_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);

         hn = Form("h_t_dr_A_J%d_PT%d", kJ, kPT);
         h_t_dr_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,5.);
         hn = Form("h_t_dl_A_J%d_PT%d", kJ, kPT);
         h_t_dl_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
         hn = Form("h_t_dca2_A_J%d_PT%d", kJ, kPT);
         h_t_dca2_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_t_dcaV0_A_J%d_PT%d", kJ, kPT);
         h_t_dcaV0_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_t_idSubproc_A_J%d_PT%d", kJ, kPT);
         h_t_idSubproc_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),100,0,100);
         hn = Form("h_t_drParton_A_J%d_PT%d", kJ, kPT);
         h_t_drParton_A[kJ][kPT] = new TH2D(hn.Data(),hn.Data(),200,0,10,200,0,10);
         hn = Form("h_t_fParton_L_J%d_PT%d", kJ, kPT);
         h_t_fParton_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);
         hn = Form("h_t_fPartonS_L_J%d_PT%d", kJ, kPT);
         h_t_fPartonS_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),35,-10,25);

         h_t_pt_Ap[kJ][kPT]->Sumw2();
         h_t_eta_Ap[kJ][kPT]->Sumw2();
         h_t_phi_Ap[kJ][kPT]->Sumw2();
         h_t_dca_Ap[kJ][kPT]->Sumw2();
         h_t_nSig_Ap[kJ][kPT]->Sumw2();
         h_t_pt_Api[kJ][kPT]->Sumw2();
         h_t_eta_Api[kJ][kPT]->Sumw2();
         h_t_phi_Api[kJ][kPT]->Sumw2();
         h_t_dca_Api[kJ][kPT]->Sumw2();
         h_t_nSig_Api[kJ][kPT]->Sumw2();
         h_t_pt_A[kJ][kPT]->Sumw2();
         h_t_eta_A[kJ][kPT]->Sumw2();
         h_t_phi_A[kJ][kPT]->Sumw2();
         h_t_im_A[kJ][kPT]->Sumw2();
         h_t_dr_A[kJ][kPT]->Sumw2();
         h_t_dl_A[kJ][kPT]->Sumw2();
         h_t_dca2_A[kJ][kPT]->Sumw2();
         h_t_dcaV0_A[kJ][kPT]->Sumw2();
         h_t_idSubproc_A[kJ][kPT]->Sumw2();
         h_t_drParton_A[kJ][kPT]->Sumw2();
         h_t_fParton_A[kJ][kPT]->Sumw2();
         h_t_fParton_A[kJ][kPT]->Sumw2();
      }
   }
}

void toHist::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();


}

Bool_t toHist::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either toHist::GetEntry() or TBranch::GetEntry()
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
   cout << "===-->  Working on Event:\t" << entry << " === EventID: " << g_evtN << endl;
   cout << "===-->  g_pvz:\t(" << g_pvx << "," << g_pvy << "," << g_pvz << ")" << endl;
   cout << "===-->  m_pvz:\t(" << m_pvx << "," << m_pvy << "," << m_pvz << ")" << endl;

   double weight_fill = weight_pt_hard;//weight_pt_hard;
   cout << "===-->  Trigger Selection: " << fOption.Data() << "\t===> Weight" << weight_fill << endl;

   int trigT = 1;
   if( fOption.Contains("JP0") ) trigT = trig[0];
   if( fOption.Contains("JP1") ) trigT = trig[1];
   if( fOption.Contains("JP2") ) trigT = trig[2];
   if( fOption.Contains("AJP") ) trigT = trig[3];

   if( !trigT ) return kTRUE;
   //cout << "===-->  Trigger Pass: " << fOption.Data() << endl;

   h_g_idSubproc->Fill(g_idSubproc, weight_fill); 
   h_g_pvz->Fill(g_pvz, weight_fill);
   h_m_pvz->Fill(m_pvz, weight_fill);
   h_g_pv_geantProc->Fill(g_pv_geantProc, weight_fill);
   h_g_pv_geantMedium->Fill(g_pv_geantMedium, weight_fill);
   h_g_pv_generatorProc->Fill(g_pv_generatorProc, weight_fill);
   //cout << "===-->  Event Filled " << endl;

   h_p_ptHard0->Fill(p_ptHard);
   h_p_ptHard1->Fill(p_ptHard, weight_fill);
   h_p_cosTheta->Fill(p_cosTheta, weight_fill);

   for (int i = 0; i < njet; ++i)  {
      h_deteta_J->Fill(J_deteta[i], weight_fill);
      h_eta_J->Fill(J_eta[i], weight_fill);
      h_pt_J->Fill(J_pt[i], weight_fill);
      h_phi_J->Fill(J_phi[i], weight_fill); 
      h_rt_J->Fill(J_rt[i], weight_fill);
      h_charge_J->Fill(J_charge[i], weight_fill);
      h_drParton_J->Fill(J_drParton1[i],J_drParton2[i], weight_fill);
      int fParton = g_idParton1;
      if (J_drParton2[i]<J_drParton1[i])
      {
         fParton = g_idParton2;
      }
      h_fParton_J->Fill(fParton, weight_fill);

      if (J_drParton1<1.0 || J_drParton2<1.0)
      {
         int fPartonS = g_idParton1;
         if (J_drParton2[i]<J_drParton1[i])
         {
            fPartonS = g_idParton2;
         }
         h_fPartonS_J->Fill(fPartonS, weight_fill);
      }
   }

   ReadCutTable(ptVmin-1);
   //cout << "===-->  Cut read: " << ptVmin-1 << endl;

   for( int kJ=0; kJ<2; ++kJ ) {
      for( int i=0; i<g_nL; ++i ){
         if( g_pt_L[i]<ptVmin || g_pt_L[i]>=ptVmax ) {
            Abort("Err: g_L pt range out !!!");
         }
         if( kJ ) {
            if( g_index_L[i]<0 ) continue;
            if( g_dr_L[i]<0 || g_dr_L[i]>0.6 ) continue;
            int iJ = g_index_L[i];
            h_g_fz_L[ptVmin-1]->Fill(g_pt_L[i]/J_pt[iJ], weight_fill);
         }

         //___Add_selection_cut_here____
         //cout << "===-->  g_L Filling " << endl;
         h_g_e_Lp[kJ][ptVmin-1]->Fill(g_e_Lp[i], weight_fill);   
         h_g_pt_Lp[kJ][ptVmin-1]->Fill(g_pt_Lp[i], weight_fill);   
         h_g_eta_Lp[kJ][ptVmin-1]->Fill(g_eta_Lp[i], weight_fill);   
         h_g_phi_Lp[kJ][ptVmin-1]->Fill(g_phi_Lp[i], weight_fill);   
         h_g_e_Lpi[kJ][ptVmin-1]->Fill(g_e_Lpi[i], weight_fill);   
         h_g_pt_Lpi[kJ][ptVmin-1]->Fill(g_pt_Lpi[i], weight_fill);   
         h_g_eta_Lpi[kJ][ptVmin-1]->Fill(g_eta_Lpi[i], weight_fill);   
         h_g_phi_Lpi[kJ][ptVmin-1]->Fill(g_phi_Lpi[i], weight_fill);   
         h_g_e_L[kJ][ptVmin-1]->Fill(g_e_L[i], weight_fill);   
         h_g_pt_L[kJ][ptVmin-1]->Fill(g_pt_L[i], weight_fill);   
         h_g_eta_L[kJ][ptVmin-1]->Fill(g_eta_L[i], weight_fill);   
         h_g_phi_L[kJ][ptVmin-1]->Fill(g_phi_L[i], weight_fill);   
         h_g_im_L[kJ][ptVmin-1]->Fill(g_im_L[i], weight_fill);
         h_g_idSubproc_L[kJ][ptVmin-1]->Fill(g_idSubproc, weight_fill);

         if( g_gid_parent_L[i]!=0 ) {
            g_pid_parent_L[i] = findPid( g_gid_parent_L[i] );
            cout << "gid :: pid  ===>   " << g_gid_parent_L[i] << "\t::\t" << g_pid_parent_L[i] << endl;
         }
         h_g_pid_parent_L[kJ][ptVmin-1]->Fill(g_pid_parent_L[i], weight_fill);   

         h_g_dr_L[kJ][ptVmin-1]->Fill(g_dr_L[i], weight_fill);
         h_g_drParton_L[kJ][ptVmin-1]->Fill(g_drParton1_L[i],g_drParton2_L[i], weight_fill); 
         //h_g_deta_L[kJ][ptVmin-1]->Fill(g_deta_L[i], weight_fill);   
         //h_g_dphi_L[kJ][ptVmin-1]->Fill(g_dphi_L[i], weight_fill);

         int fParton = g_idParton1;
         if (g_drParton2_L[i]<g_drParton1_L[i])
         {
            fParton = g_idParton2;
         }
         h_g_fParton_L[kT][ptVmin-1]->Fill(fParton, weight_fill);
   
         if (g_drParton1_L[i]<1.0 || g_drParton2_L[i]<1.0)
         {
            int fPartonS = g_idParton1;
            if (g_drParton2_L[i]<g_drParton1_L[i])
            {
               fPartonS = g_idParton2;
            }
            h_g_fPartonS_L[kT][ptVmin-1]->Fill(fPartonS, weight_fill);
         }
      }

      for( int i=0; i<g_nA; ++i ){
         if( g_pt_A[i]<ptVmin || g_pt_A[i]>=ptVmax ) {
             Abort("Err: g_A pt range out !!!");
         }
         if( kJ ) {
            if( g_index_A[i]<0 ) continue;
            if( g_dr_A[i]<0 || g_dr_A[i]>0.6 ) continue;
            int iJ = g_index_A[i];
            h_g_fz_A[ptVmin-1]->Fill(g_pt_A[i]/J_pt[iJ], weight_fill);
         }
         //cout << "===-->  g_A Filling " << g_index_A[i] << "\t======\t" << g_dr_A[i] << endl;
         //cout << "===-->  g_A Filling " << ptVmin << "\t======\t" << kJ << endl;
         //___Add_selection_cut_here____
         //
         h_g_e_Ap[kJ][ptVmin-1]->Fill(g_e_Ap[i], weight_fill);   
         h_g_pt_Ap[kJ][ptVmin-1]->Fill(g_pt_Ap[i], weight_fill);   
         h_g_eta_Ap[kJ][ptVmin-1]->Fill(g_eta_Ap[i], weight_fill);   
         h_g_phi_Ap[kJ][ptVmin-1]->Fill(g_phi_Ap[i], weight_fill);   
         h_g_e_Api[kJ][ptVmin-1]->Fill(g_e_Api[i], weight_fill);   
         h_g_pt_Api[kJ][ptVmin-1]->Fill(g_pt_Api[i], weight_fill);   
         h_g_eta_Api[kJ][ptVmin-1]->Fill(g_eta_Api[i], weight_fill);   
         h_g_phi_Api[kJ][ptVmin-1]->Fill(g_phi_Api[i], weight_fill);   
         h_g_e_A[kJ][ptVmin-1]->Fill(g_e_A[i], weight_fill);   
         h_g_pt_A[kJ][ptVmin-1]->Fill(g_pt_A[i], weight_fill);   
         h_g_eta_A[kJ][ptVmin-1]->Fill(g_eta_A[i], weight_fill);   
         h_g_phi_A[kJ][ptVmin-1]->Fill(g_phi_A[i], weight_fill);   
         h_g_im_A[kJ][ptVmin-1]->Fill(g_im_A[i], weight_fill);
         //cout << "===-->  g_A Filling " << ptVmin << "\t======\t" << g_im_A[i] << endl;
         h_g_geantProc_start_A[kJ][ptVmin-1]->Fill(g_geantProc_start_A[i], weight_fill);   
         h_g_geantMedium_start_A[kJ][ptVmin-1]->Fill(g_geantMedium_start_A[i], weight_fill);   
         h_g_generatorProc_start_A[kJ][ptVmin-1]->Fill(g_generatorProc_start_A[i], weight_fill);
         h_g_idSubproc_A[kJ][ptVmin-1]->Fill(g_idSubproc, weight_fill); 

         if( g_gid_parent_A[i]!=0 ) g_pid_parent_A[i] = findPid( g_gid_parent_A[i] );
         h_g_pid_parent_A[kJ][ptVmin-1]->Fill(g_pid_parent_A[i], weight_fill);   

         h_g_dr_A[kJ][ptVmin-1]->Fill(g_dr_A[i], weight_fill);
         h_g_drParton_A[kJ][ptVmin-1]->Fill(g_drParton1_A[i],g_drParton2_A[i], weight_fill); 
         //cout << "===-->  g_A Filled " << endl;

         int fParton = g_idParton1;
         if (g_drParton2_A[i]<g_drParton1_A[i])
         {
            fParton = g_idParton2;
         }
         h_g_fParton_A[kT][ptVmin-1]->Fill(fParton, weight_fill);
   
         if (g_drParton1_A[i]<1.0 || g_drParton2_A[i]<1.0)
         {
            int fPartonS = g_idParton1;
            if (g_drParton2_A[i]<g_drParton1_A[i])
            {
               fPartonS = g_idParton2;
            }
            h_g_fPartonS_A[kT][ptVmin-1]->Fill(fPartonS, weight_fill);
         }
      }

      for( int i=0; i<a_nL; ++i ){
         if( a_pt_L[i]<ptVmin || a_pt_L[i]>=ptVmax ) {
             Abort("Err: a_L pt range out !!!");
         }
                  //cout << "===-->  a_L Filling " << endl;
         h_a_ratio_Lp[kJ][ptVmin-1]->Fill(a_ratio_Lp[i], weight_fill);
         h_a_ratio_Lpi[kJ][ptVmin-1]->Fill(a_ratio_Lpi[i], weight_fill);
         if( a_ratio_Lp[i]<0.51 || a_ratio_Lpi[i]<0.51 ) continue;
         //___Ldd_selection_cut_here____
         if( a_dca_Lp[i] > 200.0 ) continue;
         if( a_dca_Lpi[i] > 200.0 ) continue;
         if( a_dca_Lpi[i]>16 && a_dca_Lp[i]<0.8 ) continue;
         if( a_dca_Lpi[i]>45 ) continue;
         if( a_crp_L[i]   < c_crp_min ) continue;
         if( a_dca_Lp[i]  < c_dca_min_proton ) continue;
         if( a_dca_Lpi[i] < c_dca_min_pion ) continue;
         if( a_dca2_L[i]  > c_dca2_max ) continue;
         if( a_dcaV0_L[i] > c_dcaV0_max ) continue;
         if( a_dl_L[i] < c_dl_min ) continue;
         TVector3 tPi;
         tPi.SetPtEtaPhi( a_pt_Lpi[i], a_eta_Lpi[i], a_phi_Lpi[i] );
         if( tPi.Mag() < c_P_min_pion ) continue;

         if( kJ ) {
            if( a_index_L[i]<0 ) continue;
            if( a_dr_L[i]<0 || a_dr_L[i]>0.6 ) continue;
            int iJ = a_index_L[i];
            h_a_fz_L[ptVmin-1]->Fill(a_pt_L[i]/J_pt[iJ], weight_fill);
         }

         h_a_e_Lp[kJ][ptVmin-1]->Fill(a_e_Lp[i], weight_fill);   
         h_a_pt_Lp[kJ][ptVmin-1]->Fill(a_pt_Lp[i], weight_fill);   
         h_a_eta_Lp[kJ][ptVmin-1]->Fill(a_eta_Lp[i], weight_fill);   
         h_a_phi_Lp[kJ][ptVmin-1]->Fill(a_phi_Lp[i], weight_fill);   
         h_a_e_Lpi[kJ][ptVmin-1]->Fill(a_e_Lpi[i], weight_fill);   
         h_a_pt_Lpi[kJ][ptVmin-1]->Fill(a_pt_Lpi[i], weight_fill);   
         h_a_eta_Lpi[kJ][ptVmin-1]->Fill(a_eta_Lpi[i], weight_fill);   
         h_a_phi_Lpi[kJ][ptVmin-1]->Fill(a_phi_Lpi[i], weight_fill);     
         h_a_pt_L[kJ][ptVmin-1]->Fill(a_pt_L[i], weight_fill);   
         h_a_eta_L[kJ][ptVmin-1]->Fill(a_eta_L[i], weight_fill);   
         h_a_phi_L[kJ][ptVmin-1]->Fill(a_phi_L[i], weight_fill);   
         h_a_im_L[kJ][ptVmin-1]->Fill(a_im_L[i], weight_fill);   
         h_a_idSubproc_L[kJ][ptVmin-1]->Fill(g_idSubproc, weight_fill);

         if( a_gid_parent_L[i]!=0 ) a_pid_parent_L[i] = findPid( a_gid_parent_L[i] );
         h_a_pid_parent_L[kJ][ptVmin-1]->Fill(a_pid_parent_L[i], weight_fill);   

         h_a_dr_L[kJ][ptVmin-1]->Fill(a_dr_L[i], weight_fill); 
         h_a_drParton_L[kJ][ptVmin-1]->Fill(a_drParton1_L[i],a_drParton2_L[i], weight_fill);
         //h_a_deta_L[kJ][ptVmin-1]->Fill(a_deta_L[i], weight_fill);   
         //h_a_dphi_L[kJ][ptVmin-1]->Fill(a_dphi_L[i], weight_fill);

         h_a_nFit_Lp[kJ][ptVmin-1]->Fill(a_nFit_Lp[i], weight_fill);
         h_a_dca_Lp[kJ][ptVmin-1]->Fill(a_dca_Lp[i], weight_fill);
         h_a_nFit_Lpi[kJ][ptVmin-1]->Fill(a_nFit_Lpi[i], weight_fill);
         h_a_dca_Lpi[kJ][ptVmin-1]->Fill(a_dca_Lpi[i], weight_fill);
         h_a_dl_L[kJ][ptVmin-1]->Fill(a_dl_L[i], weight_fill);
         h_a_dca2_L[kJ][ptVmin-1]->Fill(a_dca2_L[i], weight_fill);
         h_a_dcaV0_L[kJ][ptVmin-1]->Fill(a_dcaV0_L[i], weight_fill);

         int fParton = g_idParton1;
         if (a_drParton2_L[i]<a_drParton1_L[i])
         {
            fParton = g_idParton2;
         }
         h_a_fParton_L[kT][ptVmin-1]->Fill(fParton, weight_fill);
   
         if (a_drParton1_L[i]<1.0 || a_drParton2_L[i]<1.0)
         {
            int fPartonS = g_idParton1;
            if (a_drParton2_L[i]<a_drParton1_L[i])
            {
               fPartonS = g_idParton2;
            }
            h_a_fPartonS_L[kT][ptVmin-1]->Fill(fPartonS, weight_fill);
         }
      }

      for( int i=0; i<a_nA; ++i ){
         if( a_pt_A[i]<ptVmin || a_pt_A[i]>=ptVmax ) {
             Abort("Err: a_A pt range out !!!");
         }
                  //cout << "===-->  a_A Filling " << endl;
         h_a_ratio_Ap[kJ][ptVmin-1]->Fill(a_ratio_Ap[i], weight_fill);
         h_a_ratio_Api[kJ][ptVmin-1]->Fill(a_ratio_Api[i], weight_fill);
         if( a_ratio_Ap[i]<0.51 || a_ratio_Api[i]<0.51 ) continue;
         //___Add_selection_cut_here____
         if( a_dca_Ap[i] > 200.0 ) continue;
         if( a_dca_Api[i] > 200.0 ) continue;
         if( a_dca_Ap[i]>20 ) continue;
         if( a_dca_Api[i]>20 && a_dca_Ap[i]<0.8 ) continue;
         if( a_crp_A[i]   < c_crp_min ) continue;
         if( a_dca_Ap[i]  < c_dca_min_proton ) continue;
         if( a_dca_Api[i] < c_dca_min_pion ) continue;
         if( a_dca2_A[i]  > c_dca2_max ) continue;
         if( a_dcaV0_A[i] > c_dcaV0_max ) continue;
         if( a_dl_A[i] < c_dl_min ) continue;
         TVector3 tPi;
         tPi.SetPtEtaPhi( a_pt_Api[i], a_eta_Api[i], a_phi_Api[i] );
         if( tPi.Mag()   < c_P_min_pion ) continue;

         if( kJ ) {
            if( a_index_A[i]<0 ) continue;
            if( a_dr_A[i]<0 || a_dr_A[i]>0.6 ) continue;
            int iJ = a_index_A[i];
            h_a_fz_A[ptVmin-1]->Fill(a_pt_A[i]/J_pt[iJ], weight_fill);
         }

         h_a_e_Ap[kJ][ptVmin-1]->Fill(a_e_Ap[i], weight_fill);   
         h_a_pt_Ap[kJ][ptVmin-1]->Fill(a_pt_Ap[i], weight_fill);   
         h_a_eta_Ap[kJ][ptVmin-1]->Fill(a_eta_Ap[i], weight_fill);   
         h_a_phi_Ap[kJ][ptVmin-1]->Fill(a_phi_Ap[i], weight_fill);   
         h_a_e_Api[kJ][ptVmin-1]->Fill(a_e_Api[i], weight_fill);   
         h_a_pt_Api[kJ][ptVmin-1]->Fill(a_pt_Api[i], weight_fill);   
         h_a_eta_Api[kJ][ptVmin-1]->Fill(a_eta_Api[i], weight_fill);   
         h_a_phi_Api[kJ][ptVmin-1]->Fill(a_phi_Api[i], weight_fill);   
         h_a_pt_A[kJ][ptVmin-1]->Fill(a_pt_A[i], weight_fill);   
         h_a_eta_A[kJ][ptVmin-1]->Fill(a_eta_A[i], weight_fill);   
         h_a_phi_A[kJ][ptVmin-1]->Fill(a_phi_A[i], weight_fill);   
         h_a_im_A[kJ][ptVmin-1]->Fill(a_im_A[i], weight_fill);
         h_a_idSubproc_A[kJ][ptVmin-1]->Fill(g_idSubproc, weight_fill);

         if( a_gid_parent_A[i]!=0 ) a_pid_parent_A[i] = findPid( a_gid_parent_A[i] );
         h_a_pid_parent_A[kJ][ptVmin-1]->Fill(a_pid_parent_A[i], weight_fill);   

         h_a_dr_A[kJ][ptVmin-1]->Fill(a_dr_A[i], weight_fill);
         h_a_drParton_A[kJ][ptVmin-1]->Fill(a_drParton1_A[i],a_drParton2_A[i], weight_fill);
         //h_a_deta_A[kJ][ptVmin-1]->Fill(a_deta_A[i], weight_fill);   
         //h_a_dphi_A[kJ][ptVmin-1]->Fill(a_dphi_A[i], weight_fill);

         h_a_nFit_Ap[kJ][ptVmin-1]->Fill(a_nFit_Ap[i], weight_fill);
         h_a_dca_Ap[kJ][ptVmin-1]->Fill(a_dca_Ap[i], weight_fill);
         h_a_nFit_Api[kJ][ptVmin-1]->Fill(a_nFit_Api[i], weight_fill);
         h_a_dca_Api[kJ][ptVmin-1]->Fill(a_dca_Api[i], weight_fill);
         h_a_dl_A[kJ][ptVmin-1]->Fill(a_dl_A[i], weight_fill);
         h_a_dca2_A[kJ][ptVmin-1]->Fill(a_dca2_A[i], weight_fill);
         h_a_dcaV0_A[kJ][ptVmin-1]->Fill(a_dcaV0_A[i], weight_fill);

         int fParton = g_idParton1;
         if (a_drParton2_A[i]<a_drParton1_A[i])
         {
            fParton = g_idParton2;
         }
         h_a_fParton_A[kT][ptVmin-1]->Fill(fParton, weight_fill);
   
         if (a_drParton1_A[i]<1.0 || a_drParton2_A[i]<1.0)
         {
            int fPartonS = g_idParton1;
            if (a_drParton2_A[i]<a_drParton1_A[i])
            {
               fPartonS = g_idParton2;
            }
            h_a_fPartonS_A[kT][ptVmin-1]->Fill(fPartonS, weight_fill);
         }
      }

      for( int i=0; i<m_nL; ++i ){
         if(m_pt_L[i]<ptVmin ||m_pt_L[i]>=ptVmax ) {
             Abort("Err:m_L pt range out !!!");
         }
         //___Ldd_selection_cut_here____
         if(m_dca_Lp[i] > 200.0 ) continue;
         if(m_dca_Lpi[i] > 200.0 ) continue;
         if(m_dca_Lpi[i]>16 &&m_dca_Lp[i]<0.8 ) continue;
         if(m_dca_Lpi[i]>45 ) continue;
         if(m_crp_L[i]   < c_crp_min ) continue;
         if(m_dca_Lp[i]  < c_dca_min_proton ) continue;
         if(m_dca_Lpi[i] < c_dca_min_pion ) continue;
         if(m_dca2_L[i]  > c_dca2_max ) continue;
         if(m_dcaV0_L[i] > c_dcaV0_max ) continue;
         if(m_dl_L[i] < c_dl_min ) continue;
         TVector3 tPi;
         tPi.SetPtEtaPhi(m_pt_Lpi[i],m_eta_Lpi[i],m_phi_Lpi[i] );
         if( tPi.Mag() < c_P_min_pion ) continue;

         if( kJ ) {
            if(m_index_L[i]<0 ) continue;
            if(m_dr_L[i]<0 ||m_dr_L[i]>0.6 ) continue;
            int iJ =m_index_L[i];
            h_m_fz_L[ptVmin-1]->Fill(m_pt_L[i]/J_pt[iJ], weight_fill);
         }

         h_m_pt_Lp[kJ][ptVmin-1]->Fill(m_pt_Lp[i], weight_fill);   
         h_m_eta_Lp[kJ][ptVmin-1]->Fill(m_eta_Lp[i], weight_fill);   
         h_m_phi_Lp[kJ][ptVmin-1]->Fill(m_phi_Lp[i], weight_fill);   
         h_m_pt_Lpi[kJ][ptVmin-1]->Fill(m_pt_Lpi[i], weight_fill);   
         h_m_eta_Lpi[kJ][ptVmin-1]->Fill(m_eta_Lpi[i], weight_fill);   
         h_m_phi_Lpi[kJ][ptVmin-1]->Fill(m_phi_Lpi[i], weight_fill);     
         h_m_pt_L[kJ][ptVmin-1]->Fill(m_pt_L[i], weight_fill);   
         h_m_eta_L[kJ][ptVmin-1]->Fill(m_eta_L[i], weight_fill);   
         h_m_phi_L[kJ][ptVmin-1]->Fill(m_phi_L[i], weight_fill);   
         h_m_im_L[kJ][ptVmin-1]->Fill(m_im_L[i], weight_fill);   
         h_m_idSubproc_L[kJ][ptVmin-1]->Fill(g_idSubproc, weight_fill);

         h_m_dr_L[kJ][ptVmin-1]->Fill(m_dr_L[i], weight_fill); 
         h_m_drParton_L[kJ][ptVmin-1]->Fill(m_drParton1_L[i],a_drParton2_L[i], weight_fill);
         //h_m_deta_L[kJ][ptVmin-1]->Fill(m_deta_L[i], weight_fill);   
         //h_m_dphi_L[kJ][ptVmin-1]->Fill(m_dphi_L[i], weight_fill);

         h_m_dca_Lp[kJ][ptVmin-1]->Fill(m_dca_Lp[i], weight_fill);
         h_m_nSig_Lp[kJ][ptVmin-1]->Fill(m_nSigP_Lp[i], weight_fill);
         h_m_dca_Lpi[kJ][ptVmin-1]->Fill(m_dca_Lpi[i], weight_fill);
         h_m_nSig_Lpi[kJ][ptVmin-1]->Fill(m_nSigPi_Lpi[i], weight_fill);
         h_m_dl_L[kJ][ptVmin-1]->Fill(m_dl_L[i], weight_fill);
         h_m_dca2_L[kJ][ptVmin-1]->Fill(m_dca2_L[i], weight_fill);
         h_m_dcaV0_L[kJ][ptVmin-1]->Fill(m_dcaV0_L[i], weight_fill);

         int fParton = g_idParton1;
         if (m_drParton2_L[i]<m_drParton1_L[i])
         {
            fParton = g_idParton2;
         }
         h_m_fParton_L[kT][ptVmin-1]->Fill(fParton, weight_fill);
   
         if (m_drParton1_L[i]<1.0 || m_drParton2_L[i]<1.0)
         {
            int fPartonS = g_idParton1;
            if (m_drParton2_L[i]<m_drParton1_L[i])
            {
               fPartonS = g_idParton2;
            }
            h_m_fPartonS_L[kT][ptVmin-1]->Fill(fPartonS, weight_fill);
         }
      }

      for( int i=0; i<m_nA; ++i ){
         if(m_pt_A[i]<ptVmin ||m_pt_A[i]>=ptVmax ) {
             Abort("Err:m_A pt range out !!!");
         }
         //___Add_selection_cut_here____
         if(m_dca_Ap[i] > 200.0 ) continue;
         if(m_dca_Api[i] > 200.0 ) continue;
         if(m_dca_Ap[i]>20 ) continue;
         if(m_dca_Api[i]>20 && m_dca_Ap[i]<0.8 ) continue;
         if(m_crp_A[i]   < c_crp_min ) continue;
         if(m_dca_Ap[i]  < c_dca_min_proton ) continue;
         if(m_dca_Api[i] < c_dca_min_pion ) continue;
         if(m_dca2_A[i]  > c_dca2_max ) continue;
         if(m_dcaV0_A[i] > c_dcaV0_max ) continue;
         if(m_dl_A[i] < c_dl_min ) continue;
         TVector3 tPi;
         tPi.SetPtEtaPhi(m_pt_Api[i],m_eta_Api[i],m_phi_Api[i] );
         if( tPi.Mag() < c_P_min_pion ) continue;

         if( kJ ) {
            if(m_index_A[i]<0 ) continue;
            if(m_dr_A[i]<0 ||m_dr_A[i]>0.6 ) continue;
            int iJ =m_index_A[i];
            h_m_fz_A[ptVmin-1]->Fill(m_pt_A[i]/J_pt[iJ], weight_fill);
         }

         h_m_pt_Ap[kJ][ptVmin-1]->Fill(m_pt_Ap[i], weight_fill);   
         h_m_eta_Ap[kJ][ptVmin-1]->Fill(m_eta_Ap[i], weight_fill);   
         h_m_phi_Ap[kJ][ptVmin-1]->Fill(m_phi_Ap[i], weight_fill);   
         h_m_pt_Api[kJ][ptVmin-1]->Fill(m_pt_Api[i], weight_fill);   
         h_m_eta_Api[kJ][ptVmin-1]->Fill(m_eta_Api[i], weight_fill);   
         h_m_phi_Api[kJ][ptVmin-1]->Fill(m_phi_Api[i], weight_fill);     
         h_m_pt_A[kJ][ptVmin-1]->Fill(m_pt_A[i], weight_fill);   
         h_m_eta_A[kJ][ptVmin-1]->Fill(m_eta_A[i], weight_fill);   
         h_m_phi_A[kJ][ptVmin-1]->Fill(m_phi_A[i], weight_fill);   
         h_m_im_A[kJ][ptVmin-1]->Fill(m_im_A[i], weight_fill);   
         h_m_idSubproc_A[kJ][ptVmin-1]->Fill(g_idSubproc, weight_fill);

         h_m_dr_A[kJ][ptVmin-1]->Fill(m_dr_A[i], weight_fill); 
         h_m_drParton_A[kJ][ptVmin-1]->Fill(m_drParton1_A[i],a_drParton2_A[i], weight_fill);
         //h_m_deta_A[kJ][ptVmin-1]->Fill(m_deta_A[i], weight_fill);   
         //h_m_dphi_A[kJ][ptVmin-1]->Fill(m_dphi_A[i], weight_fill);

         h_m_dca_Ap[kJ][ptVmin-1]->Fill(m_dca_Ap[i], weight_fill);
         h_m_nSig_Ap[kJ][ptVmin-1]->Fill(m_nSigP_Ap[i], weight_fill);
         h_m_dca_Api[kJ][ptVmin-1]->Fill(m_dca_Api[i], weight_fill);
         h_m_nSig_Api[kJ][ptVmin-1]->Fill(m_nSigPi_Api[i], weight_fill);
         h_m_dl_A[kJ][ptVmin-1]->Fill(m_dl_A[i], weight_fill);
         h_m_dca2_A[kJ][ptVmin-1]->Fill(m_dca2_A[i], weight_fill);
         h_m_dcaV0_A[kJ][ptVmin-1]->Fill(m_dcaV0_A[i], weight_fill);

         int fParton = g_idParton1;
         if (m_drParton2_A[i]<m_drParton1_A[i])
         {
            fParton = g_idParton2;
         }
         h_m_fParton_A[kT][ptVmin-1]->Fill(fParton, weight_fill);
   
         if (m_drParton1_A[i]<1.0 || m_drParton2_A[i]<1.0)
         {
            int fPartonS = g_idParton1;
            if (m_drParton2_A[i]<m_drParton1_A[i])
            {
               fPartonS = g_idParton2;
            }
            h_m_fPartonS_A[kT][ptVmin-1]->Fill(fPartonS, weight_fill);
         }
      }

      for( int i=0; i<m_nL; ++i ){
         if(m_pt_L[i]<ptVmin ||m_pt_L[i]>=ptVmax ) {
             Abort("Err:m_L pt range out !!!");
         }
         int P_tag=0;
         int Pi_tag=0;
         for (int j = 0; j < g_nL; ++j) {
            if (m_idT_Lp[i] == g_key_Lp[j]) P_tag=1;
            if (m_idT_Lpi[i] == g_key_Lpi[i]) Pi_tag=1;
         }
         if (!(P_tag*Pi_tag)) continue;
         //___Ldd_selection_cut_here____
         if(m_dca_Lp[i] > 200.0 ) continue;
         if(m_dca_Lpi[i] > 200.0 ) continue;
         if(m_dca_Lpi[i]>16 &&m_dca_Lp[i]<0.8 ) continue;
         if(m_dca_Lpi[i]>45 ) continue;
         if(m_crp_L[i]   < c_crp_min ) continue;
         if(m_dca_Lp[i]  < c_dca_min_proton ) continue;
         if(m_dca_Lpi[i] < c_dca_min_pion ) continue;
         if(m_dca2_L[i]  > c_dca2_max ) continue;
         if(m_dcaV0_L[i] > c_dcaV0_max ) continue;
         if(m_dl_L[i] < c_dl_min ) continue;
         TVector3 tPi;
         tPi.SetPtEtaPhi(m_pt_Lpi[i],m_eta_Lpi[i],m_phi_Lpi[i] );
         if( tPi.Mag() < c_P_min_pion ) continue;

         if( kJ ) {
            if(m_index_L[i]<0 ) continue;
            if(m_dr_L[i]<0 ||m_dr_L[i]>0.6 ) continue;
            int iJ =m_index_L[i];
            h_t_fz_L[ptVmin-1]->Fill(m_pt_L[i]/J_pt[iJ], weight_fill);
         }

         h_t_pt_Lp[kJ][ptVmin-1]->Fill(m_pt_Lp[i], weight_fill);   
         h_t_eta_Lp[kJ][ptVmin-1]->Fill(m_eta_Lp[i], weight_fill);   
         h_t_phi_Lp[kJ][ptVmin-1]->Fill(m_phi_Lp[i], weight_fill);   
         h_t_pt_Lpi[kJ][ptVmin-1]->Fill(m_pt_Lpi[i], weight_fill);   
         h_t_eta_Lpi[kJ][ptVmin-1]->Fill(m_eta_Lpi[i], weight_fill);   
         h_t_phi_Lpi[kJ][ptVmin-1]->Fill(m_phi_Lpi[i], weight_fill);     
         h_t_pt_L[kJ][ptVmin-1]->Fill(m_pt_L[i], weight_fill);   
         h_t_eta_L[kJ][ptVmin-1]->Fill(m_eta_L[i], weight_fill);   
         h_t_phi_L[kJ][ptVmin-1]->Fill(m_phi_L[i], weight_fill);   
         h_t_im_L[kJ][ptVmin-1]->Fill(m_im_L[i], weight_fill);   
         h_t_idSubproc_L[kJ][ptVmin-1]->Fill(g_idSubproc, weight_fill);  

         h_t_dr_L[kJ][ptVmin-1]->Fill(m_dr_L[i], weight_fill); 
         h_t_drParton_L[kJ][ptVmin-1]->Fill(m_drParton1_L[i],a_drParton2_L[i], weight_fill);
         //h_t_deta_L[kJ][ptVmin-1]->Fill(m_deta_L[i], weight_fill);   
         //h_t_dphi_L[kJ][ptVmin-1]->Fill(m_dphi_L[i], weight_fill);

         h_t_dca_Lp[kJ][ptVmin-1]->Fill(m_dca_Lp[i], weight_fill);
         h_t_nSig_Lp[kJ][ptVmin-1]->Fill(m_nSigP_Lp[i], weight_fill);
         h_t_dca_Lpi[kJ][ptVmin-1]->Fill(m_dca_Lpi[i], weight_fill);
         h_t_nSig_Lpi[kJ][ptVmin-1]->Fill(m_nSigPi_Lpi[i], weight_fill);
         h_t_dl_L[kJ][ptVmin-1]->Fill(m_dl_L[i], weight_fill);
         h_t_dca2_L[kJ][ptVmin-1]->Fill(m_dca2_L[i], weight_fill);
         h_t_dcaV0_L[kJ][ptVmin-1]->Fill(m_dcaV0_L[i], weight_fill);

         int fParton = g_idParton1;
         if (m_drParton2_L[i]<m_drParton1_L[i])
         {
            fParton = g_idParton2;
         }
         h_t_fParton_L[kT][ptVmin-1]->Fill(fParton, weight_fill);
   
         if (m_drParton1_L[i]<1.0 || m_drParton2_L[i]<1.0)
         {
            int fPartonS = g_idParton1;
            if (m_drParton2_L[i]<m_drParton1_L[i])
            {
               fPartonS = g_idParton2;
            }
            h_t_fPartonS_L[kT][ptVmin-1]->Fill(fPartonS, weight_fill);
         }
      }

      for( int i=0; i<m_nA; ++i ){
         if(m_pt_A[i]<ptVmin ||m_pt_A[i]>=ptVmax ) {
             Abort("Err:m_A pt range out !!!");
         }
         int P_tag=0;
         int Pi_tag=0;
         for (int j = 0; j < g_nL; ++j) {
            if (m_idT_Ap[i] == g_key_Ap[j]) P_tag=1;
            if (m_idT_Api[i] == g_key_Api[i]) Pi_tag=1;
         }
         if (!(P_tag*Pi_tag)) continue;
         //___Add_selection_cut_here____
         if(m_dca_Ap[i] > 200.0 ) continue;
         if(m_dca_Api[i] > 200.0 ) continue;
         if(m_dca_Ap[i]>20 ) continue;
         if(m_dca_Api[i]>20 && m_dca_Ap[i]<0.8 ) continue;
         if(m_crp_A[i]   < c_crp_min ) continue;
         if(m_dca_Ap[i]  < c_dca_min_proton ) continue;
         if(m_dca_Api[i] < c_dca_min_pion ) continue;
         if(m_dca2_A[i]  > c_dca2_max ) continue;
         if(m_dcaV0_A[i] > c_dcaV0_max ) continue;
         if(m_dl_A[i] < c_dl_min ) continue;
         TVector3 tPi;
         tPi.SetPtEtaPhi(m_pt_Api[i],m_eta_Api[i],m_phi_Api[i] );
         if( tPi.Mag() < c_P_min_pion ) continue;

         if( kJ ) {
            if(m_index_A[i]<0 ) continue;
            if(m_dr_A[i]<0 ||m_dr_A[i]>0.6 ) continue;
            int iJ =m_index_A[i];
            h_t_fz_A[ptVmin-1]->Fill(m_pt_A[i]/J_pt[iJ], weight_fill);
         }

         h_t_pt_Ap[kJ][ptVmin-1]->Fill(m_pt_Ap[i], weight_fill);   
         h_t_eta_Ap[kJ][ptVmin-1]->Fill(m_eta_Ap[i], weight_fill);   
         h_t_phi_Ap[kJ][ptVmin-1]->Fill(m_phi_Ap[i], weight_fill);   
         h_t_pt_Api[kJ][ptVmin-1]->Fill(m_pt_Api[i], weight_fill);   
         h_t_eta_Api[kJ][ptVmin-1]->Fill(m_eta_Api[i], weight_fill);   
         h_t_phi_Api[kJ][ptVmin-1]->Fill(m_phi_Api[i], weight_fill);     
         h_t_pt_A[kJ][ptVmin-1]->Fill(m_pt_A[i], weight_fill);   
         h_t_eta_A[kJ][ptVmin-1]->Fill(m_eta_A[i], weight_fill);   
         h_t_phi_A[kJ][ptVmin-1]->Fill(m_phi_A[i], weight_fill);   
         h_t_im_A[kJ][ptVmin-1]->Fill(m_im_A[i], weight_fill);   
         h_t_idSubproc_A[kJ][ptVmin-1]->Fill(g_idSubproc, weight_fill);

         h_t_dr_A[kJ][ptVmin-1]->Fill(m_dr_A[i], weight_fill); 
         h_t_drParton_A[kJ][ptVmin-1]->Fill(m_drParton1_A[i],a_drParton2_A[i], weight_fill);
         //h_t_deta_A[kJ][ptVmin-1]->Fill(m_deta_A[i], weight_fill);   
         //h_t_dphi_A[kJ][ptVmin-1]->Fill(m_dphi_A[i], weight_fill);

         h_t_dca_Ap[kJ][ptVmin-1]->Fill(m_dca_Ap[i], weight_fill);
         h_t_nSig_Ap[kJ][ptVmin-1]->Fill(m_nSigP_Ap[i], weight_fill);
         h_t_dca_Api[kJ][ptVmin-1]->Fill(m_dca_Api[i], weight_fill);
         h_t_nSig_Api[kJ][ptVmin-1]->Fill(m_nSigPi_Api[i], weight_fill);
         h_t_dl_A[kJ][ptVmin-1]->Fill(m_dl_A[i], weight_fill);
         h_t_dca2_A[kJ][ptVmin-1]->Fill(m_dca2_A[i], weight_fill);
         h_t_dcaV0_A[kJ][ptVmin-1]->Fill(m_dcaV0_A[i], weight_fill);

         int fParton = g_idParton1;
         if (m_drParton2_A[i]<m_drParton1_A[i])
         {
            fParton = g_idParton2;
         }
         h_t_fParton_A[kT][ptVmin-1]->Fill(fParton, weight_fill);
   
         if (m_drParton1_A[i]<1.0 || m_drParton2_A[i]<1.0)
         {
            int fPartonS = g_idParton1;
            if (m_drParton2_A[i]<m_drParton1_A[i])
            {
               fPartonS = g_idParton2;
            }
            h_t_fPartonS_A[kT][ptVmin-1]->Fill(fPartonS, weight_fill);
         }
      }
   }
   return kTRUE;
}

void toHist::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void toHist::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
