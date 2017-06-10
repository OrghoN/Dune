void positionResolution(){

// open files
        vector<TFile *> files {new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nubar_fgt.dst.root","READ"),new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nu_fgt.dst.root","READ"),new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nubar_gar.dst.root","READ"),new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nu_gar.dst.root","READ")};

        vector<TH1F *> difference {new TH1F("nubar_fgt_dif","y_true-y_reco",100,0,1), new TH1F("nu_fgt_dif","y_true-y_reco",100,0,1), new TH1F("nubar_gar_dif","y_true-y_reco",100,0,1), new TH1F("nu_gar_dif","y_true-y_reco",100,0,1)};
        vector<TH1F *> division {new TH1F("nubar_fgt_div","y_true-y_reco",100,0,1), new TH1F("nu_fgt_div","y_true-y_reco",100,0,1), new TH1F("nubar_gar_div","y_true-y_reco",100,0,1), new TH1F("nu_gar_div","y_true-y_reco",100,0,1)};
        vector<TH1F *> h_true {new TH1F("nubar_fgt_y_true","y_true",100,0,1), new TH1F("nu_fgt_y_true","y_true",100,0,1), new TH1F("nubar_gar_y_true","y_true",100,0,1), new TH1F("nu_gar_y_true","y_true",100,0,1)};
        vector<TH1F *> h_reco {new TH1F("nubar_fgt_y_reco","y_reco",100,0,1), new TH1F("nu_fgt_y_reco","y_reco",100,0,1), new TH1F("nubar_gar_y_reco","y_reco",100,0,1), new TH1F("nu_gar_y_reco","y_reco",100,0,1)};

        TFile *output = new TFile("/dune/data/users/oneogi/positionResolution.root","NEW");

        for (size_t i = 0; i < files.size(); i++) {
        // for (size_t i = 0; i < 1; i++) {
                TTreeReader reader("dune_dst", files[i]);

                TTreeReaderValue<Float_t> y_true(reader, "y_true");
                TTreeReaderValue<Float_t> y_reco(reader, "y_reco");

                while (reader.Next()) {
                        h_true[i]->Fill(*y_true);
			h_reco[i]->Fill(*y_reco);
		        difference[i]->Fill(*y_true - *y_reco);
                        division[i]->Fill(*y_reco / *y_true);
                }

                difference[i]->Write();
                division[i]->Write();
                h_true[i]->Write();
                h_reco[i]->Write();
        }
}
