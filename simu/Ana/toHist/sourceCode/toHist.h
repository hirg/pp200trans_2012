//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Oct 31 14:06:14 2016 by ROOT version 5.34/30
// from TTree SimuTree_merged/SimuTree_merged
// found on file: ../../merge/testData/mc_ptH_2_3_13050009_2000.match.root
//////////////////////////////////////////////////////////

#ifndef toHist_h
#define toHist_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
class TH1D;
class TH2D;

// Fixed size dimensions of array or collections stored in the TTree if any.
const int kMax = 50;

const double cut_nSigma_protect[6]   = { 0.50, 0.50, 0.60, 0.80, 1.00, 1.00 };
const double cut_nSigma_proton[6]    = { 3.00, 3.00, 3.00, 3.00, 3.00, 3.00 };
const double cut_nSigma_pion[6]      = { 3.00, 3.00, 3.00, 3.00, 3.00, 3.00 };
const double cut_dca_min_pion[6]     = { 0.60, 0.55, 0.50, 0.50, 0.50, 0.50 };
const double Kcut_dca_min_pion[6]    = { 0.60, 0.55, 0.50, 0.45, 0.40, 0.35 };
const double cut_dca_min_proton[6]   = { 0.25, 0.20, 0.10, 0.05, 0.05, 0.05 };
const double Kcut_dca_min_proton[6]  = { 0.60, 0.55, 0.50, 0.45, 0.40, 0.35 };
const double cut_crp_min[6]          = { 0.95, 0.95, 0.95, 0.95, 0.95, 0.95 };
const double Kcut_crp_min[6]         = { 0.99, 0.99, 0.99, 0.99, 0.99, 0.99 };
const double cut_dca2_max[6]         = { 0.80, 0.70, 0.60, 0.50, 0.45, 0.45 };
const double Kcut_dca2_max[6]        = { 0.70, 0.65, 0.55, 0.45, 0.40, 0.35 };
const double cut_dcaV0_max[6]        = { 1.00, 1.00, 1.00, 1.00, 1.00, 1.00 };
const double Kcut_dcaV0_max[6]       = { 0.60, 0.70, 0.80, 0.80, 0.80, 0.80 };
const double cut_dl_min[6]           = { 3.50, 4.00, 4.00, 4.50, 5.00, 5.50 };
const double Kcut_dl_min[6]          = { 1.20, 1.40, 1.50, 1.60, 1.80, 2.00 };
const double cut_dl_max[6]           = { 1.3e02, 1.4e02, 1.5e02, 1.6e02, 1.7e02, 1.8e02 };
const double cut_P_min_pion[6]       = { 0.15, 0.15, 0.20, 0.25, 0.30, 0.40 };



// Particle ID map
int findPid( int gid )
{
   map<int,int> id_map;

   id_map[19] = 3222;
   id_map[20] = 3212;
   id_map[21] = 3112;
   id_map[22] = 3322;
   id_map[23] = 3312;
   id_map[24] = 3334;

   id_map[27] = -3222;
   id_map[28] = -3212;
   id_map[29] = -3112;
   id_map[30] = -3322;
   id_map[31] = -3312;
   id_map[32] = -3334;

   return id_map[gid];
}

class toHist : public TSelector {
private :
   TTree         *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   int           ptHmin;
   int           ptVmin;
   int           ptVmax;
   double        weight_pt_hard;
   double        weight_pt_v0;
   double        weight_pvz;
   double        weight_run;
   int           trig[4];
   int           trig_sub[4];
   int           g_runN;
   int           g_evtN;
   int           g_idSubproc;
   double        g_pvx;
   double        g_pvy;
   double        g_pvz;
   double        m_pvx;
   double        m_pvy;
   double        m_pvz;
   int           g_pv_geantProc;
   int           g_pv_geantMedium;
   int           g_pv_generatorProc;
   int           g_pv_key;
   int           g_nJets;

   double        p_s;
   double        p_t;
   double        p_u;
   double        p_y;
   double        p_ptHard;
   double        p_cosTheta;
   double        p_x1;
   double        p_x2;
   int           p_f1;
   int           p_f2;
   int           p_f3;
   int           p_f4;

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
   int           g_pid_Lp[kMax];   //[g_nL]
   int           g_gid_Lp[kMax];   //[g_nL]
   int           g_key_Lp[kMax];   //[g_nL]
   double        g_e_Lp[kMax];   //[g_nL]
   double        g_pt_Lp[kMax];   //[g_nL]
   double        g_eta_Lp[kMax];   //[g_nL]
   double        g_phi_Lp[kMax];   //[g_nL]
   double        g_im_Lp[kMax];   //[g_nL]
   int           g_pid_Lpi[kMax];   //[g_nL]
   int           g_gid_Lpi[kMax];   //[g_nL]
   int           g_key_Lpi[kMax];   //[g_nL]
   double        g_e_Lpi[kMax];   //[g_nL]
   double        g_pt_Lpi[kMax];   //[g_nL]
   double        g_eta_Lpi[kMax];   //[g_nL]
   double        g_phi_Lpi[kMax];   //[g_nL]
   double        g_im_Lpi[kMax];   //[g_nL]
   double        g_x_stop_L[kMax];   //[g_nL]
   double        g_y_stop_L[kMax];   //[g_nL]
   double        g_z_stop_L[kMax];   //[g_nL]
   int           g_pid_L[kMax];   //[g_nL]
   int           g_gid_L[kMax];   //[g_nL]
   int           g_key_L[kMax];   //[g_nL]
   double        g_e_L[kMax];   //[g_nL]
   double        g_pt_L[kMax];   //[g_nL]
   double        g_eta_L[kMax];   //[g_nL]
   double        g_phi_L[kMax];   //[g_nL]
   double        g_im_L[kMax];   //[g_nL]
   double        g_x_start_L[kMax];   //[g_nL]
   double        g_y_start_L[kMax];   //[g_nL]
   double        g_z_start_L[kMax];   //[g_nL]
   int           g_pid_parent_L[kMax];   //[g_nL]
   int           g_gid_parent_L[kMax];   //[g_nL]
   int           g_key_parent_L[kMax];   //[g_nL]
   double        g_drParton1_L[kMax];
   double        g_drParton2_L[kMax];

   int           g_index_L[kMax];   //[g_nL]
   int           g_type_L[kMax];   //[g_nL]
   double        g_dr_L[kMax];   //[g_nL]
   double        g_deta_L[kMax];   //[g_nL]
   double        g_dphi_L[kMax];   //[g_nL]

