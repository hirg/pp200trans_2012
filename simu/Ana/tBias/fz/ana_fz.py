#from ROOT import TFile, TH1D, TCanvas, TStyle

reckind_List = ['g','a','m','t']
particle_List = ['L','A']

trig_List = ['ZB','JP0','JP1','JP2','AJP']

for i in xrange(1,7):
	print i
	fin_ZB = TFile('mc_ptV%d.hist_ZB.root'%i)
	fin_JP0 = TFile('mc_ptV%d.hist_JP0.root'%i)
	fin_JP1 = TFile('mc_ptV%d.hist_JP1.root'%i)
	fin_JP2 = TFile('mc_ptV%d.hist_JP2.root'%i)
	fin_AJP = TFile('mc_ptV%d.hist_AJP.root'%i)

	for j in reckind_List:
		print j

		for k in particle_List:
			tc = TCanvas('c','c',700,500)
			print k
			h_ZB = fin_ZB.Get('h_%s_fz_%s_PT%d'%(j,k,i))
			h_JP0 = fin_JP0.Get('h_%s_fz_%s_PT%d'%(j,k,i))
			h_JP1 = fin_JP1.Get('h_%s_fz_%s_PT%d'%(j,k,i))
			h_JP2 = fin_JP2.Get('h_%s_fz_%s_PT%d'%(j,k,i))
			h_AJP = fin_AJP.Get('h_%s_fz_%s_PT%d'%(j,k,i))

			h_ZB.Scale(1.0/(h_ZB.Integral()))
			h_JP0.Scale(1.0/(h_JP0.Integral()))
			h_JP1.Scale(1.0/(h_JP1.Integral()))
			h_JP2.Scale(1.0/(h_JP2.Integral()))
			h_AJP.Scale(1.0/(h_AJP.Integral()))

			h_ZB.SetMarkerStyle(34)
			h_JP0.SetMarkerStyle(20)
			h_JP1.SetMarkerStyle(21)
			h_JP2.SetMarkerStyle(24)
			h_AJP.SetMarkerStyle(25)

			h_ZB.SetMarkerColor(2)
			h_JP0.SetMarkerStyle(4)
			h_JP1.SetMarkerStyle(6)
			h_JP2.SetMarkerStyle(8)
			h_AJP.SetMarkerStyle(9)

			h_ZB.SetXTitle('z(=L_pt/J_pt)')
			tc.cd()
			h_ZB.Draw()
			h_JP0.Draw('same')
			h_JP1.Draw('same')
			h_JP2.Draw('same')
			h_AJP.Draw('same')

			cn = 'Pic/fz_%s_%s_PT%d.eps' %(j,k,i)
			tc.SaveAs(cn)
			pass
		pass
	pass 
