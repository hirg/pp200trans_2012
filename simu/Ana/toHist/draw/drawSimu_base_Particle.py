from ROOT import TFile, TH1D, TH2D, TCanvas, TStyle, TLegend, gStyle
import sys

gStyle.SetOptStat(0)

ptH=sys.argv[1]
ptV=sys.argv[2]

Trig_List=['ZB','JP0','JP1','JP2','AJP']
MarkerC_List=[1,2,4,6,8]
Par_List=['L','A']
LPar_List=['#Lambda','#bar{#Lambda}']
Type_List=['g','a','m','t']

# Event Level
It_List=['im','pt','eta','phi','dr']

X_List=['Mass_p#pi[GeV/c]','p_{T}[GeV/c]','#eta','#phi','#DeltaR']

Title_List=['Invariant Mass of ','p_{T} of ','#eta of ','#phi of ','#DeltaR of ']

file_List=[]

for i in xrange(0,5):
	print i
	fdir='../data/ptH_%s/'%(ptH)
	fn='mc_ptH_%s_ptV%s.hist_%s.root'%(ptH,ptV,Trig_List[i])

	fn_full=fdir+fn

	file_List.append(TFile(fn_full))
	pass

c=TCanvas('c','c',700,500)
for j in xrange(0,5):
	print It_List[j]

	for iPar in xrange(0,2):
		print Par_List[iPar]

		for iT in xrange(0,4):
			print Type_List[iT]

			for iJ in xrange(0,2):
				lg=TLegend(0.12,0.82,0.6,0.89)
				lg.SetNColumns(5)
				lg.SetBorderSize(0)

				for i in xrange(0,5):

					hn='h_%s_%s_%s_J%d_PT%d'%(Type_List[iT],It_List[j],Par_List[iPar],iJ,int(ptV)-1)
					ht=file_List[i].Get(hn)
					ht.SetXTitle(X_List[j])
					ht.SetTitle(Title_List[j]+LPar_List[iPar])
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
				cn='Pic_base/ptH_%s/ptV_%s/h_%s_%s_%s_J%d_PT%s.eps'%(ptH,ptV,Type_List[iT],It_List[j],Par_List[iPar],iJ,ptV)
				c.SaveAs(cn)
				cn='Pic_base/ptH_%s/ptV_%s/h_%s_%s_%s_J%d_PT%s.png'%(ptH,ptV,Type_List[iT],It_List[j],Par_List[iPar],iJ,ptV)
				c.SaveAs(cn)
				pass
			pass
		pass
	pass