   int           g_nA;
   int           g_pid_Ap[kMax];   //[g_nA]
   int           g_gid_Ap[kMax];   //[g_nA]
   int           g_key_Ap[kMax];   //[g_nA]
   double        g_e_Ap[kMax];   //[g_nA]
   double        g_pt_Ap[kMax];   //[g_nA]
   double        g_eta_Ap[kMax];   //[g_nA]
   double        g_phi_Ap[kMax];   //[g_nA]
   double        g_im_Ap[kMax];   //[g_nA]
   int           g_pid_Api[kMax];   //[g_nA]
   int           g_gid_Api[kMax];   //[g_nA]
   int           g_key_Api[kMax];   //[g_nA]
   double        g_e_Api[kMax];   //[g_nA]
   double        g_pt_Api[kMax];   //[g_nA]
   double        g_eta_Api[kMax];   //[g_nA]
   double        g_phi_Api[kMax];   //[g_nA]
   double        g_im_Api[kMax];   //[g_nA]
   double        g_x_stop_A[kMax];   //[g_nA]
   double        g_y_stop_A[kMax];   //[g_nA]
   double        g_z_stop_A[kMax];   //[g_nA]
   int           g_pid_A[kMax];   //[g_nA]
   int           g_gid_A[kMax];   //[g_nA]
   int           g_key_A[kMax];   //[g_nA]
   double        g_e_A[kMax];   //[g_nA]
   double        g_pt_A[kMax];   //[g_nA]
   double        g_eta_A[kMax];   //[g_nA]
   double        g_phi_A[kMax];   //[g_nA]
   double        g_im_A[kMax];   //[g_nA]
   double        g_x_start_A[kMax];   //[g_nA]
   double        g_y_start_A[kMax];   //[g_nA]
   double        g_z_start_A[kMax];   //[g_nA]
   int           g_pid_parent_A[kMax];   //[g_nA]
   int           g_gid_parent_A[kMax];   //[g_nA]
   int           g_key_parent_A[kMax];   //[g_nA]
   double        g_drParton1_A[kMax];
   double        g_drParton2_A[kMax];
   int           g_index_A[kMax];   //[g_nA]
   int           g_type_A[kMax];   //[g_nA]
   double        g_dr_A[kMax];   //[g_nA]
   double        g_deta_A[kMax];   //[g_nA]
   double        g_dphi_A[kMax];   //[g_nA]

   int           g_nK;
   int           g_pid_Kp[kMax];   //[g_nK]
   int           g_gid_Kp[kMax];   //[g_nK]
   int           g_key_Kp[kMax];   //[g_nK]
   double        g_e_Kp[kMax];   //[g_nK]
   double        g_pt_Kp[kMax];   //[g_nK]
   double        g_eta_Kp[kMax];   //[g_nK]
   double        g_phi_Kp[kMax];   //[g_nK]
   double        g_im_Kp[kMax];   //[g_nK]
   int           g_pid_Kpi[kMax];   //[g_nK]
   int           g_gid_Kpi[kMax];   //[g_nK]
   int           g_key_Kpi[kMax];   //[g_nK]
   double        g_e_Kpi[kMax];   //[g_nK]
   double        g_pt_Kpi[kMax];   //[g_nK]
   double        g_eta_Kpi[kMax];   //[g_nK]
   double        g_phi_Kpi[kMax];   //[g_nK]
   double        g_im_Kpi[kMax];   //[g_nK]
   double        g_x_stop_K[kMax];   //[g_nK]
   double        g_y_stop_K[kMax];   //[g_nK]
   double        g_z_stop_K[kMax];   //[g_nK]
   int           g_pid_K[kMax];   //[g_nK]
   int           g_gid_K[kMax];   //[g_nK]
   int           g_key_K[kMax];   //[g_nK]
   double        g_e_K[kMax];   //[g_nK]
   double        g_pt_K[kMax];   //[g_nK]
   double        g_eta_K[kMax];   //[g_nK]
   double        g_phi_K[kMax];   //[g_nK]
   double        g_im_K[kMax];   //[g_nK]
   double        g_x_start_K[kMax];   //[g_nK]
   double        g_y_start_K[kMax];   //[g_nK]
   double        g_z_start_K[kMax];   //[g_nK]
   int           g_pid_parent_K[kMax];   //[g_nK]
   int           g_gid_parent_K[kMax];   //[g_nK]
   int           g_key_parent_K[kMax];   //[g_nK]
   double        g_drParton1_K[kMax];
   double        g_drParton2_K[kMax];
   int           g_index_K[kMax];   //[g_nK]
   int           g_type_K[kMax];   //[g_nK]
   double        g_dr_K[kMax];   //[g_nK]
   double        g_deta_K[kMax];   //[g_nK]
   double        g_dphi_K[kMax];   //[g_nK]

   int           a_nL;
   int           a_pid_Lp[kMax];   //[a_nL]
   int           a_gid_Lp[kMax];   //[a_nL]
   int           a_key_Lp[kMax];   //[a_nL]
   double        a_e_Lp[kMax];   //[a_nL]
   double        a_pt_Lp[kMax];   //[a_nL]
   double        a_eta_Lp[kMax];   //[a_nL]
   double        a_phi_Lp[kMax];   //[a_nL]
   double        a_dca_Lp[kMax];   //[a_nL]
   int           a_flag_Lp[kMax];   //[a_nL]
   int           a_nFit_Lp[kMax];   //[a_nL]
   double        a_ratio_Lp[kMax];   //[a_nL]
   int           a_pid_Lpi[kMax];   //[a_nL]
   int           a_gid_Lpi[kMax];   //[a_nL]
   int           a_key_Lpi[kMax];   //[a_nL]
   double        a_e_Lpi[kMax];   //[a_nL]
   double        a_pt_Lpi[kMax];   //[a_nL]
   double        a_eta_Lpi[kMax];   //[a_nL]
   double        a_phi_Lpi[kMax];   //[a_nL]
   double        a_dca_Lpi[kMax];   //[a_nL]
   int           a_flag_Lpi[kMax];   //[a_nL]
   int           a_nFit_Lpi[kMax];   //[a_nL]
   double        a_ratio_Lpi[kMax];   //[a_nL]
   double        a_x_stop_L[kMax];   //[a_nL]
   double        a_y_stop_L[kMax];   //[a_nL]
   double        a_z_stop_L[kMax];   //[a_nL]
   double        a_pt_L[kMax];   //[a_nL]
   double        a_eta_L[kMax];   //[a_nL]
   double        a_phi_L[kMax];   //[a_nL]
   double        a_im_L[kMax];   //[a_nL]
   double        a_dl_L[kMax];   //[a_nL]
   double        a_dca2_L[kMax];   //[a_nL]
   double        a_dcaV0_L[kMax];   //[a_nL]
   double        a_crp_L[kMax];   //[a_nL]
   int           a_pid_parent_L[kMax];   //[a_nL]
   int           a_gid_parent_L[kMax];   //[a_nL]
   int           a_key_parent_L[kMax];   //[a_nL]
   double        a_drParton1_L[kMax];
   double        a_drParton2_L[kMax];
   int           a_index_L[kMax];   //[a_nL]
   int           a_type_L[kMax];   //[a_nL]
   double        a_dr_L[kMax];   //[a_nL]
   double        a_deta_L[kMax];   //[a_nL]
   double        a_dphi_L[kMax];   //[a_nL]

