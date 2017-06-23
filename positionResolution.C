void positionResolution(){

        // open files
        vector<TFile *> files {new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nubar_fgt.dst.root","READ"),new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nu_fgt.dst.root","READ"),new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nubar_gar.dst.root","READ"),new TFile("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nu_gar.dst.root","READ")};

        //create histograms
        vector<TH1F *> differenceX {new TH1F("nubar_fgt_difX","trueVtxX-recoVtxX",100,-0.2,0.2), new TH1F("nu_fgt_difX","trueVtxX-recoVtxX",100,-0.2,0.2), new TH1F("nubar_gar_difX","trueVtxX-recoVtxX",100,-0.2,0.2), new TH1F("nu_gar_difX","trueVtxX-recoVtxX",100,-0.2,0.2)};
        vector<TH1F *> divisionX {new TH1F("nubar_fgt_divX","trueVtxX-recoVtxX",100,-0.2,0.2), new TH1F("nu_fgt_divX","trueVtxX-recoVtxX",100,-0.2,0.2), new TH1F("nubar_gar_divX","trueVtxX-recoVtxX",100,-0.2,0.2), new TH1F("nu_gar_divX","trueVtxX-recoVtxX",100,-0.2,0.2)};

        vector<TH1F *> differenceY {new TH1F("nubar_fgt_difY","trueVtxY-recoVtxY",100,-0.2,0.2), new TH1F("nu_fgt_difY","trueVtxY-recoVtxY",100,-0.2,0.2), new TH1F("nubar_gar_difY","trueVtxY-recoVtxY",100,-0.2,0.2), new TH1F("nu_gar_difY","trueVtxY-recoVtxY",100,-0.2,0.2)};
        vector<TH1F *> divisionY {new TH1F("nubar_fgt_divY","trueVtxY-recoVtxY",100,-0.2,0.2), new TH1F("nu_fgt_divY","trueVtxY-recoVtxY",100,-0.2,0.2), new TH1F("nubar_gar_divY","trueVtxY-recoVtxY",100,-0.2,0.2), new TH1F("nu_gar_divY","trueVtxY-recoVtxY",100,-0.2,0.2)};

        vector<TH1F *> differenceZ {new TH1F("nubar_fgt_difZ","trueVtxZ-recoVtxZ",100,-0.2,0.2), new TH1F("nu_fgt_difZ","trueVtxZ-recoVtxZ",100,-0.2,0.2), new TH1F("nubar_gar_difZ","trueVtxZ-recoVtxZ",100,-0.2,0.2), new TH1F("nu_gar_difZ","trueVtxZ-recoVtxZ",100,-0.2,0.2)};
        vector<TH1F *> divisionZ {new TH1F("nubar_fgt_divZ","trueVtxZ-recoVtxZ",100,-0.2,0.2), new TH1F("nu_fgt_divZ","trueVtxZ-recoVtxZ",100,-0.2,0.2), new TH1F("nubar_gar_divZ","trueVtxZ-recoVtxZ",100,-0.2,0.2), new TH1F("nu_gar_divZ","trueVtxZ-recoVtxZ",100,-0.2,0.2)};

        vector<TH1F *> differenceE {new TH1F("nubar_fgt_difE","Ev-EV_reco",100,0,4), new TH1F("nu_fgt_difE","Ev-EV_reco",100,0,4), new TH1F("nubar_gar_difE","Ev-EV_reco",100,0,4), new TH1F("nu_gar_difE","Ev-EV_reco",100,0,4)};
        vector<TH1F *> divisionE {new TH1F("nubar_fgt_divE","Ev-EV_reco",100,0,2), new TH1F("nu_fgt_divE","Ev-EV_reco",100,0,2), new TH1F("nubar_gar_divE","Ev-EV_reco",100,0,2), new TH1F("nu_gar_divE","Ev-EV_reco",100,0,2)};

        //create output file
        TFile *output = new TFile("/dune/data/users/oneogi/positionResolution.root","RECREATE");

        //loop over files
        for (size_t i = 0; i < files.size(); i++) {
                //Create Readers
                TTreeReader reader("dune_dst", files[i]);

                TTreeReaderValue<Float_t> Ev(reader, "Ev");
                TTreeReaderValue<Float_t> Ev_reco(reader, "Ev_reco");

                TTreeReaderValue<Float_t> trueVtxX(reader, "trueVtxX");
                TTreeReaderValue<Float_t> recoVtxX(reader, "recoVtxX");

                TTreeReaderValue<Float_t> trueVtxY(reader, "trueVtxY");
                TTreeReaderValue<Float_t> recoVtxY(reader, "recoVtxY");

                TTreeReaderValue<Float_t> trueVtxZ(reader, "trueVtxZ");
                TTreeReaderValue<Float_t> recoVtxZ(reader, "recoVtxZ");

                // cout << "file" << 1 << endl;

                //loop over ntuples
                while (reader.Next()) {
                        differenceX[i]->Fill(*trueVtxX - *recoVtxX);
                        divisionX[i]->Fill(*recoVtxX / *trueVtxX);

                        differenceY[i]->Fill(*trueVtxY - *recoVtxY);
                        divisionY[i]->Fill(*recoVtxY / *trueVtxY);

                        differenceZ[i]->Fill(*trueVtxZ - *recoVtxZ);
                        divisionZ[i]->Fill(*recoVtxZ / *trueVtxZ);

                        differenceE[i]->Fill(*Ev - *Ev_reco);
                        divisionE[i]->Fill(*Ev_reco / *Ev);

                }

                //write to file
                differenceX[i]->Write();
                divisionX[i]->Write();

                differenceY[i]->Write();
                divisionY[i]->Write();

                differenceZ[i]->Write();
                divisionZ[i]->Write();

                differenceE[i]->Write();
                divisionE[i]->Write();

        }
}
