#include "Overlay_Abstraction.C"

void abstractionDemo(){
  //read in files
  //Files that are read in during this step can be found at
  ///uscms_data/d1/oneogi/JaneHistograms/instantaneous_luminosity/DQM_V0001_R000273158__Global__CMSSW_X_Y_Z__RECO.root
  ///uscms_data/d1/oneogi/JaneHistograms/instantaneous_luminosity/DQM_V0001_R000273725__Global__CMSSW_X_Y_Z__RECO.root
  ///uscms_data/d1/oneogi/JaneHistograms/instantaneous_luminosity/DQM_V0001_R000274172__Global__CMSSW_X_Y_Z__RECO.root
  ///The files need to be copied to the same directory to run this macro
  vector<TFile *> files {new TFile("./DQM_V0001_R000273158__Global__CMSSW_X_Y_Z__RECO.root", "READ"), new TFile("./DQM_V0001_R000273725__Global__CMSSW_X_Y_Z__RECO.root", "READ"), new TFile("./DQM_V0001_R000274172__Global__CMSSW_X_Y_Z__RECO.root", "READ")};

  //variable name
  TString variable = "/ME_Eff_PFPtBarrel";
  TString trigger = "HLT_PFJet140_wrt_HLT_PFJet80";

  //style choices
  vector<Color_t> colors {kBlue, kRed, kGreen};
  vector<Width_t> lineWidths {3, 3, 3};
  vector<Style_t> lineStyles {1, 2, 2};

  //legend
  vector<TString> legendEntries {"273158 NVtx=18", "273725 NVtx=13", "274172 NVtx=12"};
  Double_t legend[4] = {0.311613, 0.148203, 0.512385, 0.325092};

  //statistics positions
  vector<vector <Double_t>> statPositions {{0.78,0.584735,0.98,0.743855}, {0.78,0.775,0.98,0.935}, {0.620301, 0.15065, 0.820802, 0.307891}};
  Double_t zoom[] ={0,100};

  //create canvas
  TCanvas * Canvas = new TCanvas(trigger,"",800,800);

  //define paths
  vector<TString> paths {"DQMData/Run 273158/HLT/Run summary/JetMET/RelativeTriggerEff/" + trigger + variable,"DQMData/Run 273725/HLT/Run summary/JetMET/RelativeTriggerEff/" + trigger + variable, "DQMData/Run 274172/HLT/Run summary/JetMET/RelativeTriggerEff/" + trigger + variable};

  //Define titles
  TString titles[] = {trigger + " " + variable, variable, "Efficiency"};

  // //Draw Call (some versions that eliminate a lot of the less often used parameters)
  // DrawOverlay(files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, legend);
  // DrawOverlay(files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, legend, "test1");
  //
  // DrawOverlay(files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend);
  // DrawOverlay(files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend, "test2");
  //
  // DrawOverlay(false, zoom, false, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend);
  // DrawOverlay(false, zoom, false, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend, "test3");
  //
  // DrawOverlay(false, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend);
  // DrawOverlay(false, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend, "test4");
  //
  // DrawOverlay(Canvas, 1, false, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend);
  // DrawOverlay(Canvas, 1, false, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend, "test5");
  //
  // DrawOverlay(Canvas, 1, false, zoom, false, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend);
  //FUll Draw Call
  DrawOverlay(Canvas, 1, false, zoom, false, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legend, "FullDrawCall");
}
