/**
 * Draws an overlay graph based on the parameters given
 * @param Canvas         *Canvas                      Pointer to the canvas object on which the graph is to be drawn
 * @param pad            Int_t                        Pad in which the graph is to be drawn
 * @param isZoomed       bool                         A boolean that states whether any zooming is to occur
 * @param zoomRange      Double_t[2]                  A 2 number array that sets the range in which zooming is to occur. Has no effect if previous boolean is false or if range outside full range of graphs
 * @param isNormalized   bool                         A boolean that states whether the graph is to be normalized
 * @param isLogScale     bool                         A boolean that states whether the graph is in linear or log scale
 * @param files          vector<TFile *>              A vector containing the list of files that the graphs are to be drawn from. Each file corresponds to the path in the same index.
 * @param paths          vector<TString>              A vector containing the list of paths that the graphs are to be drawn from. Each path should start from the root o the folder sturcture in the relevant file and go down to the variable.
 * @param colors         vector<Color_t>              A vector containing the list of the colors that the graphs are to be drawn in
 * @param lineWidths     vector<Width_t>              A vector containing the widths of each graph
 * @param lineStyles     vector<Style_t>              A vector containing the line style of each graph
 * @param legendEntries  vector<TString>              A vector containing the legend entries for each graph
 * @param titles         TString[3]                   A 3 String array that contains the titles. The first is the main title, the second the x-axis title and the third the y-axis title
 * @param statPositions  vector<vector <Double_t>>    A vector containing a list of vectors with 4 elements which spcify the coordinates of each statistics box in the order <fX1NDC, fY1NDC, fX2NDC, fY2NDC>
 * @param statStyles     Style_t                      A code that describes what the statistics boxes contain
 * @param legendPosition Double_t[4]                  A 4 element array that has the coordinates of the legend in the order <fX1NDC, fY1NDC, fX2NDC, fY2NDC>
 * @param filename       TString                      The filename that the canvas is to be saved in
 */

//everything
void DrawOverlay(TCanvas *Canvas, Int_t pad, bool isZoomed,  Double_t zoomRange[2], bool isNormalized, bool isLogScale, vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4], TString filename){
  //initialize values
  vector<TH1F *> graphs;
  Double_t yMax;
  TLegend * legend = new TLegend(legendPosition[0], legendPosition[1], legendPosition[2], legendPosition[3]);
  vector<TPaveStats *> stats;

  //Canvas
  Canvas->cd(pad);

  for (size_t i = 0; i < paths.size(); i++) {
    //get histograms
    graphs.push_back((TH1F*) files[i]->Get(paths[i]));

    //Draw parameters
    graphs[i]->SetLineColor(colors[i]);
    graphs[i]->SetLineWidth(lineWidths[i]);
    graphs[i]->SetLineStyle(lineStyles[i]);

    //normalize
    if (isNormalized) {
      graphs[i]->Scale(1.0/graphs[i]->Integral());
    }

    //axis scaling
    if (i==0) {
      yMax = graphs[i]->GetMaximum();
    }
    else if (yMax<graphs[i]->GetMaximum()) {
      yMax = graphs[i]->GetMaximum();
    }

    //legend
    legend->AddEntry(graphs[i],legendEntries[i],"l");

    //Draw
    if (i==0) {
      graphs[i]->Draw("HIST");
    }
    else{
      graphs[i]->Draw("SAMES");
    }

    //fit
    // graphs[i]->Fit("gaus", "I+", "SAME");

    gPad->Modified();
    gPad->Update();

    //stats
    stats.push_back((TPaveStats*) (graphs[i]->FindObject("stats")));
    stats[i]->SetTextColor(colors[i]);
    stats[i]->SetX1NDC(statPositions[i][0]);
    stats[i]->SetY1NDC(statPositions[i][1]);
    stats[i]->SetX2NDC(statPositions[i][2]);
    stats[i]->SetY2NDC(statPositions[i][3]);

  }

  //Overall Graph
  graphs[0]->SetTitle(titles[0]);
  graphs[0]->GetYaxis()->SetTitleSize(0.04);
  graphs[0]->GetYaxis()->SetTitleOffset(1.2);
  graphs[0]->GetYaxis()->SetLabelSize(0.04);
  graphs[0]->GetXaxis()->SetTitleSize(0.04);
  graphs[0]->GetXaxis()->SetLabelSize(0.04);
  graphs[0]->GetXaxis()->SetTitleOffset(1);
  graphs[0]->GetXaxis()->SetTitle(titles[1]);
  graphs[0]->GetYaxis()->SetTitle(titles[2]);
  graphs[0]->SetMaximum(yMax+yMax/10);

  //zoom handling

  if (isZoomed){
      graphs[0]->GetXaxis()->SetRangeUser(zoomRange[0], zoomRange[1]);
  }
  //legend
  legend->SetFillColor(kWhite);
  legend->SetBorderSize(0);
  legend->SetTextSize(0.043);
  legend->Draw();

  // graphs[0]->GetXaxis()->SetRangeUser(0,100);

  gStyle->SetOptStat(statStyles);
  // gStyle->SetOptFit();

  if (isLogScale) {
    gPad->SetLogy();
  }

  //save image
  char saveName[256];
  strcpy(saveName, "./");
  strcat(saveName,filename);
  strcat(saveName, ".png");
  Canvas->SaveAs(saveName);
}

