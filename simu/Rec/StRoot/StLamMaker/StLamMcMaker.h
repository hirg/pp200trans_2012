////////////////////////////////////////////////////////////////////////
//
// StLamMcMaker.h
// Created by Jincheng Mei on Dec.17th 2015.
// Used for reading simulation root file
//
////////////////////////////////////////////////////////////////////////

#ifndef ____StLamMcMaker__
#define ____StLamMcMaker__

#include <stdio.h>
#include "StMaker.h"
#include "StAssociationMaker/StAssociationMaker.h"
#include "TLorentzVector.h"
#include "TVector3.h"

#if defined(__MAKECINT__)
#pragma link C++ class TVector3 >+;
#endif

class StChain;
class St_particle;
class St_g2t_event;
class St_g2t_pythia;
class StarGenEvent;
class StarGenParticle;
class StarGenPPEvent;
class StarGenStats;
class TH1D;
class TH2D;
class StMcEventMaker;
class StGlobalTrack;
class TFile;
class TTree;
class StMuDst;
class StMcEvent;
class StMuDstMaker;
class StMuEvent;
class StTriggerSimuMaker;
class StMuDst2StEventMaker;
class StEmcSimulatorMaker;

using namespace std;

const int kMax = 100;

class StLamMcMaker : public StMaker{
	public:
		StLamMcMaker(const char *name, StMuDstMaker *uDstMaker, const char *OutPutFile);
		
		virtual int  Init();
		virtual int  Make();
		virtual int  Finish();

		void InitOutTree();

		StAssociationMaker    *fassociationMaker;
		StMcEventMaker        *fmcEventMaker;
		StEmcSimulatorMaker   *femcSimulatorMaker;
		StTriggerSimuMaker    *ftrigSimuMaker;

		TFile                 *fOutFile;
		TTree                 *fOutTree;
	
	protected:
		StMuDstMaker          *fmuDstMaker;

	private:
		const char            *foutName;
		StMcEvent             *fmcEvent;
		StMuDst               *fmu;
		StMuEvent             *fmuEvent;

		rcTrackMapType        *fmRcTrackMap;
		mcTrackMapType        *fmMcTrackMap;

		TH1D                  *h_PVz0_g;
                TH1D                  *h_PVz1_g;
                TH1D                  *h_PVz0_m;
                TH1D                  *h_PVz1_m;

                TH2D                  *h2_etaphi_pi_P_g;
                TH2D                  *h2_etaphi_pi_P_a;
                TH2D                  *h2_etaphi_pi_P_m;
                TH2D                  *h2_etaphi_pi_M_g;
                TH2D                  *h2_etaphi_pi_M_a;
                TH2D                  *h2_etaphi_pi_M_m;
                TH2D                  *h2_etaphi_p_P_g;
                TH2D                  *h2_etaphi_p_P_a;
                TH2D                  *h2_etaphi_p_P_m;
                TH2D                  *h2_etaphi_p_M_g;
                TH2D                  *h2_etaphi_p_M_a;
                TH2D                  *h2_etaphi_p_M_m;

		int trig[4];
		int trig_sub[4];

		double  p_s;
		double  p_t;
		double  p_u;
		double  p_y;
		double  p_ptHard;
		double  p_cosTheta;
		double  p_x1;
		double  p_x2;
		int     p_f1;
		int     p_f2;
		int     p_f3;
		int     p_f4;

		int     g_runN;
		int     g_evtN;
		int     g_idSubproc;
		double  g_pvx;
		double  g_pvy;
		double  g_pvz;
		int     g_pv_geantProc;
		int     g_pv_geantMedium;
		int     g_pv_generatorProc;
		int     g_pv_key;
		int     g_nJets;

                int     g_idParton1;
                double  g_pxParton1;
                double  g_pyParton1;
                double  g_pzParton1;
                double  g_mParton1;
                double  g_eParton1;
                int     g_idParton2;
                double  g_pxParton2;
                double  g_pyParton2;
                double  g_pzParton2;
                double  g_mParton2;
                double  g_eParton2;

