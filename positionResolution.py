import ROOT as root

f = root.TFile.Open("positionResolution.root", "READ")

hist=f.Get("nu_gar_difX")

hist.Draw();

root.gApplication.Run()
