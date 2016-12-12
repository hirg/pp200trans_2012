//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 27 17:56:16 2016 by ROOT version 5.34/30
// from TTree SimuTree/Simulation Tree
// found on file: ptH_4_5/test_v0.root
//////////////////////////////////////////////////////////

#ifndef v0Tree_reader_h
#define v0Tree_reader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class v0Tree_reader {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   int           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   int           g_runN;
   int           g_evtN;
   int           g_idSubproc;
   double        g_pvx;
   double        g_pvy;
   double        g_pvz;
   int           g_pv_geantProc;
   int           g_pv_geantMedium;
   int           g_pv_generatorProc;
   int           g_pv_key;
   int           g_nJets;
   double        g_impactPar;
   double        g_phiRP;
   
   int           g_idParton1;
   double        g_pxParton1;
   double        g_pyParton1;
   double        g_pzParton1;
   double        g_mParton1;
   double        g_eParton1;
   int           g_idParton2;
   double        g_pxParton2;
   double        g_pyParton2;
   double        g_pzParton2;
   double        g_mParton2;
   double        g_eParton2;

   int           g_nL;
   int           g_pid_Lp[100];   //[g_nL]
   int           g_gid_Lp[100];   //[g_nL]
   int           g_key_Lp[100];   //[g_nL]
   double        g_e_Lp[100];   //[g_nL]
   double        g_pt_Lp[100];   //[g_nL]
   double        g_eta_Lp[100];   //[g_nL]
   double        g_phi_Lp[100];   //[g_nL]
   double        g_im_Lp[100];   //[g_nL]
   int           g_pid_Lpi[100];   //[g_nL]
   int           g_gid_Lpi[100];   //[g_nL]
   int           g_key_Lpi[100];   //[g_nL]
   double        g_e_Lpi[100];   //[g_nL]
   double        g_pt_Lpi[100];   //[g_nL]
   double        g_eta_Lpi[100];   //[g_nL]
   double        g_phi_Lpi[100];   //[g_nL]
   double        g_im_Lpi[100];   //[g_nL]
   double        g_x_stop_L[100];   //[g_nL]
   double        g_y_stop_L[100];   //[g_nL]
   double        g_z_stop_L[100];   //[g_nL]
   int           g_pid_L[100];   //[g_nL]
   int           g_gid_L[100];   //[g_nL]
   int           g_key_L[100];   //[g_nL]
   double        g_e_L[100];   //[g_nL]
   double        g_pt_L[100];   //[g_nL]
   double        g_eta_L[100];   //[g_nL]
   double        g_phi_L[100];   //[g_nL]
   double        g_im_L[100];   //[g_nL]
   double        g_x_start_L[100];   //[g_nL]
   double        g_y_start_L[100];   //[g_nL]
   double        g_z_start_L[100];   //[g_nL]
   int           g_geantProc_start_L[100];   //[g_nL]
   int           g_geantMedium_start_L[100];   //[g_nL]
   int           g_generatorProc_start_L[100];   //[g_nL]
   int           g_key_start_L[100];   //[g_nL]
   int           g_pid_parent_L[100];   //[g_nL]
   int           g_gid_parent_L[100];   //[g_nL]
   int           g_key_parent_L[100];   //[g_nL]

   int           g_nA;
   int           g_pid_Ap[100];   //[g_nA]
   int           g_gid_Ap[100];   //[g_nA]
   int           g_key_Ap[100];   //[g_nA]
   double        g_e_Ap[100];   //[g_nA]
   double        g_pt_Ap[100];   //[g_nA]
   double        g_eta_Ap[100];   //[g_nA]
   double        g_phi_Ap[100];   //[g_nA]
   double        g_im_Ap[100];   //[g_nA]
   int           g_pid_Api[100];   //[g_nA]
   int           g_gid_Api[100];   //[g_nA]
   int           g_key_Api[100];   //[g_nA]
   double        g_e_Api[100];   //[g_nA]
   double        g_pt_Api[100];   //[g_nA]
   double        g_eta_Api[100];   //[g_nA]
   double        g_phi_Api[100];   //[g_nA]
   double        g_im_Api[100];   //[g_nA]
   double        g_x_stop_A[100];   //[g_nA]
   double        g_y_stop_A[100];   //[g_nA]
   double        g_z_stop_A[100];   //[g_nA]
   int           g_pid_A[100];   //[g_nA]
   int           g_gid_A[100];   //[g_nA]
   int           g_key_A[100];   //[g_nA]
   double        g_e_A[100];   //[g_nA]
   double        g_pt_A[100];   //[g_nA]
   double        g_eta_A[100];   //[g_nA]
   double        g_phi_A[100];   //[g_nA]
   double        g_im_A[100];   //[g_nA]
   double        g_x_start_A[100];   //[g_nA]
   double        g_y_start_A[100];   //[g_nA]
   double        g_z_start_A[100];   //[g_nA]
   int           g_geantProc_start_A[100];   //[g_nA]
   int           g_geantMedium_start_A[100];   //[g_nA]
   int           g_generatorProc_start_A[100];   //[g_nA]
   int           g_key_start_A[100];   //[g_nA]
   int           g_pid_parent_A[100];   //[g_nA]
   int           g_gid_parent_A[100];   //[g_nA]
   int           g_key_parent_A[100];   //[g_nA]

   int           g_nK;
   int           g_pid_Kp[100];   //[g_nK]
   int           g_gid_Kp[100];   //[g_nK]
   int           g_key_Kp[100];   //[g_nK]
   double        g_e_Kp[100];   //[g_nK]
   double        g_pt_Kp[100];   //[g_nK]
   double        g_eta_Kp[100];   //[g_nK]
   double        g_phi_Kp[100];   //[g_nK]
   double        g_im_Kp[100];   //[g_nK]
   int           g_pid_Kpi[100];   //[g_nK]
   int           g_gid_Kpi[100];   //[g_nK]
   int           g_key_Kpi[100];   //[g_nK]
   double        g_e_Kpi[100];   //[g_nK]
   double        g_pt_Kpi[100];   //[g_nK]
   double        g_eta_Kpi[100];   //[g_nK]
   double        g_phi_Kpi[100];   //[g_nK]
   double        g_im_Kpi[100];   //[g_nK]
   double        g_x_stop_K[100];   //[g_nK]
   double        g_y_stop_K[100];   //[g_nK]
   double        g_z_stop_K[100];   //[g_nK]
   int           g_pid_K[100];   //[g_nK]
   int           g_gid_K[100];   //[g_nK]
   int           g_key_K[100];   //[g_nK]
   double        g_e_K[100];   //[g_nK]
   double        g_pt_K[100];   //[g_nK]
   double        g_eta_K[100];   //[g_nK]
   double        g_phi_K[100];   //[g_nK]
   double        g_im_K[100];   //[g_nK]
   double        g_x_start_K[100];   //[g_nK]
   double        g_y_start_K[100];   //[g_nK]
   double        g_z_start_K[100];   //[g_nK]
   int           g_geantProc_start_K[100];   //[g_nK]
   int           g_geantMedium_start_K[100];   //[g_nK]
   int           g_generatorProc_start_K[100];   //[g_nK]
   int           g_key_start_K[100];   //[g_nK]
   int           g_pid_parent_K[100];   //[g_nK]
   int           g_gid_parent_K[100];   //[g_nK]
   int           g_key_parent_K[100];   //[g_nK]

   int           a_nL;
   int           a_pid_Lp[100];   //[a_nL]
   int           a_gid_Lp[100];   //[a_nL]
   int           a_key_Lp[100];   //[a_nL]
   double        a_e_Lp[100];   //[a_nL]
   double        a_pt_Lp[100];   //[a_nL]
   double        a_eta_Lp[100];   //[a_nL]
   double        a_phi_Lp[100];   //[a_nL]
   double        a_dca_Lp[100];   //[a_nL]
   int           a_flag_Lp[100];   //[a_nL]
   int           a_nFit_Lp[100];   //[a_nL]
   double        a_ratio_Lp[100];   //[a_nL]
   int           a_pid_Lpi[100];   //[a_nL]
   int           a_gid_Lpi[100];   //[a_nL]
   int           a_key_Lpi[100];   //[a_nL]
   double        a_e_Lpi[100];   //[a_nL]
   double        a_pt_Lpi[100];   //[a_nL]
   double        a_eta_Lpi[100];   //[a_nL]
   double        a_phi_Lpi[100];   //[a_nL]
   double        a_dca_Lpi[100];   //[a_nL]
   int           a_flag_Lpi[100];   //[a_nL]
   int           a_nFit_Lpi[100];   //[a_nL]
   double        a_ratio_Lpi[100];   //[a_nL]
   double        a_x_stop_L[100];   //[a_nL]
   double        a_y_stop_L[100];   //[a_nL]
   double        a_z_stop_L[100];   //[a_nL]
   double        a_pt_L[100];   //[a_nL]
   double        a_eta_L[100];   //[a_nL]
   double        a_phi_L[100];   //[a_nL]
   double        a_im_L[100];   //[a_nL]
   double        a_dl_L[100];   //[a_nL]
   double        a_dca2_L[100];   //[a_nL]
   double        a_dcaV0_L[100];   //[a_nL]
   double        a_crp_L[100];   //[a_nL]
   int           a_pid_parent_L[100];   //[a_nL]
   int           a_gid_parent_L[100];   //[a_nL]
   int           a_key_parent_L[100];   //[a_nL]

   int           a_nA;
   int           a_pid_Ap[100];   //[a_nA]
   int           a_gid_Ap[100];   //[a_nA]
   int           a_key_Ap[100];   //[a_nA]
   double        a_e_Ap[100];   //[a_nA]
   double        a_pt_Ap[100];   //[a_nA]
   double        a_eta_Ap[100];   //[a_nA]
   double        a_phi_Ap[100];   //[a_nA]
   double        a_dca_Ap[100];   //[a_nA]
   int           a_flag_Ap[100];   //[a_nA]
   int           a_nFit_Ap[100];   //[a_nA]
   double        a_ratio_Ap[100];   //[a_nA]
   int           a_pid_Api[100];   //[a_nA]
   int           a_gid_Api[100];   //[a_nA]
   int           a_key_Api[100];   //[a_nA]
   double        a_e_Api[100];   //[a_nA]
   double        a_pt_Api[100];   //[a_nA]
   double        a_eta_Api[100];   //[a_nA]
   double        a_phi_Api[100];   //[a_nA]
   double        a_dca_Api[100];   //[a_nA]
   int           a_flag_Api[100];   //[a_nA]
   int           a_nFit_Api[100];   //[a_nA]
   double        a_ratio_Api[100];   //[a_nA]
   double        a_x_stop_A[100];   //[a_nA]
   double        a_y_stop_A[100];   //[a_nA]
   double        a_z_stop_A[100];   //[a_nA]
   double        a_pt_A[100];   //[a_nA]
   double        a_eta_A[100];   //[a_nA]
   double        a_phi_A[100];   //[a_nA]
   double        a_im_A[100];   //[a_nA]
   double        a_dl_A[100];   //[a_nA]
   double        a_dca2_A[100];   //[a_nA]
   double        a_dcaV0_A[100];   //[a_nA]
   double        a_crp_A[100];   //[a_nA]
   int           a_pid_parent_A[100];   //[a_nA]
   int           a_gid_parent_A[100];   //[a_nA]
   int           a_key_parent_A[100];   //[a_nA]

   int           a_nK;
   int           a_pid_Kp[100];   //[a_nK]
   int           a_gid_Kp[100];   //[a_nK]
   int           a_key_Kp[100];   //[a_nK]
   double        a_e_Kp[100];   //[a_nK]
   double        a_pt_Kp[100];   //[a_nK]
   double        a_eta_Kp[100];   //[a_nK]
   double        a_phi_Kp[100];   //[a_nK]
   double        a_dca_Kp[100];   //[a_nK]
   int           a_flag_Kp[100];   //[a_nK]
   int           a_nFit_Kp[100];   //[a_nK]
   double        a_ratio_Kp[100];   //[a_nK]
   int           a_pid_Kpi[100];   //[a_nK]
   int           a_gid_Kpi[100];   //[a_nK]
   int           a_key_Kpi[100];   //[a_nK]
   double        a_e_Kpi[100];   //[a_nK]
   double        a_pt_Kpi[100];   //[a_nK]
   double        a_eta_Kpi[100];   //[a_nK]
   double        a_phi_Kpi[100];   //[a_nK]
   double        a_dca_Kpi[100];   //[a_nK]
   int           a_flag_Kpi[100];   //[a_nK]
   int           a_nFit_Kpi[100];   //[a_nK]
   double        a_ratio_Kpi[100];   //[a_nK]
   double        a_x_stop_K[100];   //[a_nK]
   double        a_y_stop_K[100];   //[a_nK]
   double        a_z_stop_K[100];   //[a_nK]
   double        a_pt_K[100];   //[a_nK]
   double        a_eta_K[100];   //[a_nK]
   double        a_phi_K[100];   //[a_nK]
   double        a_im_K[100];   //[a_nK]
   double        a_dl_K[100];   //[a_nK]
   double        a_dca2_K[100];   //[a_nK]
   double        a_dcaV0_K[100];   //[a_nK]
   double        a_crp_K[100];   //[a_nK]
   int           a_pid_parent_K[100];   //[a_nK]
   int           a_gid_parent_K[100];   //[a_nK]
   int           a_key_parent_K[100];   //[a_nK]

   int           trig[8];
   int           trig_sub[5];
   int           m_runN;
   int           m_evtN;
   int           magn;
   double        m_pvx;
   double        m_pvy;
   double        m_pvz;
   int           m_nL;
   double        m_dEdx_Lp[100];   //[m_nL]
   double        m_nSigP_Lp[100];   //[m_nL]
   double        m_nSigPi_Lp[100];   //[m_nL]
   double        m_pt_Lp[100];   //[m_nL]
   double        m_eta_Lp[100];   //[m_nL]
   double        m_phi_Lp[100];   //[m_nL]
   double        m_dca_Lp[100];   //[m_nL]
   int           m_qaT_Lp[100];   //[m_nL]
   int           m_idT_Lp[100];   //[m_nL]
   double        m_tof_Lp[100];   //[m_nL]
   double        m_beta_Lp[100];   //[m_nL]
   double        m_dEdx_Lpi[100];   //[m_nL]
   double        m_nSigP_Lpi[100];   //[m_nL]
   double        m_nSigPi_Lpi[100];   //[m_nL]
   double        m_pt_Lpi[100];   //[m_nL]
   double        m_eta_Lpi[100];   //[m_nL]
   double        m_phi_Lpi[100];   //[m_nL]
   double        m_dca_Lpi[100];   //[m_nL]
   int           m_qaT_Lpi[100];   //[m_nL]
   int           m_idT_Lpi[100];   //[m_nL]
   double        m_tof_Lpi[100];   //[m_nL]
   double        m_beta_Lpi[100];   //[m_nL]
   double        m_dca2_L[100];   //[m_nL]
   double        m_dcaV0_L[100];   //[m_nL]
   double        m_crp_L[100];   //[m_nL]
   double        m_dl_L[100];   //[m_nL]
   double        m_im_L[100];   //[m_nL]
   double        m_V0x_L[100];   //[m_nL]
   double        m_V0y_L[100];   //[m_nL]
   double        m_V0z_L[100];   //[m_nL]
   double        m_pt_L[100];   //[m_nL]
   double        m_eta_L[100];   //[m_nL]
   double        m_phi_L[100];   //[m_nL]
   int           m_nA;
   double        m_dEdx_Ap[100];   //[m_nA]
   double        m_nSigP_Ap[100];   //[m_nA]
   double        m_nSigPi_Ap[100];   //[m_nA]
   double        m_pt_Ap[100];   //[m_nA]
   double        m_eta_Ap[100];   //[m_nA]
   double        m_phi_Ap[100];   //[m_nA]
   double        m_dca_Ap[100];   //[m_nA]
   int           m_qaT_Ap[100];   //[m_nA]
   int           m_idT_Ap[100];   //[m_nA]
   int           m_tof_Ap[100];   //[m_nA]
   double        m_beta_Ap[100];   //[m_nA]
   double        m_dEdx_Api[100];   //[m_nA]
   double        m_nSigP_Api[100];   //[m_nA]
   double        m_nSigPi_Api[100];   //[m_nA]
   double        m_pt_Api[100];   //[m_nA]
   double        m_eta_Api[100];   //[m_nA]
   double        m_phi_Api[100];   //[m_nA]
   double        m_dca_Api[100];   //[m_nA]
   int           m_qaT_Api[100];   //[m_nA]
   int           m_idT_Api[100];   //[m_nA]
   int           m_tof_Api[100];   //[m_nA]
   double        m_beta_Api[100];   //[m_nA]
   double        m_dca2_A[100];   //[m_nA]
   double        m_dcaV0_A[100];   //[m_nA]
   double        m_crp_A[100];   //[m_nA]
   double        m_dl_A[100];   //[m_nA]
   double        m_im_A[100];   //[m_nA]
   double        m_V0x_A[100];   //[m_nA]
   double        m_V0y_A[100];   //[m_nA]
   double        m_V0z_A[100];   //[m_nA]
   double        m_pt_A[100];   //[m_nA]
   double        m_eta_A[100];   //[m_nA]
   double        m_phi_A[100];   //[m_nA]
   int           m_nK;
   double        m_dEdx_Kp[100];   //[m_nK]
   double        m_nSigP_Kp[100];   //[m_nK]
   double        m_nSigPi_Kp[100];   //[m_nK]
   double        m_pt_Kp[100];   //[m_nK]
   double        m_eta_Kp[100];   //[m_nK]
   double        m_phi_Kp[100];   //[m_nK]
   double        m_dca_Kp[100];   //[m_nK]
   int           m_qaT_Kp[100];   //[m_nK]
   int           m_idT_Kp[100];   //[m_nK]
   int           m_tof_Kp[100];   //[m_nK]
   double        m_beta_Kp[100];   //[m_nK]
   double        m_dEdx_Kpi[100];   //[m_nK]
   double        m_nSigP_Kpi[100];   //[m_nK]
   double        m_nSigPi_Kpi[100];   //[m_nK]
   double        m_pt_Kpi[100];   //[m_nK]
   double        m_eta_Kpi[100];   //[m_nK]
   double        m_phi_Kpi[100];   //[m_nK]
   double        m_dca_Kpi[100];   //[m_nK]
   int           m_qaT_Kpi[100];   //[m_nK]
   int           m_idT_Kpi[100];   //[m_nK]
   int           m_tof_Kpi[100];   //[m_nK]
   double        m_beta_Kpi[100];   //[m_nK]
   double        m_dca2_K[100];   //[m_nK]
   double        m_dcaV0_K[100];   //[m_nK]
   double        m_crp_K[100];   //[m_nK]
   double        m_dl_K[100];   //[m_nK]
   double        m_im_K[100];   //[m_nK]
   double        m_V0x_K[100];   //[m_nK]
   double        m_V0y_K[100];   //[m_nK]
   double        m_V0z_K[100];   //[m_nK]
   double        m_pt_K[100];   //[m_nK]
   double        m_eta_K[100];   //[m_nK]
   double        m_phi_K[100];   //[m_nK]

   // List of branches
   TBranch        *b_g_runN;   //!
   TBranch        *b_g_evtN;   //!
   TBranch        *b_g_idSubproc;   //!
   TBranch        *b_g_pvx;   //!
   TBranch        *b_g_pvy;   //!
   TBranch        *b_g_pvz;   //!
   TBranch        *b_g_pv_geantProc;   //!
   TBranch        *b_g_pv_geantMedium;   //!
   TBranch        *b_g_pv_generatorProc;   //!
   TBranch        *b_g_pv_key;   //!
   TBranch        *b_g_nJets;   //!
   TBranch        *b_g_impactPar;
   TBranch        *b_g_phiRP;

   TBranch        *b_g_idParton1;
   TBranch        *b_g_pxParton1;
   TBranch        *b_g_pyParton1;
   TBranch        *b_g_pzParton1;
   TBranch        *b_g_mParton1;
   TBranch        *b_g_eParton1;
   TBranch        *b_g_idParton2;
   TBranch        *b_g_pxParton2;
   TBranch        *b_g_pyParton2;
   TBranch        *b_g_pzParton2;
   TBranch        *b_g_mParton2;
   TBranch        *b_g_eParton2;

   TBranch        *b_g_nL;   //!
   TBranch        *b_g_pid_Lp;   //!
   TBranch        *b_g_gid_Lp;   //!
   TBranch        *b_g_key_Lp;   //!
   TBranch        *b_g_e_Lp;   //!
   TBranch        *b_g_pt_Lp;   //!
   TBranch        *b_g_eta_Lp;   //!
   TBranch        *b_g_phi_Lp;   //!
   TBranch        *b_g_im_Lp;   //!
   TBranch        *b_g_pid_Lpi;   //!
   TBranch        *b_g_gid_Lpi;   //!
   TBranch        *b_g_key_Lpi;   //!
   TBranch        *b_g_e_Lpi;   //!
   TBranch        *b_g_pt_Lpi;   //!
   TBranch        *b_g_eta_Lpi;   //!
   TBranch        *b_g_phi_Lpi;   //!
   TBranch        *b_g_im_Lpi;   //!
   TBranch        *b_g_x_stop_L;   //!
   TBranch        *b_g_y_stop_L;   //!
   TBranch        *b_g_z_stop_L;   //!
   TBranch        *b_g_pid_L;   //!
   TBranch        *b_g_gid_L;   //!
   TBranch        *b_g_key_L;   //!
   TBranch        *b_g_e_L;   //!
   TBranch        *b_g_pt_L;   //!
   TBranch        *b_g_eta_L;   //!
   TBranch        *b_g_phi_L;   //!
   TBranch        *b_g_im_L;   //!
   TBranch        *b_g_x_start_L;   //!
   TBranch        *b_g_y_start_L;   //!
   TBranch        *b_g_z_start_L;   //!
   TBranch        *b_g_geantProc_start_L;   //!
   TBranch        *b_g_geantMedium_start_L;   //!
   TBranch        *b_g_generatorProc_start_L;   //!
   TBranch        *b_g_key_start_L;   //!
   TBranch        *b_g_pid_parent_L;   //!
   TBranch        *b_g_gid_parent_L;   //!
   TBranch        *b_g_key_parent_L;   //!

   TBranch        *b_g_nA;   //!
   TBranch        *b_g_pid_Ap;   //!
   TBranch        *b_g_gid_Ap;   //!
   TBranch        *b_g_key_Ap;   //!
   TBranch        *b_g_e_Ap;   //!
   TBranch        *b_g_pt_Ap;   //!
   TBranch        *b_g_eta_Ap;   //!
   TBranch        *b_g_phi_Ap;   //!
   TBranch        *b_g_im_Ap;   //!
   TBranch        *b_g_pid_Api;   //!
   TBranch        *b_g_gid_Api;   //!
   TBranch        *b_g_key_Api;   //!
   TBranch        *b_g_e_Api;   //!
   TBranch        *b_g_pt_Api;   //!
   TBranch        *b_g_eta_Api;   //!
   TBranch        *b_g_phi_Api;   //!
   TBranch        *b_g_im_Api;   //!
   TBranch        *b_g_x_stop_A;   //!
   TBranch        *b_g_y_stop_A;   //!
   TBranch        *b_g_z_stop_A;   //!
   TBranch        *b_g_pid_A;   //!
   TBranch        *b_g_gid_A;   //!
   TBranch        *b_g_key_A;   //!
   TBranch        *b_g_e_A;   //!
   TBranch        *b_g_pt_A;   //!
   TBranch        *b_g_eta_A;   //!
   TBranch        *b_g_phi_A;   //!
   TBranch        *b_g_im_A;   //!
   TBranch        *b_g_x_start_A;   //!
   TBranch        *b_g_y_start_A;   //!
   TBranch        *b_g_z_start_A;   //!
   TBranch        *b_g_geantProc_start_A;   //!
   TBranch        *b_g_geantMedium_start_A;   //!
   TBranch        *b_g_generatorProc_start_A;   //!
   TBranch        *b_g_key_start_A;   //!
   TBranch        *b_g_pid_parent_A;   //!
   TBranch        *b_g_gid_parent_A;   //!
   TBranch        *b_g_key_parent_A;   //!

   TBranch        *b_g_nK;   //!
   TBranch        *b_g_pid_Kp;   //!
   TBranch        *b_g_gid_Kp;   //!
   TBranch        *b_g_key_Kp;   //!
   TBranch        *b_g_e_Kp;   //!
   TBranch        *b_g_pt_Kp;   //!
   TBranch        *b_g_eta_Kp;   //!
   TBranch        *b_g_phi_Kp;   //!
   TBranch        *b_g_im_Kp;   //!
   TBranch        *b_g_pid_Kpi;   //!
   TBranch        *b_g_gid_Kpi;   //!
   TBranch        *b_g_key_Kpi;   //!
   TBranch        *b_g_e_Kpi;   //!
   TBranch        *b_g_pt_Kpi;   //!
   TBranch        *b_g_eta_Kpi;   //!
   TBranch        *b_g_phi_Kpi;   //!
   TBranch        *b_g_im_Kpi;   //!
   TBranch        *b_g_x_stop_K;   //!
   TBranch        *b_g_y_stop_K;   //!
   TBranch        *b_g_z_stop_K;   //!
   TBranch        *b_g_pid_K;   //!
   TBranch        *b_g_gid_K;   //!
   TBranch        *b_g_key_K;   //!
   TBranch        *b_g_e_K;   //!
   TBranch        *b_g_pt_K;   //!
   TBranch        *b_g_eta_K;   //!
   TBranch        *b_g_phi_K;   //!
   TBranch        *b_g_im_K;   //!
   TBranch        *b_g_x_start_K;   //!
   TBranch        *b_g_y_start_K;   //!
   TBranch        *b_g_z_start_K;   //!
   TBranch        *b_g_geantProc_start_K;   //!
   TBranch        *b_g_geantMedium_start_K;   //!
   TBranch        *b_g_generatorProc_start_K;   //!
   TBranch        *b_g_key_start_K;   //!
   TBranch        *b_g_pid_parent_K;   //!
   TBranch        *b_g_gid_parent_K;   //!
   TBranch        *b_g_key_parent_K;   //!

   TBranch        *b_a_nL;   //!
   TBranch        *b_a_pid_Lp;   //!
   TBranch        *b_a_gid_Lp;   //!
   TBranch        *b_a_key_Lp;   //!
   TBranch        *b_a_e_Lp;   //!
   TBranch        *b_a_pt_Lp;   //!
   TBranch        *b_a_eta_Lp;   //!
   TBranch        *b_a_phi_Lp;   //!
   TBranch        *b_a_dca_Lp;   //!
   TBranch        *b_a_flag_Lp;   //!
   TBranch        *b_a_nFit_Lp;   //!
   TBranch        *b_a_ratio_Lp;   //!
   TBranch        *b_a_pid_Lpi;   //!
   TBranch        *b_a_gid_Lpi;   //!
   TBranch        *b_a_key_Lpi;   //!
   TBranch        *b_a_e_Lpi;   //!
   TBranch        *b_a_pt_Lpi;   //!
   TBranch        *b_a_eta_Lpi;   //!
   TBranch        *b_a_phi_Lpi;   //!
   TBranch        *b_a_dca_Lpi;   //!
   TBranch        *b_a_flag_Lpi;   //!
   TBranch        *b_a_nFit_Lpi;   //!
   TBranch        *b_a_ratio_Lpi;   //!
   TBranch        *b_a_x_stop_L;   //!
   TBranch        *b_a_y_stop_L;   //!
   TBranch        *b_a_z_stop_L;   //!
   TBranch        *b_a_pt_L;   //!
   TBranch        *b_a_eta_L;   //!
   TBranch        *b_a_phi_L;   //!
   TBranch        *b_a_im_L;   //!
   TBranch        *b_a_dl_L;   //!
   TBranch        *b_a_dca2_L;   //!
   TBranch        *b_a_dcaV0_L;   //!
   TBranch        *b_a_crp_L;   //!
   TBranch        *b_a_pid_parent_L;   //!
   TBranch        *b_a_gid_parent_L;   //!
   TBranch        *b_a_key_parent_L;   //!

   TBranch        *b_a_nA;   //!
   TBranch        *b_a_pid_Ap;   //!
   TBranch        *b_a_gid_Ap;   //!
   TBranch        *b_a_key_Ap;   //!
   TBranch        *b_a_e_Ap;   //!
   TBranch        *b_a_pt_Ap;   //!
   TBranch        *b_a_eta_Ap;   //!
   TBranch        *b_a_phi_Ap;   //!
   TBranch        *b_a_dca_Ap;   //!
   TBranch        *b_a_flag_Ap;   //!
   TBranch        *b_a_nFit_Ap;   //!
   TBranch        *b_a_ratio_Ap;   //!
   TBranch        *b_a_pid_Api;   //!
   TBranch        *b_a_gid_Api;   //!
   TBranch        *b_a_key_Api;   //!
   TBranch        *b_a_e_Api;   //!
   TBranch        *b_a_pt_Api;   //!
   TBranch        *b_a_eta_Api;   //!
   TBranch        *b_a_phi_Api;   //!
   TBranch        *b_a_dca_Api;   //!
   TBranch        *b_a_flag_Api;   //!
   TBranch        *b_a_nFit_Api;   //!
   TBranch        *b_a_ratio_Api;   //!
   TBranch        *b_a_x_stop_A;   //!
   TBranch        *b_a_y_stop_A;   //!
   TBranch        *b_a_z_stop_A;   //!
   TBranch        *b_a_pt_A;   //!
   TBranch        *b_a_eta_A;   //!
   TBranch        *b_a_phi_A;   //!
   TBranch        *b_a_im_A;   //!
   TBranch        *b_a_dl_A;   //!
   TBranch        *b_a_dca2_A;   //!
   TBranch        *b_a_dcaV0_A;   //!
   TBranch        *b_a_crp_A;   //!
   TBranch        *b_a_pid_parent_A;   //!
   TBranch        *b_a_gid_parent_A;   //!
   TBranch        *b_a_key_parent_A;   //!

   TBranch        *b_a_nK;   //!
   TBranch        *b_a_pid_Kp;   //!
   TBranch        *b_a_gid_Kp;   //!
   TBranch        *b_a_key_Kp;   //!
   TBranch        *b_a_e_Kp;   //!
   TBranch        *b_a_pt_Kp;   //!
   TBranch        *b_a_eta_Kp;   //!
   TBranch        *b_a_phi_Kp;   //!
   TBranch        *b_a_dca_Kp;   //!
   TBranch        *b_a_flag_Kp;   //!
   TBranch        *b_a_nFit_Kp;   //!
   TBranch        *b_a_ratio_Kp;   //!
   TBranch        *b_a_pid_Kpi;   //!
   TBranch        *b_a_gid_Kpi;   //!
   TBranch        *b_a_key_Kpi;   //!
   TBranch        *b_a_e_Kpi;   //!
   TBranch        *b_a_pt_Kpi;   //!
   TBranch        *b_a_eta_Kpi;   //!
   TBranch        *b_a_phi_Kpi;   //!
   TBranch        *b_a_dca_Kpi;   //!
   TBranch        *b_a_flag_Kpi;   //!
   TBranch        *b_a_nFit_Kpi;   //!
   TBranch        *b_a_ratio_Kpi;   //!
   TBranch        *b_a_x_stop_K;   //!
   TBranch        *b_a_y_stop_K;   //!
   TBranch        *b_a_z_stop_K;   //!
   TBranch        *b_a_pt_K;   //!
   TBranch        *b_a_eta_K;   //!
   TBranch        *b_a_phi_K;   //!
   TBranch        *b_a_im_K;   //!
   TBranch        *b_a_dl_K;   //!
   TBranch        *b_a_dca2_K;   //!
   TBranch        *b_a_dcaV0_K;   //!
   TBranch        *b_a_crp_K;   //!
   TBranch        *b_a_pid_parent_K;   //!
   TBranch        *b_a_gid_parent_K;   //!
   TBranch        *b_a_key_parent_K;   //!

   TBranch        *b_trig;   //!
   TBranch        *b_trig_sub;   //!
   TBranch        *b_m_runN;   //!
   TBranch        *b_m_evtN;   //!
   TBranch        *b_magn;   //!
   TBranch        *b_m_pvx;   //!
   TBranch        *b_m_pvy;   //!
   TBranch        *b_m_pvz;   //!
   TBranch        *b_m_nL;   //!
   TBranch        *b_m_dEdx_Lp;   //!
   TBranch        *b_m_nSigP_Lp;   //!
   TBranch        *b_m_nSigPi_Lp;   //!
   TBranch        *b_m_pt_Lp;   //!
   TBranch        *b_m_eta_Lp;   //!
   TBranch        *b_m_phi_Lp;   //!
   TBranch        *b_m_dca_Lp;   //!
   TBranch        *b_m_qaT_Lp;   //!
   TBranch        *b_m_idT_Lp;   //!
   TBranch        *b_m_tof_Lp;   //!
   TBranch        *b_m_beta_Lp;   //!
   TBranch        *b_m_dEdx_Lpi;   //!
   TBranch        *b_m_nSigP_Lpi;   //!
   TBranch        *b_m_nSigPi_Lpi;   //!
   TBranch        *b_m_pt_Lpi;   //!
   TBranch        *b_m_eta_Lpi;   //!
   TBranch        *b_m_phi_Lpi;   //!
   TBranch        *b_m_dca_Lpi;   //!
   TBranch        *b_m_qaT_Lpi;   //!
   TBranch        *b_m_idT_Lpi;   //!
   TBranch        *b_m_tof_Lpi;   //!
   TBranch        *b_m_beta_Lpi;   //!
   TBranch        *b_m_dca2_L;   //!
   TBranch        *b_m_dcaV0_L;   //!
   TBranch        *b_m_crp_L;   //!
   TBranch        *b_m_dl_L;   //!
   TBranch        *b_m_im_L;   //!
   TBranch        *b_m_V0x_L;   //!
   TBranch        *b_m_V0y_L;   //!
   TBranch        *b_m_V0z_L;   //!
   TBranch        *b_m_pt_L;   //!
   TBranch        *b_m_eta_L;   //!
   TBranch        *b_m_phi_L;   //!
   TBranch        *b_m_nA;   //!
   TBranch        *b_m_dEdx_Ap;   //!
   TBranch        *b_m_nSigP_Ap;   //!
   TBranch        *b_m_nSigPi_Ap;   //!
   TBranch        *b_m_pt_Ap;   //!
   TBranch        *b_m_eta_Ap;   //!
   TBranch        *b_m_phi_Ap;   //!
   TBranch        *b_m_dca_Ap;   //!
   TBranch        *b_m_qaT_Ap;   //!
   TBranch        *b_m_idT_Ap;   //!
   TBranch        *b_m_tof_Ap;   //!
   TBranch        *b_m_beta_Ap;   //!
   TBranch        *b_m_dEdx_Api;   //!
   TBranch        *b_m_nSigP_Api;   //!
   TBranch        *b_m_nSigPi_Api;   //!
   TBranch        *b_m_pt_Api;   //!
   TBranch        *b_m_eta_Api;   //!
   TBranch        *b_m_phi_Api;   //!
   TBranch        *b_m_dca_Api;   //!
   TBranch        *b_m_qaT_Api;   //!
   TBranch        *b_m_idT_Api;   //!
   TBranch        *b_m_tof_Api;   //!
   TBranch        *b_m_beta_Api;   //!
   TBranch        *b_m_dca2_A;   //!
   TBranch        *b_m_dcaV0_A;   //!
   TBranch        *b_m_crp_A;   //!
   TBranch        *b_m_dl_A;   //!
   TBranch        *b_m_im_A;   //!
   TBranch        *b_m_V0x_A;   //!
   TBranch        *b_m_V0y_A;   //!
   TBranch        *b_m_V0z_A;   //!
   TBranch        *b_m_pt_A;   //!
   TBranch        *b_m_eta_A;   //!
   TBranch        *b_m_phi_A;   //!
   TBranch        *b_m_nK;   //!
   TBranch        *b_m_dEdx_Kp;   //!
   TBranch        *b_m_nSigP_Kp;   //!
   TBranch        *b_m_nSigPi_Kp;   //!
   TBranch        *b_m_pt_Kp;   //!
   TBranch        *b_m_eta_Kp;   //!
   TBranch        *b_m_phi_Kp;   //!
   TBranch        *b_m_dca_Kp;   //!
   TBranch        *b_m_qaT_Kp;   //!
   TBranch        *b_m_idT_Kp;   //!
   TBranch        *b_m_tof_Kp;   //!
   TBranch        *b_m_beta_Kp;   //!
   TBranch        *b_m_dEdx_Kpi;   //!
   TBranch        *b_m_nSigP_Kpi;   //!
   TBranch        *b_m_nSigPi_Kpi;   //!
   TBranch        *b_m_pt_Kpi;   //!
   TBranch        *b_m_eta_Kpi;   //!
   TBranch        *b_m_phi_Kpi;   //!
   TBranch        *b_m_dca_Kpi;   //!
   TBranch        *b_m_qaT_Kpi;   //!
   TBranch        *b_m_idT_Kpi;   //!
   TBranch        *b_m_tof_Kpi;   //!
   TBranch        *b_m_beta_Kpi;   //!
   TBranch        *b_m_dca2_K;   //!
   TBranch        *b_m_dcaV0_K;   //!
   TBranch        *b_m_crp_K;   //!
   TBranch        *b_m_dl_K;   //!
   TBranch        *b_m_im_K;   //!
   TBranch        *b_m_V0x_K;   //!
   TBranch        *b_m_V0y_K;   //!
   TBranch        *b_m_V0z_K;   //!
   TBranch        *b_m_pt_K;   //!
   TBranch        *b_m_eta_K;   //!
   TBranch        *b_m_phi_K;   //!

   v0Tree_reader(TTree *tree=0);
   virtual ~v0Tree_reader();
   virtual int      Cut(int entry);
   virtual int      GetEntry(int entry);
   virtual int      GetEntryWithIndex(int major, int minor=0);
   virtual int      LoadTree(int entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual bool     Notify();
   virtual void     Show(int entry = -1);
};