   int           a_nA;
   int           a_pid_Ap[kMax];   //[a_nA]
   int           a_gid_Ap[kMax];   //[a_nA]
   int           a_key_Ap[kMax];   //[a_nA]
   double        a_e_Ap[kMax];   //[a_nA]
   double        a_pt_Ap[kMax];   //[a_nA]
   double        a_eta_Ap[kMax];   //[a_nA]
   double        a_phi_Ap[kMax];   //[a_nA]
   double        a_dca_Ap[kMax];   //[a_nA]
   int           a_flag_Ap[kMax];   //[a_nA]
   int           a_nFit_Ap[kMax];   //[a_nA]
   double        a_ratio_Ap[kMax];   //[a_nA]
   int           a_pid_Api[kMax];   //[a_nA]
   int           a_gid_Api[kMax];   //[a_nA]
   int           a_key_Api[kMax];   //[a_nA]
   double        a_e_Api[kMax];   //[a_nA]
   double        a_pt_Api[kMax];   //[a_nA]
   double        a_eta_Api[kMax];   //[a_nA]
   double        a_phi_Api[kMax];   //[a_nA]
   double        a_dca_Api[kMax];   //[a_nA]
   int           a_flag_Api[kMax];   //[a_nA]
   int           a_nFit_Api[kMax];   //[a_nA]
   double        a_ratio_Api[kMax];   //[a_nA]
   double        a_x_stop_A[kMax];   //[a_nA]
   double        a_y_stop_A[kMax];   //[a_nA]
   double        a_z_stop_A[kMax];   //[a_nA]
   double        a_pt_A[kMax];   //[a_nA]
   double        a_eta_A[kMax];   //[a_nA]
   double        a_phi_A[kMax];   //[a_nA]
   double        a_im_A[kMax];   //[a_nA]
   double        a_dl_A[kMax];   //[a_nA]
   double        a_dca2_A[kMax];   //[a_nA]
   double        a_dcaV0_A[kMax];   //[a_nA]
   double        a_crp_A[kMax];   //[a_nA]
   int           a_pid_parent_A[kMax];   //[a_nA]
   int           a_gid_parent_A[kMax];   //[a_nA]
   int           a_key_parent_A[kMax];   //[a_nA]
   double        a_drParton1_A[kMax];
   double        a_drParton2_A[kMax];
   int           a_index_A[kMax];   //[a_nA]
   int           a_type_A[kMax];   //[a_nA]
   double        a_dr_A[kMax];   //[a_nA]
   double        a_deta_A[kMax];   //[a_nA]
   double        a_dphi_A[kMax];   //[a_nA]

   int           a_nK;
   int           a_pid_Kp[kMax];   //[a_nK]
   int           a_gid_Kp[kMax];   //[a_nK]
   int           a_key_Kp[kMax];   //[a_nK]
   double        a_e_Kp[kMax];   //[a_nK]
   double        a_pt_Kp[kMax];   //[a_nK]
   double        a_eta_Kp[kMax];   //[a_nK]
   double        a_phi_Kp[kMax];   //[a_nK]
   double        a_dca_Kp[kMax];   //[a_nK]
   int           a_flag_Kp[kMax];   //[a_nK]
   int           a_nFit_Kp[kMax];   //[a_nK]
   double        a_ratio_Kp[kMax];   //[a_nK]
   int           a_pid_Kpi[kMax];   //[a_nK]
   int           a_gid_Kpi[kMax];   //[a_nK]
   int           a_key_Kpi[kMax];   //[a_nK]
   double        a_e_Kpi[kMax];   //[a_nK]
   double        a_pt_Kpi[kMax];   //[a_nK]
   double        a_eta_Kpi[kMax];   //[a_nK]
   double        a_phi_Kpi[kMax];   //[a_nK]
   double        a_dca_Kpi[kMax];   //[a_nK]
   int           a_flag_Kpi[kMax];   //[a_nK]
   int           a_nFit_Kpi[kMax];   //[a_nK]
   double        a_ratio_Kpi[kMax];   //[a_nK]
   double        a_x_stop_K[kMax];   //[a_nK]
   double        a_y_stop_K[kMax];   //[a_nK]
   double        a_z_stop_K[kMax];   //[a_nK]
   double        a_pt_K[kMax];   //[a_nK]
   double        a_eta_K[kMax];   //[a_nK]
   double        a_phi_K[kMax];   //[a_nK]
   double        a_im_K[kMax];   //[a_nK]
   double        a_dl_K[kMax];   //[a_nK]
   double        a_dca2_K[kMax];   //[a_nK]
   double        a_dcaV0_K[kMax];   //[a_nK]
   double        a_crp_K[kMax];   //[a_nK]
   int           a_pid_parent_K[kMax];   //[a_nK]
   int           a_gid_parent_K[kMax];   //[a_nK]
   int           a_key_parent_K[kMax];   //[a_nK]
   double        a_drParton1_K[kMax];
   double        a_drParton2_K[kMax];
   int           a_index_K[kMax];   //[a_nK]
   int           a_type_K[kMax];   //[a_nK]
   double        a_dr_K[kMax];   //[a_nK]
   double        a_deta_K[kMax];   //[a_nK]
   double        a_dphi_K[kMax];   //[a_nK]

   int           m_nL;
   double        m_dEdx_Lp[kMax];   //[m_nL]
   double        m_nSigP_Lp[kMax];   //[m_nL]
   double        m_nSigPi_Lp[kMax];   //[m_nL]
   double        m_pt_Lp[kMax];   //[m_nL]
   double        m_eta_Lp[kMax];   //[m_nL]
   double        m_phi_Lp[kMax];   //[m_nL]
   double        m_dca_Lp[kMax];   //[m_nL]
   int           m_qaT_Lp[kMax];   //[m_nL]
   int           m_idT_Lp[kMax];   //[m_nL]
   int           m_tof_Lp[kMax];   //[m_nL]
   double        m_beta_Lp[kMax];   //[m_nL]
   double        m_dEdx_Lpi[kMax];   //[m_nL]
   double        m_nSigP_Lpi[kMax];   //[m_nL]
   double        m_nSigPi_Lpi[kMax];   //[m_nL]
   double        m_pt_Lpi[kMax];   //[m_nL]
   double        m_eta_Lpi[kMax];   //[m_nL]
   double        m_phi_Lpi[kMax];   //[m_nL]
   double        m_dca_Lpi[kMax];   //[m_nL]
   int           m_qaT_Lpi[kMax];   //[m_nL]
   int           m_idT_Lpi[kMax];   //[m_nL]
   int           m_tof_Lpi[kMax];   //[m_nL]
   double        m_beta_Lpi[kMax];   //[m_nL]
   double        m_dca2_L[kMax];   //[m_nL]
   double        m_dcaV0_L[kMax];   //[m_nL]
   double        m_crp_L[kMax];   //[m_nL]
   double        m_dl_L[kMax];   //[m_nL]
   double        m_im_L[kMax];   //[m_nL]
   double        m_V0x_L[kMax];   //[m_nL]
   double        m_V0y_L[kMax];   //[m_nL]
   double        m_V0z_L[kMax];   //[m_nL]
   double        m_pt_L[kMax];   //[m_nL]
   double        m_eta_L[kMax];   //[m_nL]
   double        m_phi_L[kMax];   //[m_nL]
   int           m_index_L[kMax];   //[m_nL]
   int           m_type_L[kMax];   //[m_nL]
   double        m_dr_L[kMax];   //[m_nL]
   double        m_deta_L[kMax];   //[m_nL]
   double        m_dphi_L[kMax];   //[m_nL]
   double        m_drParton1_L[kMax];
   double        m_drParton2_L[kMax];

