/////////////////////////////////////////////////////////////////////////
//
// StLamMcMaker.cxx
// Created by Jincheng Mei on Dec.17th 2015.
// Used for reading simulation root file
//
/////////////////////////////////////////////////////////////////////////


// include header file
// ROOT
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
// STAR
#include "StChain.h"
#include "StarClassLibrary/StHelix.hh"
#include "StarClassLibrary/StThreeVectorD.hh"
#include "StarClassLibrary/StLorentzVectorF.hh"
#include "StarClassLibrary/StPhysicalHelixD.hh"
#include "StarClassLibrary/SystemOfUnits.h"
#include "StEvent.h"
#include "StEventTypes.h"
#include "StEvent/StTrack.h"
#include "StEvent/StGlobalTrack.h"
#include "StMuDSTMaker/COMMON/StMuDstMaker.h"
#include "StMuDSTMaker/COMMON/StMuDst.h"
#include "StMuDSTMaker/COMMON/StMuEvent.h"
#include "StMuDSTMaker/COMMON/StMuTrack.h"
#include "StMuDSTMaker/COMMON/StMuEmcCollection.h"
#include "StMuDSTMaker/COMMON/StMuEmcUtil.h"
#include "StMuDSTMaker/COMMON/StMuDst2StEventMaker.h"
#include "StMuDSTMaker/COMMON/StMuPrimaryVertex.h"
#include "StEventUtilities/StuRefMult.hh"
#include "StTriggerUtilities/StTriggerSimuMaker.h"
#include "StTriggerUtilities/StTriggerSimuResult.h"
#include "StTriggerUtilities/Bbc/StBbcTriggerSimu.h"
#include "StTriggerUtilities/Emc/StEmcTriggerSimu.h"
#include "StTriggerUtilities/Bemc/StBemcTriggerSimu.h"
#include "StTriggerUtilities/L2Emulator/StL2TriggerSimu.h"
#include "StEEmcSimulatorMaker/StEEmcSlowMaker.h"
#include "StMcEvent.hh"
#include "StMcEventTypes.hh"
#include "StMcEvent/StMcTrack.hh"
#include "StMcEventMaker/StMcEventMaker.h"
#include "StAssociationMaker/StAssociationMaker.h"
#include "StAssociationMaker/StTrackPairInfo.hh"

#include "St_DataSet.h"
#include "St_DataSetIter.h"
#include "tables/St_g2t_event_Table.h"
#include "tables/St_particle_Table.h"
#include "tables/St_g2t_pythia_Table.h"

// Mine
#include "StLamMcMaker.h"


//___Particle_Standard_Mass_from_PDG______________________________________
const double M_proton = 0.938272;    // Proton
const double M_pion   = 0.139570;    // Pion+/-

//___Find_StGlobalTrack_based_on_StMcTrack________________________________
StGlobalTrack* partnerTrack(mcTrackMapType* map, StMcTrack* mT) {
	mcTrackMapIter i = map->find(mT);
	StGlobalTrack* rT = 0;
	if (i != map->end()) rT = const_cast<StGlobalTrack*>((*i).second->partnerTrack() );
	return rT;
}

//___Find_StMcTrack_based_on_StGlobalTrack_________________________________
StMcTrack* partnerMcTrack(rcTrackMapType* map, StGlobalTrack* rT) {
	rcTrackMapIter i = map->find(rT);
	StMcTrack* mT = 0;
	if (i != map->end()) mT = const_cast<StMcTrack*>( (*i).second->partnerMcTrack() );
	return mT;
}

//___Calculate_OpenAngle_between_Two_daughters_____________________________
double OpenAngle(StLorentzVectorF momlv, StLorentzVectorF da1_lv, StLorentzVectorF da2_lv) {
	//StLorentzVectorF da1_lvb = da1_lv.boost(momlv);
	//StLorentzVectorF da2_lvb = da2_lv.boost(momlv);
	double oa = da1_lv.vect().angle(da2_lv.vect());
	return oa;
}

//___Calculate_Cos*theta___________________________________________________
double CosThetaStar(StLorentzVectorF mum, StLorentzVectorF son) {
	StLorentzVectorF son_cm = son.boost(mum);
	double cs = (-1*mum.vect().unit()).dot(son_cm.vect().unit());
	return cs;
}

//___Check_StMuTrack_Quality_______________________________________________
bool CheckTra(StMuTrack* tra) {
	if( tra->nHitsFit() < 10 ) return false;
	if( double(tra->nHitsFit())/double(tra->nHitsPoss()) < 0.51 ) return false;
	if( tra->flag()<0 || tra->flag()>1000 ) return false;

	return true;
}

ClassImp(StLamMcMaker)

//___Constructor___________________________________________________________
StLamMcMaker::StLamMcMaker
(
 const char *name, 
 StMuDstMaker *uDstMaker, 
 const char *OutPutFile
 )
:StMaker( name ), fmuDstMaker( uDstMaker ), foutName( OutPutFile )
{
	LOG_INFO << "StLamMcMaker Construction Begin ~~~" << endm;
}


