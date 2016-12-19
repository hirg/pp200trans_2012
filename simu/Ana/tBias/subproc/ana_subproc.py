from ROOT import TFile, TH1D, TCanvas, TStyle, TLegend, TPaveText, TLatex
import sys

ptH = sys.argv[1]

reckind_List = ['g','a']
particle_List = ['L','A']

trig_List = ['ZB','JP0','JP1','JP2','AJP']
subid_List = [11,12,13,28,53,68]
str_subid_List = ['f_{i}f_{j}#rightarrow f_{i}f_{j}','f_{i}#bar{f_{i}}#rightarrow f_{k}#bar{f_{k}}','f_{i}#bar{f_{i}}#rightarrow gg',\
'f_{i}g#rightarrow f_{i}g','gg#rightarrow f_{k}f_{k}','gg#rightarrow gg']

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
        fin_ZB = TFile('../../toHist/data/ptH_%s/mc_ptH_%s_ptV%d.hist_ZB.root'%(ptH,ptH,i))
        fin_JP0 = TFile('../../toHist/data/ptH_%s/mc_ptH_%s_ptV%d.hist_JP0.root'%(ptH,ptH,i))
        fin_JP1 = TFile('../../toHist/data/ptH_%s/mc_ptH_%s_ptV%d.hist_JP1.root'%(ptH,ptH,i))
        fin_JP2 = TFile('../../toHist/data/ptH_%s/mc_ptH_%s_ptV%d.hist_JP2.root'%(ptH,ptH,i))
        fin_AJP = TFile('../../toHist/data/ptH_%s/mc_ptH_%s_ptV%d.hist_AJP.root'%(ptH,ptH,i))
        
        for j in reckind_List:
                print j

                for m in xrange(0,2):
                        print m

                        for k in particle_List:
                                print k

                                fout = open('ptH_%s/change_subproc_%s_%s_J%d_PT%d.txt'%(ptH,j,k,m,i),'w')
                                tc=TCanvas('c','c',700,500)
                                
                                h_ZB=fin_ZB.Get('h_%s_idSubproc_%s_J%d_PT%d'%(j,k,m,i-1))
                                h_JP0=fin_JP0.Get('h_%s_idSubproc_%s_J%d_PT%d'%(j,k,m,i-1))
                                h_JP1=fin_JP1.Get('h_%s_idSubproc_%s_J%d_PT%d'%(j,k,m,i-1))
                                h_JP2=fin_JP2.Get('h_%s_idSubproc_%s_J%d_PT%d'%(j,k,m,i-1))
                                h_AJP=fin_AJP.Get('h_%s_idSubproc_%s_J%d_PT%d'%(j,k,m,i-1))

                                h_ZB.Scale(1.0000/(h_ZB.Integral()))
                                h_JP0.Scale(1.0000/(h_JP0.Integral()))
                                h_JP1.Scale(1.0000/(h_JP1.Integral()))
                                h_JP2.Scale(1.0000/(h_JP2.Integral()))
                                h_AJP.Scale(1.0000/(h_AJP.Integral()))
                                
                                d_ZB=TH1D('subproc_ZB','subproc_ZB',6,0,6)
                                d_JP0=TH1D('subproc_JP0','subproc_JP0',6,0,6)
                                d_JP1=TH1D('subproc_JP1','subproc_JP1',6,0,6)
                                d_JP2=TH1D('subproc_JP2','subproc_JP2',6,0,6)
                                d_AJP=TH1D('subproc_AJP','subproc_AJP',6,0,6)

                                for subid_bin in xrange(1,7):

                                        d_ZB.GetXaxis().SetBinLabel(subid_bin,str_subid_List[subid_bin-1])
                                        d_JP0.GetXaxis().SetBinLabel(subid_bin,str_subid_List[subid_bin-1])
                                        d_JP1.GetXaxis().SetBinLabel(subid_bin,str_subid_List[subid_bin-1])
                                        d_JP2.GetXaxis().SetBinLabel(subid_bin,str_subid_List[subid_bin-1])
                                        d_AJP.GetXaxis().SetBinLabel(subid_bin,str_subid_List[subid_bin-1])

                                        subid=subid_List[subid_bin-1]
                                        fout.write(subid)
                                        fout.write('\n')
                                        nEvts_ZB=h_ZB.GetBinContent(subid+1)

                                        nEvts=h_ZB.GetBinContent(subid+1)
                                        enEvts=h_ZB.GetBinError(subid+1)
                                        d_ZB.SetBinContent(subid_bin,nEvts)
                                        d_ZB.SetBinError(subid_bin,enEvts)
                                        fout.write('ZB:\t')
                                        fout.write(nEvts)
                                        fout.write('\t')
                                        fout.write(nEvts-nEvts_ZB)
                                        fout.write('\n')

                                        nEvts=h_JP0.GetBinContent(subid+1)
                                        enEvts=h_JP0.GetBinError(subid+1)
                                        d_JP0.SetBinContent(subid_bin,nEvts)
                                        d_JP0.SetBinError(subid_bin,enEvts)
                                        fout.write('JP0:\t')
                                        fout.write(nEvts)
                                        fout.write('\t')
                                        fout.write(nEvts-nEvts_ZB)
                                        fout.write('\n')

                                        nEvts=h_JP1.GetBinContent(subid+1)
                                        enEvts=h_JP1.GetBinError(subid+1)
                                        d_JP1.SetBinContent(subid_bin,nEvts)
                                        d_JP1.SetBinError(subid_bin,enEvts)
                                        fout.write('JP1:\t')
                                        fout.write(nEvts)
                                        fout.write('\t')
                                        fout.write(nEvts-nEvts_ZB)
                                        fout.write('\n')

                                        nEvts=h_JP2.GetBinContent(subid+1)
                                        enEvts=h_JP2.GetBinError(subid+1)
                                        d_JP2.SetBinContent(subid_bin,nEvts)
                                        d_JP2.SetBinError(subid_bin,enEvts)
                                        fout.write('JP2:\t')
                                        fout.write(nEvts)
                                        fout.write('\t')
                                        fout.write(nEvts-nEvts_ZB)
                                        fout.write('\n')

                                        nEvts=h_AJP.GetBinContent(subid+1)
                                        enEvts=h_AJP.GetBinError(subid+1)
                                        d_AJP.SetBinContent(subid_bin,nEvts)
                                        d_AJP.SetBinError(subid_bin,enEvts)
                                        fout.write('AJP:\t')
                                        fout.write(nEvts)
                                        fout.write('\t')
                                        fout.write(nEvts-nEvts_ZB)
                                        fout.write('\n')
                                        pass
                                        
                                d_ZB.SetMarkerStyle(20)
                                d_JP0.SetMarkerStyle(20)
                                d_JP1.SetMarkerStyle(20)
                                d_JP2.SetMarkerStyle(20)
                                d_AJP.SetMarkerStyle(20)

                                d_ZB.SetMarkerColor(1)
                                d_JP0.SetMarkerColor(2)
                                d_JP1.SetMarkerColor(4)
                                d_JP2.SetMarkerColor(6)
                                d_AJP.SetMarkerColor(8)

                                d_ZB.SetLineColor(1)
                                d_JP0.SetLineColor(2)
                                d_JP1.SetLineColor(4)
                                d_JP2.SetLineColor(6)
                                d_AJP.SetLineColor(8)

                                d_ZB.SetXTitle('Subprocess')
                                d_ZB.SetTitle('Subprocess for %s, J%d, pt%s'%(k,m,i))
                                d_ZB.GetYaxis().SetRangeUser(0,1.0)

                                tc.cd()
                                d_ZB.Draw()
                                d_JP0.Draw('same')
                                d_JP1.Draw('same')
                                d_JP2.Draw('same')
                                d_AJP.Draw('same')

                                lg=TLegend(0.15,0.75,0.4,0.88)
                                lg.SetBorderSize(0)
                                lg.SetNColumns(2)

                                lg.AddEntry(d_ZB,'MB ','lep')
                                lg.AddEntry(d_JP0,'JP0','lep')
                                lg.AddEntry(d_JP1,'JP1','lep')
                                lg.AddEntry(d_JP2,'JP2','lep')
                                lg.AddEntry(d_AJP,'AJP','lep')

                                lg.Draw('same')

                                cn = 'Pic/ptH_%s/subproc_%s_%s_J%d_PT%d.png' %(ptH,j,k,m,i)
                                tc.SaveAs(cn)
                                cn = 'Pic/ptH_%s/subproc_%s_%s_J%d_PT%d.eps' %(ptH,j,k,m,i)
                                tc.SaveAs(cn)
                                
                                fout.close()
                                pass
                        pass
                pass
        pass