   int           m_nA;
   double        m_dEdx_Ap[kMax];   //[m_nA]
   double        m_nSigP_Ap[kMax];   //[m_nA]
   double        m_nSigPi_Ap[kMax];   //[m_nA]
   double        m_pt_Ap[kMax];   //[m_nA]
   double        m_eta_Ap[kMax];   //[m_nA]
   double        m_phi_Ap[kMax];   //[m_nA]
   double        m_dca_Ap[kMax];   //[m_nA]
   int           m_qaT_Ap[kMax];   //[m_nA]
   int           m_idT_Ap[kMax];   //[m_nA]
   int           m_tof_Ap[kMax];   //[m_nA]
   double        m_beta_Ap[kMax];   //[m_nA]
   double        m_dEdx_Api[kMax];   //[m_nA]
   double        m_nSigP_Api[kMax];   //[m_nA]
   double        m_nSigPi_Api[kMax];   //[m_nA]
   double        m_pt_Api[kMax];   //[m_nA]
   double        m_eta_Api[kMax];   //[m_nA]
   double        m_phi_Api[kMax];   //[m_nA]
   double        m_dca_Api[kMax];   //[m_nA]
   int           m_qaT_Api[kMax];   //[m_nA]
   int           m_idT_Api[kMax];   //[m_nA]
   int           m_tof_Api[kMax];   //[m_nA]
   double        m_beta_Api[kMax];   //[m_nA]
   double        m_dca2_A[kMax];   //[m_nA]
   double        m_dcaV0_A[kMax];   //[m_nA]
   double        m_crp_A[kMax];   //[m_nA]
   double        m_dl_A[kMax];   //[m_nA]
   double        m_im_A[kMax];   //[m_nA]
   double        m_V0x_A[kMax];   //[m_nA]
   double        m_V0y_A[kMax];   //[m_nA]
   double        m_V0z_A[kMax];   //[m_nA]
   double        m_pt_A[kMax];   //[m_nA]
   double        m_eta_A[kMax];   //[m_nA]
   double        m_phi_A[kMax];   //[m_nA]
   int           m_index_A[kMax];   //[m_nA]
   int           m_type_A[kMax];   //[m_nA]
   double        m_dr_A[kMax];   //[m_nA]
   double        m_deta_A[kMax];   //[m_nA]
   double        m_dphi_A[kMax];   //[m_nA]
   double        m_drParton1_A[kMax];
   double        m_drParton2_A[kMax];

   int           m_nK;
   double        m_dEdx_Kp[kMax];   //[m_nK]
   double        m_nSigP_Kp[kMax];   //[m_nK]
   double        m_nSigPi_Kp[kMax];   //[m_nK]
   double        m_pt_Kp[kMax];   //[m_nK]
   double        m_eta_Kp[kMax];   //[m_nK]
   double        m_phi_Kp[kMax];   //[m_nK]
   double        m_dca_Kp[kMax];   //[m_nK]
   int           m_qaT_Kp[kMax];   //[m_nK]
   int           m_idT_Kp[kMax];   //[m_nK]
   int           m_tof_Kp[kMax];   //[m_nK]
   double        m_beta_Kp[kMax];   //[m_nK]
   double        m_dEdx_Kpi[kMax];   //[m_nK]
   double        m_nSigP_Kpi[kMax];   //[m_nK]
   double        m_nSigPi_Kpi[kMax];   //[m_nK]
   double        m_pt_Kpi[kMax];   //[m_nK]
   double        m_eta_Kpi[kMax];   //[m_nK]
   double        m_phi_Kpi[kMax];   //[m_nK]
   double        m_dca_Kpi[kMax];   //[m_nK]
   int           m_qaT_Kpi[kMax];   //[m_nK]
   int           m_idT_Kpi[kMax];   //[m_nK]
   int           m_tof_Kpi[kMax];   //[m_nK]
   double        m_beta_Kpi[kMax];   //[m_nK]
   double        m_dca2_K[kMax];   //[m_nK]
   double        m_dcaV0_K[kMax];   //[m_nK]
   double        m_crp_K[kMax];   //[m_nK]
   double        m_dl_K[kMax];   //[m_nK]
   double        m_im_K[kMax];   //[m_nK]
   double        m_V0x_K[kMax];   //[m_nK]
   double        m_V0y_K[kMax];   //[m_nK]
   double        m_V0z_K[kMax];   //[m_nK]
   double        m_pt_K[kMax];   //[m_nK]
   double        m_eta_K[kMax];   //[m_nK]
   double        m_phi_K[kMax];   //[m_nK]
   int           m_index_K[kMax];   //[m_nK]
   int           m_type_K[kMax];   //[m_nK]
   double        m_dr_K[kMax];   //[m_nK]
   double        m_deta_K[kMax];   //[m_nK]
   double        m_dphi_K[kMax];   //[m_nK]
   double        m_drParton1_K[kMax];
   double        m_drParton2_K[kMax];

   int           njet;
   int           IsJP0s[kMax];   //[njet]
   int           IsJP1s[kMax];   //[njet]
   int           IsJP2s[kMax];   //[njet]
   int           IsAJPs[kMax];   //[njet]
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
   int           J_ncell[kMax];   //[njet]
   int           J_ntra[kMax];   //[njet]
   double        J_drParton1[kMax];
   double        J_drParton2[kMax];

   // List of branches
   TBranch        *b_p_s;
   TBranch        *b_p_t;
   TBranch        *b_p_u;
   TBranch        *b_p_y;
   TBranch        *b_p_ptHard;
   TBranch        *b_p_cosTheta;
   TBranch        *b_p_x1;
   TBranch        *b_p_x2;
   TBranch        *b_p_f1;
   TBranch        *b_p_f2;
   TBranch        *b_p_f3;
   TBranch        *b_p_f4;

   TBranch        *b_ptHmin;   //!
   TBranch        *b_ptVmin;   //!
   TBranch        *b_ptVmax;   //!
   TBranch        *b_weight_pt_hard;   //!
   TBranch        *b_weight_pt_v0;   //!
   TBranch        *b_weight_pvz;   //!
   TBranch        *b_weight_run;   //!
   TBranch        *b_trig;   //!
   TBranch        *b_trig_sub;   //!
   TBranch        *b_g_runN;   //!
   TBranch        *b_g_evtN;   //!
   TBranch        *b_g_idSubproc;   //!
   TBranch        *b_g_pvx;   //!
   TBranch        *b_g_pvy;   //!
   TBranch        *b_g_pvz;   //!
   TBranch        *b_m_pvx;   //!
   TBranch        *b_m_pvy;   //!
   TBranch        *b_m_pvz;   //!
   TBranch        *b_g_pv_geantProc;   //!
   TBranch        *b_g_pv_geantMedium;   //!
   TBranch        *b_g_pv_generatorProc;   //!
   TBranch        *b_g_pv_key;   //!
   TBranch        *b_g_nJets;   //!

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
   TBranch        *b_g_index_L;   //!
   TBranch        *b_g_type_L;   //!
   TBranch        *b_g_dr_L;   //!
   TBranch        *b_g_deta_L;   //!
   TBranch        *b_g_dphi_L;   //!
   TBranch        *b_g_drParton1_L;
   TBranch        *b_g_drParton2_L;

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
   TBranch        *b_g_index_A;   //!
   TBranch        *b_g_type_A;   //!
   TBranch        *b_g_dr_A;   //!
   TBranch        *b_g_deta_A;   //!
   TBranch        *b_g_dphi_A;   //!
   TBranch        *b_g_drParton1_A;
   TBranch        *b_g_drParton2_A;

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
   TBranch        *b_g_index_K;   //!
   TBranch        *b_g_type_K;   //!
   TBranch        *b_g_dr_K;   //!
   TBranch        *b_g_deta_K;   //!
   TBranch        *b_g_dphi_K;   //!
   TBranch        *b_g_drParton1_K;
   TBranch        *b_g_drParton2_K;

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
   TBranch        *b_a_index_L;   //!
   TBranch        *b_a_type_L;   //!
   TBranch        *b_a_dr_L;   //!
   TBranch        *b_a_deta_L;   //!
   TBranch        *b_a_dphi_L;   //!
   TBranch        *b_a_drParton1_L;
   TBranch        *b_a_drParton2_L;

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
   TBranch        *b_a_index_A;   //!
   TBranch        *b_a_type_A;   //!
   TBranch        *b_a_dr_A;   //!
   TBranch        *b_a_deta_A;   //!
   TBranch        *b_a_dphi_A;   //!
   TBranch        *b_a_drParton1_A;
   TBranch        *b_a_drParton2_A;

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
   TBranch        *b_a_index_K;   //!
   TBranch        *b_a_type_K;   //!
   TBranch        *b_a_dr_K;   //!
   TBranch        *b_a_deta_K;   //!
   TBranch        *b_a_dphi_K;   //!
   TBranch        *b_a_drParton1_K;
   TBranch        *b_a_drParton2_K;

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
   TBranch        *b_m_index_L;   //!
   TBranch        *b_m_type_L;   //!
   TBranch        *b_m_dr_L;   //!
   TBranch        *b_m_deta_L;   //!
   TBranch        *b_m_dphi_L;   //!
   TBranch        *b_m_drParton1_L;
   TBranch        *b_m_drParton2_L;

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
   TBranch        *b_m_index_A;   //!
   TBranch        *b_m_type_A;   //!
   TBranch        *b_m_dr_A;   //!
   TBranch        *b_m_deta_A;   //!
   TBranch        *b_m_dphi_A;   //!
   TBranch        *b_m_drParton1_A;
   TBranch        *b_m_drParton2_A;

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
   TBranch        *b_m_index_K;   //!
   TBranch        *b_m_type_K;   //!
   TBranch        *b_m_dr_K;   //!
   TBranch        *b_m_deta_K;   //!
   TBranch        *b_m_dphi_K;   //!
   TBranch        *b_m_drParton1_K;
   TBranch        *b_m_drParton2_K;

