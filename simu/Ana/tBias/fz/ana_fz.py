from ROOT import TFile, TH1D, TCanvas, TStyle, TLegend, TPaveText, TLatex

reckind_List = ['g','a','m','t']
particle_List = ['L','A']

trig_List = ['ZB','JP0','JP1','JP2','AJP']

def cal_shift_error( pX, pY, epX, epY):
	pXsq=pX*pX
	pYsq=pY*pY
	epXsq=epX*epX
	epYsq=epY*epY

	outE=abs( ( (1. - 2. pX / pY)  epXsq  + pXsq * epYsq / pYsq ) / pYsq )
	return outE
	pass

def cal_shift( pX, pY ):
	return abs( (pX-pY)/pY )
	pass

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
			h_ZB = fin_ZB.Get('h_%s_fz_%s_PT%d'%(j,k,i-1))
			h_JP0 = fin_JP0.Get('h_%s_fz_%s_PT%d'%(j,k,i-1))
			h_JP1 = fin_JP1.Get('h_%s_fz_%s_PT%d'%(j,k,i-1))
			h_JP2 = fin_JP2.Get('h_%s_fz_%s_PT%d'%(j,k,i-1))
			h_AJP = fin_AJP.Get('h_%s_fz_%s_PT%d'%(j,k,i-1))

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
			h_ZB.SetTitle('fz shift for %s, pt%s'%(k,i))
			tc.cd()
			h_ZB.Draw()
			h_JP0.Draw('same')
			h_JP1.Draw('same')
			h_JP2.Draw('same')
			h_AJP.Draw('same')

			lg=TLegend(0.6,0.7,0.9,0.9)
			lg.AddEntry(h_ZB,'MB','lep')
			lg.AddEntry(h_JP0,'JP0','lep')
			lg.AddEntry(h_JP1,'JP1','lep')
			lg.AddEntry(h_JP2,'JP2','lep')
			lg.AddEntry(h_AJP,'AJP','lep')

			m_ZB=h_ZB.GetMean()
			m_JP0=h_JP0.GetMean()
			m_JP1=h_JP1.GetMean()
			m_JP2=h_JP2.GetMean()
			m_AJP=h_AJP.GetMean()
			em_ZB=h_ZB.GetMeanError()
			em_JP0=h_JP0.GetMeanError()
			em_JP1=h_JP1.GetMeanError()
			em_JP2=h_JP2.GetMeanError()
			em_AJP=h_AJP.GetMeanError()

			shift_JP0=cal_shift(m_JP0,m_ZB)
			shift_JP1=cal_shift(m_JP1,m_ZB)
			shift_JP2=cal_shift(m_JP2,m_ZB)
			shift_AJP=cal_shift(m_AJP,m_ZB)

			shift_error_JP0=cal_shift_error(m_JP0,m_ZB,em_JP0,em_ZB)
			shift_error_JP1=cal_shift_error(m_JP1,m_ZB,em_JP1,em_ZB)
			shift_error_JP2=cal_shift_error(m_JP2,m_ZB,em_JP2,em_ZB)
			shift_error_AJP=cal_shift_error(m_AJP,m_ZB,em_AJP,em_ZB)

			pt=TPaveText(0.6,0.4,0.9,0.7)
			pt.AddText('shift of mean value')
			pt.AddText('JP0: %.4f#pm%.4f'%(shift_JP0,shift_error_JP0))
			pt.AddText('JP1: %.4f#pm%.4f'%(shift_JP1,shift_error_JP1))
			pt.AddText('JP2: %.4f#pm%.4f'%(shift_JP2,shift_error_JP2))
			pt.AddText('AJP: %.4f#pm%.4f'%(shift_AJP,shift_error_AJP))

			lg.Draw('same')
			pt.Draw('same')

			cn = 'Pic/fz_%s_%s_PT%d.png' %(j,k,i)
			tc.SaveAs(cn)
			pass
		pass
	pass 
