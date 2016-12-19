from ROOT import TFile, TH1D, TH2D, TCanvas, TStyle, TLegend, gStyle
import sys

gStyle.SetOptStat(0)

ptH=sys.argv[1]
ptV=sys.argv[2]

Trig_List=['ZB','JP0','JP1','JP2','AJP']
MarkerC_List=[1,2,4,6,8]

# Event Level
It_List=['g_pvz','m_pvz','g_idSubproc','eta_J','pt_J','phi_J','rt_J','charge_J','fParton_J','fPartonS_J','drParton_J']

X_List=['pvz[cm]','pvz[cm]','Subprocess ID','#eta','p_{T}[GeV/c]','#phi',\
'neutral fraction','charged fraction','orignal parton flavour','orignal parton flavour','dr_Parton1']

Title_List=['pvz for McEvent','pvz for MuEvent','Subprocess ID of Event Level','Jet #eta','Jet p_{T}','Jet #phi',\
'Jet neutral fraction','Jet charged fraction','Jet orignal parton flavour','Jet orignal parton flavour','dr_Parton1']

file_List=[]

for i in xrange(0,5):
	print i
	fdir='../data/ptH_%s/'%(ptH)
	fn='mc_ptH_%s_ptV%s.hist_%s.root'%(ptH,ptV,Trig_List[i])

	fn_full=fdir+fn

	file_List.append(TFile(fn_full))
	pass

c=TCanvas('c','c',700,500)
for j in xrange(0,10):
	print It_List[j]
	lg=TLegend(0.12,0.82,0.6,0.89)
	lg.SetNColumns(5)
	lg.SetBorderSize(0)

	for i in xrange(0,5):
		hn='h_%s'%(It_List[j])
		ht=file_List[i].Get(hn)
		ht.SetXTitle(X_List[j])
		ht.SetTitle(Title_List[j])
		ht.SetMarkerStyle(20)
		ht.SetMarkerColor(MarkerC_List[i])
		ht.SetLineColor(MarkerC_List[i])
		lg.AddEntry(ht,Trig_List[i],"lep")
		c.cd()
		if i==0:
			ht.Draw()
			pass
		else:
			ht.Draw('same')
		pass
		
	lg.Draw('same')
	cn='Pic_base/ptH_%s/ptV_%s/c_%s.eps'%(ptH,ptV,It_List[j])
	c.SaveAs(cn)
	cn='Pic_base/ptH_%s/ptV_%s/c_%s.png'%(ptH,ptV,It_List[j])
	c.SaveAs(cn)
	pass

