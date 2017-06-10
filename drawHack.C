void y_true(){
  TFile *input = new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nubar_fgt.dst.root","READ");
  TTree *tree = (TTree*)input->Get("dune_dst");

  // tree->GetListOfBranches()->Print();

  TFile *output = new TFile("testOut.root","RECREATE");

  tree->Draw("y_true>>y_true");
  tree->Draw("y_reco>>y_reco");


  output->Write();
}