//___Initialize_the_Output_Tree____________________________________________
void StLamMcMaker::InitOutTree() {
	LOG_INFO << "Output Tree Build" << endm;
	
	fOutTree = new TTree( "SimuTree", "Simulation Tree" );
	fOutTree->SetDirectory( fOutFile );

	fOutTree->Branch("g_runN", &g_runN, "g_runN/I");
	fOutTree->Branch("g_evtN", &g_evtN, "g_evtN/I");
	fOutTree->Branch("g_idSubproc", &g_idSubproc, "g_idSubproc/I");
        fOutTree->Branch("g_impactPar", &g_impactPar, "g_impactPar/D");
        fOutTree->Branch("g_phiRP", &g_phiRP, "g_phiRP/D");
	fOutTree->Branch("g_pvx", &g_pvx, "g_pvx/D");
	fOutTree->Branch("g_pvy", &g_pvy, "g_pvy/D");
	fOutTree->Branch("g_pvz", &g_pvz, "g_pvz/D");
	fOutTree->Branch("g_pv_geantProc", &g_pv_geantProc, "g_pv_geantProc/I");
	fOutTree->Branch("g_pv_geantMedium", &g_pv_geantMedium, "g_pv_geantMedium/I");
	fOutTree->Branch("g_pv_generatorProc", &g_pv_generatorProc, "g_pv_generatorProc/I");
	fOutTree->Branch("g_pv_key", &g_pv_key, "g_pv_key/I");
        fOutTree->Branch("g_nJets", &g_nJets, "g_nJets/I");

        fOutTree->Branch("g_idParton1", &g_idParton1, "g_idParton1/I");
        fOutTree->Branch("g_pxParton1", &g_pxParton1, "g_pxParton1/D");
        fOutTree->Branch("g_pyParton1", &g_pyParton1, "g_pyParton1/D");
        fOutTree->Branch("g_pzParton1", &g_pzParton1, "g_pzParton1/D");
        fOutTree->Branch("g_mParton1", &g_mParton1, "g_mParton1/D");
        fOutTree->Branch("g_eParton1", &g_eParton1, "g_eParton1/D");
        fOutTree->Branch("g_idParton2", &g_idParton2, "g_idParton2/I");
        fOutTree->Branch("g_pxParton2", &g_pxParton2, "g_pxParton2/D");
        fOutTree->Branch("g_pyParton2", &g_pyParton2, "g_pyParton2/D");
        fOutTree->Branch("g_pzParton2", &g_pzParton2, "g_pzParton2/D");
        fOutTree->Branch("g_mParton2", &g_mParton2, "g_mParton2/D");
        fOutTree->Branch("g_eParton2", &g_eParton2, "g_eParton2/D");

	fOutTree->Branch("g_nL", &g_nL, "g_nL/I");
        fOutTree->Branch("g_pid_Lp", g_pid_Lp, "g_pid_Lp[g_nL]/I");
        fOutTree->Branch("g_gid_Lp", g_gid_Lp, "g_gid_Lp[g_nL]/I");
        fOutTree->Branch("g_key_Lp", g_key_Lp, "g_key_Lp[g_nL]/I");
        fOutTree->Branch("g_e_Lp", g_e_Lp, "g_e_Lp[g_nL]/D");  
        fOutTree->Branch("g_pt_Lp", g_pt_Lp, "g_pt_Lp[g_nL]/D");
        fOutTree->Branch("g_eta_Lp", g_eta_Lp, "g_eta_Lp[g_nL]/D");
        fOutTree->Branch("g_phi_Lp", g_phi_Lp, "g_phi_Lp[g_nL]/D");
        fOutTree->Branch("g_im_Lp", g_im_Lp, "g_im_Lp[g_nL]/D");
        fOutTree->Branch("g_pid_Lpi", g_pid_Lpi, "g_pid_Lpi[g_nL]/I");
        fOutTree->Branch("g_gid_Lpi", g_gid_Lpi, "g_gid_Lpi[g_nL]/I");
        fOutTree->Branch("g_key_Lpi", g_key_Lpi, "g_key_Lpi[g_nL]/I");
        fOutTree->Branch("g_e_Lpi", g_e_Lpi, "g_e_Lpi[g_nL]/D");  
        fOutTree->Branch("g_pt_Lpi", g_pt_Lpi, "g_pt_Lpi[g_nL]/D");
        fOutTree->Branch("g_eta_Lpi", g_eta_Lpi, "g_eta_Lpi[g_nL]/D");
        fOutTree->Branch("g_phi_Lpi", g_phi_Lpi, "g_phi_Lpi[g_nL]/D");
        fOutTree->Branch("g_im_Lpi", g_im_Lpi, "g_im_Lpi[g_nL]/D");
        fOutTree->Branch("g_x_stop_L", g_x_stop_L, "g_x_stop_L[g_nL]/D");
        fOutTree->Branch("g_y_stop_L", g_y_stop_L, "g_y_stop_L[g_nL]/D");
        fOutTree->Branch("g_z_stop_L", g_z_stop_L, "g_z_stop_L[g_nL]/D");
        fOutTree->Branch("g_pid_L", g_pid_L, "g_pid_L[g_nL]/I");
        fOutTree->Branch("g_gid_L", g_gid_L, "g_gid_L[g_nL]/I");
        fOutTree->Branch("g_key_L", g_key_L, "g_key_L[g_nL]/I");
        fOutTree->Branch("g_e_L", g_e_L, "g_e_L[g_nL]/D");  
        fOutTree->Branch("g_pt_L", g_pt_L, "g_pt_L[g_nL]/D");
        fOutTree->Branch("g_eta_L", g_eta_L, "g_eta_L[g_nL]/D");
        fOutTree->Branch("g_phi_L", g_phi_L, "g_phi_L[g_nL]/D");
        fOutTree->Branch("g_im_L", g_im_L, "g_im_L[g_nL]/D");
        fOutTree->Branch("g_x_start_L", g_x_start_L, "g_x_start_L[g_nL]/D");
        fOutTree->Branch("g_y_start_L", g_y_start_L, "g_y_start_L[g_nL]/D");
        fOutTree->Branch("g_z_start_L", g_z_start_L, "g_z_start_L[g_nL]/D");
        fOutTree->Branch("g_geantProc_start_L", g_geantProc_start_L, "g_geantProc_start_L[g_nL]/I");
        fOutTree->Branch("g_geantMedium_start_L", g_geantMedium_start_L, "g_geantMedium_start_L[g_nL]/I");
        fOutTree->Branch("g_generatorProc_start_L", g_generatorProc_start_L, "g_generatorProc_start_L[g_nL]/I");
        fOutTree->Branch("g_key_start_L", g_key_start_L, "g_key_start_L[g_nL]/I");
        fOutTree->Branch("g_pid_parent_L", g_pid_parent_L, "g_pid_parent_L[g_nL]/I");
        fOutTree->Branch("g_gid_parent_L", g_gid_parent_L, "g_gid_parent_L[g_nL]/I");
        fOutTree->Branch("g_key_parent_L", g_key_parent_L, "g_key_parent_L[g_nL]/I");

	fOutTree->Branch("g_nA", &g_nA, "g_nA/I");
        fOutTree->Branch("g_pid_Ap", g_pid_Ap, "g_pid_Ap[g_nA]/I");
        fOutTree->Branch("g_gid_Ap", g_gid_Ap, "g_gid_Ap[g_nA]/I");
        fOutTree->Branch("g_key_Ap", g_key_Ap, "g_key_Ap[g_nA]/I");
        fOutTree->Branch("g_e_Ap", g_e_Ap, "g_e_Ap[g_nA]/D");  
        fOutTree->Branch("g_pt_Ap", g_pt_Ap, "g_pt_Ap[g_nA]/D");
        fOutTree->Branch("g_eta_Ap", g_eta_Ap, "g_eta_Ap[g_nA]/D");
        fOutTree->Branch("g_phi_Ap", g_phi_Ap, "g_phi_Ap[g_nA]/D");
        fOutTree->Branch("g_im_Ap", g_im_Ap, "g_im_Ap[g_nA]/D");
        fOutTree->Branch("g_pid_Api", g_pid_Api, "g_pid_Api[g_nA]/I");
        fOutTree->Branch("g_gid_Api", g_gid_Api, "g_gid_Api[g_nA]/I");
        fOutTree->Branch("g_key_Api", g_key_Api, "g_key_Api[g_nA]/I");
        fOutTree->Branch("g_e_Api", g_e_Api, "g_e_Api[g_nA]/D");  
        fOutTree->Branch("g_pt_Api", g_pt_Api, "g_pt_Api[g_nA]/D");
        fOutTree->Branch("g_eta_Api", g_eta_Api, "g_eta_Api[g_nA]/D");
        fOutTree->Branch("g_phi_Api", g_phi_Api, "g_phi_Api[g_nA]/D");
        fOutTree->Branch("g_im_Api", g_im_Api, "g_im_Api[g_nA]/D");
        fOutTree->Branch("g_x_stop_A", g_x_stop_A, "g_x_stop_A[g_nA]/D");
        fOutTree->Branch("g_y_stop_A", g_y_stop_A, "g_y_stop_A[g_nA]/D");
        fOutTree->Branch("g_z_stop_A", g_z_stop_A, "g_z_stop_A[g_nA]/D");
        fOutTree->Branch("g_pid_A", g_pid_A, "g_pid_A[g_nA]/I");
        fOutTree->Branch("g_gid_A", g_gid_A, "g_gid_A[g_nA]/I");
        fOutTree->Branch("g_key_A", g_key_A, "g_key_A[g_nA]/I");
        fOutTree->Branch("g_e_A", g_e_A, "g_e_A[g_nA]/D");  
        fOutTree->Branch("g_pt_A", g_pt_A, "g_pt_A[g_nA]/D");
        fOutTree->Branch("g_eta_A", g_eta_A, "g_eta_A[g_nA]/D");
        fOutTree->Branch("g_phi_A", g_phi_A, "g_phi_A[g_nA]/D");
        fOutTree->Branch("g_im_A", g_im_A, "g_im_A[g_nA]/D");
        fOutTree->Branch("g_x_start_A", g_x_start_A, "g_x_start_A[g_nA]/D");
        fOutTree->Branch("g_y_start_A", g_y_start_A, "g_y_start_A[g_nA]/D");
        fOutTree->Branch("g_z_start_A", g_z_start_A, "g_z_start_A[g_nA]/D");
        fOutTree->Branch("g_geantProc_start_A", g_geantProc_start_A, "g_geantProc_start_A[g_nA]/I");
        fOutTree->Branch("g_geantMedium_start_A", g_geantMedium_start_A, "g_geantMedium_start_A[g_nA]/I");
        fOutTree->Branch("g_generatorProc_start_A", g_generatorProc_start_A, "g_generatorProc_start_A[g_nA]/I");
        fOutTree->Branch("g_key_start_A", g_key_start_A, "g_key_start_A[g_nA]/I");
        fOutTree->Branch("g_pid_parent_A", g_pid_parent_A, "g_pid_parent_A[g_nA]/I");
        fOutTree->Branch("g_gid_parent_A", g_gid_parent_A, "g_gid_parent_A[g_nA]/I");
        fOutTree->Branch("g_key_parent_A", g_key_parent_A, "g_key_parent_A[g_nA]/I");

	fOutTree->Branch("g_nK", &g_nK, "g_nK/I");
        fOutTree->Branch("g_pid_Kp", g_pid_Kp, "g_pid_Kp[g_nK]/I");
        fOutTree->Branch("g_gid_Kp", g_gid_Kp, "g_gid_Kp[g_nK]/I");
        fOutTree->Branch("g_key_Kp", g_key_Kp, "g_key_Kp[g_nK]/I");
        fOutTree->Branch("g_e_Kp", g_e_Kp, "g_e_Kp[g_nK]/D");  
        fOutTree->Branch("g_pt_Kp", g_pt_Kp, "g_pt_Kp[g_nK]/D");
        fOutTree->Branch("g_eta_Kp", g_eta_Kp, "g_eta_Kp[g_nK]/D");
        fOutTree->Branch("g_phi_Kp", g_phi_Kp, "g_phi_Kp[g_nK]/D");
        fOutTree->Branch("g_im_Kp", g_im_Kp, "g_im_Kp[g_nK]/D");
        fOutTree->Branch("g_pid_Kpi", g_pid_Kpi, "g_pid_Kpi[g_nK]/I");
        fOutTree->Branch("g_gid_Kpi", g_gid_Kpi, "g_gid_Kpi[g_nK]/I");
        fOutTree->Branch("g_key_Kpi", g_key_Kpi, "g_key_Kpi[g_nK]/I");
        fOutTree->Branch("g_e_Kpi", g_e_Kpi, "g_e_Kpi[g_nK]/D");  
        fOutTree->Branch("g_pt_Kpi", g_pt_Kpi, "g_pt_Kpi[g_nK]/D");
        fOutTree->Branch("g_eta_Kpi", g_eta_Kpi, "g_eta_Kpi[g_nK]/D");
        fOutTree->Branch("g_phi_Kpi", g_phi_Kpi, "g_phi_Kpi[g_nK]/D");
        fOutTree->Branch("g_im_Kpi", g_im_Kpi, "g_im_Kpi[g_nK]/D");
        fOutTree->Branch("g_x_stop_K", g_x_stop_K, "g_x_stop_K[g_nK]/D");
        fOutTree->Branch("g_y_stop_K", g_y_stop_K, "g_y_stop_K[g_nK]/D");
        fOutTree->Branch("g_z_stop_K", g_z_stop_K, "g_z_stop_K[g_nK]/D");
        fOutTree->Branch("g_pid_K", g_pid_K, "g_pid_K[g_nK]/I");
        fOutTree->Branch("g_gid_K", g_gid_K, "g_gid_K[g_nK]/I");
        fOutTree->Branch("g_key_K", g_key_K, "g_key_K[g_nK]/I");
        fOutTree->Branch("g_e_K", g_e_K, "g_e_K[g_nK]/D");  
        fOutTree->Branch("g_pt_K", g_pt_K, "g_pt_K[g_nK]/D");
        fOutTree->Branch("g_eta_K", g_eta_K, "g_eta_K[g_nK]/D");
        fOutTree->Branch("g_phi_K", g_phi_K, "g_phi_K[g_nK]/D");
        fOutTree->Branch("g_im_K", g_im_K, "g_im_K[g_nK]/D");
        fOutTree->Branch("g_x_start_K", g_x_start_K, "g_x_start_K[g_nK]/D");
        fOutTree->Branch("g_y_start_K", g_y_start_K, "g_y_start_K[g_nK]/D");
        fOutTree->Branch("g_z_start_K", g_z_start_K, "g_z_start_K[g_nK]/D");
        fOutTree->Branch("g_geantProc_start_K", g_geantProc_start_K, "g_geantProc_start_K[g_nK]/I");
        fOutTree->Branch("g_geantMedium_start_K", g_geantMedium_start_K, "g_geantMedium_start_K[g_nK]/I");
        fOutTree->Branch("g_generatorProc_start_K", g_generatorProc_start_K, "g_generatorProc_start_K[g_nK]/I");
        fOutTree->Branch("g_key_start_K", g_key_start_K, "g_key_start_K[g_nK]/I");
        fOutTree->Branch("g_pid_parent_K", g_pid_parent_K, "g_pid_parent_K[g_nK]/I");
        fOutTree->Branch("g_gid_parent_K", g_gid_parent_K, "g_gid_parent_K[g_nK]/I");
        fOutTree->Branch("g_key_parent_K", g_key_parent_K, "g_key_parent_K[g_nK]/I");

	fOutTree->Branch("a_nL", &a_nL, "a_nL/I");
        fOutTree->Branch("a_pid_Lp", a_pid_Lp, "a_pid_Lp[a_nL]/I");
        fOutTree->Branch("a_gid_Lp", a_gid_Lp, "a_gid_Lp[a_nL]/I");
        fOutTree->Branch("a_key_Lp", a_key_Lp, "a_key_Lp[a_nL]/I");
        fOutTree->Branch("a_e_Lp", a_e_Lp, "a_e_Lp[a_nL]/D");
        fOutTree->Branch("a_pt_Lp", a_pt_Lp, "a_pt_Lp[a_nL]/D");
        fOutTree->Branch("a_eta_Lp", a_eta_Lp, "a_eta_Lp[a_nL]/D");
        fOutTree->Branch("a_phi_Lp", a_phi_Lp, "a_phi_Lp[a_nL]/D");
        fOutTree->Branch("a_dca_Lp", a_dca_Lp, "a_dca_Lp[a_nL]/D");
        fOutTree->Branch("a_flag_Lp", a_flag_Lp, "a_flag_Lp[a_nL]/I");
        fOutTree->Branch("a_nFit_Lp", a_nFit_Lp, "a_nFit_Lp[a_nL]/I");
        fOutTree->Branch("a_ratio_Lp", a_ratio_Lp, "a_ratio_Lp[a_nL]/D");
        fOutTree->Branch("a_pid_Lpi", a_pid_Lpi, "a_pid_Lpi[a_nL]/I");
        fOutTree->Branch("a_gid_Lpi", a_gid_Lpi, "a_gid_Lpi[a_nL]/I");
        fOutTree->Branch("a_key_Lpi", a_key_Lpi, "a_key_Lpi[a_nL]/I");
        fOutTree->Branch("a_e_Lpi", a_e_Lpi, "a_e_Lpi[a_nL]/D");
        fOutTree->Branch("a_pt_Lpi", a_pt_Lpi, "a_pt_Lpi[a_nL]/D");
        fOutTree->Branch("a_eta_Lpi", a_eta_Lpi, "a_eta_Lpi[a_nL]/D");
        fOutTree->Branch("a_phi_Lpi", a_phi_Lpi, "a_phi_Lpi[a_nL]/D"); 
        fOutTree->Branch("a_dca_Lpi", a_dca_Lpi, "a_dca_Lpi[a_nL]/D");
        fOutTree->Branch("a_flag_Lpi", a_flag_Lpi, "a_flag_Lpi[a_nL]/I");
        fOutTree->Branch("a_nFit_Lpi", a_nFit_Lpi, "a_nFit_Lpi[a_nL]/I");
        fOutTree->Branch("a_ratio_Lpi", a_ratio_Lpi, "a_ratio_Lpi[a_nL]/D");
        fOutTree->Branch("a_x_stop_L", a_x_stop_L, "a_x_stop_L[a_nL]/D");
        fOutTree->Branch("a_y_stop_L", a_y_stop_L, "a_y_stop_L[a_nL]/D");
        fOutTree->Branch("a_z_stop_L", a_z_stop_L, "a_z_stop_L[a_nL]/D");
        fOutTree->Branch("a_pt_L", a_pt_L, "a_pt_L[a_nL]/D");
        fOutTree->Branch("a_eta_L", a_eta_L, "a_eta_L[a_nL]/D");
        fOutTree->Branch("a_phi_L", a_phi_L, "a_phi_L[a_nL]/D");
        fOutTree->Branch("a_im_L", a_im_L, "a_im_L[a_nL]/D");
        fOutTree->Branch("a_dl_L", a_dl_L, "a_dl_L[a_nL]/D");
        fOutTree->Branch("a_dca2_L", a_dca2_L, "a_dca2_L[a_nL]/D");
        fOutTree->Branch("a_dcaV0_L", a_dcaV0_L, "a_dcaV0_L[a_nL]/D");
        fOutTree->Branch("a_crp_L", a_crp_L, "a_crp_L[a_nL]/D");
        fOutTree->Branch("a_pid_parent_L", a_pid_parent_L, "a_pid_mom_L[a_nL]/I");
        fOutTree->Branch("a_gid_parent_L", a_gid_parent_L, "a_gid_mom_L[a_nL]/I");
        fOutTree->Branch("a_key_parent_L", a_key_parent_L, "a_key_mom_L[a_nL]/I");
	
	fOutTree->Branch("a_nA", &a_nA, "a_nA/I");
        fOutTree->Branch("a_pid_Ap", a_pid_Ap, "a_pid_Ap[a_nA]/I");
        fOutTree->Branch("a_gid_Ap", a_gid_Ap, "a_gid_Ap[a_nA]/I");
        fOutTree->Branch("a_key_Ap", a_key_Ap, "a_key_Ap[a_nA]/I");
        fOutTree->Branch("a_e_Ap", a_e_Ap, "a_e_Ap[a_nA]/D");
        fOutTree->Branch("a_pt_Ap", a_pt_Ap, "a_pt_Ap[a_nA]/D");
        fOutTree->Branch("a_eta_Ap", a_eta_Ap, "a_eta_Ap[a_nA]/D");
        fOutTree->Branch("a_phi_Ap", a_phi_Ap, "a_phi_Ap[a_nA]/D");
        fOutTree->Branch("a_dca_Ap", a_dca_Ap, "a_dca_Ap[a_nA]/D");
        fOutTree->Branch("a_flag_Ap", a_flag_Ap, "a_flag_Ap[a_nA]/I");
        fOutTree->Branch("a_nFit_Ap", a_nFit_Ap, "a_nFit_Ap[a_nA]/I");
        fOutTree->Branch("a_ratio_Ap", a_ratio_Ap, "a_ratio_Ap[a_nA]/D");
        fOutTree->Branch("a_pid_Api", a_pid_Api, "a_pid_Api[a_nA]/I");
        fOutTree->Branch("a_gid_Api", a_gid_Api, "a_gid_Api[a_nA]/I");
        fOutTree->Branch("a_key_Api", a_key_Api, "a_key_Api[a_nA]/I");
        fOutTree->Branch("a_e_Api", a_e_Api, "a_e_Api[a_nA]/D");
        fOutTree->Branch("a_pt_Api", a_pt_Api, "a_pt_Api[a_nA]/D");
        fOutTree->Branch("a_eta_Api", a_eta_Api, "a_eta_Api[a_nA]/D");
        fOutTree->Branch("a_phi_Api", a_phi_Api, "a_phi_Api[a_nA]/D"); 
        fOutTree->Branch("a_dca_Api", a_dca_Api, "a_dca_Api[a_nA]/D");
        fOutTree->Branch("a_flag_Api", a_flag_Api, "a_flag_Api[a_nA]/I");
        fOutTree->Branch("a_nFit_Api", a_nFit_Api, "a_nFit_Api[a_nA]/I");
        fOutTree->Branch("a_ratio_Api", a_ratio_Api, "a_ratio_Api[a_nA]/D");
        fOutTree->Branch("a_x_stop_A", a_x_stop_A, "a_x_stop_A[a_nA]/D");
        fOutTree->Branch("a_y_stop_A", a_y_stop_A, "a_y_stop_A[a_nA]/D");
        fOutTree->Branch("a_z_stop_A", a_z_stop_A, "a_z_stop_A[a_nA]/D");
        fOutTree->Branch("a_pt_A", a_pt_A, "a_pt_A[a_nA]/D");
        fOutTree->Branch("a_eta_A", a_eta_A, "a_eta_A[a_nA]/D");
        fOutTree->Branch("a_phi_A", a_phi_A, "a_phi_A[a_nA]/D");
        fOutTree->Branch("a_im_A", a_im_A, "a_im_A[a_nA]/D");
        fOutTree->Branch("a_dl_A", a_dl_A, "a_dl_A[a_nA]/D");
        fOutTree->Branch("a_dca2_A", a_dca2_A, "a_dca2_A[a_nA]/D");
        fOutTree->Branch("a_dcaV0_A", a_dcaV0_A, "a_dcaV0_A[a_nA]/D");
        fOutTree->Branch("a_crp_A", a_crp_A, "a_crp_A[a_nA]/D");
        fOutTree->Branch("a_pid_parent_A", a_pid_parent_A, "a_pid_mom_A[a_nA]/I");
        fOutTree->Branch("a_gid_parent_A", a_gid_parent_A, "a_gid_mom_A[a_nA]/I");
        fOutTree->Branch("a_key_parent_A", a_key_parent_A, "a_key_mom_A[a_nA]/I");

	fOutTree->Branch("a_nK", &a_nK, "a_nK/I");
        fOutTree->Branch("a_pid_Kp", a_pid_Kp, "a_pid_Kp[a_nK]/I");
        fOutTree->Branch("a_gid_Kp", a_gid_Kp, "a_gid_Kp[a_nK]/I");
        fOutTree->Branch("a_key_Kp", a_key_Kp, "a_key_Kp[a_nK]/I");
        fOutTree->Branch("a_e_Kp", a_e_Kp, "a_e_Kp[a_nK]/D");
        fOutTree->Branch("a_pt_Kp", a_pt_Kp, "a_pt_Kp[a_nK]/D");
        fOutTree->Branch("a_eta_Kp", a_eta_Kp, "a_eta_Kp[a_nK]/D");
        fOutTree->Branch("a_phi_Kp", a_phi_Kp, "a_phi_Kp[a_nK]/D");
        fOutTree->Branch("a_dca_Kp", a_dca_Kp, "a_dca_Kp[a_nK]/D");
        fOutTree->Branch("a_flag_Kp", a_flag_Kp, "a_flag_Kp[a_nK]/I");
        fOutTree->Branch("a_nFit_Kp", a_nFit_Kp, "a_nFit_Kp[a_nK]/I");
        fOutTree->Branch("a_ratio_Kp", a_ratio_Kp, "a_ratio_Kp[a_nK]/D");
        fOutTree->Branch("a_pid_Kpi", a_pid_Kpi, "a_pid_Kpi[a_nK]/I");
        fOutTree->Branch("a_gid_Kpi", a_gid_Kpi, "a_gid_Kpi[a_nK]/I");
        fOutTree->Branch("a_key_Kpi", a_key_Kpi, "a_key_Kpi[a_nK]/I");
        fOutTree->Branch("a_e_Kpi", a_e_Kpi, "a_e_Kpi[a_nK]/D");
        fOutTree->Branch("a_pt_Kpi", a_pt_Kpi, "a_pt_Kpi[a_nK]/D");
        fOutTree->Branch("a_eta_Kpi", a_eta_Kpi, "a_eta_Kpi[a_nK]/D");
        fOutTree->Branch("a_phi_Kpi", a_phi_Kpi, "a_phi_Kpi[a_nK]/D"); 
        fOutTree->Branch("a_dca_Kpi", a_dca_Kpi, "a_dca_Kpi[a_nK]/D");
        fOutTree->Branch("a_flag_Kpi", a_flag_Kpi, "a_flag_Kpi[a_nK]/I");
        fOutTree->Branch("a_nFit_Kpi", a_nFit_Kpi, "a_nFit_Kpi[a_nK]/I");
        fOutTree->Branch("a_ratio_Kpi", a_ratio_Kpi, "a_ratio_Kpi[a_nK]/D");
        fOutTree->Branch("a_x_stop_K", a_x_stop_K, "a_x_stop_K[a_nK]/D");
        fOutTree->Branch("a_y_stop_K", a_y_stop_K, "a_y_stop_K[a_nK]/D");
        fOutTree->Branch("a_z_stop_K", a_z_stop_K, "a_z_stop_K[a_nK]/D");
        fOutTree->Branch("a_pt_K", a_pt_K, "a_pt_K[a_nK]/D");
        fOutTree->Branch("a_eta_K", a_eta_K, "a_eta_K[a_nK]/D");
        fOutTree->Branch("a_phi_K", a_phi_K, "a_phi_K[a_nK]/D");
        fOutTree->Branch("a_im_K", a_im_K, "a_im_K[a_nK]/D");
        fOutTree->Branch("a_dl_K", a_dl_K, "a_dl_K[a_nK]/D");
        fOutTree->Branch("a_dca2_K", a_dca2_K, "a_dca2_K[a_nK]/D");
        fOutTree->Branch("a_dcaV0_K", a_dcaV0_K, "a_dcaV0_K[a_nK]/D");
        fOutTree->Branch("a_crp_K", a_crp_K, "a_crp_K[a_nK]/D");
        fOutTree->Branch("a_pid_parent_K", a_pid_parent_K, "a_pid_mom_K[a_nK]/I");
        fOutTree->Branch("a_gid_parent_K", a_gid_parent_K, "a_gid_mom_K[a_nK]/I");
        fOutTree->Branch("a_key_parent_K", a_key_parent_K, "a_key_mom_K[a_nK]/I");
	
        fOutTree->Branch("trig",   trig, "trig[8]/I");
        fOutTree->Branch("trig_sub",   trig_sub, "trig_sub[5]/I");
	fOutTree->Branch("m_runN", &m_runN, "m_runN/I");
	fOutTree->Branch("m_evtN", &m_evtN, "m_evtN/I");
	fOutTree->Branch("magn",   &magn, "magn/I");
	fOutTree->Branch("m_pvx",  &m_pvx, "m_pvx/D");
	fOutTree->Branch("m_pvy",  &m_pvy, "m_pvy/D");
	fOutTree->Branch("m_pvz",  &m_pvz, "m_pvz/D");

	fOutTree->Branch("m_nL", &m_nL, "m_nL/I");
	fOutTree->Branch("m_dEdx_Lp",    m_dEdx_Lp,    "m_dEdx_Lp[m_nL]/D");
	fOutTree->Branch("m_nSigP_Lp",   m_nSigP_Lp,   "m_nSigP_Lp[m_nL]/D");
	fOutTree->Branch("m_nSigPi_Lp",  m_nSigPi_Lp,  "m_nSigPi_Lp[m_nL]/D");
	fOutTree->Branch("m_pt_Lp",      m_pt_Lp,      "m_pt_Lp[m_nL]/D");
	fOutTree->Branch("m_eta_Lp",     m_eta_Lp,     "m_eta_Lp[m_nL]/D");
	fOutTree->Branch("m_phi_Lp",     m_phi_Lp,     "m_phi_Lp[m_nL]/D");
	fOutTree->Branch("m_dca_Lp",     m_dca_Lp,     "m_dca_Lp[m_nL]/D");
	fOutTree->Branch("m_qaT_Lp",     m_qaT_Lp,     "m_qaT_Lp[m_nL]/I");
	fOutTree->Branch("m_idT_Lp",     m_idT_Lp,     "m_idT_Lp[m_nL]/I");
        fOutTree->Branch("m_tof_Lp",     m_tof_Lp,     "m_tof_Lp[m_nL]/D");
	fOutTree->Branch("m_beta_Lp",    m_beta_Lp,    "m_beta_Lp[m_nL]/D");
	fOutTree->Branch("m_dEdx_Lpi",   m_dEdx_Lpi,   "m_dEdx_Lpi[m_nL]/D");
	fOutTree->Branch("m_nSigP_Lpi",  m_nSigP_Lpi,  "m_nSigP_Lpi[m_nL]/D");
	fOutTree->Branch("m_nSigPi_Lpi", m_nSigPi_Lpi, "m_nSigPi_Lpi[m_nL]/D");
	fOutTree->Branch("m_pt_Lpi",     m_pt_Lpi,     "m_pt_Lpi[m_nL]/D");
	fOutTree->Branch("m_eta_Lpi",    m_eta_Lpi,    "m_eta_Lpi[m_nL]/D");
	fOutTree->Branch("m_phi_Lpi",    m_phi_Lpi,    "m_phi_Lpi[m_nL]/D");
	fOutTree->Branch("m_dca_Lpi",    m_dca_Lpi,    "m_dca_Lpi[m_nL]/D");
	fOutTree->Branch("m_qaT_Lpi",    m_qaT_Lpi,    "m_qaT_Lpi[m_nL]/I");
	fOutTree->Branch("m_idT_Lpi",    m_idT_Lpi,    "m_idT_Lpi[m_nL]/I");
        fOutTree->Branch("m_tof_Lpi",    m_tof_Lpi,    "m_tof_Lpi[m_nL]/D");
	fOutTree->Branch("m_beta_Lpi",   m_beta_Lpi,   "m_beta_Lpi[m_nL]/D");
	fOutTree->Branch("m_dca2_L",     m_dca2_L,     "m_dca2_L[m_nL]/D");
	fOutTree->Branch("m_dcaV0_L",    m_dcaV0_L,    "m_dcaV0_L[m_nL]/D");
	fOutTree->Branch("m_crp_L",      m_crp_L,      "m_crp_L[m_nL]/D");
	fOutTree->Branch("m_dl_L",       m_dl_L,       "m_dl_L[m_nL]/D");
	fOutTree->Branch("m_im_L",       m_im_L,       "m_im_L[m_nL]/D");
	fOutTree->Branch("m_V0x_L",      m_V0x_L,      "m_V0x_L[m_nL]/D");
	fOutTree->Branch("m_V0y_L",      m_V0y_L,      "m_V0y_L[m_nL]/D");
	fOutTree->Branch("m_V0z_L",      m_V0z_L,      "m_V0z_L[m_nL]/D");
	fOutTree->Branch("m_pt_L",       m_pt_L,       "m_pt_L[m_nL]/D");
	fOutTree->Branch("m_eta_L",      m_eta_L,      "m_eta_L[m_nL]/D");
	fOutTree->Branch("m_phi_L",      m_phi_L,      "m_phi_L[m_nL]/D");

	fOutTree->Branch("m_nA", &m_nA, "m_nA/I");
	fOutTree->Branch("m_dEdx_Ap",    m_dEdx_Ap,    "m_dEdx_Ap[m_nA]/D");
	fOutTree->Branch("m_nSigP_Ap",   m_nSigP_Ap,   "m_nSigP_Ap[m_nA]/D");
	fOutTree->Branch("m_nSigPi_Ap",  m_nSigPi_Ap,  "m_nSigPi_Ap[m_nA]/D");
	fOutTree->Branch("m_pt_Ap",      m_pt_Ap,      "m_pt_Ap[m_nA]/D");
	fOutTree->Branch("m_eta_Ap",     m_eta_Ap,     "m_eta_Ap[m_nA]/D");
	fOutTree->Branch("m_phi_Ap",     m_phi_Ap,     "m_phi_Ap[m_nA]/D");
	fOutTree->Branch("m_dca_Ap",     m_dca_Ap,     "m_dca_Ap[m_nA]/D");
	fOutTree->Branch("m_qaT_Ap",     m_qaT_Ap,     "m_qaT_Ap[m_nA]/I");
	fOutTree->Branch("m_idT_Ap",     m_idT_Ap,     "m_idT_Ap[m_nA]/I");
        fOutTree->Branch("m_tof_Ap",     m_tof_Ap,     "m_tof_Ap[m_nA]/I");
	fOutTree->Branch("m_beta_Ap",    m_beta_Ap,    "m_beta_Ap[m_nA]/D");
	fOutTree->Branch("m_dEdx_Api",   m_dEdx_Api,   "m_dEdx_Api[m_nA]/D");
	fOutTree->Branch("m_nSigP_Api",  m_nSigP_Api,  "m_nSigP_Api[m_nA]/D");
	fOutTree->Branch("m_nSigPi_Api", m_nSigPi_Api, "m_nSigPi_Api[m_nA]/D");
	fOutTree->Branch("m_pt_Api",     m_pt_Api,     "m_pt_Api[m_nA]/D");
	fOutTree->Branch("m_eta_Api",    m_eta_Api,    "m_eta_Api[m_nA]/D");
	fOutTree->Branch("m_phi_Api",    m_phi_Api,    "m_phi_Api[m_nA]/D");
	fOutTree->Branch("m_dca_Api",    m_dca_Api,    "m_dca_Api[m_nA]/D");
	fOutTree->Branch("m_qaT_Api",    m_qaT_Api,    "m_qaT_Api[m_nA]/I");
	fOutTree->Branch("m_idT_Api",    m_idT_Api,    "m_idT_Api[m_nA]/I");
        fOutTree->Branch("m_tof_Api",    m_tof_Api,    "m_tof_Api[m_nA]/I");
	fOutTree->Branch("m_beta_Api",   m_beta_Api,   "m_beta_Api[m_nA]/D");
	fOutTree->Branch("m_dca2_A",     m_dca2_A,     "m_dca2_A[m_nA]/D");
	fOutTree->Branch("m_dcaV0_A",    m_dcaV0_A,    "m_dcaV0_A[m_nA]/D");
	fOutTree->Branch("m_crp_A",      m_crp_A,      "m_crp_A[m_nA]/D");
	fOutTree->Branch("m_dl_A",       m_dl_A,       "m_dl_A[m_nA]/D");
	fOutTree->Branch("m_im_A",       m_im_A,       "m_im_A[m_nA]/D");
	fOutTree->Branch("m_V0x_A",      m_V0x_A,      "m_V0x_A[m_nA]/D");
	fOutTree->Branch("m_V0y_A",      m_V0y_A,      "m_V0y_A[m_nA]/D");
	fOutTree->Branch("m_V0z_A",      m_V0z_A,      "m_V0z_A[m_nA]/D");
	fOutTree->Branch("m_pt_A",       m_pt_A,       "m_pt_A[m_nA]/D");
	fOutTree->Branch("m_eta_A",      m_eta_A,      "m_eta_A[m_nA]/D");
	fOutTree->Branch("m_phi_A",      m_phi_A,      "m_phi_A[m_nA]/D");

	fOutTree->Branch("m_nK", &m_nK, "m_nK/I");
	fOutTree->Branch("m_dEdx_Kp",    m_dEdx_Kp,    "m_dEdx_Kp[m_nK]/D");
	fOutTree->Branch("m_nSigP_Kp",   m_nSigP_Kp,   "m_nSigP_Kp[m_nK]/D");
	fOutTree->Branch("m_nSigPi_Kp",  m_nSigPi_Kp,  "m_nSigPi_Kp[m_nK]/D");
	fOutTree->Branch("m_pt_Kp",      m_pt_Kp,      "m_pt_Kp[m_nK]/D");
	fOutTree->Branch("m_eta_Kp",     m_eta_Kp,     "m_eta_Kp[m_nK]/D");
	fOutTree->Branch("m_phi_Kp",     m_phi_Kp,     "m_phi_Kp[m_nK]/D");
	fOutTree->Branch("m_dca_Kp",     m_dca_Kp,     "m_dca_Kp[m_nK]/D");
	fOutTree->Branch("m_qaT_Kp",     m_qaT_Kp,     "m_qaT_Kp[m_nK]/I");
	fOutTree->Branch("m_idT_Kp",     m_idT_Kp,     "m_idT_Kp[m_nK]/I");
        fOutTree->Branch("m_tof_Kp",     m_tof_Kp,     "m_tof_Kp[m_nK]/I");
	fOutTree->Branch("m_beta_Kp",    m_beta_Kp,    "m_beta_Kp[m_nK]/D");
	fOutTree->Branch("m_dEdx_Kpi",   m_dEdx_Kpi,   "m_dEdx_Kpi[m_nK]/D");
	fOutTree->Branch("m_nSigP_Kpi",  m_nSigP_Kpi,  "m_nSigP_Kpi[m_nK]/D");
	fOutTree->Branch("m_nSigPi_Kpi", m_nSigPi_Kpi, "m_nSigPi_Kpi[m_nK]/D");
	fOutTree->Branch("m_pt_Kpi",     m_pt_Kpi,     "m_pt_Kpi[m_nK]/D");
	fOutTree->Branch("m_eta_Kpi",    m_eta_Kpi,    "m_eta_Kpi[m_nK]/D");
	fOutTree->Branch("m_phi_Kpi",    m_phi_Kpi,    "m_phi_Kpi[m_nK]/D");
	fOutTree->Branch("m_dca_Kpi",    m_dca_Kpi,    "m_dca_Kpi[m_nK]/D");
	fOutTree->Branch("m_qaT_Kpi",    m_qaT_Kpi,    "m_qaT_Kpi[m_nK]/I");
	fOutTree->Branch("m_idT_Kpi",    m_idT_Kpi,    "m_idT_Kpi[m_nK]/I");
        fOutTree->Branch("m_tof_Kpi",    m_tof_Kpi,    "m_tof_Kpi[m_nK]/I");
	fOutTree->Branch("m_beta_Kpi",   m_beta_Kpi,   "m_beta_Kpi[m_nK]/D");
	fOutTree->Branch("m_dca2_K",     m_dca2_K,     "m_dca2_K[m_nK]/D");
	fOutTree->Branch("m_dcaV0_K",    m_dcaV0_K,    "m_dcaV0_K[m_nK]/D");
	fOutTree->Branch("m_crp_K",      m_crp_K,      "m_crp_K[m_nK]/D");
	fOutTree->Branch("m_dl_K",       m_dl_K,       "m_dl_K[m_nK]/D");
	fOutTree->Branch("m_im_K",       m_im_K,       "m_im_K[m_nK]/D");
	fOutTree->Branch("m_V0x_K",      m_V0x_K,      "m_V0x_K[m_nK]/D");
	fOutTree->Branch("m_V0y_K",      m_V0y_K,      "m_V0y_K[m_nK]/D");
	fOutTree->Branch("m_V0z_K",      m_V0z_K,      "m_V0z_K[m_nK]/D");
	fOutTree->Branch("m_pt_K",       m_pt_K,       "m_pt_K[m_nK]/D");
	fOutTree->Branch("m_eta_K",      m_eta_K,      "m_eta_K[m_nK]/D");
	fOutTree->Branch("m_phi_K",      m_phi_K,      "m_phi_K[m_nK]/D");


	LOG_INFO << "Output Tree Build Finish" << endm;
}

