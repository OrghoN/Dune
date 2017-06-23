import ROOT as root

f = root.TFile.Open("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nubar_fgt.dst.root", "READ")

hist.Draw()

root.gApplication.Run()
