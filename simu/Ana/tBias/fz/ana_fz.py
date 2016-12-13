from ROOT import TFile, TH1D, TCanvas, TStyle, TLegend, TPaveText, TLatex

reckind_List = ['g','a','m','t']
particle_List = ['L','A']

trig_List = ['ZB','JP0','JP1','JP2','AJP']

def cal_shift_error( pX, pY, epX, epY):
        pXsq=pX*pX
        pYsq=pY*pY
        epXsq=epX*epX
        epYsq=epY*epY

        outE=abs( ( (1 - 2*pX / pY)*epXsq  + pXsq * epYsq / pYsq ) / pYsq )
        return outE
        pass

def cal_shift( pX, pY ):
        return abs( (pX-pY)/pY )
        pass

for i in xrange(3,4):
        print i
        fin_ZB = TFile('../../toHist/data/mc_ptV%d.hist_ZB.root'%i)
        fin_JP0 = TFile('../../toHist/data/mc_ptV%d.hist_JP0.root'%i)
        fin_JP1 = TFile('../../toHist/data/mc_ptV%d.hist_JP1.root'%i)
        fin_JP2 = TFile('../../toHist/data/mc_ptV%d.hist_JP2.root'%i)
        fin_AJP = TFile('../../toHist/data/mc_ptV%d.hist_AJP.root'%i)

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

                        h_ZB.SetMarkerStyle(20)
                        h_JP0.SetMarkerStyle(20)
                        h_JP1.SetMarkerStyle(20)
                        h_JP2.SetMarkerStyle(20)
                        h_AJP.SetMarkerStyle(20)

                        h_ZB.SetMarkerColor(1)
                        h_JP0.SetMarkerColor(2)
                        h_JP1.SetMarkerColor(4)
                        h_JP2.SetMarkerColor(6)
                        h_AJP.SetMarkerColor(8)

                        h_ZB.SetMarkerLine(1)
                        h_JP0.SetMarkerLine(2)
                        h_JP1.SetMarkerLine(4)
                        h_JP2.SetMarkerLine(6)
                        h_AJP.SetMarkerLine(8)

                        h_ZB.SetXTitle('z(=L_pt/J_pt)')
                        h_ZB.SetTitle('fz shift for %s, pt%s'%(k,i))
                        h_ZB.GetYaxis().SetRangeUser(0,0.06)

                        tc.cd()
                        h_ZB.Draw()
                        h_JP0.Draw('same')
                        h_JP1.Draw('same')
                        h_JP2.Draw('same')
                        h_AJP.Draw('same')

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
                        print shift_error_JP0
                        print shift_error_JP1
                        print shift_error_JP2
                        print shift_error_AJP

                        lg=TLegend(0.4,0.6,0.9,0.8)
                        lg.SetBorderSize(0)

                        lg.AddEntry(h_ZB,'MB      Shifit','lep')
                        tchar='JP0:  %.4f#pm%.4f'%(shift_JP0,shift_error_JP0)
                        lg.AddEntry(h_JP0,tchar,'lep')
                        tchar='JP1:  %.4f#pm%.4f'%(shift_JP1,shift_error_JP1)
                        lg.AddEntry(h_JP1,tchar,'lep')
                        tchar='JP2:  %.4f#pm%.4f'%(shift_JP2,shift_error_JP2)
                        lg.AddEntry(h_JP2,tchar,'lep')
                        tchar='AJP:  %.4f#pm%.4f'%(shift_AJP,shift_error_AJP)
                        lg.AddEntry(h_AJP,tchar,'lep')

                        lg.Draw('same')

                        cn = 'Pic/fz_%s_%s_PT%d.png' %(j,k,i)
                        tc.SaveAs(cn)
                        pass
                pass
        pass
