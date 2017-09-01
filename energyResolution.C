#include "Overlay_Abstraction.C"

void energyResolution(){

        //open file
        TFile *file = new TFile("./positionResolution.root", "READ");
        vector<TFile *> files {file,file};

        //paths
        vector<TString> nubarDifPath {"nubar_fgt_difE","nubar_gar_difE"};
        vector<TString> nuDifPath {"nu_fgt_difE","nu_gar_difE"};
        vector<TString> nubarDivPath {"nubar_fgt_divE","nubar_gar_divE"};
        vector<TString> nuDivPath {"nu_fgt_divE","nu_gar_divE"};

        //style choices
        vector<Color_t> colors {kBlue, kRed};
        vector<Width_t> lineWidths {4, 4};
        vector<Style_t> lineStyles {2,2};

        //legend
        vector<TString> legendEntries {"Fine Grained Tracker", "Gas Argon"};
        Double_t legendDif[4] = {0.305095, 0.7083, 0.505867, 0.88496};
        Double_t legendDiv[4] = {0.134309, 0.718847, 0.33508, 0.895507};

        vector<vector <Double_t>> statPositions {{0.78,0.584735,0.98,0.743855}, {0.78,0.775,0.98,0.935}};

        //titles
        TString nuBarDifTitles[] = {"AntiNeutrino Energy in Near Detector", "Ev - Ev_reco", ""};
        TString nuDifTitles[] = {"Neutrino Energy in Near Detector", "Ev - Ev_reco", ""};
        TString nuBarDivTitles[] = {"AntiNeutrino Energy in Near Detector", "Ev_reco / Ev", ""};
        TString nuDivTitles[] = {"Neutrino Energy in Near Detector", "Ev_reco / Ev", ""};

        //dummy variable
        Double_t zoom[] ={0,100};

        //create canvas and divide it
        TCanvas * nuBarCanvas = new TCanvas("nuBar","",1600,800);
        TCanvas * nuCanvas = new TCanvas("nu","",1600,800);

        nuBarCanvas->Divide(2,1);
        nuCanvas->Divide(2,1);

        //actual Draw Calls
        DrawOverlay(nuBarCanvas, 1, false, zoom, true, false, files, nubarDifPath, colors, lineWidths, lineStyles, legendEntries, nuBarDifTitles, statPositions, 1111, legendDif, "nuBar");
        DrawOverlay(nuCanvas, 1, false, zoom, true, false, files, nuDifPath, colors, lineWidths, lineStyles, legendEntries, nuDifTitles, statPositions, 1111, legendDif, "nu");
        DrawOverlay(nuBarCanvas, 2, false, zoom, true, false, files, nubarDivPath, colors, lineWidths, lineStyles, legendEntries, nuBarDivTitles, statPositions, 1111, legendDiv, "nuBar");
        DrawOverlay(nuCanvas, 2, false, zoom, true, false, files, nuDivPath, colors, lineWidths, lineStyles, legendEntries, nuDivTitles, statPositions, 1111, legendDiv, "nu");

        //fixes centering bug
        DrawOverlay(nuBarCanvas, 1, false, zoom, true, false, files, nubarDifPath, colors, lineWidths, lineStyles, legendEntries, nuBarDifTitles, statPositions, 1111, legendDif, "nuBar");
        DrawOverlay(nuCanvas, 1, false, zoom, true, false, files, nuDifPath, colors, lineWidths, lineStyles, legendEntries, nuDifTitles, statPositions, 1111, legendDif, "nu");
        DrawOverlay(nuBarCanvas, 2, false, zoom, true, false, files, nubarDivPath, colors, lineWidths, lineStyles, legendEntries, nuBarDivTitles, statPositions, 1111, legendDiv, "nuBar");
        DrawOverlay(nuCanvas, 2, false, zoom, true, false, files, nuDivPath, colors, lineWidths, lineStyles, legendEntries, nuDivTitles, statPositions, 1111, legendDiv, "nu");

}