   TBranch        *b_njet;   //!
   TBranch        *b_IsJP0s;   //!
   TBranch        *b_IsJP1s;   //!
   TBranch        *b_IsJP2s;   //!
   TBranch        *b_IsAJPs;   //!
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
   TBranch        *b_J_ntra;   //!
   TBranch        *b_J_drParton1;
   TBranch        *b_J_drParton2;

   double  c_nSigma_protect;
   double  c_nSigma_proton;
   double  c_nSigma_pion;
   double  c_dca_min_proton;
   double  c_dca_min_pion;
   double  Kc_dca_min_pion;
   double  c_crp_min;
   double  Kc_crp_min;
   double  c_dca2_max;
   double  Kc_dca2_max;
   double  c_dcaV0_max;
   double  Kc_dcaV0_max;
   double  c_dl_min;
   double  Kc_dl_min;
   double  c_dl_max;
   double  c_P_min_pion;

public:   
   toHist(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~toHist() { }
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
           void    ReadCutTable( int pT );
//           bool    Check_idT( int idTruth );

   TH1D           *h_trig;

   TH1D           *h_g_idSubproc;   //!
   TH1D           *h_g_pvx;   //!
   TH1D           *h_g_pvy;   //!
   TH1D           *h_g_pvz;   //!
   TH1D           *h_m_pvx;   //!
   TH1D           *h_m_pvy;   //!
   TH1D           *h_m_pvz;   //!
   TH1D           *h_g_pv_geantProc;   //!
   TH1D           *h_g_pv_geantMedium;   //!
   TH1D           *h_g_pv_generatorProc;   //!
   TH1D           *h_g_pv_key;   //!

   TH1D           *h_p_ptHard0;
   TH1D           *h_p_ptHard1;
   TH1D           *h_p_cosTheta;

   TH1D           *h_nJet;
   TH1D           *h_deteta_J;
   TH1D           *h_eta_J;
   TH1D           *h_pt_J;
   TH1D           *h_phi_J;
   TH1D           *h_rt_J;
   TH1D           *h_charge_J;
   TH2D           *h_drParton_J;
   TH1D           *h_fParton_J;

   TH1D           *h_g_e_Lp[2][6];   //!
   TH1D           *h_g_pt_Lp[2][6];   //!
   TH1D           *h_g_eta_Lp[2][6];   //!
   TH1D           *h_g_phi_Lp[2][6];   //!
   TH1D           *h_g_im_Lp[2][6];   //!
   TH1D           *h_g_e_Lpi[2][6];   //!
   TH1D           *h_g_pt_Lpi[2][6];   //!
   TH1D           *h_g_eta_Lpi[2][6];   //!
   TH1D           *h_g_phi_Lpi[2][6];   //!
   TH1D           *h_g_im_Lpi[2][6];   //!
   TH1D           *h_g_x_stop_L[2][6];   //!
   TH1D           *h_g_y_stop_L[2][6];   //!
   TH1D           *h_g_z_stop_L[2][6];   //!
   TH1D           *h_g_e_L[2][6];   //!
   TH1D           *h_g_pt_L[2][6];   //!
   TH1D           *h_g_eta_L[2][6];   //!
   TH1D           *h_g_phi_L[2][6];   //!
   TH1D           *h_g_im_L[2][6];   //!
   TH1D           *h_g_x_start_L[2][6];   //!
   TH1D           *h_g_y_start_L[2][6];   //!
   TH1D           *h_g_z_start_L[2][6];   //!
   TH1D           *h_g_pid_parent_L[2][6];   //!
   TH1D           *h_g_index_L[2][6];   //!
   TH1D           *h_g_type_L[2][6];   //!
   TH1D           *h_g_dr_L[2][6];   //!
   TH1D           *h_g_deta_L[2][6];   //!
   TH1D           *h_g_dphi_L[2][6];   //!
   TH1D           *h_g_idSubproc_L[2][6];
   TH2D           *h_g_drParton_L[2][6];
   TH1D           *h_g_fParton_L[2][6];

   TH1D           *h_g_e_Ap[2][6];   //!
   TH1D           *h_g_pt_Ap[2][6];   //!
   TH1D           *h_g_eta_Ap[2][6];   //!
   TH1D           *h_g_phi_Ap[2][6];   //!
   TH1D           *h_g_im_Ap[2][6];   //!
   TH1D           *h_g_e_Api[2][6];   //!
   TH1D           *h_g_pt_Api[2][6];   //!
   TH1D           *h_g_eta_Api[2][6];   //!
   TH1D           *h_g_phi_Api[2][6];   //!
   TH1D           *h_g_im_Api[2][6];   //!
   TH1D           *h_g_x_stop_A[2][6];   //!
   TH1D           *h_g_y_stop_A[2][6];   //!
   TH1D           *h_g_z_stop_A[2][6];   //!
   TH1D           *h_g_e_A[2][6];   //!
   TH1D           *h_g_pt_A[2][6];   //!
   TH1D           *h_g_eta_A[2][6];   //!
   TH1D           *h_g_phi_A[2][6];   //!
   TH1D           *h_g_im_A[2][6];   //!
   TH1D           *h_g_x_start_A[2][6];   //!
   TH1D           *h_g_y_start_A[2][6];   //!
   TH1D           *h_g_z_start_A[2][6];   //!
   TH1D           *h_g_pid_parent_A[2][6];   //!
   TH1D           *h_g_index_A[2][6];   //!
   TH1D           *h_g_type_A[2][6];   //!
   TH1D           *h_g_dr_A[2][6];   //!
   TH1D           *h_g_deta_A[2][6];   //!
   TH1D           *h_g_dphi_A[2][6];   //!
   TH1D           *h_g_idSubproc_A[2][6];
   TH2D           *h_g_drParton_A[2][6];
   TH1D           *h_g_fParton_A[2][6];

   TH1D           *h_a_e_Lp[2][6];   //!
   TH1D           *h_a_pt_Lp[2][6];   //!
   TH1D           *h_a_eta_Lp[2][6];   //!
   TH1D           *h_a_phi_Lp[2][6];   //!
   TH1D           *h_a_dca_Lp[2][6];   //!
   TH1D           *h_a_flag_Lp[2][6];   //!
   TH1D           *h_a_nFit_Lp[2][6];   //!
   TH1D           *h_a_ratio_Lp[2][6];   //!
   TH1D           *h_a_e_Lpi[2][6];   //!
   TH1D           *h_a_pt_Lpi[2][6];   //!
   TH1D           *h_a_eta_Lpi[2][6];   //!
   TH1D           *h_a_phi_Lpi[2][6];   //!
   TH1D           *h_a_dca_Lpi[2][6];   //!
   TH1D           *h_a_flag_Lpi[2][6];   //!
   TH1D           *h_a_nFit_Lpi[2][6];   //!
   TH1D           *h_a_ratio_Lpi[2][6];   //!
   TH1D           *h_a_x_stop_L[2][6];   //!
   TH1D           *h_a_y_stop_L[2][6];   //!
   TH1D           *h_a_z_stop_L[2][6];   //!
   TH1D           *h_a_pt_L[2][6];   //!
   TH1D           *h_a_eta_L[2][6];   //!
   TH1D           *h_a_phi_L[2][6];   //!
   TH1D           *h_a_im_L[2][6];   //!
   TH1D           *h_a_dl_L[2][6];   //!
   TH1D           *h_a_dca2_L[2][6];   //!
   TH1D           *h_a_dcaV0_L[2][6];   //!
   TH1D           *h_a_crp_L[2][6];   //!
   TH1D           *h_a_pid_parent_L[2][6];   //!
   TH1D           *h_a_index_L[2][6];   //!
   TH1D           *h_a_type_L[2][6];   //!
   TH1D           *h_a_dr_L[2][6];   //!
   TH1D           *h_a_deta_L[2][6];   //!
   TH1D           *h_a_dphi_L[2][6];   //!
   TH1D           *h_a_idSubproc_L[2][6];
   TH2D           *h_a_drParton_L[2][6];
   TH1D           *h_a_fParton_L[2][6];

   TH1D           *h_a_e_Ap[2][6];   //!
   TH1D           *h_a_pt_Ap[2][6];   //!
   TH1D           *h_a_eta_Ap[2][6];   //!
   TH1D           *h_a_phi_Ap[2][6];   //!
   TH1D           *h_a_dca_Ap[2][6];   //!
   TH1D           *h_a_flag_Ap[2][6];   //!
   TH1D           *h_a_nFit_Ap[2][6];   //!
   TH1D           *h_a_ratio_Ap[2][6];   //!
   TH1D           *h_a_e_Api[2][6];   //!
   TH1D           *h_a_pt_Api[2][6];   //!
   TH1D           *h_a_eta_Api[2][6];   //!
   TH1D           *h_a_phi_Api[2][6];   //!
   TH1D           *h_a_dca_Api[2][6];   //!
   TH1D           *h_a_flag_Api[2][6];   //!
   TH1D           *h_a_nFit_Api[2][6];   //!
   TH1D           *h_a_ratio_Api[2][6];   //!
   TH1D           *h_a_x_stop_A[2][6];   //!
   TH1D           *h_a_y_stop_A[2][6];   //!
   TH1D           *h_a_z_stop_A[2][6];   //!
   TH1D           *h_a_pt_A[2][6];   //!
   TH1D           *h_a_eta_A[2][6];   //!
   TH1D           *h_a_phi_A[2][6];   //!
   TH1D           *h_a_im_A[2][6];   //!
   TH1D           *h_a_dl_A[2][6];   //!
   TH1D           *h_a_dca2_A[2][6];   //!
   TH1D           *h_a_dcaV0_A[2][6];   //!
   TH1D           *h_a_crp_A[2][6];   //!
   TH1D           *h_a_pid_parent_A[2][6];   //!
   TH1D           *h_a_index_A[2][6];   //!
   TH1D           *h_a_type_A[2][6];   //!
   TH1D           *h_a_dr_A[2][6];   //!
   TH1D           *h_a_deta_A[2][6];   //!
   TH1D           *h_a_dphi_A[2][6];   //!
   TH1D           *h_a_idSubproc_A[2][6];
   TH2D           *h_a_drParton_A[2][6];
   TH1D           *h_a_fParton_A[2][6];

   TH1D           *h_m_pt_Lp[2][6];   //!
   TH1D           *h_m_eta_Lp[2][6];   //!
   TH1D           *h_m_phi_Lp[2][6];   //!
   TH1D           *h_m_dca_Lp[2][6];   //!
   TH1D           *h_m_nSig_Lp[2][6];
   TH1D           *h_m_pt_Lpi[2][6];   //!
   TH1D           *h_m_eta_Lpi[2][6];   //!
   TH1D           *h_m_phi_Lpi[2][6];   //!
   TH1D           *h_m_dca_Lpi[2][6];   //!
   TH1D           *h_m_nSig_Lpi[2][6];
   TH1D           *h_m_pt_L[2][6];   //!
   TH1D           *h_m_eta_L[2][6];   //!
   TH1D           *h_m_phi_L[2][6];   //!
   TH1D           *h_m_im_L[2][6];   //!
   TH1D           *h_m_dl_L[2][6];   //!
   TH1D           *h_m_dca2_L[2][6];   //!
   TH1D           *h_m_dcaV0_L[2][6];   //!
   TH1D           *h_m_crp_L[2][6];   //!
   TH1D           *h_m_dr_L[2][6];   //!
   TH1D           *h_m_deta_L[2][6];   //!
   TH1D           *h_m_dphi_L[2][6];   //!
   TH1D           *h_m_idSubproc_L[2][6];
   TH2D           *h_m_drParton_L[2][6];
   TH1D           *h_m_fParton_L[2][6];

   TH1D           *h_m_pt_Ap[2][6];   //!
   TH1D           *h_m_eta_Ap[2][6];   //!
   TH1D           *h_m_phi_Ap[2][6];   //!
   TH1D           *h_m_dca_Ap[2][6];   //!
   TH1D           *h_m_nSig_Ap[2][6];
   TH1D           *h_m_pt_Api[2][6];   //!
   TH1D           *h_m_eta_Api[2][6];   //!
   TH1D           *h_m_phi_Api[2][6];   //!
   TH1D           *h_m_dca_Api[2][6];   //!
   TH1D           *h_m_nSig_Api[2][6];
   TH1D           *h_m_pt_A[2][6];   //!
   TH1D           *h_m_eta_A[2][6];   //!
   TH1D           *h_m_phi_A[2][6];   //!
   TH1D           *h_m_im_A[2][6];   //!
   TH1D           *h_m_dl_A[2][6];   //!
   TH1D           *h_m_dca2_A[2][6];   //!
   TH1D           *h_m_dcaV0_A[2][6];   //!
   TH1D           *h_m_crp_A[2][6];   //!
   TH1D           *h_m_dr_A[2][6];   //!
   TH1D           *h_m_deta_A[2][6];   //!
   TH1D           *h_m_dphi_A[2][6];   //!
   TH1D           *h_m_idSubproc_A[2][6];
   TH2D           *h_m_drParton_A[2][6];
   TH1D           *h_m_fParton_A[2][6];
   /*
   TH1D           *h_m_pid_parent_L[2][6];   //!
   TH1D           *h_m_key_parent_L[2][6];   //!
   TH1D           *h_m_pid_mmom_L[2][6];   //!
   TH1D           *h_m_key_mmom_L[2][6];   //!
   */

   TH1D           *h_t_pt_Lp[2][6];   //!
   TH1D           *h_t_eta_Lp[2][6];   //!
   TH1D           *h_t_phi_Lp[2][6];   //!
   TH1D           *h_t_dca_Lp[2][6];   //!
   TH1D           *h_t_nSig_Lp[2][6];
   TH1D           *h_t_pt_Lpi[2][6];   //!
   TH1D           *h_t_eta_Lpi[2][6];   //!
   TH1D           *h_t_phi_Lpi[2][6];   //!
   TH1D           *h_t_dca_Lpi[2][6];   //!
   TH1D           *h_t_nSig_Lpi[2][6];
   TH1D           *h_t_pt_L[2][6];   //!
   TH1D           *h_t_eta_L[2][6];   //!
   TH1D           *h_t_phi_L[2][6];   //!
   TH1D           *h_t_im_L[2][6];   //!
   TH1D           *h_t_dl_L[2][6];   //!
   TH1D           *h_t_dca2_L[2][6];   //!
   TH1D           *h_t_dcaV0_L[2][6];   //!
   TH1D           *h_t_crp_L[2][6];   //!
   TH1D           *h_t_dr_L[2][6];   //!
   TH1D           *h_t_deta_L[2][6];   //!
   TH1D           *h_t_dphi_L[2][6];   //!
   TH1D           *h_t_idSubproc_L[2][6];
   TH2D           *h_t_drParton_L[2][6];
   TH1D           *h_t_fParton_L[2][6];

   TH1D           *h_t_pt_Ap[2][6];   //!
   TH1D           *h_t_eta_Ap[2][6];   //!
   TH1D           *h_t_phi_Ap[2][6];   //!
   TH1D           *h_t_dca_Ap[2][6];   //!
   TH1D           *h_t_nSig_Ap[2][6];
   TH1D           *h_t_pt_Api[2][6];   //!
   TH1D           *h_t_eta_Api[2][6];   //!
   TH1D           *h_t_phi_Api[2][6];   //!
   TH1D           *h_t_dca_Api[2][6];   //!
   TH1D           *h_t_nSig_Api[2][6];
   TH1D           *h_t_pt_A[2][6];   //!
   TH1D           *h_t_eta_A[2][6];   //!
   TH1D           *h_t_phi_A[2][6];   //!
   TH1D           *h_t_im_A[2][6];   //!
   TH1D           *h_t_dl_A[2][6];   //!
   TH1D           *h_t_dca2_A[2][6];   //!
   TH1D           *h_t_dcaV0_A[2][6];   //!
   TH1D           *h_t_crp_A[2][6];   //!
   TH1D           *h_t_dr_A[2][6];   //!
   TH1D           *h_t_deta_A[2][6];   //!
   TH1D           *h_t_dphi_A[2][6];   //!
   TH1D           *h_t_idSubproc_A[2][6];
   TH2D           *h_t_drParton_A[2][6];
   TH1D           *h_t_fParton_L[2][6];

   TH1D           *h_g_fz_L[6];
   TH1D           *h_g_fz_A[6];

   TH1D           *h_a_fz_L[6];
   TH1D           *h_a_fz_A[6];

   TH1D           *h_m_fz_L[6];
   TH1D           *h_m_fz_A[6];

   TH1D           *h_t_fz_L[6];
   TH1D           *h_t_fz_A[6];

   ClassDef(toHist,0);
};

#endif

#ifdef toHist_cxx
void toHist::Init(TTree *tree)
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