		int     g_nL;
                int     g_pid_Lp[kMax];
                int     g_gid_Lp[kMax];
                int     g_key_Lp[kMax];
                double  g_e_Lp[kMax];
                double  g_pt_Lp[kMax];
                double  g_eta_Lp[kMax];
                double  g_phi_Lp[kMax];
                double  g_im_Lp[kMax];
                int     g_pid_Lpi[kMax];
                int     g_gid_Lpi[kMax];
                int     g_key_Lpi[kMax];
                double  g_e_Lpi[kMax];
                double  g_pt_Lpi[kMax];
                double  g_eta_Lpi[kMax];
                double  g_phi_Lpi[kMax];
                double  g_im_Lpi[kMax];
                double  g_x_stop_L[kMax];
                double  g_y_stop_L[kMax];
                double  g_z_stop_L[kMax];
                int     g_pid_L[kMax];
                int     g_gid_L[kMax];
                int     g_key_L[kMax];
                double  g_e_L[kMax];
                double  g_pt_L[kMax];
                double  g_eta_L[kMax];
                double  g_phi_L[kMax];
                double  g_im_L[kMax];
                double  g_x_start_L[kMax];
                double  g_y_start_L[kMax];
                double  g_z_start_L[kMax];
                int     g_pid_parent_L[kMax];
                int     g_gid_parent_L[kMax];
                int     g_key_parent_L[kMax];

                int     g_nA;
                int     g_pid_Ap[kMax];
                int     g_gid_Ap[kMax];
                int     g_key_Ap[kMax];
                double  g_e_Ap[kMax];
                double  g_pt_Ap[kMax];
                double  g_eta_Ap[kMax];
                double  g_phi_Ap[kMax];
                double  g_im_Ap[kMax];
                int     g_pid_Api[kMax];
                int     g_gid_Api[kMax];
                int     g_key_Api[kMax];
                double  g_e_Api[kMax];
                double  g_pt_Api[kMax];
                double  g_eta_Api[kMax];
                double  g_phi_Api[kMax];
                double  g_im_Api[kMax];
                double  g_x_stop_A[kMax];
                double  g_y_stop_A[kMax];
                double  g_z_stop_A[kMax];
                int     g_pid_A[kMax];
                int     g_gid_A[kMax];
                int     g_key_A[kMax];
                double  g_e_A[kMax];
                double  g_pt_A[kMax];
                double  g_eta_A[kMax];
                double  g_phi_A[kMax];
                double  g_im_A[kMax];
                double  g_x_start_A[kMax];
                double  g_y_start_A[kMax];
                double  g_z_start_A[kMax];
                int     g_pid_parent_A[kMax];
                int     g_gid_parent_A[kMax];
                int     g_key_parent_A[kMax];

                int     g_nK;
                int     g_pid_Kp[kMax];
                int     g_gid_Kp[kMax];
                int     g_key_Kp[kMax];
                double  g_e_Kp[kMax];
                double  g_pt_Kp[kMax];
                double  g_eta_Kp[kMax];
                double  g_phi_Kp[kMax];
                double  g_im_Kp[kMax];
                int     g_pid_Kpi[kMax];
                int     g_gid_Kpi[kMax];
                int     g_key_Kpi[kMax];
                double  g_e_Kpi[kMax];
                double  g_pt_Kpi[kMax];
                double  g_eta_Kpi[kMax];
                double  g_phi_Kpi[kMax];
                double  g_im_Kpi[kMax];
                double  g_x_stop_K[kMax];
                double  g_y_stop_K[kMax];
                double  g_z_stop_K[kMax];
                int     g_pid_K[kMax];
                int     g_gid_K[kMax];
                int     g_key_K[kMax];
                double  g_e_K[kMax];
                double  g_pt_K[kMax];
                double  g_eta_K[kMax];
                double  g_phi_K[kMax];
                double  g_im_K[kMax];
                double  g_x_start_K[kMax];
                double  g_y_start_K[kMax];
                double  g_z_start_K[kMax];
                int     g_pid_parent_K[kMax];
                int     g_gid_parent_K[kMax];
                int     g_key_parent_K[kMax];

