from ROOT import TFile, TH1D, TCanvas, TStyle, TLegend, TPaveText, TLatex

reckind_List = ['g','a','m','t']
particle_List = ['L','A']

trig_List = ['ZB','JP0','JP1','JP2','AJP']
item_List = ['im','eta','phi']

def cal_shift_error( pX, pY, epX, epY):
        pXsq=pX*pX
        pYsq=pY*pY
        epXsq=epX*epX
        epYsq=epY*epY

        outE=abs( ( (1 - 2*pX/pY)*epXsq+pXsq * epYsq / pYsq ) / pYsq )
        return outE
        pass

def cal_shift( pX, pY ):
        return abs( (pX-pY)/pY )
        pass

for i in xrange(3,4):
        print i

        fin_3 = TFile('../../toHist/data/Jpt5/mc_ptH_3_4_3000.hist_JP2.root'%i)
        fin_4 = TFile('../../toHist/data/Jpt5/mc_ptH_4_5_3000.hist_JP2.root'%i)
        fin_5 = TFile('../../toHist/data/Jpt5/mc_ptH_5_6_3000.hist_JP2.root'%i)
        fin_6 = TFile('../../toHist/data/Jpt5/mc_ptH_6_8_3000.hist_JP2.root'%i)
        fin_11 = TFile('../../toHist/data/Jpt5/mc_ptH_11_15_3000.hist_JP2.root'%i)
        fin_15 = TFile('../../toHist/data/Jpt5/mc_ptH_15_20_3000.hist_JP2.root'%i)
        fin_20 = TFile('../../toHist/data/Jpt5/mc_ptH_20_25_3000.hist_JP2.root'%i)
        fin_25 = TFile('../../toHist/data/Jpt5/mc_ptH_25_35_3000.hist_JP2.root'%i)

        for j in reckind_List:
                print j

                for m in xrange(0,2):
                        print m

                        for k in particle_List:
                                print k

                                for n in item_List:
                                        print n

                                        tc=TCanvas('c','c',1600,700)

                                        h_3=fin_3.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))
                                        h_4=fin_4.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))
                                        h_5=fin_5.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))
                                        h_6=fin_6.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))
                                        h_11=fin_11.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))
                                        h_15=fin_15.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))
                                        h_20=fin_20.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))
                                        h_25=fin_25.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))

                                        h_3.Scale(1.0000/(h_3.Integral()))
                                        h_4.Scale(1.0000/(h_4.Integral()))
                                        h_5.Scale(1.0000/(h_5.Integral()))
                                        h_6.Scale(1.0000/(h_6.Integral()))
                                        h_11.Scale(1.0000/(h_.Integral()))
                                        h_15.Scale(1.0000/(h_5.Integral()))
                                        h_20.Scale(1.0000/(h_5.Integral()))
                                        h_25.Scale(1.0000/(h_5.Integral()))

                                        if n=='eta':
                                                h_3.Rebin(5)
                                                h_4.Rebin(5)
                                                h_5.Rebin(5)
                                                pass
                                        if n=='phi':
                                                h_3.Rebin(5)
                                                h_4.Rebin(5)
                                                h_5.Rebin(5)
                                                pass

                                        h_3.SetMarkerStyle(20)
                                        h_4.SetMarkerStyle(20)
                                        h_5.SetMarkerStyle(20)
                                        h_6.SetMarkerStyle(20)
                                        h_11.SetMarkerStyle(20)
                                        h_15.SetMarkerStyle(20)
                                        h_20.SetMarkerStyle(20)
                                        h_25.SetMarkerStyle(20)

                                        h_3.SetMarkerColor(2)
                                        h_4.SetMarkerColor(4)
                                        h_5.SetMarkerColor(6)
                                        h_6.SetMarkerColor(6)
                                        h_11.SetMarkerColor(6)
                                        h_15.SetMarkerColor(6)
                                        h_20.SetMarkerColor(6)
                                        h_25.SetMarkerColor(6)

                                        h_3.SetLineColor(2)
                                        h_4.SetLineColor(4)
                                        h_5.SetLineColor(6)
                                        h_6.SetLineColor(6)
                                        h_11.SetLineColor(6)
                                        h_15.SetLineColor(6)
                                        h_20.SetLineColor(6)
                                        h_25.SetLineColor(6)

                                        tc.cd(1)
                                        h_3.Draw()
                                        tc.cd(2)
                                        h_4.Draw()
                                        tc.cd(3)
                                        h_5.Draw()                                    
                                        tc.cd(4)
                                        h_6.Draw()
                                        tc.cd(5)
                                        h_11.Draw()
                                        tc.cd(6)
                                        h_15.Draw()
                                        tc.cd(7)
                                        h_20.Draw()
                                        tc.cd(8)
                                        h_25.Draw()
                                        lg.Draw('same')

                                        cn = 'Pic/%s_%s_%s_J%d_PT%d.png' %(n,j,k,m,i)
                                        tc.SaveAs(cn)
                                        cn = 'Pic/%s_%s_%s_J%d_PT%d.eps' %(n,j,k,m,i)
                                        tc.SaveAs(cn)

                                        pass
                                pass
                        pass
                pass
        pass