   fChain->SetBranchAddress("p_s", &p_s, &b_p_s);
   fChain->SetBranchAddress("p_t", &p_t, &b_p_t);
   fChain->SetBranchAddress("p_u", &p_u, &b_p_u);
   fChain->SetBranchAddress("p_y", &p_y, &b_p_y);
   fChain->SetBranchAddress("p_ptHard", &p_ptHard, &b_p_ptHard);
   fChain->SetBranchAddress("p_cosTheta", &p_cosTheta, &b_p_cosTheta);
   fChain->SetBranchAddress("p_x1", &p_x1, &b_p_x1);
   fChain->SetBranchAddress("p_x2", &p_x2, &b_p_x2);
   fChain->SetBranchAddress("p_f1", &p_f1, &b_p_f1);
   fChain->SetBranchAddress("p_f2", &p_f2, &b_p_f2);
   fChain->SetBranchAddress("p_f3", &p_f3, &b_p_f3);
   fChain->SetBranchAddress("p_f4", &p_f4, &b_p_f4);

   fChain->SetBranchAddress("ptHmin", &ptHmin, &b_ptHmin);
   fChain->SetBranchAddress("ptVmin", &ptVmin, &b_ptVmin);
   fChain->SetBranchAddress("ptVmax", &ptVmax, &b_ptVmax);
   fChain->SetBranchAddress("weight_pt_hard", &weight_pt_hard, &b_weight_pt_hard);
   fChain->SetBranchAddress("weight_pt_v0", &weight_pt_v0, &b_weight_pt_v0);
   fChain->SetBranchAddress("weight_pvz", &weight_pvz, &b_weight_pvz);
   fChain->SetBranchAddress("weight_run", &weight_run, &b_weight_run);
   fChain->SetBranchAddress("trig", trig, &b_trig);
   fChain->SetBranchAddress("trig_sub", trig_sub, &b_trig_sub);
   fChain->SetBranchAddress("g_runN", &g_runN, &b_g_runN);
   fChain->SetBranchAddress("g_evtN", &g_evtN, &b_g_evtN);
   fChain->SetBranchAddress("g_idSubproc", &g_idSubproc, &b_g_idSubproc);
   fChain->SetBranchAddress("g_pvx", &g_pvx, &b_g_pvx);
   fChain->SetBranchAddress("g_pvy", &g_pvy, &b_g_pvy);
   fChain->SetBranchAddress("g_pvz", &g_pvz, &b_g_pvz);
   fChain->SetBranchAddress("m_pvx", &m_pvx, &b_m_pvx);
   fChain->SetBranchAddress("m_pvy", &m_pvy, &b_m_pvy);
   fChain->SetBranchAddress("m_pvz", &m_pvz, &b_m_pvz);
   fChain->SetBranchAddress("g_pv_geantProc", &g_pv_geantProc, &b_g_pv_geantProc);
   fChain->SetBranchAddress("g_pv_geantMedium", &g_pv_geantMedium, &b_g_pv_geantMedium);
   fChain->SetBranchAddress("g_pv_generatorProc", &g_pv_generatorProc, &b_g_pv_generatorProc);
   fChain->SetBranchAddress("g_pv_key", &g_pv_key, &b_g_pv_key);
   fChain->SetBranchAddress("g_nJets", &g_nJets, &b_g_nJets);