		int     a_nL;
                int     a_pid_Lp[kMax];
                int     a_gid_Lp[kMax];
                int     a_key_Lp[kMax];
                double  a_e_Lp[kMax];
                double  a_pt_Lp[kMax];
                double  a_eta_Lp[kMax];
                double  a_phi_Lp[kMax];
                double  a_dca_Lp[kMax];
                int     a_flag_Lp[kMax];
                int     a_nFit_Lp[kMax];
                double  a_ratio_Lp[kMax];
                int     a_pid_Lpi[kMax];
                int     a_gid_Lpi[kMax];
                int     a_key_Lpi[kMax];
                double  a_e_Lpi[kMax];
                double  a_pt_Lpi[kMax];
                double  a_eta_Lpi[kMax];
                double  a_phi_Lpi[kMax];
                double  a_dca_Lpi[kMax];
                int     a_flag_Lpi[kMax];
                int     a_nFit_Lpi[kMax];
                double  a_ratio_Lpi[kMax];
                double  a_x_stop_L[kMax];
                double  a_y_stop_L[kMax];
                double  a_z_stop_L[kMax];
                double  a_pt_L[kMax];
                double  a_eta_L[kMax];
                double  a_phi_L[kMax];
                double  a_im_L[kMax];
                double  a_dl_L[kMax];
                double  a_dca2_L[kMax];
                double  a_dcaV0_L[kMax];
                double  a_crp_L[kMax];
                int     a_pid_parent_L[kMax];
                int     a_gid_parent_L[kMax];
                int     a_key_parent_L[kMax];

                int     a_nA;
                int     a_pid_Ap[kMax];
                int     a_gid_Ap[kMax];
                int     a_key_Ap[kMax];
                double  a_e_Ap[kMax];
                double  a_pt_Ap[kMax];
                double  a_eta_Ap[kMax];
                double  a_phi_Ap[kMax];
                double  a_dca_Ap[kMax];
                int     a_flag_Ap[kMax];
                int     a_nFit_Ap[kMax];
                double  a_ratio_Ap[kMax];
                int     a_pid_Api[kMax];
                int     a_gid_Api[kMax];
                int     a_key_Api[kMax];
                double  a_e_Api[kMax];
                double  a_pt_Api[kMax];
                double  a_eta_Api[kMax];
                double  a_phi_Api[kMax];
                double  a_dca_Api[kMax];
                int     a_flag_Api[kMax];
                int     a_nFit_Api[kMax];
                double  a_ratio_Api[kMax];
                double  a_x_stop_A[kMax];
                double  a_y_stop_A[kMax];
                double  a_z_stop_A[kMax];
                double  a_pt_A[kMax];
                double  a_eta_A[kMax];
                double  a_phi_A[kMax];
                double  a_im_A[kMax];
                double  a_dl_A[kMax];
                double  a_dca2_A[kMax];
                double  a_dcaV0_A[kMax];
                double  a_crp_A[kMax];
                int     a_pid_parent_A[kMax];
                int     a_gid_parent_A[kMax];
                int     a_key_parent_A[kMax];
 
                int     a_nK;
                int     a_pid_Kp[kMax];
                int     a_gid_Kp[kMax];
                int     a_key_Kp[kMax];
                double  a_e_Kp[kMax];
                double  a_pt_Kp[kMax];
                double  a_eta_Kp[kMax];
                double  a_phi_Kp[kMax];
                double  a_dca_Kp[kMax];
                int     a_flag_Kp[kMax];
                int     a_nFit_Kp[kMax];
                double  a_ratio_Kp[kMax];
                int     a_pid_Kpi[kMax];
                int     a_gid_Kpi[kMax];
                int     a_key_Kpi[kMax];
                double  a_e_Kpi[kMax];
                double  a_pt_Kpi[kMax];
                double  a_eta_Kpi[kMax];
                double  a_phi_Kpi[kMax];
                double  a_dca_Kpi[kMax];
                int     a_flag_Kpi[kMax];
                int     a_nFit_Kpi[kMax];
                double  a_ratio_Kpi[kMax];
                double  a_x_stop_K[kMax];
                double  a_y_stop_K[kMax];
                double  a_z_stop_K[kMax];
                double  a_pt_K[kMax];
                double  a_eta_K[kMax];
                double  a_phi_K[kMax];
                double  a_im_K[kMax];
                double  a_dl_K[kMax];
                double  a_dca2_K[kMax];
                double  a_dcaV0_K[kMax];
                double  a_crp_K[kMax];
                int     a_pid_parent_K[kMax];
                int     a_gid_parent_K[kMax];
                int     a_key_parent_K[kMax];

		int     m_runN;
		int     m_evtN;
		double  magn;
		double  m_pvx;
		double  m_pvy;
		double  m_pvz;		

