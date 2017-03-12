from ROOT import *

# gROOT.Reset()
# gSystem.Load("dunendtf")
# c1 = TCanvas( 'yComparison', 'yComparison', 200, 10, 700, 500 )

f = TFile.Open("ndtf_output_nubar_gar.dst.root")
tree = f.Get("dune_dst")
tree.Draw("y_reco:y_true")

# for event in f.dune_dst:
    # print event.y_reco

# gApplication.Run()
