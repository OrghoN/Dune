void readTree(){
        TFile *input = new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nubar_fgt.dst.root","READ");
        // TTree *tree = (TTree*)input->Get("dune_dst");

        TH1F *myHist = new TH1F("h1","ntuple",100,-4,4);

        TTreeReader reader("dune_dst", input);

        TTreeReaderValue<Float_t> y_true(reader, "y_true");
        TTreeReaderValue<Float_t> y_reco(reader, "y_reco");

        while (reader.Next()) {
                myHist->Fill(*y_true - *y_reco);
        }

        myHist->Draw();
}