		int     m_nL;
		double  m_dEdx_Lp[kMax];
		double  m_nSigP_Lp[kMax];
		double  m_nSigPi_Lp[kMax];
		double  m_pt_Lp[kMax];
		double  m_eta_Lp[kMax];
		double  m_phi_Lp[kMax];
		double  m_dca_Lp[kMax];
		int     m_qaT_Lp[kMax];
		int     m_idT_Lp[kMax];
                int     m_tof_Lp[kMax];
		double  m_beta_Lp[kMax];
		double  m_dEdx_Lpi[kMax];
		double  m_nSigP_Lpi[kMax];
		double  m_nSigPi_Lpi[kMax];
		double  m_pt_Lpi[kMax];
		double  m_eta_Lpi[kMax];
		double  m_phi_Lpi[kMax];
		double  m_dca_Lpi[kMax];
		int     m_qaT_Lpi[kMax];
		int     m_idT_Lpi[kMax];
                int     m_tof_Lpi[kMax];
		double  m_beta_Lpi[kMax];
		double  m_dca2_L[kMax];
		double  m_dcaV0_L[kMax];
		double  m_crp_L[kMax];
		double  m_dl_L[kMax];
		double  m_im_L[kMax];
		double  m_V0x_L[kMax];
		double  m_V0y_L[kMax];
		double  m_V0z_L[kMax];
		double  m_pt_L[kMax];
		double  m_eta_L[kMax];
		double  m_phi_L[kMax];

		int     m_nA;
		double  m_dEdx_Ap[kMax];
		double  m_nSigP_Ap[kMax];
		double  m_nSigPi_Ap[kMax];
		double  m_pt_Ap[kMax];
		double  m_eta_Ap[kMax];
		double  m_phi_Ap[kMax];
		double  m_dca_Ap[kMax];
		int     m_qaT_Ap[kMax];
		int     m_idT_Ap[kMax];
                int     m_tof_Ap[kMax];
		double  m_beta_Ap[kMax];
		double  m_dEdx_Api[kMax];
		double  m_nSigP_Api[kMax];
		double  m_nSigPi_Api[kMax];
		double  m_pt_Api[kMax];
		double  m_eta_Api[kMax];
		double  m_phi_Api[kMax];
		double  m_dca_Api[kMax];
		int     m_qaT_Api[kMax];
		int     m_idT_Api[kMax];
                int     m_tof_Api[kMax];
		double  m_beta_Api[kMax];
		double  m_dca2_A[kMax];
		double  m_dcaV0_A[kMax];
		double  m_crp_A[kMax];
		double  m_dl_A[kMax];
		double  m_im_A[kMax];
		double  m_V0x_A[kMax];
		double  m_V0y_A[kMax];
		double  m_V0z_A[kMax];
		double  m_pt_A[kMax];
		double  m_eta_A[kMax];
		double  m_phi_A[kMax];
		
		int     m_nK;
		double  m_dEdx_Kp[kMax];
		double  m_nSigP_Kp[kMax];
		double  m_nSigPi_Kp[kMax];
		double  m_pt_Kp[kMax];
		double  m_eta_Kp[kMax];
		double  m_phi_Kp[kMax];
		double  m_dca_Kp[kMax];
		int     m_qaT_Kp[kMax];
		int     m_idT_Kp[kMax];
                int     m_tof_Kp[kMax];
		double  m_beta_Kp[kMax];
		double  m_dEdx_Kpi[kMax];
		double  m_nSigP_Kpi[kMax];
		double  m_nSigPi_Kpi[kMax];
		double  m_pt_Kpi[kMax];
		double  m_eta_Kpi[kMax];
		double  m_phi_Kpi[kMax];
		double  m_dca_Kpi[kMax];
		int     m_qaT_Kpi[kMax];
		int     m_idT_Kpi[kMax];
                int     m_tof_Kpi[kMax];
		double  m_beta_Kpi[kMax];
		double  m_dca2_K[kMax];
		double  m_dcaV0_K[kMax];
		double  m_crp_K[kMax];
		double  m_dl_K[kMax];
		double  m_im_K[kMax];
		double  m_V0x_K[kMax];
		double  m_V0y_K[kMax];
		double  m_V0z_K[kMax];
		double  m_pt_K[kMax];
		double  m_eta_K[kMax];
		double  m_phi_K[kMax];

		ClassDef(StLamMcMaker,6);
};

#endif /* defined(____StLamMcMaker__) */