//no filename
void DrawOverlay(TCanvas *Canvas, Int_t pad, bool isZoomed, Double_t zoomRange[2], bool isNormalized, bool isLogScale, vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4]){
  DrawOverlay(Canvas, pad, isZoomed, zoomRange, isNormalized, isLogScale, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, statStyles, legendPosition, Canvas->GetName());
}

//no zoom no filename
void DrawOverlay(TCanvas *Canvas, Int_t pad, bool isNormalized, bool isLogScale, vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4]){
  Double_t zoom[] ={0,100};

  DrawOverlay(Canvas, pad, false, zoom, isNormalized, isLogScale, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, statStyles, legendPosition, Canvas->GetName());
}

//no zoom
void DrawOverlay(TCanvas *Canvas, Int_t pad, bool isNormalized, bool isLogScale, vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4], TString filename){
  Double_t zoom[] ={0,100};

  DrawOverlay(Canvas, pad, false, zoom, isNormalized, isLogScale, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, statStyles, legendPosition, filename);
}


//no canvas, pad and filename
void DrawOverlay(bool isZoomed, Double_t zoomRange[2], bool isNormalized, bool isLogScale, vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4]){
  TCanvas * Canvas = new TCanvas("Canvas","",800,800);

  DrawOverlay(Canvas, 1, isZoomed, zoomRange, isNormalized, isLogScale, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, statStyles, legendPosition, Canvas->GetName());
}

//no canvas, pad
void DrawOverlay(bool isZoomed,  Double_t zoomRange[2], bool isNormalized, bool isLogScale, vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4], TString filename){
  TCanvas * Canvas = new TCanvas("Canvas","",800,800);

  DrawOverlay(Canvas, 1, isZoomed, zoomRange, isNormalized, isLogScale, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, statStyles, legendPosition, filename);
}



//no canvas, pad and zoom
void DrawOverlay(bool isNormalized, bool isLogScale, vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4], TString filename){
  TCanvas * Canvas = new TCanvas("Canvas","",800,800);
  Double_t zoom[] ={0,100};

  DrawOverlay(Canvas, 1, false, zoom, isNormalized, isLogScale, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, statStyles, legendPosition, filename);
}

//no canvas, pad, zoom and filename
void DrawOverlay(bool isNormalized, bool isLogScale, vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4]){
  TCanvas * Canvas = new TCanvas("Canvas","",800,800);
  Double_t zoom[] ={0,100};

  DrawOverlay(Canvas, 1, false, zoom, isNormalized, isLogScale, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, statStyles, legendPosition, Canvas->GetName());
}



//no canvas, pad, zoom, normalize, logscale,
void DrawOverlay(vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4], TString filename){
  TCanvas * Canvas = new TCanvas("Canvas","",800,800);
  Double_t zoom[] ={0,100};

  DrawOverlay(Canvas, 1, false, zoom, true, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, statStyles, legendPosition, filename);
}

//no canvas, pad, zoom, normalize, logscale, filename
void DrawOverlay(vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Style_t statStyles, Double_t legendPosition[4]){
  TCanvas * Canvas = new TCanvas("Canvas","",800,800);
  Double_t zoom[] ={0,100};

  DrawOverlay(Canvas, 1, false, zoom, true, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, statStyles, legendPosition, Canvas->GetName());
}



//no canvas, pad, zoom, normalize, logscale, statstyle
void DrawOverlay(vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Double_t legendPosition[4], TString filename){
  TCanvas * Canvas = new TCanvas("Canvas","",800,800);
  Double_t zoom[] ={0,100};

  DrawOverlay(Canvas, 1, false, zoom, true, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legendPosition, filename);
}

//no canvas, pad, zoom, normalize, logscale, statstyle and filename
void DrawOverlay(vector<TFile *> files, vector<TString> paths, vector<Color_t> colors, vector<Width_t> lineWidths, vector<Style_t> lineStyles, vector<TString> legendEntries, TString titles[3], vector<vector <Double_t>> statPositions, Double_t legendPosition[4]){
  TCanvas * Canvas = new TCanvas("Canvas","",800,800);
  Double_t zoom[] ={0,100};

  DrawOverlay(Canvas, 1, false, zoom, true, false, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, 1111, legendPosition, Canvas->GetName());
}
