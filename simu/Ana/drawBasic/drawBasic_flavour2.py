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

        fin_5 = TFile('../toHist/data/Jpt5/mc_ptV%d.hist_JP1.root'%i)

        for j in reckind_List:
                print j

                for m in xrange(0,2):
                        print m

                        for k in particle_List:
                                print k

                                tc=TCanvas('c','c',700,500)
                                h_5=fin_5.Get('h_%s_drParton_%s_J%d_PT%d'%(j,k,m,i-1))
                                h_5.Scale(1.0000/(h_5.Integral()))
                                tc.cd()
                                h_5.Draw('colz')

                                cn = 'Pic/drParton_%s_%s_J%d_PT%d.png' %(j,k,m,i)
                                tc.SaveAs(cn)
                                cn = 'Pic/drParton_%s_%s_J%d_PT%d.eps' %(j,k,m,i)
                                tc.SaveAs(cn)

                                pass
                        pass
                pass
        pass
