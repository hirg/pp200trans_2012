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
#include <TH2.h>
#include <TStyle.h>


void fillHist::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   h_pvz0     = new TH1D("h_pvz0","h_pvz0",120,-60,60);   
   h_pvz1     = new TH1D("h_pvz1","h_pvz1",120,-60,60);

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
      /* code */
      hn = Form("h_peak_fz_L_PT%d", kPT);
      h_peak_fz_L[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_peak_fz_A_PT%d", kPT);
      h_peak_fz_A[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_bkg_fz_L_PT%d", kPT);
      h_bkg_fz_L[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);
      hn = Form("h_bkg_fz_A_PT%d", kPT);
      h_bkg_fz_A[kPT] = new TH1D(hn.Data(),hn.Data(),120,0,1.2);

      for (int kJ = 0; kJ < 2; ++kJ)
      {
         /* code */
         hn = Form("h_im_L_J%d_PT%d", kJ, kPT);
         h_im_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);

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
         hn = Form("h_peak_nFit_Lp_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_nFit_Lpi_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_dl_L_J%d_PT%d", kJ, kPT);
         h_peak_dl_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
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
         hn = Form("h_bkg_nFit_Lp_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Lp[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_nFit_Lpi_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Lpi[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_dl_L_J%d_PT%d", kJ, kPT);
         h_bkg_dl_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
         hn = Form("h_bkg_dca2_L_J%d_PT%d", kJ, kPT);
         h_bkg_dca2_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_dcaV0_L_J%d_PT%d", kJ, kPT);
         h_bkg_dcaV0_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_crp_L_J%d_PT%d", kJ, kPT);
         h_bkg_crp_L[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);

         hn = Form("h_im_A_J%d_PT%d", kJ, kPT);
         h_im_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),80,1.08,1.16);

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
         hn = Form("h_peak_nFit_Ap_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_nFit_Api_J%d_PT%d", kJ, kPT);
         h_peak_nFit_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_peak_dl_A_J%d_PT%d", kJ, kPT);
         h_peak_dl_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
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
         hn = Form("h_bkg_nFit_Ap_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Ap[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_nFit_Api_J%d_PT%d", kJ, kPT);
         h_bkg_nFit_Api[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),46,0,46);
         hn = Form("h_bkg_dl_A_J%d_PT%d", kJ, kPT);
         h_bkg_dl_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),250,0,50);
         hn = Form("h_bkg_dca2_A_J%d_PT%d", kJ, kPT);
         h_bkg_dca2_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_dcaV0_A_J%d_PT%d", kJ, kPT);
         h_bkg_dcaV0_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),200,0,2);
         hn = Form("h_bkg_crp_A_J%d_PT%d", kJ, kPT);
         h_bkg_crp_A[kJ][kPT] = new TH1D(hn.Data(),hn.Data(),500,0.95,1.0);
      }
   }
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

   if (entry%100000==0) cout << "current entry: " << entry << endl;

   if (!checkSpin()) return kTRUE;
   h_pvz0->Fill(pvz);

   if (!checkTrig()) return kTRUE;

   for (int kJ=0; kJ<2; ++kJ)
   {
      for (int i = 0; i < count; ++i)
      {
         /* code */
      }
   }
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
