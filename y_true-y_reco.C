TH1F* hnseg(nullptr);
void readEvent(){

   hnseg = new TH1F("hnseg",
                    "Number of segments for selected tracks",
                    4096,0,8192);
   //   Connect file generated in $ROOTSYS/test
   TFile fileIn("/pnfs/dune/persistent/TaskForce_AnaTree/ndtf_output/4th_run/ndtf_output_nubar_gar.dst.root");
   TTree* theTree = nullptr;
   TTreeReader theReader("T",&fileIn);
   TTreeReaderValue<Event> eventRV(theReader, "event");
   TTreeReaderValue<Int_t> nTracksRV(theReader, "fNtrack");

   while(theReader.Next()){
      if (*nTracksRV < 587) {
         continue; // Check if we don't have too many tracks
      }
      auto event = eventRV.Get();      //Read complete accepted event
                                       //in memory.
      hnseg->Fill(event->GetNseg());   //Fill histogram with number of
                                       //segments.
   }
   hnseg->Draw();
}
