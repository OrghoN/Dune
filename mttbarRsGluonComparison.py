from ROOT import *

gROOT.Reset()
c1 = TCanvas( 'mttbarSignalComparison', 'mttbarSignalComparison', 200, 10, 700, 500 )

f = TFile.Open("rsGluon_Top_1b.root")

histograms = [f.Get("mttbar_M_RSG1_5"), f.Get("mttbar_M_RSG2"), f.Get("mttbar_M_RSG3"), f.Get("mttbar_M_RSG4")]

colors = [1, 2, 3, 4]

i=0

legendPosition=[0.55,0.55,0.85,0.85]
legendEntries=["RS Gluon m = 1.5TeV", "RS Gluon m = 2TeV", "RS Gluon m = 3TeV", "RS Gluon m = 4TeV"]

legend = TLegend(legendPosition[0], legendPosition[1], legendPosition[2], legendPosition[3])
legend.AddEntry(histograms[0],"1 b tag and 1 top tag", "")

for histogram in histograms:
    histogram.Rebin(2)
    histogram.SetLineColor(colors[i])
    histogram.SetLineWidth(2)
    histogram.Draw("HIST SAMES")

    legend.AddEntry(histogram,legendEntries[i],"l")

    i+=1

gStyle.SetOptStat(0)

legend.SetFillColor(kWhite)
legend.SetBorderSize(0)
legend.SetTextSize(0.043)
legend.Draw()

gApplication.Run()