//___Initialize_Maker______________________________________________________
int StLamMcMaker::Init() {
	LOG_INFO << "StLamMcMaker Initialize " << endm;

	fOutFile = new TFile( foutName, "recreate" );
	InitOutTree();
	
	//LOG_INFO << "Get StMcEventMaker " << endm;
	fmcEventMaker = (StMcEventMaker*)GetMaker( "McEventMaker" );
	assert( fmcEventMaker );
	//LOG_INFO << "Get StEmcSimulatorMaker " << endm;
	//femcSimulatorMaker = (StEmcSimulatorMaker*)GetMaker( "EmcSimulator" );
	//assert( femcSimulatorMaker );
	//LOG_INFO << "Get StTriggerSimuMaker " << endm;
	ftrigSimuMaker = (StTriggerSimuMaker*)GetMaker( "TriggerSimu" );
	assert( ftrigSimuMaker );
	//LOG_INFO << "Get StAssociationMaker " << endm;
	fassociationMaker = (StAssociationMaker*)GetMaker( "Association" );
	assert( fassociationMaker );

	//LOG_INFO << "Build Some Histograms " << endm;
	h_PVz0_g = new TH1D("h_PVz0_g", "h_PVz0_g", 200, -200.0, 200.0);
        h_PVz1_g = new TH1D("h_PVz1_g", "h_PVz1_g", 200, -200.0, 200.0);
        h_PVz0_m = new TH1D("h_PVz0_m", "h_PVz0_m", 200, -200.0, 200.0);
        h_PVz1_m = new TH1D("h_PVz1_m", "h_PVz1_m", 200, -200.0, 200.0);
        h2_etaphi_pi_P_g = new TH2D("h2_etaphi_pi_P_g", "h2_etaphi_pi_P_g", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_pi_P_a = new TH2D("h2_etaphi_pi_P_a", "h2_etaphi_pi_P_a", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_pi_P_m = new TH2D("h2_etaphi_pi_P_m", "h2_etaphi_pi_P_m", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_pi_M_g = new TH2D("h2_etaphi_pi_M_g", "h2_etaphi_pi_M_g", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_pi_M_a = new TH2D("h2_etaphi_pi_M_a", "h2_etaphi_pi_M_a", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_pi_M_m = new TH2D("h2_etaphi_pi_M_m", "h2_etaphi_pi_M_m", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_p_P_g = new TH2D("h2_etaphi_p_P_g", "h2_etaphi_p_P_g", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_p_P_a = new TH2D("h2_etaphi_p_P_a", "h2_etaphi_p_P_a", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_p_P_m = new TH2D("h2_etaphi_p_P_m", "h2_etaphi_p_P_m", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_p_M_g = new TH2D("h2_etaphi_p_M_g", "h2_etaphi_p_M_g", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_p_M_a = new TH2D("h2_etaphi_p_M_a", "h2_etaphi_p_M_a", 320, -3.2, 3.2, 400, -2, 2);
        h2_etaphi_p_M_m = new TH2D("h2_etaphi_p_M_m", "h2_etaphi_p_M_m", 320, -3.2, 3.2, 400, -2, 2);

	return StMaker::Init();
}

int StLamMcMaker::Make() {
	LOG_INFO << "Start StLamMcMaker :: Make() " << GetName() << endm;

	fmcEvent = (StMcEvent*)this->GetDataSet( "StMcEvent" );
	if( !fmcEvent ) {
	    LOG_ERROR << "Error! No McEvent" << endm;
	    return kStErr;
	}
	g_runN = fmcEvent->runNumber();
	g_evtN = fmcEvent->eventNumber();
	if( !fmuDstMaker ) {
	    LOG_ERROR << "Error! No MuDstnaker " << endm;
	    return kStErr;
	}
	fmu = fmuDstMaker->muDst();
	fmuEvent = fmu->event();
	m_runN = fmuEvent->runNumber();
	m_evtN = fmuEvent->eventId();
	assert( g_evtN==m_evtN );

	StEvent *fevent = (StEvent*)this->GetInputDS("StEvent");
	if( !fevent ) {
	    LOG_ERROR << "Error! No StEvent" << endm;
	    return kStSkip;
	}

	// Trigger Simu Result
	for( int i=0; i<8; ++i ) trig[i]=0;

	if( ftrigSimuMaker->isTrigger(370601) ) trig[0]=1; //JP0
	if( ftrigSimuMaker->isTrigger(370611) ) trig[1]=1; //JP1
	if( ftrigSimuMaker->isTrigger(370621) ) trig[2]=1; //JP2
	if( ftrigSimuMaker->isTrigger(370641) ) trig[3]=1; //AJP
	//if( ftrigSimuMaker->isTrigger(370011) ) trig[4]=1; //VPDMB-nobsmd
	//if( ftrigSimuMaker->isTrigger(370501) ) trig[5]=1; //BHT0*VPDMB
        //if( ftrigSimuMaker->isTrigger(370511) ) trig[6]=1; //BHT1*VPDMB
        //if( ftrigSimuMaker->isTrigger(370531) ) trig[7]=1; //BHT2

        for( int i=0; i<5; ++i ) trig_sub[i]=0;
        if( ftrigSimuMaker->emc->JP0() ) trig_sub[0]=1;
        if( ftrigSimuMaker->emc->JP1() ) trig_sub[1]=1;
        if( ftrigSimuMaker->emc->JP2() ) trig_sub[2]=1;
        if( ftrigSimuMaker->emc->AJP() ) trig_sub[3]=1;
        //if( ftrigSimuMaker->bbc->getEandW() ) trig_sub[4]=1;


        LOG_INFO << "===---> TriggerSimuMaker Output <---===" << endm;
        //LOG_INFO << "BHT0: " << ftrigSimuMaker->isTrigger(370501) << endm;
        //LOG_INFO << "BHT1: " << ftrigSimuMaker->isTrigger(370511) << endm;
        //LOG_INFO << "BHT2: " << ftrigSimuMaker->isTrigger(370531) << endm;
        //LOG_INFO << "BBCMB: " << ftrigSimuMaker->isTrigger(370022) << endm;
        LOG_INFO << "JP0: " << ftrigSimuMaker->isTrigger(370601) << endm;
        LOG_INFO << "JP1: " << ftrigSimuMaker->isTrigger(370611) << endm;
        LOG_INFO << "JP2: " << ftrigSimuMaker->isTrigger(370621) << endm;
        LOG_INFO << "AJP: " << ftrigSimuMaker->isTrigger(370641) << endm;

        LOG_INFO << "===---> Sub TriggerSimuMaker Output <---===" << endm;
        //LOG_INFO << "BHT0: " << ftrigSimuMaker->emc->BHT0() << endm;
        //LOG_INFO << "BHT1: " << ftrigSimuMaker->emc->BHT1() << endm;
        //LOG_INFO << "BHT2: " << ftrigSimuMaker->emc->BHT2() << endm;
        //LOG_INFO << "BBCMB: " << ftrigSimuMaker->bbc->getEandW() << endm;
        LOG_INFO << "JP0: " << ftrigSimuMaker->emc->JP0() << endm;
        LOG_INFO << "JP1: " << ftrigSimuMaker->emc->JP1() << endm;
        LOG_INFO << "JP2: " << ftrigSimuMaker->emc->JP2() << endm;
        LOG_INFO << "AJP: " << ftrigSimuMaker->emc->AJP() << endm;

	if( !fassociationMaker ) {
		LOG_WARN << "No Associate Global Track found:  " << endm;
		return kStSkip;
	}
	fmRcTrackMap = fassociationMaker->rcTrackMap();
	fmMcTrackMap = fassociationMaker->mcTrackMap();
	LOG_INFO << "map pointer:" << fmRcTrackMap << endm;

	magn = fmuEvent->magneticField();
	
	// McEvent Ana
	g_idSubproc = fmcEvent->subProcessId();
        g_impactPar = fmcEvent->impactParameter();
        g_phiRP = fmcEvent->phiReactionPlane();
	g_nJets = fmcEvent->nJets();
	StMcVertex *pVertex = fmcEvent->primaryVertex();
	StThreeVectorF pvpos = pVertex->position();
	g_pvx = pvpos.x();
	g_pvy = pvpos.y();
	g_pvz = pvpos.z();
	g_pv_geantProc = pVertex->geantProcess();
	g_pv_geantMedium = pVertex->geantMedium();
	g_pv_generatorProc = pVertex->generatorProcess();
	g_pv_key = pVertex->key();
	LOG_INFO << "geant PV(x,y,z):\t(" << pvpos.x() << ", " << pvpos.y() << ", " << pvpos.z() << ")" << endm;

        if( g_pvz==0 ) { LOG_WARN << "mc event pvz==" << g_pvz << endm; return kStSkip; }
        h_PVz0_g->Fill( pvpos.z() );
        if( fabs( pvpos.z() ) > 60.0 )  return kStSkip;
        h_PVz1_g->Fill( pvpos.z() );	

        //unsigned int nDau = pVertex->numberOfDaughters();

        StSPtrVecMcTrack  & tracks = fmcEvent->tracks();
        StMcTrackIterator   tIter;

        StMcTrack *tParton1 = tracks[6];
        StMcTrack *tParton2 = tracks[7];
        g_idParton1 = tParton1->pdgId();
        g_pxParton1 = tParton1->fourMomentum().px();
        g_pyParton1 = tParton1->fourMomentum().py();
        g_pzParton1 = tParton1->fourMomentum().pz();
        g_mParton1 = tParton1->fourMomentum().m();
        g_eParton1 = tParton1->fourMomentum().e();
        g_idParton2 = tParton2->pdgId();
        g_pxParton2 = tParton2->fourMomentum().px();
        g_pyParton2 = tParton2->fourMomentum().py();
        g_pzParton2 = tParton2->fourMomentum().pz();
        g_mParton2 = tParton2->fourMomentum().m();
        g_eParton2 = tParton2->fourMomentum().e();

        //LOG_INFO << "Loop all tracks" << endm;
        int i=0;
        for(tIter = tracks.begin(); tIter != tracks.end(); tIter++) {
             StMcTrack *track = *tIter;
             const long gId = track->geantId();
             const long pId = track->pdgId();
             i++;

                 //LOG_INFO << i << " ~~pId:  " << pId << " ~~gId:  " << gId << endm;
                 //if( track->parent() ) LOG_INFO << " | mother pId: " << track->parent()->pdgId() << " ~~ mother gId: " << track->parent()->geantId() << endm;
                 LOG_INFO << "\t" << i<< "\t" << gId << "\t" << gId << "\t" << track->fourMomentum().px() << "\t" << track->fourMomentum().py() << "\t" << track->fourMomentum().pz() << "\t" << track->fourMomentum().e() << "\t" << track->fourMomentum().m() << endm;

                 if( track->pt()<0.1 ) continue;

                 if( gId==8||pId==211 ) {
                     h2_etaphi_pi_P_g->Fill(track->fourMomentum().phi(), track->pseudoRapidity());
                     StGlobalTrack *gT = partnerTrack(fmMcTrackMap,track);
                     if( gT && gT->geometry()->momentum().perp()>=0.1 ) h2_etaphi_pi_P_a->Fill(gT->geometry()->momentum().phi(), gT->geometry()->momentum().pseudoRapidity());
                 }
                 if( gId==9||pId==-211 ) {
                     h2_etaphi_pi_M_g->Fill(track->fourMomentum().phi(), track->pseudoRapidity());
                     StGlobalTrack *gT = partnerTrack(fmMcTrackMap,track);
                     if( gT && gT->geometry()->momentum().perp()>=0.1 ) h2_etaphi_pi_M_a->Fill(gT->geometry()->momentum().phi(), gT->geometry()->momentum().pseudoRapidity());
                 }
                 if( gId==14||pId==2212 ) {
                     h2_etaphi_p_P_g->Fill(track->fourMomentum().phi(), track->pseudoRapidity());
                     StGlobalTrack *gT = partnerTrack(fmMcTrackMap,track);
                     if( gT && gT->geometry()->momentum().perp()>=0.1 ) h2_etaphi_p_P_a->Fill(gT->geometry()->momentum().phi(), gT->geometry()->momentum().pseudoRapidity());
                 }
                 if( gId==15||pId==-2212 ) {
                     h2_etaphi_p_M_g->Fill(track->fourMomentum().phi(), track->pseudoRapidity());
                     StGlobalTrack *gT = partnerTrack(fmMcTrackMap,track);
                     if( gT && gT->geometry()->momentum().perp()>=0.1 ) h2_etaphi_p_M_a->Fill(gT->geometry()->momentum().phi(), gT->geometry()->momentum().pseudoRapidity());
                 }
        }

        g_nL=0; g_nA=0; g_nK=0;
        a_nL=0; a_nA=0; a_nK=0;

        i=0;
        for( tIter=tracks.begin(); tIter!=tracks.end(); tIter++ ) {
             StMcTrack *track = *tIter;
             if( !track ) continue;
             const long gId = track->geantId();
             const long pId = track->pdgId();
             i++;
             if( gId!=18 && gId!=26 && gId!=16 && fabs(pId)!=3122 && pId!=310 ) continue;
             StMcVertex *ver_start = 0; 
             StMcVertex *ver_stop = 0; 
             StMcTrack *tra_parent = 0; 
             StMcTrack *tra_dau0 = 0; 
             StMcTrack *tra_dau1 = 0; 
             StMcTrack *tra_P = 0; 
             StMcTrack *tra_Pi = 0; 

             if( gId==18 || pId==3122 ) {
                 ver_start = track->startVertex();
                 ver_stop = track->stopVertex();
                 tra_parent = track->parent();

                 //ver_stop = vertex;
                 if( !ver_start ) LOG_INFO << "|=--> ver_start cannot be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;
                 if( !ver_stop ) LOG_INFO << "|=--> ver_stop cannot be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;
                 if( !tra_parent ) LOG_INFO << "|=--> tra_parent cannot be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;

                 if( !(ver_start&&ver_stop&&tra_parent) ) {
                     LOG_INFO << "|=--> ver_start or ver_stop or tra_parent not be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm; 
                     continue;
                 } 

                 //unsigned int ndau = ver_stop->numberOfDaughters();
                 unsigned int ndau = ver_stop->numberOfDaughters();
                 //LOG_INFO << "daughter number: " << ndau << endm;
                 if( ndau != 2 ) {
                     LOG_INFO << "|=--> Number of daughters is not 2. -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;
                     continue;
                 }

                 StThreeVectorD pos_start = ver_start->position();
                 long geantProc_start = ver_start->geantProcess();
                 long geantMedium_start = ver_start->geantMedium();
                 long generatorProc_start = ver_start->generatorProcess();
                 long key_start = ver_start->key();

                 long pId_parent = tra_parent->pdgId();
                 long gId_parent = tra_parent->geantId();
                 long key_parent = tra_parent->key();

                 StThreeVectorD pos_stop = ver_stop->position();
                 tra_dau0 = ver_stop->daughter(0);
                 tra_dau1 = ver_stop->daughter(1);
                 long pId_dau0 = tra_dau0->pdgId();
                 long gId_dau0 = tra_dau0->geantId();
                 long pId_dau1 = tra_dau1->pdgId();
                 long gId_dau1 = tra_dau1->geantId();
                 if( (pId_dau0==2212||gId_dau0==14) && (pId_dau1==-211||gId_dau1==9) ) {
                     tra_P = tra_dau0;
                     tra_Pi = tra_dau1;
                 }
                 if( (pId_dau1==2212||gId_dau1==14) && (pId_dau0==-211||gId_dau0==9) ) {
                     tra_P = tra_dau1;
                     tra_Pi = tra_dau0;
                 }
                 if( !tra_P || !tra_Pi ) continue;

                 g_pid_Lp[g_nL]              = tra_P->pdgId();
                 g_gid_Lp[g_nL]              = tra_P->geantId();
                 g_key_Lp[g_nL]              = tra_P->key();
                 g_e_Lp[g_nL]                = tra_P->energy();
                 g_pt_Lp[g_nL]               = tra_P->pt();
                 g_eta_Lp[g_nL]              = tra_P->pseudoRapidity();
                 g_phi_Lp[g_nL]              = tra_P->fourMomentum().phi();
                 g_im_Lp[g_nL]               = tra_P->fourMomentum().m();

                 g_pid_Lpi[g_nL]             = tra_Pi->pdgId();             
                 g_gid_Lpi[g_nL]             = tra_Pi->geantId();
                 g_key_Lpi[g_nL]             = tra_Pi->key();
                 g_e_Lpi[g_nL]               = tra_Pi->energy();
                 g_pt_Lpi[g_nL]              = tra_Pi->pt();
                 g_eta_Lpi[g_nL]             = tra_Pi->pseudoRapidity();
                 g_phi_Lpi[g_nL]             = tra_Pi->fourMomentum().phi();
                 g_im_Lpi[g_nL]              = tra_Pi->fourMomentum().m();

                 g_x_stop_L[g_nL]            = pos_stop.x();
                 g_y_stop_L[g_nL]            = pos_stop.y();
                 g_z_stop_L[g_nL]            = pos_stop.z();

                 g_pid_L[g_nL]               = track->pdgId();
                 g_gid_L[g_nL]               = track->geantId();
                 g_key_L[g_nL]               = track->key();
                 g_e_L[g_nL]                 = track->energy();
                 g_pt_L[g_nL]                = track->pt();
                 g_eta_L[g_nL]               = track->pseudoRapidity();
                 g_phi_L[g_nL]               = track->fourMomentum().phi();
                 g_im_L[g_nL]                = track->fourMomentum().m();

                 g_x_start_L[g_nL]           = pos_start.x();
                 g_y_start_L[g_nL]           = pos_start.y();
                 g_z_start_L[g_nL]           = pos_start.z();
                 g_geantProc_start_L[g_nL]     = geantProc_start;
                 g_geantMedium_start_L[g_nL]   = geantMedium_start;
                 g_generatorProc_start_L[g_nL] = generatorProc_start;
                 g_key_start_L[g_nL]           = key_start;                 

                 g_pid_parent_L[g_nL]           = pId_parent;
                 g_gid_parent_L[g_nL]           = gId_parent;
                 g_key_parent_L[g_nL]           = key_parent;

                 g_nL++;

                 LOG_INFO << "--> Association Start" << endm;
                 StGlobalTrack *gP = partnerTrack(fmMcTrackMap,tra_P);
                 if( !gP ) continue;
                 if( gP->geometry()->momentum().perp() < 0.1 ) continue;
                 if( gP->geometry()->charge()<0 ) {
                     LOG_WARN << "charge error proton+ ? " << endm;
                     continue;
                 }    
                 StGlobalTrack *gPi = partnerTrack(fmMcTrackMap,tra_Pi);
                 if( !gPi ) continue;
                 if( gPi->geometry()->momentum().perp() < 0.1 ) continue;
                 if( gPi->geometry()->charge()>0 ) {
                     LOG_WARN << "charge error pion- ? " << endm;
                     continue;
                 }
                 LOG_INFO << "--> Find an associated global tracks" << endm;

                 short nFit_p = gP->fitTraits().numberOfFitPoints();
                 short nFitPoss_p = gP->numberOfPossiblePoints();
                 double ratio_p = double(nFit_p) / double(nFitPoss_p);
                 LOG_INFO << "Proton Track flag :  " << gP->flag() << endm;
                 LOG_INFO << "Proton Track nFit :  " << gP->fitTraits().numberOfFitPoints() << endm;
                 LOG_INFO << "Proton Track Fit_ratio :  " << ratio_p << endm;
                 if( gP->flag()<0 || gP->flag()>1000 ) continue;
                 if( nFit_p<10 ) continue;
                 //if( ratio_p<0.51 ) continue;
                 short nFit_pi = gPi->fitTraits().numberOfFitPoints();
                 short nFitPoss_pi = gPi->numberOfPossiblePoints();
                 double ratio_pi = double(nFit_pi) / double(nFitPoss_pi);
                 LOG_INFO << "Pion Track flag :  " << gPi->flag() << endm;
                 LOG_INFO << "Pion Track nFit :  " << gPi->fitTraits().numberOfFitPoints() << endm;     
                 LOG_INFO << "Pion Track Fit_ratio :  " << ratio_pi << endm;
                 if( gPi->flag()<0 || gPi->flag()>1000 ) continue;
                 if( nFit_pi<10 ) continue;
                 //if( ratio_pi<0.51 ) continue;
                 StPhysicalHelixD helix_proton = gP->geometry()->helix();
                 StPhysicalHelixD helix_pion   = gPi->geometry()->helix();
                 double pathlength_p = helix_proton.pathLength(pvpos);
                 StThreeVectorD dca3p = helix_proton.at(pathlength_p) - pvpos;
                 double dca_p = dca3p.mag();
                 //LOG_INFO << "Proton Track dca :  " << dca_p << endm;
                 double pathlength_pi = helix_pion.pathLength(pvpos);
                 StThreeVectorD dca3pi = helix_pion.at(pathlength_pi) - pvpos;
                 double dca_pi = dca3pi.mag();
                 //LOG_INFO << "Pion Track dca :  " << dca_pi << endm;
                 pair<double,double> ss = helix_proton.pathLengths(helix_pion);
                 double s1 = ss.first;
                 double s2 = ss.second;
                 StThreeVectorD V0 = (helix_proton.at(s1) + helix_pion.at(s2))/2.0;
                 StThreeVectorD V0mp = V0 - pvpos;
                 if( V0mp.mag()<2.0 ) continue;
                 StThreeVectorD tdca = helix_proton.at(s1) - helix_pion.at(s2);
                 double tdca2 = tdca.mag();
                 if( tdca2>2.0 ) continue;
                 //LOG_INFO << "DCA_2 :  " << tdca2 << endm;
                 StThreeVectorD Tp_p  = helix_proton.momentumAt(s1,magn*kilogauss);
                 StThreeVectorD Tpi_p = helix_pion.momentumAt(s2,magn*kilogauss);
                 StThreeVectorD T_p   = Tp_p + Tpi_p;
                 if( T_p.mag()<1E-5 ) continue;
                 double dot = T_p.dot(V0mp);
                 double tcrp = dot/(T_p.mag()*V0mp.mag());
                 if( tcrp<0.9 ) continue;
                 double tdcaV0 = sqrt(V0mp.mag2() - dot*dot/T_p.mag2());
                 if( tdcaV0>1.5 ) continue;
                 double Tp_E = sqrt(M_proton*M_proton + Tp_p.mag2());
                 double Tpi_E = sqrt(M_pion*M_pion + Tpi_p.mag2());
                 double T_E = Tp_E + Tpi_E;
                 double T_im = sqrt( T_E*T_E - T_p.mag2() );
                 if( T_im>1.16 ) continue;
                 if( T_im<1.08 ) continue;
                 //if( dot<0.0 ) continue;
                 //double toa = OpenAngle(T_lv, Tp_lv, Tpi_lv);

                 a_pid_Lp[a_nL]              = tra_P->pdgId();
                 a_gid_Lp[a_nL]              = tra_P->geantId();
                 a_key_Lp[a_nL]              = tra_P->key();
                 a_e_Lp[a_nL]                = Tp_p.mag();
                 a_pt_Lp[a_nL]               = Tp_p.perp();
                 a_eta_Lp[a_nL]              = Tp_p.pseudoRapidity();
                 a_phi_Lp[a_nL]              = Tp_p.phi();
                 a_dca_Lp[a_nL]              = dca_p;
                 a_flag_Lp[a_nL]             = gP->flag();
                 a_nFit_Lp[a_nL]             = nFit_p;
                 a_ratio_Lp[a_nL]            = ratio_p;

                 a_pid_Lpi[a_nL]             = tra_Pi->pdgId();             
                 a_gid_Lpi[a_nL]             = tra_Pi->geantId();
                 a_key_Lpi[a_nL]             = tra_Pi->key();
                 a_e_Lpi[a_nL]               = Tpi_p.mag();
                 a_pt_Lpi[a_nL]              = Tpi_p.perp();
                 a_eta_Lpi[a_nL]             = Tpi_p.pseudoRapidity();
                 a_phi_Lpi[a_nL]             = Tpi_p.phi();
                 a_dca_Lpi[a_nL]             = dca_pi;
                 a_flag_Lpi[a_nL]            = gPi->flag();
                 a_nFit_Lpi[a_nL]            = nFit_pi;
                 a_ratio_Lpi[a_nL]           = ratio_pi;

                 a_x_stop_L[a_nL]            = V0.x();
                 a_y_stop_L[a_nL]            = V0.y();
                 a_z_stop_L[a_nL]            = V0.z();

                 a_pt_L[a_nL]                = T_p.perp();
                 a_eta_L[a_nL]               = T_p.pseudoRapidity();
                 a_phi_L[a_nL]               = T_p.phi();
                 a_im_L[a_nL]                = T_im;
                 a_dl_L[a_nL]                = V0mp.mag();
                 a_dca2_L[a_nL]              = tdca2;
                 a_dcaV0_L[a_nL]             = tdcaV0;
                 a_crp_L[a_nL]               = tcrp;
            
                 a_pid_parent_L[a_nL]           = pId_parent;
                 a_gid_parent_L[a_nL]           = gId_parent;
                 a_key_parent_L[a_nL]           = key_parent;;

                 a_nL++;
             }

             if( gId==26 || pId==-3122 ) {
                 ver_start = track->startVertex();
                 ver_stop = track->stopVertex();
                 tra_parent = track->parent();

                 //ver_stop = vertex;
                 if( !ver_start ) LOG_INFO << "|=--> ver_start cannot be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;
                 if( !ver_stop ) LOG_INFO << "|=--> ver_stop cannot be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;
                 if( !tra_parent ) LOG_INFO << "|=--> tra_parent cannot be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;

                 if( !(ver_start&&ver_stop&&tra_parent) ) {
                     LOG_INFO << "|=--> ver_start or ver_stop or tra_parent not be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm; 
                     continue;
                 } 

                 //LOG_INFO << ver_start->position().x() << endm;
                 //LOG_INFO << ver_stop->position().x() << endm;
 
                 //unsigned int ndau = ver_stop->numberOfDaughters();
                 unsigned int ndau = ver_stop->numberOfDaughters();
                 LOG_INFO << "daughter number: " << ndau << endm;
                 if( ndau != 2 ) {
                     LOG_INFO << "|=--> Number of daughters is not 2. -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;
                     continue;
                 }

                 StThreeVectorD pos_start = ver_start->position();
                 long geantProc_start = ver_start->geantProcess();
                 long geantMedium_start = ver_start->geantMedium();
                 long generatorProc_start = ver_start->generatorProcess();
                 long key_start = ver_start->key();

                 long pId_parent = tra_parent->pdgId();
                 long gId_parent = tra_parent->geantId();
                 long key_parent = tra_parent->key();

                 StThreeVectorD pos_stop = ver_stop->position();
                 tra_dau0 = ver_stop->daughter(0);
                 tra_dau1 = ver_stop->daughter(1);
                 long pId_dau0 = tra_dau0->pdgId();
                 long gId_dau0 = tra_dau0->geantId();
                 long pId_dau1 = tra_dau1->pdgId();
                 long gId_dau1 = tra_dau1->geantId();
                 if( (pId_dau0==-2212||gId_dau0==15) && (pId_dau1==211||gId_dau1==8) ) {
                     tra_P = tra_dau0;
                     tra_Pi = tra_dau1;
                 }
                 if( (pId_dau1==-2212||gId_dau1==15) && (pId_dau0==211||gId_dau0==8) ) {
                     tra_P = tra_dau1;
                     tra_Pi = tra_dau0;
                 }
                 if( !tra_P || !tra_Pi ) continue;

                 g_pid_Ap[g_nA]              = tra_P->pdgId();
                 g_gid_Ap[g_nA]              = tra_P->geantId();
                 g_key_Ap[g_nA]              = tra_P->key();
                 g_e_Ap[g_nA]                = tra_P->energy();
                 g_pt_Ap[g_nA]               = tra_P->pt();
                 g_eta_Ap[g_nA]              = tra_P->pseudoRapidity();
                 g_phi_Ap[g_nA]              = tra_P->fourMomentum().phi();
                 g_im_Ap[g_nA]               = tra_P->fourMomentum().m();

                 g_pid_Api[g_nA]             = tra_Pi->pdgId();             
                 g_gid_Api[g_nA]             = tra_Pi->geantId();
                 g_key_Api[g_nA]             = tra_Pi->key();
                 g_e_Api[g_nA]               = tra_Pi->energy();
                 g_pt_Api[g_nA]              = tra_Pi->pt();
                 g_eta_Api[g_nA]             = tra_Pi->pseudoRapidity();
                 g_phi_Api[g_nA]             = tra_Pi->fourMomentum().phi();
                 g_im_Api[g_nA]              = tra_Pi->fourMomentum().m();

                 g_x_stop_A[g_nA]            = pos_stop.x();
                 g_y_stop_A[g_nA]            = pos_stop.y();
                 g_z_stop_A[g_nA]            = pos_stop.z();

                 g_pid_A[g_nA]               = track->pdgId();
                 g_gid_A[g_nA]               = track->geantId();
                 g_key_A[g_nA]               = track->key();
                 g_e_A[g_nA]                 = track->energy();
                 g_pt_A[g_nA]                = track->pt();
                 g_eta_A[g_nA]               = track->pseudoRapidity();
                 g_phi_A[g_nA]               = track->fourMomentum().phi();
                 g_im_A[g_nA]                = track->fourMomentum().m();

                 g_x_start_A[g_nA]           = pos_start.x();
                 g_y_start_A[g_nA]           = pos_start.y();
                 g_z_start_A[g_nA]           = pos_start.z();
                 g_geantProc_start_A[g_nA]     = geantProc_start;
                 g_geantMedium_start_A[g_nA]   = geantMedium_start;
                 g_generatorProc_start_A[g_nA] = generatorProc_start;
                 g_key_start_A[g_nA]           = key_start;                 

                 g_pid_parent_A[g_nA]           = pId_parent;
                 g_gid_parent_A[g_nA]           = gId_parent;
                 g_key_parent_A[g_nA]           = key_parent;

                 g_nA++;

                 LOG_INFO << "--> Association Start" << endm;
                 StGlobalTrack *gP = partnerTrack(fmMcTrackMap,tra_P);
                 if( !gP ) continue;
                 if( gP->geometry()->momentum().perp() < 0.1 ) continue;
                 if( gP->geometry()->charge()>0 ) {
                     LOG_WARN << "charge error proton- ? " << endm;
                     continue;
                 }    
                 StGlobalTrack *gPi = partnerTrack(fmMcTrackMap,tra_Pi);
                 if( !gPi ) continue;
                 if( gPi->geometry()->momentum().perp() < 0.1 ) continue;
                 if( gPi->geometry()->charge()<0 ) {
                     LOG_WARN << "charge error pion+ ? " << endm;
                     continue;
                 }
                 LOG_INFO << "--> Find an associated global tracks" << endm;

                 short nFit_p = gP->fitTraits().numberOfFitPoints();
                 short nFitPoss_p = gP->numberOfPossiblePoints();
                 double ratio_p = double(nFit_p) / double(nFitPoss_p);
                 LOG_INFO << "Proton Track flag :  " << gP->flag() << endm;
                 LOG_INFO << "Proton Track nFit :  " << gP->fitTraits().numberOfFitPoints() << endm;
                 LOG_INFO << "Proton Track Fit_ratio :  " << ratio_p << endm;
                 if( gP->flag()<0 || gP->flag()>1000 ) continue;
                 if( nFit_p<10 ) continue;
                 //if( ratio_p<0.51 ) continue;
                 short nFit_pi = gPi->fitTraits().numberOfFitPoints();
                 short nFitPoss_pi = gPi->numberOfPossiblePoints();
                 double ratio_pi = double(nFit_pi) / double(nFitPoss_pi);
                 LOG_INFO << "Pion Track flag :  " << gPi->flag() << endm;
                 LOG_INFO << "Pion Track nFit :  " << gPi->fitTraits().numberOfFitPoints() << endm;     
                 LOG_INFO << "Pion Track Fit_ratio :  " << ratio_pi << endm;
                 if( gPi->flag()<0 || gPi->flag()>1000 ) continue;
                 if( nFit_pi<10 ) continue;
                 //if( ratio_pi<0.51 ) continue;
                 StPhysicalHelixD helix_proton = gP->geometry()->helix();
                 StPhysicalHelixD helix_pion   = gPi->geometry()->helix();
                 double pathlength_p = helix_proton.pathLength(pvpos);
                 StThreeVectorD dca3p = helix_proton.at(pathlength_p) - pvpos;
                 double dca_p = dca3p.mag();
                 //LOG_INFO << "Proton Track dca :  " << dca_p << endm;
                 double pathlength_pi = helix_pion.pathLength(pvpos);
                 StThreeVectorD dca3pi = helix_pion.at(pathlength_pi) - pvpos;
                 double dca_pi = dca3pi.mag();
                 //LOG_INFO << "Pion Track dca :  " << dca_pi << endm;
                 pair<double,double> ss = helix_proton.pathLengths(helix_pion);
                 double s1 = ss.first;
                 double s2 = ss.second;
                 StThreeVectorD V0 = (helix_proton.at(s1) + helix_pion.at(s2))/2.0;
                 StThreeVectorD V0mp = V0 - pvpos;
                 if( V0mp.mag()<2.0 ) continue;
                 StThreeVectorD tdca = helix_proton.at(s1) - helix_pion.at(s2);
                 double tdca2 = tdca.mag();
                 if( tdca2>2.0 ) continue;
                 //LOG_INFO << "DCA_2 :  " << tdca2 << endm;
                 StThreeVectorD Tp_p  = helix_proton.momentumAt(s1,magn*kilogauss);
                 StThreeVectorD Tpi_p = helix_pion.momentumAt(s2,magn*kilogauss);
                 StThreeVectorD T_p   = Tp_p + Tpi_p;
                 if( T_p.mag()<1E-5 ) continue;
                 double dot = T_p.dot(V0mp);
                 double tcrp = dot/(T_p.mag()*V0mp.mag());
                 if( tcrp<0.9 ) continue;
                 double tdcaV0 = sqrt(V0mp.mag2() - dot*dot/T_p.mag2());
                 if( tdcaV0>1.5 ) continue;
                 double Tp_E = sqrt(M_proton*M_proton + Tp_p.mag2());
                 double Tpi_E = sqrt(M_pion*M_pion + Tpi_p.mag2());
                 double T_E = Tp_E + Tpi_E;
                 double T_im = sqrt( T_E*T_E - T_p.mag2() );
                 if( T_im>1.16 ) continue;
                 if( T_im<1.08 ) continue;
                 //if( dot<0.0 ) continue;
                 //double toa = OpenAngle(T_lv, Tp_lv, Tpi_lv);

                 a_pid_Ap[a_nA]              = tra_P->pdgId();
                 a_gid_Ap[a_nA]              = tra_P->geantId();
                 a_key_Ap[a_nA]              = tra_P->key();
                 a_e_Ap[a_nA]                = Tp_p.mag();
                 a_pt_Ap[a_nA]               = Tp_p.perp();
                 a_eta_Ap[a_nA]              = Tp_p.pseudoRapidity();
                 a_phi_Ap[a_nA]              = Tp_p.phi();
                 a_dca_Ap[a_nA]              = dca_p;
                 a_flag_Ap[a_nA]             = gP->flag();
                 a_nFit_Ap[a_nA]             = nFit_p;
                 a_ratio_Ap[a_nA]            = ratio_p;

                 a_pid_Api[a_nA]             = tra_Pi->pdgId();             
                 a_gid_Api[a_nA]             = tra_Pi->geantId();
                 a_key_Api[a_nA]             = tra_Pi->key();
                 a_e_Api[a_nA]               = Tpi_p.mag();
                 a_pt_Api[a_nA]              = Tpi_p.perp();
                 a_eta_Api[a_nA]             = Tpi_p.pseudoRapidity();
                 a_phi_Api[a_nA]             = Tpi_p.phi();
                 a_dca_Api[a_nA]             = dca_pi;
                 a_flag_Api[a_nA]            = gPi->flag();
                 a_nFit_Api[a_nA]            = nFit_pi;
                 a_ratio_Api[a_nA]            = ratio_pi;

                 a_x_stop_A[a_nA]            = V0.x();
                 a_y_stop_A[a_nA]            = V0.y();
                 a_z_stop_A[a_nA]            = V0.z();

                 a_pt_A[a_nA]                = T_p.perp();
                 a_eta_A[a_nA]               = T_p.pseudoRapidity();
                 a_phi_A[a_nA]               = T_p.phi();
                 a_im_A[a_nA]                = T_im;
                 a_dl_A[a_nA]                = V0mp.mag();
                 a_dca2_A[a_nA]              = tdca2;
                 a_dcaV0_A[a_nA]             = tdcaV0;
                 a_crp_A[a_nA]               = tcrp;
            
                 a_pid_parent_A[a_nA]           = pId_parent;
                 a_gid_parent_A[a_nA]           = gId_parent;
                 a_key_parent_A[a_nA]           = key_parent;

                 a_nA++;
             }

             if( gId==16 || pId==310 ) {
                 ver_start = track->startVertex();
                 ver_stop = track->stopVertex();
                 tra_parent = track->parent();

                 //ver_stop = vertex;
                 if( !ver_start ) LOG_INFO << "|=--> ver_start cannot be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;
                 if( !ver_stop ) LOG_INFO << "|=--> ver_stop cannot be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;
                 if( !tra_parent ) LOG_INFO << "|=--> tra_parent cannot be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;

                 if( !(ver_start&&ver_stop&&tra_parent) ) {
                     LOG_INFO << "|=--> ver_start or ver_stop or tra_parent not be found -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm; 
                     continue;
                 } 

                 //LOG_INFO << ver_start->position().x() << endm;
                 //LOG_INFO << ver_stop->position().x() << endm;
 
                 //unsigned int ndau = ver_stop->numberOfDaughters();
                 unsigned int ndau = ver_stop->numberOfDaughters();
                 LOG_INFO << "daughter number: " << ndau << endm;
                 if( ndau != 2 ) {
                     LOG_INFO << "|=--> Number of daughters is not 2. -- track index: " << i << " track pId: " << pId << " - gId: " << gId << endm;
                     continue;
                 }

                 StThreeVectorD pos_start = ver_start->position();
                 long geantProc_start = ver_start->geantProcess();
                 long geantMedium_start = ver_start->geantMedium();
                 long generatorProc_start = ver_start->generatorProcess();
                 long key_start = ver_start->key();

                 long pId_parent = tra_parent->pdgId();
                 long gId_parent = tra_parent->geantId();
                 long key_parent = tra_parent->key();

                 StThreeVectorD pos_stop = ver_stop->position();
                 tra_dau0 = ver_stop->daughter(0);
                 tra_dau1 = ver_stop->daughter(1);
                 long pId_dau0 = tra_dau0->pdgId();
                 long gId_dau0 = tra_dau0->geantId();
                 long pId_dau1 = tra_dau1->pdgId();
                 long gId_dau1 = tra_dau1->geantId();
                 if( (pId_dau0==221||gId_dau0==8) && (pId_dau1==-211||gId_dau1==9) ) {
                     tra_P = tra_dau0;
                     tra_Pi = tra_dau1;
                 }
                 if( (pId_dau1==221||gId_dau1==8) && (pId_dau0==-211||gId_dau0==9) ) {
                     tra_P = tra_dau1;
                     tra_Pi = tra_dau0;
                 }
                 if( !tra_P || !tra_Pi ) continue;

                 g_pid_Kp[g_nK]              = tra_P->pdgId();
                 g_gid_Kp[g_nK]              = tra_P->geantId();
                 g_key_Kp[g_nK]              = tra_P->key();
                 g_e_Kp[g_nK]                = tra_P->energy();
                 g_pt_Kp[g_nK]               = tra_P->pt();
                 g_eta_Kp[g_nK]              = tra_P->pseudoRapidity();
                 g_phi_Kp[g_nK]              = tra_P->fourMomentum().phi();
                 g_im_Kp[g_nK]               = tra_P->fourMomentum().m();

                 g_pid_Kpi[g_nK]             = tra_Pi->pdgId();             
                 g_gid_Kpi[g_nK]             = tra_Pi->geantId();
                 g_key_Kpi[g_nK]             = tra_Pi->key();
                 g_e_Kpi[g_nK]               = tra_Pi->energy();
                 g_pt_Kpi[g_nK]              = tra_Pi->pt();
                 g_eta_Kpi[g_nK]             = tra_Pi->pseudoRapidity();
                 g_phi_Kpi[g_nK]             = tra_Pi->fourMomentum().phi();
                 g_im_Kpi[g_nK]              = tra_Pi->fourMomentum().m();

                 g_x_stop_K[g_nK]            = pos_stop.x();
                 g_y_stop_K[g_nK]            = pos_stop.y();
                 g_z_stop_K[g_nK]            = pos_stop.z();

                 g_pid_K[g_nK]               = track->pdgId();
                 g_gid_K[g_nK]               = track->geantId();
                 g_key_K[g_nK]               = track->key();
                 g_e_K[g_nK]                 = track->energy();
                 g_pt_K[g_nK]                = track->pt();
                 g_eta_K[g_nK]               = track->pseudoRapidity();
                 g_phi_K[g_nK]               = track->fourMomentum().phi();
                 g_im_K[g_nK]                = track->fourMomentum().m();

                 g_x_start_K[g_nK]           = pos_start.x();
                 g_y_start_K[g_nK]           = pos_start.y();
                 g_z_start_K[g_nK]           = pos_start.z();
                 g_geantProc_start_K[g_nK]     = geantProc_start;
                 g_geantMedium_start_K[g_nK]   = geantMedium_start;
                 g_generatorProc_start_K[g_nK] = generatorProc_start;
                 g_key_start_K[g_nK]           = key_start;                 

                 g_pid_parent_K[g_nK]           = pId_parent;
                 g_gid_parent_K[g_nK]           = gId_parent;
                 g_key_parent_K[g_nK]           = key_parent;

                 g_nK++;

                 LOG_INFO << "--> Association Start" << endm;
                 StGlobalTrack *gP = partnerTrack(fmMcTrackMap,tra_P);
                 if( !gP ) continue;
                 if( gP->geometry()->momentum().perp() < 0.1 ) continue;
                 if( gP->geometry()->charge()<0 ) {
                     LOG_WARN << "charge error pion+ ? " << endm;
                     continue;
                 }    
                 StGlobalTrack *gPi = partnerTrack(fmMcTrackMap,tra_Pi);
                 if( !gPi ) continue;
                 if( gPi->geometry()->momentum().perp() < 0.1 ) continue;
                 if( gPi->geometry()->charge()>0 ) {
                     LOG_WARN << "charge error pion- ? " << endm;
                     continue;
                 }
                 LOG_INFO << "--> Find an associated global tracks" << endm;

                 short nFit_p = gP->fitTraits().numberOfFitPoints();
                 short nFitPoss_p = gP->numberOfPossiblePoints();
                 double ratio_p = double(nFit_p) / double(nFitPoss_p);
                 LOG_INFO << "Proton Track flag :  " << gP->flag() << endm;
                 LOG_INFO << "Proton Track nFit :  " << gP->fitTraits().numberOfFitPoints() << endm;
                 LOG_INFO << "Proton Track Fit_ratio :  " << ratio_p << endm;
                 if( gP->flag()<0 || gP->flag()>1000 ) continue;
                 if( nFit_p<10 ) continue;
                 //if( ratio_p<0.51 ) continue;
                 short nFit_pi = gPi->fitTraits().numberOfFitPoints();
                 short nFitPoss_pi = gPi->numberOfPossiblePoints();
                 double ratio_pi = double(nFit_pi) / double(nFitPoss_pi);
                 LOG_INFO << "Pion Track flag :  " << gPi->flag() << endm;
                 LOG_INFO << "Pion Track nFit :  " << gPi->fitTraits().numberOfFitPoints() << endm;     
                 LOG_INFO << "Pion Track Fit_ratio :  " << ratio_pi << endm;
                 if( gPi->flag()<0 || gPi->flag()>1000 ) continue;
                 if( nFit_pi<10 ) continue;
                 //if( ratio_pi<0.51 ) continue;
                 StPhysicalHelixD helix_proton = gP->geometry()->helix();
                 StPhysicalHelixD helix_pion   = gPi->geometry()->helix();
                 double pathlength_p = helix_proton.pathLength(pvpos);
                 StThreeVectorD dca3p = helix_proton.at(pathlength_p) - pvpos;
                 double dca_p = dca3p.mag();
                 //LOG_INFO << "Proton Track dca :  " << dca_p << endm;
                 double pathlength_pi = helix_pion.pathLength(pvpos);
                 StThreeVectorD dca3pi = helix_pion.at(pathlength_pi) - pvpos;
                 double dca_pi = dca3pi.mag();
                 //LOG_INFO << "Pion Track dca :  " << dca_pi << endm;
                 pair<double,double> ss = helix_proton.pathLengths(helix_pion);
                 double s1 = ss.first;
                 double s2 = ss.second;
                 StThreeVectorD V0 = (helix_proton.at(s1) + helix_pion.at(s2))/2.0;
                 StThreeVectorD V0mp = V0 - pvpos;
                 if( V0mp.mag()<2.0 ) continue;
                 StThreeVectorD tdca = helix_proton.at(s1) - helix_pion.at(s2);
                 double tdca2 = tdca.mag();
                 if( tdca2>2.0 ) continue;
                 //LOG_INFO << "DCA_2 :  " << tdca2 << endm;
                 StThreeVectorD Tp_p  = helix_proton.momentumAt(s1,magn*kilogauss);
                 StThreeVectorD Tpi_p = helix_pion.momentumAt(s2,magn*kilogauss);
                 StThreeVectorD T_p   = Tp_p + Tpi_p;
                 if( T_p.mag()<1E-5 ) continue;
                 double dot = T_p.dot(V0mp);
                 double tcrp = dot/(T_p.mag()*V0mp.mag());
                 if( tcrp<0.9 ) continue;
                 double tdcaV0 = sqrt(V0mp.mag2() - dot*dot/T_p.mag2());
                 if( tdcaV0>1.5 ) continue;
                 double Tp_E = sqrt(M_pion*M_pion + Tp_p.mag2());
                 double Tpi_E = sqrt(M_pion*M_pion + Tpi_p.mag2());
                 double T_E = Tp_E + Tpi_E;
                 double T_im = sqrt( T_E*T_E - T_p.mag2() );
                 if( T_im>1.16 ) continue;
                 if( T_im<1.08 ) continue;
                 //if( dot<0.0 ) continue;
                 //double toa = OpenAngle(T_lv, Tp_lv, Tpi_lv);

                 a_pid_Kp[a_nK]              = tra_P->pdgId();
                 a_gid_Kp[a_nK]              = tra_P->geantId();
                 a_key_Kp[a_nK]              = tra_P->key();
                 a_e_Kp[a_nK]                = Tp_p.mag();
                 a_pt_Kp[a_nK]               = Tp_p.perp();
                 a_eta_Kp[a_nK]              = Tp_p.pseudoRapidity();
                 a_phi_Kp[a_nK]              = Tp_p.phi();
                 a_dca_Kp[a_nK]              = dca_p;
                 a_flag_Kp[a_nK]             = gP->flag();
                 a_nFit_Kp[a_nK]             = nFit_p;
                 a_ratio_Kp[a_nK]            = ratio_p;

                 a_pid_Kpi[a_nK]             = tra_Pi->pdgId();             
                 a_gid_Kpi[a_nK]             = tra_Pi->geantId();
                 a_key_Kpi[a_nK]             = tra_Pi->key();
                 a_e_Kpi[a_nK]               = Tpi_p.mag();
                 a_pt_Kpi[a_nK]              = Tpi_p.perp();
                 a_eta_Kpi[a_nK]             = Tpi_p.pseudoRapidity();
                 a_phi_Kpi[a_nK]             = Tpi_p.phi();
                 a_dca_Kpi[a_nK]             = dca_pi;
                 a_flag_Kpi[a_nK]            = gPi->flag();
                 a_nFit_Kpi[a_nK]            = nFit_pi;
                 a_ratio_Kpi[a_nK]           = ratio_pi;

                 a_x_stop_K[a_nK]            = V0.x();
                 a_y_stop_K[a_nK]            = V0.y();
                 a_z_stop_K[a_nK]            = V0.z();

                 a_pt_K[a_nK]                = T_p.perp();
                 a_eta_K[a_nK]               = T_p.pseudoRapidity();
                 a_phi_K[a_nK]               = T_p.phi();
                 a_im_K[a_nK]                = T_im;
                 a_dl_K[a_nK]                = V0mp.mag();
                 a_dca2_K[a_nK]              = tdca2;
                 a_dcaV0_K[a_nK]             = tdcaV0;
                 a_crp_K[a_nK]               = tcrp;
            
                 a_pid_parent_K[a_nK]           = pId_parent;
                 a_gid_parent_K[a_nK]           = gId_parent;
                 a_key_parent_K[a_nK]           = key_parent;

                 a_nK++;
             }
        }


        LOG_INFO << "MuEvent Reconstruction Start " << endm;
	// MuEvent Ana
	StThreeVectorF PV = fmuEvent->primaryVertexPosition();
        //int pvrank = fmu->primaryVertex()->ranking();
        //LOG_INFO << "MuEvent PV ranck " << pvrank << endm;
        //if( pvrank <0 ) { LOG_WARN << "PV rank < 0 " << endm; return kStSkip; }
        h_PVz0_m->Fill( PV.z() );
        if( fabs(PV.z()) > 60.0 ) return kStSkip;
        h_PVz1_m->Fill( PV.z() );
	//if( fmu->numberOfPrimaryTracks() < 1 ) return kStSkip;
	if( fmu->numberOfGlobalTracks() < 2 ) return kStSkip;
	LOG_INFO << "MuEvent PVz: " << PV.z() << endm;
	m_pvx = PV.x();
	m_pvy = PV.y();
	m_pvz = PV.z();
        LOG_INFO << "MuEvent Tracks Loop Start " << endm;
	m_nL = 0; m_nA = 0; m_nK = 0;
	int ngtra = fmu->numberOfGlobalTracks();
	for( int p=0; p<ngtra; ++p ) {
		StMuTrack *ptra = fmu->globalTracks(p);
		if( ptra->charge()<0 ) continue;
		if( !CheckTra( ptra ) ) continue;
		double ptra_nSigp  = ptra->nSigmaProtonFit();
		double ptra_nSigpi = ptra->nSigmaPionFit();
		if( fabs(ptra_nSigp)>3.0 && fabs(ptra_nSigpi)>3.0 ) continue;
		for ( int n=0; n<ngtra; ++n ) {
			if( n == p ) continue;
			StMuTrack *ntra = fmu->globalTracks(n);
			if( ntra->charge() > 0 ) continue;
			if( !CheckTra( ntra ) ) continue;
			double ntra_nSigp  = ntra->nSigmaProtonFit();
			double ntra_nSigpi = ntra->nSigmaPionFit();
			if( fabs(ntra_nSigp)>3.0 && fabs(ntra_nSigpi)>3.0 ) continue;
			
			if( fabs(ptra_nSigpi)>3.0 && fabs(ntra_nSigpi)>3.0 ) continue;

			double ptra_dEdx = ptra->dEdx()*1E+6;
			double ptra_dca  = ptra->dca().mag();
			double ntra_dEdx = ntra->dEdx()*1E+6;
			double ntra_dca  = ntra->dca().mag();

			StPhysicalHelixD ptra_helix = ptra->helix();
			StPhysicalHelixD ntra_helix = ntra->helix();
			pair<double,double> ss = ptra_helix.pathLengths(ntra_helix);
			double s1 = ss.first;
			double s2 = ss.second;
			StThreeVectorD V0 = ( ptra_helix.at(s1) + ntra_helix.at(s2) )/ 2.0;
			StThreeVectorD V0mp = V0 - PV;  // V0_distance to Primary Vetex
                        if( V0mp.mag()<0.7 ) continue;
			StThreeVectorD tdca = ptra_helix.at(s1) - ntra_helix.at(s2);
			double tdca2 = tdca.mag();  // closest distence between two daughters particle
			if( tdca2 > 2.0 ) continue;
			StThreeVectorD tp_p = ptra_helix.momentumAt(s1,magn*kilogauss);
			StThreeVectorD tn_p = ntra_helix.momentumAt(s2,magn*kilogauss);
			StThreeVectorD tV0_p = tp_p + tn_p;
			if( tV0_p.mag() < 1E-5 ) continue;
			double dot = tV0_p.dot(V0mp);
			double tdcaV0 = sqrt(V0mp.mag2() - dot*dot/tV0_p.mag2());
			if( tdcaV0 > 1.5 ) continue;
			double tcrp = dot/(tV0_p.mag()*V0mp.mag());
			if ( tcrp < 0.9 ) continue;
			double Mp=0, Ep=0;
			double Mn=0, En=0;
			StLorentzVectorD tV0_lv, tp_lv, tn_lv;
			if( fabs(ptra_nSigp)<3.0 && fabs(ntra_nSigpi)<3.0 ) {
                            Mp = M_proton;
                            Mn = M_pion;
                            Ep = sqrt( Mp*Mp + tp_p.mag2() );
                            En = sqrt( Mn*Mn + tn_p.mag2() );
                            tp_lv = StLorentzVectorD(Ep, tp_p);
                            tn_lv = StLorentzVectorD(En, tn_p);
                            tV0_lv = tp_lv + tn_lv;
                            if( V0mp.mag() > 2.0 ) {
                                if( tV0_lv.m()>=1.08 && tV0_lv.m()<1.16 ) {
                                    m_dEdx_Lp[m_nL]    = ptra_dEdx;
                                    m_nSigP_Lp[m_nL]   = ptra_nSigp;
                                    m_nSigPi_Lp[m_nL]  = ptra_nSigpi;
                                    m_pt_Lp[m_nL]      = tp_lv.perp();
				    m_eta_Lp[m_nL]     = tp_lv.pseudoRapidity();
				    m_phi_Lp[m_nL]     = tp_lv.phi();
                                    m_dca_Lp[m_nL]     = ptra_dca;
                                    m_qaT_Lp[m_nL]     = ptra->qaTruth();
                                    m_idT_Lp[m_nL]     = ptra->idTruth();
                                    m_tof_Lp[m_nL]     = ptra->btofPidTraits().matchFlag();
                                    m_beta_Lp[m_nL]    = ptra->btofPidTraits().beta();
                                    m_dEdx_Lpi[m_nL]   = ntra_dEdx;
                                    m_nSigP_Lpi[m_nL]  = ntra_nSigp;
                                    m_nSigPi_Lpi[m_nL] = ntra_nSigpi;
                                    m_pt_Lpi[m_nL]     = tn_lv.perp();
                                    m_eta_Lpi[m_nL]    = tn_lv.pseudoRapidity();
                                    m_phi_Lpi[m_nL]    = tn_lv.phi();
                                    m_dca_Lpi[m_nL]    = ntra_dca;
                                    m_qaT_Lpi[m_nL]    = ntra->qaTruth();
                                    m_idT_Lpi[m_nL]    = ntra->idTruth();
                                    m_tof_Lpi[m_nL]    = ntra->btofPidTraits().matchFlag();
                                    m_beta_Lpi[m_nL]   = ntra->btofPidTraits().beta();
                                    m_dca2_L[m_nL]     = tdca2;
                                    m_dcaV0_L[m_nL]    = tdcaV0;
                                    m_crp_L[m_nL]      = tcrp;
                                    m_dl_L[m_nL]       = V0mp.mag();
                                    m_im_L[m_nL]       = tV0_lv.m();
                                    m_V0x_L[m_nL]      = V0.x();
                                    m_V0y_L[m_nL]      = V0.y();
                                    m_V0z_L[m_nL]      = V0.z();
                                    m_pt_L[m_nL]       = tV0_lv.perp();
                                    m_eta_L[m_nL]      = tV0_lv.pseudoRapidity();
                                    m_phi_L[m_nL]      = tV0_lv.phi();
                                    m_nL++;
                                } 
                            }
                        }

			if( fabs(ptra_nSigpi)<3.0 && fabs(ntra_nSigp)<3.0 ) {
                            Mp = M_pion;
                            Mn = M_proton;
                            Ep = sqrt( Mp*Mp + tp_p.mag2() );
                            En = sqrt( Mn*Mn + tn_p.mag2() );
                            tp_lv = StLorentzVectorD(Ep, tp_p);
                            tn_lv = StLorentzVectorD(En, tn_p);
                            tV0_lv = tp_lv + tn_lv;
                            if( V0mp.mag() > 2.0 ) {
                                if( tV0_lv.m()>=1.08 && tV0_lv.m()<1.16 ) {
                                    m_dEdx_Api[m_nA]   = ptra_dEdx;
                                    m_nSigP_Api[m_nA]  = ptra_nSigp;
                                    m_nSigPi_Api[m_nA] = ptra_nSigpi;
                                    m_pt_Api[m_nA]     = tp_lv.perp();
				    m_eta_Api[m_nA]    = tp_lv.pseudoRapidity();
				    m_phi_Api[m_nA]    = tp_lv.phi();
                                    m_dca_Api[m_nA]    = ptra_dca;
                                    m_qaT_Api[m_nA]    = ptra->qaTruth();
                                    m_idT_Api[m_nA]    = ptra->idTruth();
                                    m_tof_Api[m_nA]    = ptra->btofPidTraits().matchFlag();
                                    m_beta_Api[m_nA]   = ptra->btofPidTraits().beta();
                                    m_dEdx_Ap[m_nA]    = ntra_dEdx;
                                    m_nSigP_Ap[m_nA]   = ntra_nSigp;
                                    m_nSigPi_Ap[m_nA]  = ntra_nSigpi;
                                    m_pt_Ap[m_nA]      = tn_lv.perp();
                                    m_eta_Ap[m_nA]     = tn_lv.pseudoRapidity();
                                    m_phi_Ap[m_nA]     = tn_lv.phi();
                                    m_dca_Ap[m_nA]     = ntra_dca;
                                    m_qaT_Ap[m_nA]     = ntra->qaTruth();
                                    m_idT_Ap[m_nA]     = ntra->idTruth();
                                    m_tof_Ap[m_nA]     = ntra->btofPidTraits().matchFlag();
                                    m_beta_Ap[m_nA]    = ntra->btofPidTraits().beta();
                                    m_dca2_A[m_nA]     = tdca2;
                                    m_dcaV0_A[m_nA]    = tdcaV0;
                                    m_crp_A[m_nA]      = tcrp;
                                    m_dl_A[m_nA]       = V0mp.mag();
                                    m_im_A[m_nA]       = tV0_lv.m();
                                    m_V0x_A[m_nA]      = V0.x();
                                    m_V0y_A[m_nA]      = V0.y();
                                    m_V0z_A[m_nA]      = V0.z();
                                    m_pt_A[m_nA]       = tV0_lv.perp();
                                    m_eta_A[m_nA]      = tV0_lv.pseudoRapidity();
                                    m_phi_A[m_nA]      = tV0_lv.phi();
                                    m_nA++;
                                } 
                            }
                        }
			if( fabs(ptra_nSigpi)<3.0 && fabs(ntra_nSigpi)<3.0 ) {
                            Mp = M_pion;
                            Mn = M_pion;
                            Ep = sqrt( Mp*Mp + tp_p.mag2() );
                            En = sqrt( Mn*Mn + tn_p.mag2() );
                            tp_lv = StLorentzVectorD(Ep, tp_p);
                            tn_lv = StLorentzVectorD(En, tn_p);
                            tV0_lv = tp_lv + tn_lv;
                            if( V0mp.mag() > 0.7 ) {
                                if( tV0_lv.m()>=0.42 && tV0_lv.m()<0.58 ) {
                                    m_dEdx_Kp[m_nK]    = ptra_dEdx;
                                    m_nSigP_Kp[m_nK]   = ptra_nSigp;
                                    m_nSigPi_Kp[m_nK]  = ptra_nSigpi;
                                    m_pt_Kp[m_nK]      = tp_lv.perp();
				    m_eta_Kp[m_nK]     = tp_lv.pseudoRapidity();
				    m_phi_Kp[m_nK]     = tp_lv.phi();
                                    m_dca_Kp[m_nK]     = ptra_dca;
                                    m_qaT_Kp[m_nK]     = ptra->qaTruth();
                                    m_idT_Kp[m_nK]     = ptra->idTruth();
                                    m_tof_Kp[m_nK]     = ptra->btofPidTraits().matchFlag();
                                    m_beta_Kp[m_nK]    = ptra->btofPidTraits().beta();
                                    m_dEdx_Kpi[m_nK]   = ntra_dEdx;
                                    m_nSigP_Kpi[m_nK]  = ntra_nSigp;
                                    m_nSigPi_Kpi[m_nK] = ntra_nSigpi;
                                    m_pt_Kpi[m_nK]     = tn_lv.perp();
                                    m_eta_Kpi[m_nK]    = tn_lv.pseudoRapidity();
                                    m_phi_Kpi[m_nK]    = tn_lv.phi();
                                    m_dca_Kpi[m_nK]    = ntra_dca;
                                    m_qaT_Kpi[m_nK]    = ntra->qaTruth();
                                    m_idT_Kpi[m_nK]    = ntra->idTruth();
                                    m_tof_Kpi[m_nK]    = ntra->btofPidTraits().matchFlag();
                                    m_beta_Kpi[m_nK]   = ntra->btofPidTraits().beta();
                                    m_dca2_K[m_nK]     = tdca2;
                                    m_dcaV0_K[m_nK]    = tdcaV0;
                                    m_crp_K[m_nK]      = tcrp;
                                    m_dl_K[m_nK]       = V0mp.mag();
                                    m_im_K[m_nK]       = tV0_lv.m();
                                    m_V0x_K[m_nK]      = V0.x();
                                    m_V0y_K[m_nK]      = V0.y();
                                    m_V0z_K[m_nK]      = V0.z();
                                    m_pt_K[m_nK]       = tV0_lv.perp();
                                    m_eta_K[m_nK]      = tV0_lv.pseudoRapidity();
                                    m_phi_K[m_nK]      = tV0_lv.phi();
                                    m_nK++;
                                } 
                            }
                        }
                }
        }
	
	fOutTree->Fill();
	//LOG_INFO << "Fill Tree. OK" << endm;
	LOG_INFO << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endm;
	LOG_INFO << ">>                     ANA  SUMMARY                          >>" << endm;
	LOG_INFO << ">>----------------------------------------------------------->>" << endm;
	LOG_INFO << ">>            Lambda        anti-Lambda         K0s          >>" << endm;
	LOG_INFO << ">> Mc Rec :     " << g_nL << "               " << g_nA << "                " << g_nK << "           >>" << endm;
	LOG_INFO << ">> As Rec :     " << a_nL << "               " << a_nA << "                " << a_nK << "           >>" << endm;
	LOG_INFO << ">> Mu Rec :     " << m_nL << "               " << m_nA << "                " << m_nK << "           >>" << endm;
	LOG_INFO << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endm;

	return kStOK;
}

int StLamMcMaker::Finish()
{
//    fOutTree->Write();
    fOutFile->Write();
    fOutFile->Close();

    StMaker::Finish();

    return kStOK;
}

