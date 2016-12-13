from ROOT import TFile, TH1D, TCanvas, TStyle, TLegend, TPaveText, TLatex

reckind_List = ['a','m','t']
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

        fin_3 = TFile('../toHist/data/Jpt3/mc_ptV%d.hist_JP2.root'%i)
        fin_4 = TFile('../toHist/data/Jpt4/mc_ptV%d.hist_JP2.root'%i)
        fin_5 = TFile('../toHist/data/Jpt5/mc_ptV%d.hist_JP2.root'%i)

        for j in reckind_List:
                print j

                for m in xrange(0,2):
                        print m

                        for k in particle_List:
                                print k

                                for n in item_List:
                                        print n

                                        tc=TCanvas('c','c',700,500)

                                        h_3=fin_3.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))
                                        h_4=fin_4.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))
                                        h_5=fin_5.Get('h_%s_%s_%s_J%d_PT%d'%(j,n,k,m,i-1))

                                        h_3.Scale(1.0000/(h_3.Integral()))
                                        h_4.Scale(1.0000/(h_4.Integral()))
                                        h_5.Scale(1.0000/(h_5.Integral()))

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
                                        h_3.SetMarkerColor(2)
                                        h_4.SetMarkerColor(4)
                                        h_5.SetMarkerColor(6)
                                        h_3.SetLineColor(2)
                                        h_4.SetLineColor(4)
                                        h_5.SetLineColor(6)

                                        tc.cd()

                                        h_3.Draw()
                                        h_4.Draw('same')
                                        h_5.Draw('same')

                                        lg=TLegend(0.15,0.75,0.4,0.88)
                                        lg.SetBorderSize(0)

                                        lg.AddEntry(h_3,'J_pt3','lep')
                                        lg.AddEntry(h_4,'J_pt4','lep')
                                        lg.AddEntry(h_5,'J_pt5','lep')

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
