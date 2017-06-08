import ROOT as root

f = root.TFile.Open("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nubar_gar.dst.root", "READ")
tree = f.Get("dune_dst")
# tree.Draw("y_reco:y_true")
output = root.TFile.Open("gar.root", "RECREATE")

tree.Draw("y_reco")

output.Write()


#for entry in tree:
     # Now you have acess to the leaves/branches of each entry in the tree, e.g.
    #  events = entry.events
#    print "a"

root.gApplication.Run()