   fChain->SetBranchAddress("g_idParton1", &g_idParton1, &b_g_idParton1);
   fChain->SetBranchAddress("g_pxParton1", &g_pxParton1, &b_g_pxParton1);
   fChain->SetBranchAddress("g_pyParton1", &g_pyParton1, &b_g_pyParton1);
   fChain->SetBranchAddress("g_pzParton1", &g_pzParton1, &b_g_pzParton1);
   fChain->SetBranchAddress("g_mParton1", &g_mParton1, &b_g_mParton1);
   fChain->SetBranchAddress("g_eParton1", &g_eParton1, &b_g_eParton1);
   fChain->SetBranchAddress("g_idParton2", &g_idParton2, &b_g_idParton2);
   fChain->SetBranchAddress("g_pxParton2", &g_pxParton2, &b_g_pxParton2);
   fChain->SetBranchAddress("g_pyParton2", &g_pyParton2, &b_g_pyParton2);
   fChain->SetBranchAddress("g_pzParton2", &g_pzParton2, &b_g_pzParton2);
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
   fChain->SetBranchAddress("g_index_L", g_index_L, &b_g_index_L);
   fChain->SetBranchAddress("g_type_L", g_type_L, &b_g_type_L);
   fChain->SetBranchAddress("g_dr_L", g_dr_L, &b_g_dr_L);
   fChain->SetBranchAddress("g_deta_L", g_deta_L, &b_g_deta_L);
   fChain->SetBranchAddress("g_dphi_L", g_dphi_L, &b_g_dphi_L);
   fChain->SetBranchAddress("g_drParton1_L", g_drParton1_L, &b_g_drParton1_L);
   fChain->SetBranchAddress("g_drParton2_L", g_drParton2_L, &b_g_drParton2_L);

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
   fChain->SetBranchAddress("g_index_A", g_index_A, &b_g_index_A);
   fChain->SetBranchAddress("g_type_A", g_type_A, &b_g_type_A);
   fChain->SetBranchAddress("g_dr_A", g_dr_A, &b_g_dr_A);
   fChain->SetBranchAddress("g_deta_A", g_deta_A, &b_g_deta_A);
   fChain->SetBranchAddress("g_dphi_A", g_dphi_A, &b_g_dphi_A);
   fChain->SetBranchAddress("g_drParton1_A", g_drParton1_A, &b_g_drParton1_A);
   fChain->SetBranchAddress("g_drParton2_A", g_drParton2_A, &b_g_drParton2_A);

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
   fChain->SetBranchAddress("g_index_K", g_index_K, &b_g_index_K);
   fChain->SetBranchAddress("g_type_K", g_type_K, &b_g_type_K);
   fChain->SetBranchAddress("g_dr_K", g_dr_K, &b_g_dr_K);
   fChain->SetBranchAddress("g_deta_K", g_deta_K, &b_g_deta_K);
   fChain->SetBranchAddress("g_dphi_K", g_dphi_K, &b_g_dphi_K);
   fChain->SetBranchAddress("g_drParton1_K", g_drParton1_K, &b_g_drParton1_K);
   fChain->SetBranchAddress("g_drParton2_K", g_drParton2_K, &b_g_drParton2_K);

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
   fChain->SetBranchAddress("a_index_L", a_index_L, &b_a_index_L);
   fChain->SetBranchAddress("a_type_L", a_type_L, &b_a_type_L);
   fChain->SetBranchAddress("a_dr_L", a_dr_L, &b_a_dr_L);
   fChain->SetBranchAddress("a_deta_L", a_deta_L, &b_a_deta_L);
   fChain->SetBranchAddress("a_dphi_L", a_dphi_L, &b_a_dphi_L);
   fChain->SetBranchAddress("a_drParton1_L", a_drParton1_L, &b_a_drParton1_L);
   fChain->SetBranchAddress("a_drParton2_L", a_drParton2_L, &b_a_drParton2_L);

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
   fChain->SetBranchAddress("a_index_A", a_index_A, &b_a_index_A);
   fChain->SetBranchAddress("a_type_A", a_type_A, &b_a_type_A);
   fChain->SetBranchAddress("a_dr_A", a_dr_A, &b_a_dr_A);
   fChain->SetBranchAddress("a_deta_A", a_deta_A, &b_a_deta_A);
   fChain->SetBranchAddress("a_dphi_A", a_dphi_A, &b_a_dphi_A);
   fChain->SetBranchAddress("a_drParton1_A", a_drParton1_A, &b_a_drParton1_A);
   fChain->SetBranchAddress("a_drParton2_A", a_drParton2_A, &b_a_drParton2_A);

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
   fChain->SetBranchAddress("a_index_K", &a_index_K, &b_a_index_K);
   fChain->SetBranchAddress("a_type_K", &a_type_K, &b_a_type_K);
   fChain->SetBranchAddress("a_dr_K", &a_dr_K, &b_a_dr_K);
   fChain->SetBranchAddress("a_deta_K", &a_deta_K, &b_a_deta_K);
   fChain->SetBranchAddress("a_dphi_K", &a_dphi_K, &b_a_dphi_K);
   fChain->SetBranchAddress("a_drParton1_K", a_drParton1_K, &b_a_drParton1_K);
   fChain->SetBranchAddress("a_drParton2_K", a_drParton2_K, &b_a_drParton2_K);

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
   fChain->SetBranchAddress("m_index_L", m_index_L, &b_m_index_L);
   fChain->SetBranchAddress("m_type_L", m_type_L, &b_m_type_L);
   fChain->SetBranchAddress("m_dr_L", m_dr_L, &b_m_dr_L);
   fChain->SetBranchAddress("m_deta_L", m_deta_L, &b_m_deta_L);
   fChain->SetBranchAddress("m_dphi_L", m_dphi_L, &b_m_dphi_L);
   fChain->SetBranchAddress("m_drParton1_L", m_drParton1_L, &b_m_drParton1_L);
   fChain->SetBranchAddress("m_drParton2_L", m_drParton2_L, &b_m_drParton2_L);

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
   fChain->SetBranchAddress("m_index_A", m_index_A, &b_m_index_A);
   fChain->SetBranchAddress("m_type_A", m_type_A, &b_m_type_A);
   fChain->SetBranchAddress("m_dr_A", m_dr_A, &b_m_dr_A);
   fChain->SetBranchAddress("m_deta_A", m_deta_A, &b_m_deta_A);
   fChain->SetBranchAddress("m_dphi_A", m_dphi_A, &b_m_dphi_A);
   fChain->SetBranchAddress("m_drParton1_A", m_drParton1_A, &b_m_drParton1_A);
   fChain->SetBranchAddress("m_drParton2_A", m_drParton2_A, &b_m_drParton2_A);

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
   fChain->SetBranchAddress("m_index_K", m_index_K, &b_m_index_K);
   fChain->SetBranchAddress("m_type_K", m_type_K, &b_m_type_K);
   fChain->SetBranchAddress("m_dr_K", m_dr_K, &b_m_dr_K);
   fChain->SetBranchAddress("m_deta_K", m_deta_K, &b_m_deta_K);
   fChain->SetBranchAddress("m_dphi_K", m_dphi_K, &b_m_dphi_K);
   fChain->SetBranchAddress("m_drParton1_K", m_drParton1_K, &b_m_drParton1_K);
   fChain->SetBranchAddress("m_drParton2_K", m_drParton2_K, &b_m_drParton2_K);

   fChain->SetBranchAddress("njet", &njet, &b_njet);
   fChain->SetBranchAddress("IsJP0s", IsJP0s, &b_IsJP0s);
   fChain->SetBranchAddress("IsJP1s", IsJP1s, &b_IsJP1s);
   fChain->SetBranchAddress("IsJP2s", IsJP2s, &b_IsJP2s);
   fChain->SetBranchAddress("IsAJPs", IsAJPs, &b_IsAJPs);
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
   fChain->SetBranchAddress("J_ntra", J_ntra, &b_J_ntra);
   fChain->SetBranchAddress("J_drParton1", J_drParton1, &b_J_drParton1);
   fChain->SetBranchAddress("J_drParton2", J_drParton2, &b_J_drParton2);
}

bool toHist::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}






#endif // #ifdef toHist_cxx