#endif

#ifdef v0Tree_reader_cxx
v0Tree_reader::v0Tree_reader(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ptH_4_5/test_v0.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("ptH_4_5/test_v0.root");
      }
      f->GetObject("SimuTree",tree);

   }
   Init(tree);
}

v0Tree_reader::~v0Tree_reader()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

int v0Tree_reader::GetEntryWithIndex(int major, int minor)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntryWithIndex(major, minor);
}

int v0Tree_reader::GetEntry(int entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

int v0Tree_reader::LoadTree(int entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   int centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}



void v0Tree_reader::Init(TTree *tree)
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

   fChain->SetBranchAddress("g_runN", &g_runN, &b_g_runN);
   fChain->SetBranchAddress("g_evtN", &g_evtN, &b_g_evtN);
   fChain->SetBranchAddress("g_idSubproc", &g_idSubproc, &b_g_idSubproc);
   fChain->SetBranchAddress("g_pvx", &g_pvx, &b_g_pvx);
   fChain->SetBranchAddress("g_pvy", &g_pvy, &b_g_pvy);
   fChain->SetBranchAddress("g_pvz", &g_pvz, &b_g_pvz);
   fChain->SetBranchAddress("g_pv_geantProc", &g_pv_geantProc, &b_g_pv_geantProc);
   fChain->SetBranchAddress("g_pv_geantMedium", &g_pv_geantMedium, &b_g_pv_geantMedium);
   fChain->SetBranchAddress("g_pv_generatorProc", &g_pv_generatorProc, &b_g_pv_generatorProc);
   fChain->SetBranchAddress("g_pv_key", &g_pv_key, &b_g_pv_key);
   fChain->SetBranchAddress("g_nJets", &g_nJets, &b_g_nJets);
   fChain->SetBranchAddress("g_impactPar", &g_impactPar, &b_g_impactPar);
   fChain->SetBranchAddress("g_phiRP", &g_phiRP, &b_g_phiRP);

   fChain->SetBranchAddress("g_idParton1",& g_idParton1, &b_g_idParton1);
   fChain->SetBranchAddress("g_pxParton1",& g_pxParton1, &b_g_pxParton1);
   fChain->SetBranchAddress("g_pyParton1",& g_pyParton1, &b_g_pyParton1);
   fChain->SetBranchAddress("g_pzParton1",& g_pzParton1, &b_g_pzParton1);
   fChain->SetBranchAddress("g_mParton1", &g_mParton1, &b_g_mParton1);
   fChain->SetBranchAddress("g_eParton1", &g_eParton1, &b_g_eParton1);
   fChain->SetBranchAddress("g_idParton2",& g_idParton2, &b_g_idParton2);
   fChain->SetBranchAddress("g_pxParton2",& g_pxParton2, &b_g_pxParton2);
   fChain->SetBranchAddress("g_pyParton2",& g_pyParton2, &b_g_pyParton2);
   fChain->SetBranchAddress("g_pzParton2",& g_pzParton2, &b_g_pzParton2);
   fChain->SetBranchAddress("g_mParton2", &g_mParton2, &b_g_mParton2);
   fChain->SetBranchAddress("g_eParton2", &g_eParton2, &b_g_eParton2);

   fChain->SetBranchAddress("g_nL", &g_nL, &b_g_nL);
   fChain->SetBranchAddress("g_pid_Lp", g_pid_Lp, &b_g_pid_Lp);
   fChain->SetBranchAddress("g_gid_Lp", g_gid_Lp, &b_g_gid_Lp);
   fChain->SetBranchAddress("g_key_Lp", g_key_Lp, &b_g_key_Lp);
   fChain->SetBranchAddress("g_e_Lp", g_e_Lp, &b_g_e_Lp);
   fChain->SetBranchAddress("g_pt_Lp", g_pt_Lp, &b_g_pt_Lp);
   fChain->SetBranchAddress("g_eta_Lp", g_eta_Lp, &b_g_eta_Lp);
   fChain->SetBranchAddress("g_phi_Lp", g_phi_Lp, &b_g_phi_Lp);
   fChain->SetBranchAddress("g_im_Lp", g_im_Lp, &b_g_im_Lp);
   fChain->SetBranchAddress("g_pid_Lpi", g_pid_Lpi, &b_g_pid_Lpi);
   fChain->SetBranchAddress("g_gid_Lpi", g_gid_Lpi, &b_g_gid_Lpi);
   fChain->SetBranchAddress("g_key_Lpi", g_key_Lpi, &b_g_key_Lpi);
   fChain->SetBranchAddress("g_e_Lpi", g_e_Lpi, &b_g_e_Lpi);
   fChain->SetBranchAddress("g_pt_Lpi", g_pt_Lpi, &b_g_pt_Lpi);
   fChain->SetBranchAddress("g_eta_Lpi", g_eta_Lpi, &b_g_eta_Lpi);
   fChain->SetBranchAddress("g_phi_Lpi", g_phi_Lpi, &b_g_phi_Lpi);
   fChain->SetBranchAddress("g_im_Lpi", g_im_Lpi, &b_g_im_Lpi);
   fChain->SetBranchAddress("g_x_stop_L", g_x_stop_L, &b_g_x_stop_L);
   fChain->SetBranchAddress("g_y_stop_L", g_y_stop_L, &b_g_y_stop_L);
   fChain->SetBranchAddress("g_z_stop_L", g_z_stop_L, &b_g_z_stop_L);
   fChain->SetBranchAddress("g_pid_L", g_pid_L, &b_g_pid_L);
   fChain->SetBranchAddress("g_gid_L", g_gid_L, &b_g_gid_L);
   fChain->SetBranchAddress("g_key_L", g_key_L, &b_g_key_L);
   fChain->SetBranchAddress("g_e_L", g_e_L, &b_g_e_L);
   fChain->SetBranchAddress("g_pt_L", g_pt_L, &b_g_pt_L);
   fChain->SetBranchAddress("g_eta_L", g_eta_L, &b_g_eta_L);
   fChain->SetBranchAddress("g_phi_L", g_phi_L, &b_g_phi_L);
   fChain->SetBranchAddress("g_im_L", g_im_L, &b_g_im_L);
   fChain->SetBranchAddress("g_x_start_L", g_x_start_L, &b_g_x_start_L);
   fChain->SetBranchAddress("g_y_start_L", g_y_start_L, &b_g_y_start_L);
   fChain->SetBranchAddress("g_z_start_L", g_z_start_L, &b_g_z_start_L);
   fChain->SetBranchAddress("g_geantProc_start_L", g_geantProc_start_L, &b_g_geantProc_start_L);
   fChain->SetBranchAddress("g_geantMedium_start_L", g_geantMedium_start_L, &b_g_geantMedium_start_L);
   fChain->SetBranchAddress("g_generatorProc_start_L", g_generatorProc_start_L, &b_g_generatorProc_start_L);
   fChain->SetBranchAddress("g_key_start_L", g_key_start_L, &b_g_key_start_L);
   fChain->SetBranchAddress("g_pid_parent_L", g_pid_parent_L, &b_g_pid_parent_L);
   fChain->SetBranchAddress("g_gid_parent_L", g_gid_parent_L, &b_g_gid_parent_L);
   fChain->SetBranchAddress("g_key_parent_L", g_key_parent_L, &b_g_key_parent_L);

   fChain->SetBranchAddress("g_nA", &g_nA, &b_g_nA);
   fChain->SetBranchAddress("g_pid_Ap", g_pid_Ap, &b_g_pid_Ap);
   fChain->SetBranchAddress("g_gid_Ap", g_gid_Ap, &b_g_gid_Ap);
   fChain->SetBranchAddress("g_key_Ap", g_key_Ap, &b_g_key_Ap);
   fChain->SetBranchAddress("g_e_Ap", g_e_Ap, &b_g_e_Ap);
   fChain->SetBranchAddress("g_pt_Ap", g_pt_Ap, &b_g_pt_Ap);
   fChain->SetBranchAddress("g_eta_Ap", g_eta_Ap, &b_g_eta_Ap);
   fChain->SetBranchAddress("g_phi_Ap", g_phi_Ap, &b_g_phi_Ap);
   fChain->SetBranchAddress("g_im_Ap", g_im_Ap, &b_g_im_Ap);
   fChain->SetBranchAddress("g_pid_Api", g_pid_Api, &b_g_pid_Api);
   fChain->SetBranchAddress("g_gid_Api", g_gid_Api, &b_g_gid_Api);
   fChain->SetBranchAddress("g_key_Api", g_key_Api, &b_g_key_Api);
   fChain->SetBranchAddress("g_e_Api", g_e_Api, &b_g_e_Api);
   fChain->SetBranchAddress("g_pt_Api", g_pt_Api, &b_g_pt_Api);
   fChain->SetBranchAddress("g_eta_Api", g_eta_Api, &b_g_eta_Api);
   fChain->SetBranchAddress("g_phi_Api", g_phi_Api, &b_g_phi_Api);
   fChain->SetBranchAddress("g_im_Api", g_im_Api, &b_g_im_Api);
   fChain->SetBranchAddress("g_x_stop_A", g_x_stop_A, &b_g_x_stop_A);
   fChain->SetBranchAddress("g_y_stop_A", g_y_stop_A, &b_g_y_stop_A);
   fChain->SetBranchAddress("g_z_stop_A", g_z_stop_A, &b_g_z_stop_A);
   fChain->SetBranchAddress("g_pid_A", g_pid_A, &b_g_pid_A);
   fChain->SetBranchAddress("g_gid_A", g_gid_A, &b_g_gid_A);
   fChain->SetBranchAddress("g_key_A", g_key_A, &b_g_key_A);
   fChain->SetBranchAddress("g_e_A", g_e_A, &b_g_e_A);
   fChain->SetBranchAddress("g_pt_A", g_pt_A, &b_g_pt_A);
   fChain->SetBranchAddress("g_eta_A", g_eta_A, &b_g_eta_A);
   fChain->SetBranchAddress("g_phi_A", g_phi_A, &b_g_phi_A);
   fChain->SetBranchAddress("g_im_A", g_im_A, &b_g_im_A);
   fChain->SetBranchAddress("g_x_start_A", g_x_start_A, &b_g_x_start_A);
   fChain->SetBranchAddress("g_y_start_A", g_y_start_A, &b_g_y_start_A);
   fChain->SetBranchAddress("g_z_start_A", g_z_start_A, &b_g_z_start_A);
   fChain->SetBranchAddress("g_geantProc_start_A", g_geantProc_start_A, &b_g_geantProc_start_A);
   fChain->SetBranchAddress("g_geantMedium_start_A", g_geantMedium_start_A, &b_g_geantMedium_start_A);
   fChain->SetBranchAddress("g_generatorProc_start_A", g_generatorProc_start_A, &b_g_generatorProc_start_A);
   fChain->SetBranchAddress("g_key_start_A", g_key_start_A, &b_g_key_start_A);
   fChain->SetBranchAddress("g_pid_parent_A", g_pid_parent_A, &b_g_pid_parent_A);
   fChain->SetBranchAddress("g_gid_parent_A", g_gid_parent_A, &b_g_gid_parent_A);
   fChain->SetBranchAddress("g_key_parent_A", g_key_parent_A, &b_g_key_parent_A);

   fChain->SetBranchAddress("g_nK", &g_nK, &b_g_nK);
   fChain->SetBranchAddress("g_pid_Kp", g_pid_Kp, &b_g_pid_Kp);
   fChain->SetBranchAddress("g_gid_Kp", g_gid_Kp, &b_g_gid_Kp);
   fChain->SetBranchAddress("g_key_Kp", g_key_Kp, &b_g_key_Kp);
   fChain->SetBranchAddress("g_e_Kp", g_e_Kp, &b_g_e_Kp);
   fChain->SetBranchAddress("g_pt_Kp", g_pt_Kp, &b_g_pt_Kp);
   fChain->SetBranchAddress("g_eta_Kp", g_eta_Kp, &b_g_eta_Kp);
   fChain->SetBranchAddress("g_phi_Kp", g_phi_Kp, &b_g_phi_Kp);
   fChain->SetBranchAddress("g_im_Kp", g_im_Kp, &b_g_im_Kp);
   fChain->SetBranchAddress("g_pid_Kpi", g_pid_Kpi, &b_g_pid_Kpi);
   fChain->SetBranchAddress("g_gid_Kpi", g_gid_Kpi, &b_g_gid_Kpi);
   fChain->SetBranchAddress("g_key_Kpi", g_key_Kpi, &b_g_key_Kpi);
   fChain->SetBranchAddress("g_e_Kpi", g_e_Kpi, &b_g_e_Kpi);
   fChain->SetBranchAddress("g_pt_Kpi", g_pt_Kpi, &b_g_pt_Kpi);
   fChain->SetBranchAddress("g_eta_Kpi", g_eta_Kpi, &b_g_eta_Kpi);
   fChain->SetBranchAddress("g_phi_Kpi", g_phi_Kpi, &b_g_phi_Kpi);
   fChain->SetBranchAddress("g_im_Kpi", g_im_Kpi, &b_g_im_Kpi);
   fChain->SetBranchAddress("g_x_stop_K", g_x_stop_K, &b_g_x_stop_K);
   fChain->SetBranchAddress("g_y_stop_K", g_y_stop_K, &b_g_y_stop_K);
   fChain->SetBranchAddress("g_z_stop_K", g_z_stop_K, &b_g_z_stop_K);
   fChain->SetBranchAddress("g_pid_K", g_pid_K, &b_g_pid_K);
   fChain->SetBranchAddress("g_gid_K", g_gid_K, &b_g_gid_K);
   fChain->SetBranchAddress("g_key_K", g_key_K, &b_g_key_K);
   fChain->SetBranchAddress("g_e_K", g_e_K, &b_g_e_K);
   fChain->SetBranchAddress("g_pt_K", g_pt_K, &b_g_pt_K);
   fChain->SetBranchAddress("g_eta_K", g_eta_K, &b_g_eta_K);
   fChain->SetBranchAddress("g_phi_K", g_phi_K, &b_g_phi_K);
   fChain->SetBranchAddress("g_im_K", g_im_K, &b_g_im_K);
   fChain->SetBranchAddress("g_x_start_K", g_x_start_K, &b_g_x_start_K);
   fChain->SetBranchAddress("g_y_start_K", g_y_start_K, &b_g_y_start_K);
   fChain->SetBranchAddress("g_z_start_K", g_z_start_K, &b_g_z_start_K);
   fChain->SetBranchAddress("g_geantProc_start_K", g_geantProc_start_K, &b_g_geantProc_start_K);
   fChain->SetBranchAddress("g_geantMedium_start_K", g_geantMedium_start_K, &b_g_geantMedium_start_K);
   fChain->SetBranchAddress("g_generatorProc_start_K", g_generatorProc_start_K, &b_g_generatorProc_start_K);
   fChain->SetBranchAddress("g_key_start_K", g_key_start_K, &b_g_key_start_K);
   fChain->SetBranchAddress("g_pid_parent_K", g_pid_parent_K, &b_g_pid_parent_K);
   fChain->SetBranchAddress("g_gid_parent_K", g_gid_parent_K, &b_g_gid_parent_K);
   fChain->SetBranchAddress("g_key_parent_K", g_key_parent_K, &b_g_key_parent_K);

   fChain->SetBranchAddress("a_nL", &a_nL, &b_a_nL);
   fChain->SetBranchAddress("a_pid_Lp", a_pid_Lp, &b_a_pid_Lp);
   fChain->SetBranchAddress("a_gid_Lp", a_gid_Lp, &b_a_gid_Lp);
   fChain->SetBranchAddress("a_key_Lp", a_key_Lp, &b_a_key_Lp);
   fChain->SetBranchAddress("a_e_Lp", a_e_Lp, &b_a_e_Lp);
   fChain->SetBranchAddress("a_pt_Lp", a_pt_Lp, &b_a_pt_Lp);
   fChain->SetBranchAddress("a_eta_Lp", a_eta_Lp, &b_a_eta_Lp);
   fChain->SetBranchAddress("a_phi_Lp", a_phi_Lp, &b_a_phi_Lp);
   fChain->SetBranchAddress("a_dca_Lp", a_dca_Lp, &b_a_dca_Lp);
   fChain->SetBranchAddress("a_flag_Lp", a_flag_Lp, &b_a_flag_Lp);
   fChain->SetBranchAddress("a_nFit_Lp", a_nFit_Lp, &b_a_nFit_Lp);
   fChain->SetBranchAddress("a_ratio_Lp", a_ratio_Lp, &b_a_ratio_Lp);
   fChain->SetBranchAddress("a_pid_Lpi", a_pid_Lpi, &b_a_pid_Lpi);
   fChain->SetBranchAddress("a_gid_Lpi", a_gid_Lpi, &b_a_gid_Lpi);
   fChain->SetBranchAddress("a_key_Lpi", a_key_Lpi, &b_a_key_Lpi);
   fChain->SetBranchAddress("a_e_Lpi", a_e_Lpi, &b_a_e_Lpi);
   fChain->SetBranchAddress("a_pt_Lpi", a_pt_Lpi, &b_a_pt_Lpi);
   fChain->SetBranchAddress("a_eta_Lpi", a_eta_Lpi, &b_a_eta_Lpi);
   fChain->SetBranchAddress("a_phi_Lpi", a_phi_Lpi, &b_a_phi_Lpi);
   fChain->SetBranchAddress("a_dca_Lpi", a_dca_Lpi, &b_a_dca_Lpi);
   fChain->SetBranchAddress("a_flag_Lpi", a_flag_Lpi, &b_a_flag_Lpi);
   fChain->SetBranchAddress("a_nFit_Lpi", a_nFit_Lpi, &b_a_nFit_Lpi);
   fChain->SetBranchAddress("a_ratio_Lpi", a_ratio_Lpi, &b_a_ratio_Lpi);
   fChain->SetBranchAddress("a_x_stop_L", a_x_stop_L, &b_a_x_stop_L);
   fChain->SetBranchAddress("a_y_stop_L", a_y_stop_L, &b_a_y_stop_L);
   fChain->SetBranchAddress("a_z_stop_L", a_z_stop_L, &b_a_z_stop_L);
   fChain->SetBranchAddress("a_pt_L", a_pt_L, &b_a_pt_L);
   fChain->SetBranchAddress("a_eta_L", a_eta_L, &b_a_eta_L);
   fChain->SetBranchAddress("a_phi_L", a_phi_L, &b_a_phi_L);
   fChain->SetBranchAddress("a_im_L", a_im_L, &b_a_im_L);
   fChain->SetBranchAddress("a_dl_L", a_dl_L, &b_a_dl_L);
   fChain->SetBranchAddress("a_dca2_L", a_dca2_L, &b_a_dca2_L);
   fChain->SetBranchAddress("a_dcaV0_L", a_dcaV0_L, &b_a_dcaV0_L);
   fChain->SetBranchAddress("a_crp_L", a_crp_L, &b_a_crp_L);
   fChain->SetBranchAddress("a_pid_parent_L", a_pid_parent_L, &b_a_pid_parent_L);
   fChain->SetBranchAddress("a_gid_parent_L", a_gid_parent_L, &b_a_gid_parent_L);
   fChain->SetBranchAddress("a_key_parent_L", a_key_parent_L, &b_a_key_parent_L);

   fChain->SetBranchAddress("a_nA", &a_nA, &b_a_nA);
   fChain->SetBranchAddress("a_pid_Ap", a_pid_Ap, &b_a_pid_Ap);
   fChain->SetBranchAddress("a_gid_Ap", a_gid_Ap, &b_a_gid_Ap);
   fChain->SetBranchAddress("a_key_Ap", a_key_Ap, &b_a_key_Ap);
   fChain->SetBranchAddress("a_e_Ap", a_e_Ap, &b_a_e_Ap);
   fChain->SetBranchAddress("a_pt_Ap", a_pt_Ap, &b_a_pt_Ap);
   fChain->SetBranchAddress("a_eta_Ap", a_eta_Ap, &b_a_eta_Ap);
   fChain->SetBranchAddress("a_phi_Ap", a_phi_Ap, &b_a_phi_Ap);
   fChain->SetBranchAddress("a_dca_Ap", a_dca_Ap, &b_a_dca_Ap);
   fChain->SetBranchAddress("a_flag_Ap", a_flag_Ap, &b_a_flag_Ap);
   fChain->SetBranchAddress("a_nFit_Ap", a_nFit_Ap, &b_a_nFit_Ap);
   fChain->SetBranchAddress("a_ratio_Ap", a_ratio_Ap, &b_a_ratio_Ap);
   fChain->SetBranchAddress("a_pid_Api", a_pid_Api, &b_a_pid_Api);
   fChain->SetBranchAddress("a_gid_Api", a_gid_Api, &b_a_gid_Api);
   fChain->SetBranchAddress("a_key_Api", a_key_Api, &b_a_key_Api);
   fChain->SetBranchAddress("a_e_Api", a_e_Api, &b_a_e_Api);
   fChain->SetBranchAddress("a_pt_Api", a_pt_Api, &b_a_pt_Api);
   fChain->SetBranchAddress("a_eta_Api", a_eta_Api, &b_a_eta_Api);
   fChain->SetBranchAddress("a_phi_Api", a_phi_Api, &b_a_phi_Api);
   fChain->SetBranchAddress("a_dca_Api", a_dca_Api, &b_a_dca_Api);
   fChain->SetBranchAddress("a_flag_Api", a_flag_Api, &b_a_flag_Api);
   fChain->SetBranchAddress("a_nFit_Api", a_nFit_Api, &b_a_nFit_Api);
   fChain->SetBranchAddress("a_ratio_Api", a_ratio_Api, &b_a_ratio_Api);
   fChain->SetBranchAddress("a_x_stop_A", a_x_stop_A, &b_a_x_stop_A);
   fChain->SetBranchAddress("a_y_stop_A", a_y_stop_A, &b_a_y_stop_A);
   fChain->SetBranchAddress("a_z_stop_A", a_z_stop_A, &b_a_z_stop_A);
   fChain->SetBranchAddress("a_pt_A", a_pt_A, &b_a_pt_A);
   fChain->SetBranchAddress("a_eta_A", a_eta_A, &b_a_eta_A);
   fChain->SetBranchAddress("a_phi_A", a_phi_A, &b_a_phi_A);
   fChain->SetBranchAddress("a_im_A", a_im_A, &b_a_im_A);
   fChain->SetBranchAddress("a_dl_A", a_dl_A, &b_a_dl_A);
   fChain->SetBranchAddress("a_dca2_A", a_dca2_A, &b_a_dca2_A);
   fChain->SetBranchAddress("a_dcaV0_A", a_dcaV0_A, &b_a_dcaV0_A);
   fChain->SetBranchAddress("a_crp_A", a_crp_A, &b_a_crp_A);
   fChain->SetBranchAddress("a_pid_parent_A", a_pid_parent_A, &b_a_pid_parent_A);
   fChain->SetBranchAddress("a_gid_parent_A", a_gid_parent_A, &b_a_gid_parent_A);
   fChain->SetBranchAddress("a_key_parent_A", a_key_parent_A, &b_a_key_parent_A);

   fChain->SetBranchAddress("a_nK", &a_nK, &b_a_nK);
   fChain->SetBranchAddress("a_pid_Kp", &a_pid_Kp, &b_a_pid_Kp);
   fChain->SetBranchAddress("a_gid_Kp", &a_gid_Kp, &b_a_gid_Kp);
   fChain->SetBranchAddress("a_key_Kp", &a_key_Kp, &b_a_key_Kp);
   fChain->SetBranchAddress("a_e_Kp", &a_e_Kp, &b_a_e_Kp);
   fChain->SetBranchAddress("a_pt_Kp", &a_pt_Kp, &b_a_pt_Kp);
   fChain->SetBranchAddress("a_eta_Kp", &a_eta_Kp, &b_a_eta_Kp);
   fChain->SetBranchAddress("a_phi_Kp", &a_phi_Kp, &b_a_phi_Kp);
   fChain->SetBranchAddress("a_dca_Kp", &a_dca_Kp, &b_a_dca_Kp);
   fChain->SetBranchAddress("a_flag_Kp", &a_flag_Kp, &b_a_flag_Kp);
   fChain->SetBranchAddress("a_nFit_Kp", &a_nFit_Kp, &b_a_nFit_Kp);
   fChain->SetBranchAddress("a_ratio_Kp", &a_ratio_Kp, &b_a_ratio_Kp);
   fChain->SetBranchAddress("a_pid_Kpi", &a_pid_Kpi, &b_a_pid_Kpi);
   fChain->SetBranchAddress("a_gid_Kpi", &a_gid_Kpi, &b_a_gid_Kpi);
   fChain->SetBranchAddress("a_key_Kpi", &a_key_Kpi, &b_a_key_Kpi);
   fChain->SetBranchAddress("a_e_Kpi", &a_e_Kpi, &b_a_e_Kpi);
   fChain->SetBranchAddress("a_pt_Kpi", &a_pt_Kpi, &b_a_pt_Kpi);
   fChain->SetBranchAddress("a_eta_Kpi", &a_eta_Kpi, &b_a_eta_Kpi);
   fChain->SetBranchAddress("a_phi_Kpi", &a_phi_Kpi, &b_a_phi_Kpi);
   fChain->SetBranchAddress("a_dca_Kpi", &a_dca_Kpi, &b_a_dca_Kpi);
   fChain->SetBranchAddress("a_flag_Kpi", &a_flag_Kpi, &b_a_flag_Kpi);
   fChain->SetBranchAddress("a_nFit_Kpi", &a_nFit_Kpi, &b_a_nFit_Kpi);
   fChain->SetBranchAddress("a_ratio_Kpi", &a_ratio_Kpi, &b_a_ratio_Kpi);
   fChain->SetBranchAddress("a_x_stop_K", &a_x_stop_K, &b_a_x_stop_K);
   fChain->SetBranchAddress("a_y_stop_K", &a_y_stop_K, &b_a_y_stop_K);
   fChain->SetBranchAddress("a_z_stop_K", &a_z_stop_K, &b_a_z_stop_K);
   fChain->SetBranchAddress("a_pt_K", &a_pt_K, &b_a_pt_K);
   fChain->SetBranchAddress("a_eta_K", &a_eta_K, &b_a_eta_K);
   fChain->SetBranchAddress("a_phi_K", &a_phi_K, &b_a_phi_K);
   fChain->SetBranchAddress("a_im_K", &a_im_K, &b_a_im_K);
   fChain->SetBranchAddress("a_dl_K", &a_dl_K, &b_a_dl_K);
   fChain->SetBranchAddress("a_dca2_K", &a_dca2_K, &b_a_dca2_K);
   fChain->SetBranchAddress("a_dcaV0_K", &a_dcaV0_K, &b_a_dcaV0_K);
   fChain->SetBranchAddress("a_crp_K", &a_crp_K, &b_a_crp_K);
   fChain->SetBranchAddress("a_pid_parent_K", &a_pid_parent_K, &b_a_pid_parent_K);
   fChain->SetBranchAddress("a_gid_parent_K", &a_gid_parent_K, &b_a_gid_parent_K);
   fChain->SetBranchAddress("a_key_parent_K", &a_key_parent_K, &b_a_key_parent_K);

   fChain->SetBranchAddress("trig", trig, &b_trig);
   fChain->SetBranchAddress("trig_sub", trig_sub, &b_trig_sub);
   fChain->SetBranchAddress("m_runN", &m_runN, &b_m_runN);
   fChain->SetBranchAddress("m_evtN", &m_evtN, &b_m_evtN);
   fChain->SetBranchAddress("magn", &magn, &b_magn);
   fChain->SetBranchAddress("m_pvx", &m_pvx, &b_m_pvx);
   fChain->SetBranchAddress("m_pvy", &m_pvy, &b_m_pvy);
   fChain->SetBranchAddress("m_pvz", &m_pvz, &b_m_pvz);
   fChain->SetBranchAddress("m_nL", &m_nL, &b_m_nL);
   fChain->SetBranchAddress("m_dEdx_Lp", m_dEdx_Lp, &b_m_dEdx_Lp);
   fChain->SetBranchAddress("m_nSigP_Lp", m_nSigP_Lp, &b_m_nSigP_Lp);
   fChain->SetBranchAddress("m_nSigPi_Lp", m_nSigPi_Lp, &b_m_nSigPi_Lp);
   fChain->SetBranchAddress("m_pt_Lp", m_pt_Lp, &b_m_pt_Lp);
   fChain->SetBranchAddress("m_eta_Lp", m_eta_Lp, &b_m_eta_Lp);
   fChain->SetBranchAddress("m_phi_Lp", m_phi_Lp, &b_m_phi_Lp);
   fChain->SetBranchAddress("m_dca_Lp", m_dca_Lp, &b_m_dca_Lp);
   fChain->SetBranchAddress("m_qaT_Lp", m_qaT_Lp, &b_m_qaT_Lp);
   fChain->SetBranchAddress("m_idT_Lp", m_idT_Lp, &b_m_idT_Lp);
   fChain->SetBranchAddress("m_tof_Lp", m_tof_Lp, &b_m_tof_Lp);
   fChain->SetBranchAddress("m_beta_Lp", m_beta_Lp, &b_m_beta_Lp);
   fChain->SetBranchAddress("m_dEdx_Lpi", m_dEdx_Lpi, &b_m_dEdx_Lpi);
   fChain->SetBranchAddress("m_nSigP_Lpi", m_nSigP_Lpi, &b_m_nSigP_Lpi);
   fChain->SetBranchAddress("m_nSigPi_Lpi", m_nSigPi_Lpi, &b_m_nSigPi_Lpi);
   fChain->SetBranchAddress("m_pt_Lpi", m_pt_Lpi, &b_m_pt_Lpi);
   fChain->SetBranchAddress("m_eta_Lpi", m_eta_Lpi, &b_m_eta_Lpi);
   fChain->SetBranchAddress("m_phi_Lpi", m_phi_Lpi, &b_m_phi_Lpi);
   fChain->SetBranchAddress("m_dca_Lpi", m_dca_Lpi, &b_m_dca_Lpi);
   fChain->SetBranchAddress("m_qaT_Lpi", m_qaT_Lpi, &b_m_qaT_Lpi);
   fChain->SetBranchAddress("m_idT_Lpi", m_idT_Lpi, &b_m_idT_Lpi);
   fChain->SetBranchAddress("m_tof_Lpi", m_tof_Lpi, &b_m_tof_Lpi);
   fChain->SetBranchAddress("m_beta_Lpi", m_beta_Lpi, &b_m_beta_Lpi);
   fChain->SetBranchAddress("m_dca2_L", m_dca2_L, &b_m_dca2_L);
   fChain->SetBranchAddress("m_dcaV0_L", m_dcaV0_L, &b_m_dcaV0_L);
   fChain->SetBranchAddress("m_crp_L", m_crp_L, &b_m_crp_L);
   fChain->SetBranchAddress("m_dl_L", m_dl_L, &b_m_dl_L);
   fChain->SetBranchAddress("m_im_L", m_im_L, &b_m_im_L);
   fChain->SetBranchAddress("m_V0x_L", m_V0x_L, &b_m_V0x_L);
   fChain->SetBranchAddress("m_V0y_L", m_V0y_L, &b_m_V0y_L);
   fChain->SetBranchAddress("m_V0z_L", m_V0z_L, &b_m_V0z_L);
   fChain->SetBranchAddress("m_pt_L", m_pt_L, &b_m_pt_L);
   fChain->SetBranchAddress("m_eta_L", m_eta_L, &b_m_eta_L);
   fChain->SetBranchAddress("m_phi_L", m_phi_L, &b_m_phi_L);
   fChain->SetBranchAddress("m_nA", &m_nA, &b_m_nA);
   fChain->SetBranchAddress("m_dEdx_Ap", m_dEdx_Ap, &b_m_dEdx_Ap);
   fChain->SetBranchAddress("m_nSigP_Ap", m_nSigP_Ap, &b_m_nSigP_Ap);
   fChain->SetBranchAddress("m_nSigPi_Ap", m_nSigPi_Ap, &b_m_nSigPi_Ap);
   fChain->SetBranchAddress("m_pt_Ap", m_pt_Ap, &b_m_pt_Ap);
   fChain->SetBranchAddress("m_eta_Ap", m_eta_Ap, &b_m_eta_Ap);
   fChain->SetBranchAddress("m_phi_Ap", m_phi_Ap, &b_m_phi_Ap);
   fChain->SetBranchAddress("m_dca_Ap", m_dca_Ap, &b_m_dca_Ap);
   fChain->SetBranchAddress("m_qaT_Ap", m_qaT_Ap, &b_m_qaT_Ap);
   fChain->SetBranchAddress("m_idT_Ap", m_idT_Ap, &b_m_idT_Ap);
   fChain->SetBranchAddress("m_tof_Ap", m_tof_Ap, &b_m_tof_Ap);
   fChain->SetBranchAddress("m_beta_Ap", m_beta_Ap, &b_m_beta_Ap);
   fChain->SetBranchAddress("m_dEdx_Api", m_dEdx_Api, &b_m_dEdx_Api);
   fChain->SetBranchAddress("m_nSigP_Api", m_nSigP_Api, &b_m_nSigP_Api);
   fChain->SetBranchAddress("m_nSigPi_Api", m_nSigPi_Api, &b_m_nSigPi_Api);
   fChain->SetBranchAddress("m_pt_Api", m_pt_Api, &b_m_pt_Api);
   fChain->SetBranchAddress("m_eta_Api", m_eta_Api, &b_m_eta_Api);
   fChain->SetBranchAddress("m_phi_Api", m_phi_Api, &b_m_phi_Api);
   fChain->SetBranchAddress("m_dca_Api", m_dca_Api, &b_m_dca_Api);
   fChain->SetBranchAddress("m_qaT_Api", m_qaT_Api, &b_m_qaT_Api);
   fChain->SetBranchAddress("m_idT_Api", m_idT_Api, &b_m_idT_Api);
   fChain->SetBranchAddress("m_tof_Api", m_tof_Api, &b_m_tof_Api);
   fChain->SetBranchAddress("m_beta_Api", m_beta_Api, &b_m_beta_Api);
   fChain->SetBranchAddress("m_dca2_A", m_dca2_A, &b_m_dca2_A);
   fChain->SetBranchAddress("m_dcaV0_A", m_dcaV0_A, &b_m_dcaV0_A);
   fChain->SetBranchAddress("m_crp_A", m_crp_A, &b_m_crp_A);
   fChain->SetBranchAddress("m_dl_A", m_dl_A, &b_m_dl_A);
   fChain->SetBranchAddress("m_im_A", m_im_A, &b_m_im_A);
   fChain->SetBranchAddress("m_V0x_A", m_V0x_A, &b_m_V0x_A);
   fChain->SetBranchAddress("m_V0y_A", m_V0y_A, &b_m_V0y_A);
   fChain->SetBranchAddress("m_V0z_A", m_V0z_A, &b_m_V0z_A);
   fChain->SetBranchAddress("m_pt_A", m_pt_A, &b_m_pt_A);
   fChain->SetBranchAddress("m_eta_A", m_eta_A, &b_m_eta_A);
   fChain->SetBranchAddress("m_phi_A", m_phi_A, &b_m_phi_A);
   fChain->SetBranchAddress("m_nK", &m_nK, &b_m_nK);
   fChain->SetBranchAddress("m_dEdx_Kp", m_dEdx_Kp, &b_m_dEdx_Kp);
   fChain->SetBranchAddress("m_nSigP_Kp", m_nSigP_Kp, &b_m_nSigP_Kp);
   fChain->SetBranchAddress("m_nSigPi_Kp", m_nSigPi_Kp, &b_m_nSigPi_Kp);
   fChain->SetBranchAddress("m_pt_Kp", m_pt_Kp, &b_m_pt_Kp);
   fChain->SetBranchAddress("m_eta_Kp", m_eta_Kp, &b_m_eta_Kp);
   fChain->SetBranchAddress("m_phi_Kp", m_phi_Kp, &b_m_phi_Kp);
   fChain->SetBranchAddress("m_dca_Kp", m_dca_Kp, &b_m_dca_Kp);
   fChain->SetBranchAddress("m_qaT_Kp", m_qaT_Kp, &b_m_qaT_Kp);
   fChain->SetBranchAddress("m_idT_Kp", m_idT_Kp, &b_m_idT_Kp);
   fChain->SetBranchAddress("m_tof_Kp", m_tof_Kp, &b_m_tof_Kp);
   fChain->SetBranchAddress("m_beta_Kp", m_beta_Kp, &b_m_beta_Kp);
   fChain->SetBranchAddress("m_dEdx_Kpi", m_dEdx_Kpi, &b_m_dEdx_Kpi);
   fChain->SetBranchAddress("m_nSigP_Kpi", m_nSigP_Kpi, &b_m_nSigP_Kpi);
   fChain->SetBranchAddress("m_nSigPi_Kpi", m_nSigPi_Kpi, &b_m_nSigPi_Kpi);
   fChain->SetBranchAddress("m_pt_Kpi", m_pt_Kpi, &b_m_pt_Kpi);
   fChain->SetBranchAddress("m_eta_Kpi", m_eta_Kpi, &b_m_eta_Kpi);
   fChain->SetBranchAddress("m_phi_Kpi", m_phi_Kpi, &b_m_phi_Kpi);
   fChain->SetBranchAddress("m_dca_Kpi", m_dca_Kpi, &b_m_dca_Kpi);
   fChain->SetBranchAddress("m_qaT_Kpi", m_qaT_Kpi, &b_m_qaT_Kpi);
   fChain->SetBranchAddress("m_idT_Kpi", m_idT_Kpi, &b_m_idT_Kpi);
   fChain->SetBranchAddress("m_tof_Kpi", m_tof_Kpi, &b_m_tof_Kpi);
   fChain->SetBranchAddress("m_beta_Kpi", m_beta_Kpi, &b_m_beta_Kpi);
   fChain->SetBranchAddress("m_dca2_K", m_dca2_K, &b_m_dca2_K);
   fChain->SetBranchAddress("m_dcaV0_K", m_dcaV0_K, &b_m_dcaV0_K);
   fChain->SetBranchAddress("m_crp_K", m_crp_K, &b_m_crp_K);
   fChain->SetBranchAddress("m_dl_K", m_dl_K, &b_m_dl_K);
   fChain->SetBranchAddress("m_im_K", m_im_K, &b_m_im_K);
   fChain->SetBranchAddress("m_V0x_K", m_V0x_K, &b_m_V0x_K);
   fChain->SetBranchAddress("m_V0y_K", m_V0y_K, &b_m_V0y_K);
   fChain->SetBranchAddress("m_V0z_K", m_V0z_K, &b_m_V0z_K);
   fChain->SetBranchAddress("m_pt_K", m_pt_K, &b_m_pt_K);
   fChain->SetBranchAddress("m_eta_K", m_eta_K, &b_m_eta_K);
   fChain->SetBranchAddress("m_phi_K", m_phi_K, &b_m_phi_K);
   
   Notify();
}

bool v0Tree_reader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void v0Tree_reader::Show(int entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
int v0Tree_reader::Cut(int entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef v0Tree_reader_cxx
