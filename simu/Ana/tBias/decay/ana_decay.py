from ROOT import TFile, TH1D, TCanvas, TStyle, TLegend, TPaveText, TLatex

reckind_List = ['g','a']
particle_List = ['L','A']

trig_List = ['ZB','JP0','JP1','JP2','AJP']
#ppid_List = [-4232,-4132,-4122,-3334,-3322,-3312,-3224,-3214,-3212,-3114,-531,-521,-511,-443,-441,91,92,441,443,511,521,531,3114,3212,3214,3224,3312,3322,3334,4122,4132,4232]

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
        fin_ZB = TFile('../../toHist/data/mc_ptV%d.hist_ZB.root'%i)
        fin_JP0 = TFile('../../toHist/data/mc_ptV%d.hist_JP0.root'%i)
        fin_JP1 = TFile('../../toHist/data/mc_ptV%d.hist_JP1.root'%i)
        fin_JP2 = TFile('../../toHist/data/mc_ptV%d.hist_JP2.root'%i)
        fin_AJP = TFile('../../toHist/data/mc_ptV%d.hist_AJP.root'%i)

        for j in reckind_List:
                print j

                for m in xrange(0,1):
                        print m

                        for k in particle_List:
                                tc=TCanvas('c','c',700,500)
                                print k
                                h_ZB=fin_ZB.Get('h_%s_pid_parent_%s_J%d_PT%d'%(j,k,m,i-1))
                                h_JP0=fin_JP0.Get('h_%s_pid_parent_%s_J%d_PT%d'%(j,k,m,i-1))
                                h_JP1=fin_JP1.Get('h_%s_pid_parent_%s_J%d_PT%d'%(j,k,m,i-1))
                                h_JP2=fin_JP2.Get('h_%s_pid_parent_%s_J%d_PT%d'%(j,k,m,i-1))
                                h_AJP=fin_AJP.Get('h_%s_pid_parent_%s_J%d_PT%d'%(j,k,m,i-1))

                                h_ZB.Scale(1.0000/(h_ZB.Integral()))
                                h_JP0.Scale(1.0000/(h_JP0.Integral()))
                                h_JP1.Scale(1.0000/(h_JP1.Integral()))
                                h_JP2.Scale(1.0000/(h_JP2.Integral()))
                                h_AJP.Scale(1.0000/(h_AJP.Integral()))

                                h_ZB.GetXaxis().SetDecimals()
                                h_JP0.GetXaxis().SetDecimals()
                                h_JP1.GetXaxis().SetDecimals()
                                h_JP2.GetXaxis().SetDecimals()
                                h_AJP.GetXaxis().SetDecimals()

                                '''
                                d_ZB=TH1D('decay_ZB','decay_ZB',32,0,32)
                                d_JP0=TH1D('decay_JP0','decay_JP0',32,0,32)
                                d_JP1=TH1D('decay_JP1','decay_JP1',32,0,32)
                                d_JP2=TH1D('decay_JP2','decay_JP2',32,0,32)
                                d_AJP=TH1D('decay_AJP','decay_AJP',32,0,32)

                                for ppid_bin in xrange(1,33):

                                        d_ZB.GetXaxis().SetBinLabel(ppid_bin,str(ppid_List[ppid_bin-1]))
                                        d_JP0.GetXaxis().SetBinLabel(ppid_bin,str(ppid_List[ppid_bin-1]))
                                        d_JP1.GetXaxis().SetBinLabel(ppid_bin,str(ppid_List[ppid_bin-1]))
                                        d_JP2.GetXaxis().SetBinLabel(ppid_bin,str(ppid_List[ppid_bin-1]))
                                        d_AJP.GetXaxis().SetBinLabel(ppid_bin,str(ppid_List[ppid_bin-1]))

                                        nEvts=h_ZB.GetBinContent(ppid)
                                        if nEvts>0:
                                                lout='%d\t%d\t%.2e'%(ppid,ppid-5001,nEvts)
                                                print lout
                                                #pass
                                        #pass
                                '''
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

                                h_ZB.SetLineColor(1)
                                h_JP0.SetLineColor(2)
                                h_JP1.SetLineColor(4)
                                h_JP2.SetLineColor(6)
                                h_AJP.SetLineColor(8)

                                h_ZB.SetXTitle('pid_parent')
                                h_ZB.SetTitle('pid_parent distribution for %s, J%d, pt%s'%(k,m,i))
                                h_ZB.GetYaxis().SetRangeUser(0,1.0)

                                tc.cd()
                                h_ZB.Draw()
                                h_JP0.Draw('same')
                                h_JP1.Draw('same')
                                h_JP2.Draw('same')
                                h_AJP.Draw('same')

                                lg=TLegend(0.45,0.7,0.7,0.9)
                                lg.SetBorderSize(0)

                                lg.AddEntry(h_ZB,'MB ','lep')
                                lg.AddEntry(h_JP0,'JP0','lep')
                                lg.AddEntry(h_JP1,'JP1','lep')
                                lg.AddEntry(h_JP2,'JP2','lep')
                                lg.AddEntry(h_AJP,'AJP','lep')

                                lg.Draw('same')

                                cn = 'Pic/decay_%s_%s_J%d_PT%d.png' %(j,k,m,i)
                                tc.SaveAs(cn)
                                cn = 'Pic/decay_%s_%s_J%d_PT%d.eps' %(j,k,m,i)
                                tc.SaveAs(cn)

                                #pass
                        #pass
                #pass
        #pass
