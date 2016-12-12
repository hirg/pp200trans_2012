/*
 *
 * Code wrote by Jincheng Mei(SDU) on 2016-11-25
 * Used to generate the final simulation tree including the v0 infor, jet infor and the relationship between them.
 * 
 * The input of the code request the file name of v0 ttree and it will get the jet tree file related then generate the output file name automatically.
 *
 * Request weight for pt_hard bin file
 * Request weight for pvz bin file (second)
 *
 */

#include <TVector3.h>
#include <TLorentzVector.h>
#include "v0Tree_reader.h"
#include "jetTree_reader.h"
#include "matchTree.h"

void matchTree(const char* inFn_V0)
{

    string strfn_jet(inFn_V0);
    strfn_jet.replace(strfn_jet.find_first_of('.')+1, 2, "sjet");
    const char* inFn_Jet = strfn_jet.c_str();

    auto const n = strfn_jet.find_last_of('/');
    string strfn_match = strfn_jet.substr(n+1);

    strfn_match.replace(strfn_match.find_first_of('.')+1, 4, "match");
    const char* outFn = strfn_match.c_str();

    int count = 2;
    if( strfn_match.substr(8,1)=="_" ) count = 1; 
    ptHmin = stoi(strfn_match.substr(7,count));
    ptVmin = stoi(strfn_match.substr(strfn_match.find_last_of('_')+1,1));
    ptVmax = ptVmin+1;
    if( ptVmax==7 ) ptVmax = 8;
    
    cout << endl;
    cout << "====--->  Input File_V0:  " << inFn_V0 << endl;
    cout << "====--->  Input File_Jet: " << inFn_Jet << endl;
    cout << "====--->  File PT bin Info: Output File name ~ " << outFn << endl;
    cout << "====--->  pt_hard_min: " << ptHmin << endl;
    cout << "====--->  pt_V0_min: " << ptVmin << endl;
    cout << "====--->  pt_V0_max: " << ptVmax << endl;
    cout << endl;

    TFile *fin_V0 = new TFile(inFn_V0);
    if( !fin_V0->IsOpen() ) {
    	cerr << "V0 file open failed. ";
    	return;
    }
    TFile *fin_Jet = new TFile(inFn_Jet);
    if( !fin_Jet->IsOpen() ) {
    	cerr << "Jet file open failed. ";
    	return;
    }

    TTree *tin_V0 = (TTree*)fin_V0->Get("SimuTree");
    TTree *tin_Jet = (TTree*)fin_Jet->Get("simple_Jet");

    int index_V0 = tin_V0->BuildIndex("m_runN", "m_evtN");
    int index_Jet = tin_Jet->BuildIndex("runID", "evtID");

    if( index_V0<0 || index_Jet<0 ) {
    	cerr << "Tree Index Building Failed. ";
    	return;
    }

    weight_pt_hard = 1.0;
    weight_pt_v0 = 1.0;
    weight_run = 1.0;

    map<int,double> map_weight_pt_hard = getMAP_ptHweight( ptVmin );
    weight_pt_hard = map_weight_pt_hard[ptHmin];
    //cout << "8\t" << map_weight_pt_hard[8] << "\tptHmin: "  << ptHmin << "\t" << weight_pt_hard << endl;
    //cout << "11\t" << map_weight_pt_hard[11] << "\tptHmin: "  << ptHmin << "\t" << weight_pt_hard << endl;

    TFile *fout = new TFile(outFn, "recreate");
    TTree *tout = new TTree("SimuTree_merged", "SimuTree_merged");
    tout->SetDirectory(fout);

    BuildTree_Out(tout);

    int nEvts = tin_V0->GetEntries();
    v0Tree_reader *v0Tree = new v0Tree_reader(tin_V0);
    jetTree_reader *jetTree = new jetTree_reader(tin_Jet);

    cout << "====--->  Prepare word done and event loop begins ~~" << endl;
    cout << "====--->  Total events: " << nEvts << endl;

    for( int iE=0; iE<nEvts; iE++ )
    {
    	v0Tree->GetEntry(iE);
    	jetTree->GetEntryWithIndex(v0Tree->m_runN, v0Tree->m_evtN);

    	assert(v0Tree->m_runN==jetTree->runID && v0Tree->m_evtN==jetTree->evtID);

    	weight_pvz = 1.0;

        m_runN = v0Tree->m_runN;
        m_evtN = v0Tree->m_evtN;
        magn = v0Tree->magn;
        m_pvx = v0Tree->m_pvx;
        m_pvy = v0Tree->m_pvy;
        m_pvz = v0Tree->m_pvz;
        g_runN = v0Tree->g_runN;
        g_evtN = v0Tree->g_evtN;
        g_idSubproc = v0Tree->g_idSubproc;
        g_pvx = v0Tree->g_pvx;
        g_pvy = v0Tree->g_pvy;
        g_pvz = v0Tree->g_pvz;
        g_pv_geantProc = v0Tree->g_pv_geantProc;
        g_pv_geantMedium = v0Tree->g_pv_geantMedium;
        g_pv_generatorProc = v0Tree->g_pv_generatorProc;
        g_pv_key = v0Tree->g_pv_key;
        g_nJets = v0Tree->g_nJets;

        g_idParton1 = v0Tree->g_idParton1;
        g_pxParton1 = v0Tree->g_pxParton1;
        g_pyParton1 = v0Tree->g_pyParton1;
        g_pzParton1 = v0Tree->g_pzParton1;
        g_mParton1 = v0Tree->g_mParton1;
        g_eParton1 = v0Tree->g_eParton1;
        g_idParton2 = v0Tree->g_idParton2;
        g_pxParton2 = v0Tree->g_pxParton2;
        g_pyParton2 = v0Tree->g_pyParton2;
        g_pzParton2 = v0Tree->g_pzParton2;
        g_mParton2 = v0Tree->g_mParton2;
        g_eParton2 = v0Tree->g_eParton2;

        TLorentzVector V4_Parton1;
        V4_Parton1.SetPxPyPzE( g_pxParton1, g_pyParton1, g_pzParton1, g_eParton1);
        TLorentzVector V4_Parton2;
        V4_Parton2.SetPxPyPzE( g_pxParton2, g_pyParton2, g_pzParton2, g_eParton2);

        for (int i=0; i<4; ++i)
        {
            trig[i] = v0Tree->trig[i];
            trig_sub[i] = v0Tree->trig_sub[i];
        }
    	IsJP0s = jetTree->IsJP0s;
    	IsJP1s = jetTree->IsJP1s;
    	IsJP2s = jetTree->IsJP2s;
    	IsAJPs = jetTree->IsAJPs;

    	njet = jetTree->njet;
    	for( int j=0; j<njet; j++ ) {
    		J_sv[j] = jetTree->J_sv[j];
    		J_deteta[j] = jetTree->J_deteta[j];
    		J_eta[j] = jetTree->J_eta[j];
    		J_pt[j] = jetTree->J_pt[j];
    		J_phi[j] = jetTree->J_phi[j];
    		J_rt[j] = jetTree->J_rt[j];
    		J_E[j] = jetTree->J_E[j];
    		J_btowEt[j] = jetTree->J_btowEt[j];
    		J_tpcEt[j] = jetTree->J_tpcEt[j];
    		J_charge[j] = jetTree->J_charge[j];
    		J_ncell[j] = jetTree->J_ncell[j];
    		J_ntra[j] = jetTree->J_ntra[j];

            TVector3 V3;
            V3.SetPtEtaPhi(J_pt[j], J_eta[j], J_phi[j]);
            J_drParton1[j] = V3.DeltaR(V4_Parton1.Vect());
            J_drParton2[j] = V3.DeltaR(V4_Parton2.Vect());
    	}
        g_nL=0;
        //cout << "g_nL_v0Tree:\t" << v0Tree->g_nL << endl;
        for( int i=0; i<v0Tree->g_nL; ++i ) {
            if( v0Tree->g_pt_L[i]<ptVmin || v0Tree->g_pt_L[i]>=ptVmax ) { cout << "g_L pt out. current value: " << v0Tree->g_pt_L[i] << endl; continue; }
            if( fabs(v0Tree->g_eta_L[i]) > 1.20 ) { cout << "g_L eta out. " << endl; continue; }
            g_pid_Lp[g_nL] = v0Tree->g_pid_Lp[i];
            g_gid_Lp[g_nL] = v0Tree->g_gid_Lp[i];
            g_key_Lp[g_nL] = v0Tree->g_key_Lp[i];
            g_e_Lp[g_nL] = v0Tree->g_e_Lp[i];
            g_pt_Lp[g_nL] = v0Tree->g_pt_Lp[i];
            g_eta_Lp[g_nL] = v0Tree->g_eta_Lp[i];
            g_phi_Lp[g_nL] = v0Tree->g_phi_Lp[i];
            g_im_Lp[g_nL] = v0Tree->g_im_Lp[i];
            g_pid_Lpi[g_nL] = v0Tree->g_pid_Lpi[i];
            g_gid_Lpi[g_nL] = v0Tree->g_gid_Lpi[i];
            g_key_Lpi[g_nL] = v0Tree->g_key_Lpi[i];
            g_e_Lpi[g_nL] = v0Tree->g_e_Lpi[i];
            g_pt_Lpi[g_nL] = v0Tree->g_pt_Lpi[i];
            g_eta_Lpi[g_nL] = v0Tree->g_eta_Lpi[i];
            g_phi_Lpi[g_nL] = v0Tree->g_phi_Lpi[i];
            g_im_Lpi[g_nL] = v0Tree->g_im_Lpi[i];
            g_x_stop_L[g_nL] = v0Tree->g_x_stop_L[i];
            g_y_stop_L[g_nL] = v0Tree->g_y_stop_L[i];
            g_z_stop_L[g_nL] = v0Tree->g_z_stop_L[i];
            g_pid_L[g_nL] = v0Tree->g_pid_L[i];
            g_gid_L[g_nL] = v0Tree->g_gid_L[i];
            g_key_L[g_nL] = v0Tree->g_key_L[i];
            g_e_L[g_nL] = v0Tree->g_e_L[i];
            g_pt_L[g_nL] = v0Tree->g_pt_L[i];
            g_eta_L[g_nL] = v0Tree->g_eta_L[i];
            g_phi_L[g_nL] = v0Tree->g_phi_L[i];
            g_im_L[g_nL] = v0Tree->g_im_L[i];
            g_x_start_L[g_nL] = v0Tree->g_x_start_L[i];
            g_y_start_L[g_nL] = v0Tree->g_y_start_L[i];
            g_z_start_L[g_nL] = v0Tree->g_z_start_L[i];
            g_geantProc_start_L[g_nL] = v0Tree->g_geantProc_start_L[i];
            g_geantMedium_start_L[g_nL] = v0Tree->g_geantMedium_start_L[i];
            g_generatorProc_start_L[g_nL] = v0Tree->g_generatorProc_start_L[i];
            g_key_start_L[g_nL] = v0Tree->g_key_start_L[i];
            g_pid_parent_L[g_nL] = v0Tree->g_pid_parent_L[i];
            g_gid_parent_L[g_nL] = v0Tree->g_gid_parent_L[i];
            g_key_parent_L[g_nL] = v0Tree->g_key_parent_L[i];

            g_index_L[g_nL] = -1;
            g_type_L[g_nL]  = -1;
            g_dr_L[g_nL]    = 10;
            g_dphi_L[g_nL]  = 10;
            g_deta_L[g_nL]  = 10;

            g_nL++;
        }
        g_nA = 0;
        for( int i=0; i<v0Tree->g_nA; ++i ) {
            if( v0Tree->g_pt_A[i]<ptVmin || v0Tree->g_pt_A[i]>=ptVmax ) continue;
            if( fabs(v0Tree->g_eta_A[i]) > 1.20 ) continue;
            g_pid_Ap[g_nA] = v0Tree->g_pid_Ap[i];
            g_gid_Ap[g_nA] = v0Tree->g_gid_Ap[i];
            g_key_Ap[g_nA] = v0Tree->g_key_Ap[i];
            g_e_Ap[g_nA] = v0Tree->g_e_Ap[i];
            g_pt_Ap[g_nA] = v0Tree->g_pt_Ap[i];
            g_eta_Ap[g_nA] = v0Tree->g_eta_Ap[i];
            g_phi_Ap[g_nA] = v0Tree->g_phi_Ap[i];
            g_im_Ap[g_nA] = v0Tree->g_im_Ap[i];
            g_pid_Api[g_nA] = v0Tree->g_pid_Api[i];
            g_gid_Api[g_nA] = v0Tree->g_gid_Api[i];
            g_key_Api[g_nA] = v0Tree->g_key_Api[i];
            g_e_Api[g_nA] = v0Tree->g_e_Api[i];
            g_pt_Api[g_nA] = v0Tree->g_pt_Api[i];
            g_eta_Api[g_nA] = v0Tree->g_eta_Api[i];
            g_phi_Api[g_nA] = v0Tree->g_phi_Api[i];
            g_im_Api[g_nA] = v0Tree->g_im_Api[i];
            g_x_stop_A[g_nA] = v0Tree->g_x_stop_A[i];
            g_y_stop_A[g_nA] = v0Tree->g_y_stop_A[i];
            g_z_stop_A[g_nA] = v0Tree->g_z_stop_A[i];
            g_pid_A[g_nA] = v0Tree->g_pid_A[i];
            g_gid_A[g_nA] = v0Tree->g_gid_A[i];
            g_key_A[g_nA] = v0Tree->g_key_A[i];
            g_e_A[g_nA] = v0Tree->g_e_A[i];
            g_pt_A[g_nA] = v0Tree->g_pt_A[i];
            g_eta_A[g_nA] = v0Tree->g_eta_A[i];
            g_phi_A[g_nA] = v0Tree->g_phi_A[i];
            g_im_A[g_nA] = v0Tree->g_im_A[i];
            g_x_start_A[g_nA] = v0Tree->g_x_start_A[i];
            g_y_start_A[g_nA] = v0Tree->g_y_start_A[i];
            g_z_start_A[g_nA] = v0Tree->g_z_start_A[i];
            g_geantProc_start_A[g_nA] = v0Tree->g_geantProc_start_A[i];
            g_geantMedium_start_A[g_nA] = v0Tree->g_geantMedium_start_A[i];
            g_generatorProc_start_A[g_nA] = v0Tree->g_generatorProc_start_A[i];
            g_key_start_A[g_nA] = v0Tree->g_key_start_A[i];
            g_pid_parent_A[g_nA] = v0Tree->g_pid_parent_A[i];
            g_gid_parent_A[g_nA] = v0Tree->g_gid_parent_A[i];
            g_key_parent_A[g_nA] = v0Tree->g_key_parent_A[i];

            g_index_A[g_nA] = -1;
            g_type_A[g_nA]  = -1;
            g_dr_A[g_nA]    = 10;
            g_dphi_A[g_nA]  = 10;
            g_deta_A[g_nA]  = 10;

            g_nA++;
        }
        g_nK = 0;
        for( int i=0; i<v0Tree->g_nK; ++i ) {
            if( v0Tree->g_pt_K[i]<ptVmin || v0Tree->g_pt_K[i]>=ptVmax ) continue;
            if( fabs(v0Tree->g_eta_K[i]) > 1.20 ) continue;
            g_pid_Kp[g_nK] = v0Tree->g_pid_Kp[i];
            g_gid_Kp[g_nK] = v0Tree->g_gid_Kp[i];
            g_key_Kp[g_nK] = v0Tree->g_key_Kp[i];
            g_e_Kp[g_nK] = v0Tree->g_e_Kp[i];
            g_pt_Kp[g_nK] = v0Tree->g_pt_Kp[i];
            g_eta_Kp[g_nK] = v0Tree->g_eta_Kp[i];
            g_phi_Kp[g_nK] = v0Tree->g_phi_Kp[i];
            g_im_Kp[g_nK] = v0Tree->g_im_Kp[i];
            g_pid_Kpi[g_nK] = v0Tree->g_pid_Kpi[i];
            g_gid_Kpi[g_nK] = v0Tree->g_gid_Kpi[i];
            g_key_Kpi[g_nK] = v0Tree->g_key_Kpi[i];
            g_e_Kpi[g_nK] = v0Tree->g_e_Kpi[i];
            g_pt_Kpi[g_nK] = v0Tree->g_pt_Kpi[i];
            g_eta_Kpi[g_nK] = v0Tree->g_eta_Kpi[i];
            g_phi_Kpi[g_nK] = v0Tree->g_phi_Kpi[i];
            g_im_Kpi[g_nK] = v0Tree->g_im_Kpi[i];
            g_x_stop_K[g_nK] = v0Tree->g_x_stop_K[i];
            g_y_stop_K[g_nK] = v0Tree->g_y_stop_K[i];
            g_z_stop_K[g_nK] = v0Tree->g_z_stop_K[i];
            g_pid_K[g_nK] = v0Tree->g_pid_K[i];
            g_gid_K[g_nK] = v0Tree->g_gid_K[i];
            g_key_K[g_nK] = v0Tree->g_key_K[i];
            g_e_K[g_nK] = v0Tree->g_e_K[i];
            g_pt_K[g_nK] = v0Tree->g_pt_K[i];
            g_eta_K[g_nK] = v0Tree->g_eta_K[i];
            g_phi_K[g_nK] = v0Tree->g_phi_K[i];
            g_im_K[g_nK] = v0Tree->g_im_K[i];
            g_x_start_K[g_nK] = v0Tree->g_x_start_K[i];
            g_y_start_K[g_nK] = v0Tree->g_y_start_K[i];
            g_z_start_K[g_nK] = v0Tree->g_z_start_K[i];
            g_geantProc_start_K[g_nK] = v0Tree->g_geantProc_start_K[i];
            g_geantMedium_start_K[g_nK] = v0Tree->g_geantMedium_start_K[i];
            g_generatorProc_start_K[g_nK] = v0Tree->g_generatorProc_start_K[i];
            g_key_start_K[g_nK] = v0Tree->g_key_start_K[i];
            g_pid_parent_K[g_nK] = v0Tree->g_pid_parent_K[i];
            g_gid_parent_K[g_nK] = v0Tree->g_gid_parent_K[i];
            g_key_parent_K[g_nK] = v0Tree->g_key_parent_K[i];

            g_index_K[g_nK] = -1;
            g_type_K[g_nK]  = -1;
            g_dr_K[g_nK]    = 10;
            g_dphi_K[g_nK]  = 10;
            g_deta_K[g_nK]  = 10;

            g_nK++;
        }
        a_nL = 0;
        for( int i=0; i<v0Tree->a_nL; ++i ) {
            if( v0Tree->a_pt_L[i]<ptVmin || v0Tree->a_pt_L[i]>=ptVmax ) continue;
            if( fabs(v0Tree->a_eta_L[i]) > 1.20 ) continue;
            a_pid_Lp[a_nL] = v0Tree->a_pid_Lp[i];
            a_gid_Lp[a_nL] = v0Tree->a_gid_Lp[i];
            a_key_Lp[a_nL] = v0Tree->a_key_Lp[i];
            a_e_Lp[a_nL] = v0Tree->a_e_Lp[i];
            a_pt_Lp[a_nL] = v0Tree->a_pt_Lp[i];
            a_eta_Lp[a_nL] = v0Tree->a_eta_Lp[i];
            a_phi_Lp[a_nL] = v0Tree->a_phi_Lp[i];
            a_dca_Lp[a_nL] = v0Tree->a_dca_Lp[i];
            a_flag_Lp[a_nL] = v0Tree->a_flag_Lp[i];
            a_nFit_Lp[a_nL] = v0Tree->a_nFit_Lp[i];
            a_ratio_Lp[a_nL] = v0Tree->a_ratio_Lp[i];
            a_pid_Lpi[a_nL] = v0Tree->a_pid_Lpi[i];
            a_gid_Lpi[a_nL] = v0Tree->a_gid_Lpi[i];
            a_key_Lpi[a_nL] = v0Tree->a_key_Lpi[i];
            a_e_Lpi[a_nL] = v0Tree->a_e_Lpi[i];
            a_pt_Lpi[a_nL] = v0Tree->a_pt_Lpi[i];
            a_eta_Lpi[a_nL] = v0Tree->a_eta_Lpi[i];
            a_phi_Lpi[a_nL] = v0Tree->a_phi_Lpi[i];
            a_dca_Lpi[a_nL] = v0Tree->a_dca_Lpi[i];
            a_flag_Lpi[a_nL] = v0Tree->a_flag_Lpi[i];
            a_nFit_Lpi[a_nL] = v0Tree->a_nFit_Lpi[i];
            a_ratio_Lpi[a_nL] = v0Tree->a_ratio_Lpi[i];
            a_x_stop_L[a_nL] = v0Tree->a_x_stop_L[i];
            a_y_stop_L[a_nL] = v0Tree->a_y_stop_L[i];
            a_z_stop_L[a_nL] = v0Tree->a_z_stop_L[i];
            a_pt_L[a_nL] = v0Tree->a_pt_L[i];
            a_eta_L[a_nL] = v0Tree->a_eta_L[i];
            a_phi_L[a_nL] = v0Tree->a_phi_L[i];
            a_im_L[a_nL] = v0Tree->a_im_L[i];
            a_dl_L[a_nL] = v0Tree->a_dl_L[i];
            a_dca2_L[a_nL] = v0Tree->a_dca2_L[i];
            a_dcaV0_L[a_nL] = v0Tree->a_dcaV0_L[i];
            a_crp_L[a_nL] = v0Tree->a_crp_L[i];
            a_pid_parent_L[a_nL] = v0Tree->g_pid_parent_L[i];
            a_gid_parent_L[a_nL] = v0Tree->g_gid_parent_L[i];
            a_key_parent_L[a_nL] = v0Tree->g_key_parent_L[i];

            a_index_L[a_nL] = -1;
            a_type_L[a_nL]  = -1;
            a_dr_L[a_nL]    = 10;
            a_dphi_L[a_nL]  = 10;
            a_deta_L[a_nL]  = 10;

            a_nL++;
        }
        a_nA = 0;
        for( int i=0; i<v0Tree->a_nA; ++i ) {
            if( v0Tree->a_pt_A[i]<ptVmin || v0Tree->a_pt_A[i]>=ptVmax ) continue;
            if( fabs(v0Tree->a_eta_A[i]) > 1.20 ) continue;
            a_pid_Ap[a_nA] = v0Tree->a_pid_Ap[i];
            a_gid_Ap[a_nA] = v0Tree->a_gid_Ap[i];
            a_key_Ap[a_nA] = v0Tree->a_key_Ap[i];
            a_e_Ap[a_nA] = v0Tree->a_e_Ap[i];
            a_pt_Ap[a_nA] = v0Tree->a_pt_Ap[i];
            a_eta_Ap[a_nA] = v0Tree->a_eta_Ap[i];
            a_phi_Ap[a_nA] = v0Tree->a_phi_Ap[i];
            a_dca_Ap[a_nA] = v0Tree->a_dca_Ap[i];
            a_flag_Ap[a_nA] = v0Tree->a_flag_Ap[i];
            a_nFit_Ap[a_nA] = v0Tree->a_nFit_Ap[i];
            a_ratio_Ap[a_nA] = v0Tree->a_ratio_Ap[i];
            a_pid_Api[a_nA] = v0Tree->a_pid_Api[i];
            a_gid_Api[a_nA] = v0Tree->a_gid_Api[i];
            a_key_Api[a_nA] = v0Tree->a_key_Api[i];
            a_e_Api[a_nA] = v0Tree->a_e_Api[i];
            a_pt_Api[a_nA] = v0Tree->a_pt_Api[i];
            a_eta_Api[a_nA] = v0Tree->a_eta_Api[i];
            a_phi_Api[a_nA] = v0Tree->a_phi_Api[i];
            a_dca_Api[a_nA] = v0Tree->a_dca_Api[i];
            a_flag_Api[a_nA] = v0Tree->a_flag_Api[i];
            a_nFit_Api[a_nA] = v0Tree->a_nFit_Api[i];
            a_ratio_Api[a_nA] = v0Tree->a_ratio_Api[i];
            a_x_stop_A[a_nA] = v0Tree->a_x_stop_A[i];
            a_y_stop_A[a_nA] = v0Tree->a_y_stop_A[i];
            a_z_stop_A[a_nA] = v0Tree->a_z_stop_A[i];
            a_pt_A[a_nA] = v0Tree->a_pt_A[i];
            a_eta_A[a_nA] = v0Tree->a_eta_A[i];
            a_phi_A[a_nA] = v0Tree->a_phi_A[i];
            a_im_A[a_nA] = v0Tree->a_im_A[i];
            a_dl_A[a_nA] = v0Tree->a_dl_A[i];
            a_dca2_A[a_nA] = v0Tree->a_dca2_A[i];
            a_dcaV0_A[a_nA] = v0Tree->a_dcaV0_A[i];
            a_crp_A[a_nA] = v0Tree->a_crp_A[i];
            a_pid_parent_A[a_nA] = v0Tree->g_pid_parent_A[i];
            a_gid_parent_A[a_nA] = v0Tree->g_gid_parent_A[i];
            a_key_parent_A[a_nA] = v0Tree->g_key_parent_A[i];

            a_index_A[a_nA] = -1;
            a_type_A[a_nA]  = -1;
            a_dr_A[a_nA]    = 10;
            a_dphi_A[a_nA]  = 10;
            a_deta_A[a_nA]  = 10;

            a_nA++;
        }
        a_nK = 0;
        for( int i=0; i<v0Tree->a_nK; ++i ) {
            if( v0Tree->a_pt_K[i]<ptVmin || v0Tree->a_pt_K[i]>=ptVmax ) continue;
            if( fabs(v0Tree->a_eta_K[i]) > 1.20 ) continue;
            a_pid_Kp[a_nK] = v0Tree->a_pid_Kp[i];
            a_gid_Kp[a_nK] = v0Tree->a_gid_Kp[i];
            a_key_Kp[a_nK] = v0Tree->a_key_Kp[i];
            a_e_Kp[a_nK] = v0Tree->a_e_Kp[i];
            a_pt_Kp[a_nK] = v0Tree->a_pt_Kp[i];
            a_eta_Kp[a_nK] = v0Tree->a_eta_Kp[i];
            a_phi_Kp[a_nK] = v0Tree->a_phi_Kp[i];
            a_dca_Kp[a_nK] = v0Tree->a_dca_Kp[i];
            a_flag_Kp[a_nK] = v0Tree->a_flag_Kp[i];
            a_nFit_Kp[a_nK] = v0Tree->a_nFit_Kp[i];
            a_ratio_Kp[a_nK] = v0Tree->a_ratio_Kp[i];
            a_pid_Kpi[a_nK] = v0Tree->a_pid_Kpi[i];
            a_gid_Kpi[a_nK] = v0Tree->a_gid_Kpi[i];
            a_key_Kpi[a_nK] = v0Tree->a_key_Kpi[i];
            a_e_Kpi[a_nK] = v0Tree->a_e_Kpi[i];
            a_pt_Kpi[a_nK] = v0Tree->a_pt_Kpi[i];
            a_eta_Kpi[a_nK] = v0Tree->a_eta_Kpi[i];
            a_phi_Kpi[a_nK] = v0Tree->a_phi_Kpi[i];
            a_dca_Kpi[a_nK] = v0Tree->a_dca_Kpi[i];
            a_flag_Kpi[a_nK] = v0Tree->a_flag_Kpi[i];
            a_nFit_Kpi[a_nK] = v0Tree->a_nFit_Kpi[i];
            a_ratio_Kpi[a_nK] = v0Tree->a_ratio_Kpi[i];
            a_x_stop_K[a_nK] = v0Tree->a_x_stop_K[i];
            a_y_stop_K[a_nK] = v0Tree->a_y_stop_K[i];
            a_z_stop_K[a_nK] = v0Tree->a_z_stop_K[i];
            a_pt_K[a_nK] = v0Tree->a_pt_K[i];
            a_eta_K[a_nK] = v0Tree->a_eta_K[i];
            a_phi_K[a_nK] = v0Tree->a_phi_K[i];
            a_im_K[a_nK] = v0Tree->a_im_K[i];
            a_dl_K[a_nK] = v0Tree->a_dl_K[i];
            a_dca2_K[a_nK] = v0Tree->a_dca2_K[i];
            a_dcaV0_K[a_nK] = v0Tree->a_dcaV0_K[i];
            a_crp_K[a_nK] = v0Tree->a_crp_K[i];
            a_pid_parent_K[a_nK] = v0Tree->g_pid_parent_K[i];
            a_gid_parent_K[a_nK] = v0Tree->g_gid_parent_K[i];
            a_key_parent_K[a_nK] = v0Tree->g_key_parent_K[i];

            a_index_K[a_nK] = -1;
            a_type_K[a_nK]  = -1;
            a_dr_K[a_nK]    = 10;
            a_dphi_K[a_nK]  = 10;
            a_deta_K[a_nK]  = 10;

            a_nK++;
        }
        m_nL = 0;
        for( int i=0; i<v0Tree->m_nL; ++i ) {
            if( v0Tree->m_pt_L[i]<ptVmin || v0Tree->m_pt_L[i]>=ptVmax ) continue;
            if( fabs(v0Tree->m_eta_L[i]) > 1.20 ) continue;
            m_dEdx_Lp[m_nL] = v0Tree->m_dEdx_Lp[i];
            m_nSigP_Lp[m_nL] = v0Tree->m_nSigP_Lp[i];
            m_nSigPi_Lp[m_nL] = v0Tree->m_nSigPi_Lp[i];
            m_pt_Lp[m_nL] = v0Tree->m_pt_Lp[i];
            m_eta_Lp[m_nL] = v0Tree->m_eta_Lp[i];
            m_phi_Lp[m_nL] = v0Tree->m_phi_Lp[i];
            m_dca_Lp[m_nL] = v0Tree->m_dca_Lp[i];
            m_qaT_Lp[m_nL] = v0Tree->m_qaT_Lp[i];
            m_idT_Lp[m_nL] = v0Tree->m_idT_Lp[i];
            m_tof_Lp[m_nL] = v0Tree->m_tof_Lp[i];
            m_beta_Lp[m_nL] = v0Tree->m_beta_Lp[i];
            m_dEdx_Lpi[m_nL] = v0Tree->m_dEdx_Lpi[i];
            m_nSigP_Lpi[m_nL] = v0Tree->m_nSigP_Lpi[i];
            m_nSigPi_Lpi[m_nL] = v0Tree->m_nSigPi_Lpi[i];
            m_pt_Lpi[m_nL] = v0Tree->m_pt_Lpi[i];
            m_eta_Lpi[m_nL] = v0Tree->m_eta_Lpi[i];
            m_phi_Lpi[m_nL] = v0Tree->m_phi_Lpi[i];
            m_dca_Lpi[m_nL] = v0Tree->m_dca_Lpi[i];
            m_qaT_Lpi[m_nL] = v0Tree->m_qaT_Lpi[i];
            m_idT_Lpi[m_nL] = v0Tree->m_idT_Lpi[i];
            m_tof_Lpi[m_nL] = v0Tree->m_tof_Lpi[i];
            m_beta_Lpi[m_nL] = v0Tree->m_beta_Lpi[i];
            m_dca2_L[m_nL] = v0Tree->m_dca2_L[i];
            m_dcaV0_L[m_nL] = v0Tree->m_dcaV0_L[i];
            m_crp_L[m_nL] = v0Tree->m_crp_L[i];
            m_dl_L[m_nL] = v0Tree->m_dl_L[i];
            m_im_L[m_nL] = v0Tree->m_im_L[i];
            m_V0x_L[m_nL] = v0Tree->m_V0x_L[i];
            m_V0y_L[m_nL] = v0Tree->m_V0y_L[i];
            m_V0z_L[m_nL] = v0Tree->m_V0z_L[i];
            m_pt_L[m_nL] = v0Tree->m_pt_L[i];
            m_eta_L[m_nL] = v0Tree->m_eta_L[i];
            m_phi_L[m_nL] = v0Tree->m_phi_L[i];

            m_index_L[m_nL] = -1;
            m_type_L[m_nL]  = -1;
            m_dr_L[m_nL]    = 10;
            m_dphi_L[m_nL]  = 10;
            m_deta_L[m_nL]  = 10;

            m_nL++;
        }
        m_nA = 0;
        for( int i=0; i<v0Tree->m_nA; ++i ) {
            if( v0Tree->m_pt_A[i]<ptVmin || v0Tree->m_pt_A[i]>=ptVmax ) continue;
            if( fabs(v0Tree->m_eta_A[i]) > 1.20 ) continue;
            m_dEdx_Ap[m_nA] = v0Tree->m_dEdx_Ap[i];
            m_nSigP_Ap[m_nA] = v0Tree->m_nSigP_Ap[i];
            m_nSigPi_Ap[m_nA] = v0Tree->m_nSigPi_Ap[i];
            m_pt_Ap[m_nA] = v0Tree->m_pt_Ap[i];
            m_eta_Ap[m_nA] = v0Tree->m_eta_Ap[i];
            m_phi_Ap[m_nA] = v0Tree->m_phi_Ap[i];
            m_dca_Ap[m_nA] = v0Tree->m_dca_Ap[i];
            m_qaT_Ap[m_nA] = v0Tree->m_qaT_Ap[i];
            m_idT_Ap[m_nA] = v0Tree->m_idT_Ap[i];
            m_tof_Ap[m_nA] = v0Tree->m_tof_Ap[i];
            m_beta_Ap[m_nA] = v0Tree->m_beta_Ap[i];
            m_dEdx_Api[m_nA] = v0Tree->m_dEdx_Api[i];
            m_nSigP_Api[m_nA] = v0Tree->m_nSigP_Api[i];
            m_nSigPi_Api[m_nA] = v0Tree->m_nSigPi_Api[i];
            m_pt_Api[m_nA] = v0Tree->m_pt_Api[i];
            m_eta_Api[m_nA] = v0Tree->m_eta_Api[i];
            m_phi_Api[m_nA] = v0Tree->m_phi_Api[i];
            m_dca_Api[m_nA] = v0Tree->m_dca_Api[i];
            m_qaT_Api[m_nA] = v0Tree->m_qaT_Api[i];
            m_idT_Api[m_nA] = v0Tree->m_idT_Api[i];
            m_tof_Api[m_nA] = v0Tree->m_tof_Api[i];
            m_beta_Api[m_nA] = v0Tree->m_beta_Api[i];
            m_dca2_A[m_nA] = v0Tree->m_dca2_A[i];
            m_dcaV0_A[m_nA] = v0Tree->m_dcaV0_A[i];
            m_crp_A[m_nA] = v0Tree->m_crp_A[i];
            m_dl_A[m_nA] = v0Tree->m_dl_A[i];
            m_im_A[m_nA] = v0Tree->m_im_A[i];
            m_V0x_A[m_nA] = v0Tree->m_V0x_A[i];
            m_V0y_A[m_nA] = v0Tree->m_V0y_A[i];
            m_V0z_A[m_nA] = v0Tree->m_V0z_A[i];
            m_pt_A[m_nA] = v0Tree->m_pt_A[i];
            m_eta_A[m_nA] = v0Tree->m_eta_A[i];
            m_phi_A[m_nA] = v0Tree->m_phi_A[i];

            m_index_A[m_nA] = -1;
            m_type_A[m_nA]  = -1;
            m_dr_A[m_nA]    = 10;
            m_dphi_A[m_nA]  = 10;
            m_deta_A[m_nA]  = 10;

            m_nA++;
        }
        m_nK = 0;
        for( int i=0; i<v0Tree->m_nK; ++i ) {
            if( v0Tree->m_pt_K[i]<ptVmin || v0Tree->m_pt_K[i]>=ptVmax ) continue;
            if( fabs(v0Tree->m_eta_K[i]) > 1.20 ) continue;
            m_dEdx_Kp[m_nK] = v0Tree->m_dEdx_Kp[i];
            m_nSigP_Kp[m_nK] = v0Tree->m_nSigP_Kp[i];
            m_nSigPi_Kp[m_nK] = v0Tree->m_nSigPi_Kp[i];
            m_pt_Kp[m_nK] = v0Tree->m_pt_Kp[i];
            m_eta_Kp[m_nK] = v0Tree->m_eta_Kp[i];
            m_phi_Kp[m_nK] = v0Tree->m_phi_Kp[i];
            m_dca_Kp[m_nK] = v0Tree->m_dca_Kp[i];
            m_qaT_Kp[m_nK] = v0Tree->m_qaT_Kp[i];
            m_idT_Kp[m_nK] = v0Tree->m_idT_Kp[i];
            m_tof_Kp[m_nK] = v0Tree->m_tof_Kp[i];
            m_beta_Kp[m_nK] = v0Tree->m_beta_Kp[i];
            m_dEdx_Kpi[m_nK] = v0Tree->m_dEdx_Kpi[i];
            m_nSigP_Kpi[m_nK] = v0Tree->m_nSigP_Kpi[i];
            m_nSigPi_Kpi[m_nK] = v0Tree->m_nSigPi_Kpi[i];
            m_pt_Kpi[m_nK] = v0Tree->m_pt_Kpi[i];
            m_eta_Kpi[m_nK] = v0Tree->m_eta_Kpi[i];
            m_phi_Kpi[m_nK] = v0Tree->m_phi_Kpi[i];
            m_dca_Kpi[m_nK] = v0Tree->m_dca_Kpi[i];
            m_qaT_Kpi[m_nK] = v0Tree->m_qaT_Kpi[i];
            m_idT_Kpi[m_nK] = v0Tree->m_idT_Kpi[i];
            m_tof_Kpi[m_nK] = v0Tree->m_tof_Kpi[i];
            m_beta_Kpi[m_nK] = v0Tree->m_beta_Kpi[i];
            m_dca2_K[m_nK] = v0Tree->m_dca2_K[i];
            m_dcaV0_K[m_nK] = v0Tree->m_dcaV0_K[i];
            m_crp_K[m_nK] = v0Tree->m_crp_K[i];
            m_dl_K[m_nK] = v0Tree->m_dl_K[i];
            m_im_K[m_nK] = v0Tree->m_im_K[i];
            m_V0x_K[m_nK] = v0Tree->m_V0x_K[i];
            m_V0y_K[m_nK] = v0Tree->m_V0y_K[i];
            m_V0z_K[m_nK] = v0Tree->m_V0z_K[i];
            m_pt_K[m_nK] = v0Tree->m_pt_K[i];
            m_eta_K[m_nK] = v0Tree->m_eta_K[i];
            m_phi_K[m_nK] = v0Tree->m_phi_K[i];

            m_index_K[m_nK] = -1;
            m_type_K[m_nK]  = -1;
            m_dr_K[m_nK]    = 10;
            m_dphi_K[m_nK]  = 10;
            m_deta_K[m_nK]  = 10;

            m_nK++;
        }

        for( int i=0; i<g_nL; ++i ) {
        	TVector3 aV;
        	aV.SetPtEtaPhi(g_pt_L[i],g_eta_L[i],g_phi_L[i]);
            TLorentzVector aV4;
            aV4.SetVectM(aV, g_im_L[i]);
            g_drParton1_L[i] = aV4.DeltaR(V4_Parton1);
            g_drParton2_L[i] = aV4.DeltaR(V4_Parton2);
            for( int j=0; j<njet; ++j ) {
                if( J_deteta[j] < -0.7 || J_deteta[j] > 0.9 ) continue;
                if( J_rt[j] > 0.95 ) continue;
                TVector3 aJet;
                aJet.SetPtEtaPhi(J_pt[j],J_eta[j],J_phi[j]);
                double tdr = aJet.DeltaR( aV );
                if( tdr<m_dr_L[i] ) {
                    g_index_L[i] = j;
                    g_dr_L[i] = tdr;
                    g_dphi_L[i] = aJet.DeltaPhi( aV );
                    g_deta_L[i] = aJet.Eta() - aV.Eta();
                }
            }
        }
        for( int i=0; i<g_nA; ++i ) {
        	TVector3 aV;
        	aV.SetPtEtaPhi(g_pt_A[i],g_eta_A[i],g_phi_A[i]);
            TLorentzVector aV4;
            aV4.SetVectM(aV, g_im_A[i]);
            g_drParton1_A[i] = aV4.DeltaR(V4_Parton1);
            g_drParton2_A[i] = aV4.DeltaR(V4_Parton2);
            for( int j=0; j<njet; ++j ) {
                if( J_deteta[j] < -0.7 || J_deteta[j] > 0.9 ) continue;
                if( J_rt[j] > 0.95 ) continue;
                TVector3 aJet;
                aJet.SetPtEtaPhi(J_pt[j],J_eta[j],J_phi[j]);
                double tdr = aJet.DeltaR( aV );
                if( tdr<m_dr_A[i] ) {
                    g_index_A[i] = j;
                    g_dr_A[i] = tdr;
                    g_dphi_A[i] = aJet.DeltaPhi( aV );
                    g_deta_A[i] = aJet.Eta() - aV.Eta();
                }
            }
        }
        for( int i=0; i<g_nK; ++i ) {
        	TVector3 aV;
        	aV.SetPtEtaPhi(g_pt_K[i],g_eta_K[i],g_phi_K[i]);
            TLorentzVector aV4;
            aV4.SetVectM(aV, g_im_K[i]);
            g_drParton1_K[i] = aV4.DeltaR(V4_Parton1);
            g_drParton2_K[i] = aV4.DeltaR(V4_Parton2);
            for( int j=0; j<njet; ++j ) {
                if( J_deteta[j] < -0.7 || J_deteta[j] > 0.9 ) continue;
                if( J_rt[j] > 0.95 ) continue;
                TVector3 aJet;
                aJet.SetPtEtaPhi(J_pt[j],J_eta[j],J_phi[j]);
                double tdr = aJet.DeltaR( aV );
                if( tdr<m_dr_K[i] ) {
                    g_index_K[i] = j;
                    g_dr_K[i] = tdr;
                    g_dphi_K[i] = aJet.DeltaPhi( aV );
                    g_deta_K[i] = aJet.Eta() - aV.Eta();
                }
            }
        }

        for( int i=0; i<a_nL; ++i ) {
        	TVector3 aV;
        	aV.SetPtEtaPhi(a_pt_L[i],a_eta_L[i],a_phi_L[i]);
            TLorentzVector aV4;
            aV4.SetVectM(aV, a_im_L[i]);
            a_drParton1_L[i] = aV4.DeltaR(V4_Parton1);
            a_drParton2_L[i] = aV4.DeltaR(V4_Parton2);
            for( int j=0; j<njet; ++j ) {
                if( J_deteta[j] < -0.7 || J_deteta[j] > 0.9 ) continue;
                if( J_rt[j] > 0.95 ) continue;
                TVector3 aJet;
                aJet.SetPtEtaPhi(J_pt[j],J_eta[j],J_phi[j]);
                double tdr = aJet.DeltaR( aV );
                if( tdr<m_dr_L[i] ) {
                    a_index_L[i] = j;
                    a_dr_L[i] = tdr;
                    a_dphi_L[i] = aJet.DeltaPhi( aV );
                    a_deta_L[i] = aJet.Eta() - aV.Eta();
                }
            }
        }
        for( int i=0; i<a_nA; ++i ) {
        	TVector3 aV;
        	aV.SetPtEtaPhi(a_pt_A[i],a_eta_A[i],a_phi_A[i]);
            TLorentzVector aV4;
            aV4.SetVectM(aV, a_im_A[i]);
            a_drParton1_A[i] = aV4.DeltaR(V4_Parton1);
            a_drParton2_A[i] = aV4.DeltaR(V4_Parton2);
            for( int j=0; j<njet; ++j ) {
                if( J_deteta[j] < -0.7 || J_deteta[j] > 0.9 ) continue;
                if( J_rt[j] > 0.95 ) continue;
                TVector3 aJet;
                aJet.SetPtEtaPhi(J_pt[j],J_eta[j],J_phi[j]);
                double tdr = aJet.DeltaR( aV );
                if( tdr<m_dr_A[i] ) {
                    a_index_A[i] = j;
                    a_dr_A[i] = tdr;
                    a_dphi_A[i] = aJet.DeltaPhi( aV );
                    a_deta_A[i] = aJet.Eta() - aV.Eta();
                }
            }
        }
        for( int i=0; i<a_nK; ++i ) {
        	TVector3 aV;
        	aV.SetPtEtaPhi(a_pt_K[i],a_eta_K[i],a_phi_K[i]);
            TLorentzVector aV4;
            aV4.SetVectM(aV, a_im_K[i]);
            a_drParton1_K[i] = aV4.DeltaR(V4_Parton1);
            a_drParton2_K[i] = aV4.DeltaR(V4_Parton2);
            for( int j=0; j<njet; ++j ) {
                if( J_deteta[j] < -0.7 || J_deteta[j] > 0.9 ) continue;
                if( J_rt[j] > 0.95 ) continue;
                TVector3 aJet;
                aJet.SetPtEtaPhi(J_pt[j],J_eta[j],J_phi[j]);
                double tdr = aJet.DeltaR( aV );
                if( tdr<m_dr_K[i] ) {
                    a_index_K[i] = j;
                    a_dr_K[i] = tdr;
                    a_dphi_K[i] = aJet.DeltaPhi( aV );
                    a_deta_K[i] = aJet.Eta() - aV.Eta();
                }
            }
        }

        for( int i=0; i<m_nL; ++i ) {
        	TVector3 aV;
        	aV.SetPtEtaPhi(m_pt_L[i],m_eta_L[i],m_phi_L[i]);
            TLorentzVector aV4;
            aV4.SetVectM(aV, m_im_L[i]);
            m_drParton1_L[i] = aV4.DeltaR(V4_Parton1);
            m_drParton2_L[i] = aV4.DeltaR(V4_Parton2);
            for( int j=0; j<njet; ++j ) {
                if( J_deteta[j] < -0.7 || J_deteta[j] > 0.9 ) continue;
                if( J_rt[j] > 0.95 ) continue;
                TVector3 aJet;
                aJet.SetPtEtaPhi(J_pt[j],J_eta[j],J_phi[j]);
                double tdr = aJet.DeltaR( aV );
                if( tdr<m_dr_L[i] ) {
                    m_index_L[i] = j;
                    m_dr_L[i] = tdr;
                    m_dphi_L[i] = aJet.DeltaPhi( aV );
                    m_deta_L[i] = aJet.Eta() - aV.Eta();
                }
            }
        }
        for( int i=0; i<m_nL; ++i ) {
        	TVector3 aV;
        	aV.SetPtEtaPhi(m_pt_A[i],m_eta_A[i],m_phi_A[i]);
            TLorentzVector aV4;
            aV4.SetVectM(aV, m_im_A[i]);
            m_drParton1_A[i] = aV4.DeltaR(V4_Parton1);
            m_drParton2_A[i] = aV4.DeltaR(V4_Parton2);
            for( int j=0; j<njet; ++j ) {
                if( J_deteta[j] < -0.7 || J_deteta[j] > 0.9 ) continue;
                if( J_rt[j] > 0.95 ) continue;
                TVector3 aJet;
                aJet.SetPtEtaPhi(J_pt[j],J_eta[j],J_phi[j]);
                double tdr = aJet.DeltaR( aV );
                if( tdr<m_dr_A[i] ) {
                    m_index_A[i] = j;
                    m_dr_A[i] = tdr;
                    m_dphi_A[i] = aJet.DeltaPhi( aV );
                    m_deta_A[i] = aJet.Eta() - aV.Eta();
                }
            }
        }
        for( int i=0; i<m_nL; ++i ) {
        	TVector3 aV;
        	aV.SetPtEtaPhi(m_pt_K[i],m_eta_K[i],m_phi_K[i]);
            TLorentzVector aV4;
            aV4.SetVectM(aV, m_im_K[i]);
            m_drParton1_K[i] = aV4.DeltaR(V4_Parton1);
            m_drParton2_K[i] = aV4.DeltaR(V4_Parton2);
            for( int j=0; j<njet; ++j ) {
                if( J_deteta[j] < -0.7 || J_deteta[j] > 0.9 ) continue;
                if( J_rt[j] > 0.95 ) continue;
                TVector3 aJet;
                aJet.SetPtEtaPhi(J_pt[j],J_eta[j],J_phi[j]);
                double tdr = aJet.DeltaR( aV );
                if( tdr<m_dr_K[i] ) {
                    m_index_K[i] = j;
                    m_dr_K[i] = tdr;
                    m_dphi_K[i] = aJet.DeltaPhi( aV );
                    m_deta_K[i] = aJet.Eta() - aV.Eta();
                }
            }
        }
        tout->Fill();
    }
    fout->Write();
    fout->Close();
    fin_V0->Close();
    fin_Jet->Close();
}


