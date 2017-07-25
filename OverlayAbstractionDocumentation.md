## 2016-07-20 Overlay Graph Macro

**(ON)** I went ahead and made a function to make overlay graphs since we ended up needing to make a bunch of them, this document details how to use the function.

If you wanted to test it out, here are a set of commands for getting started.

``bash scp

<username>@cmslpc40.fnal.gov:/uscms_data/d1/oneogi/JaneHistograms/instantaneous_luminosity/DQM_V0001_R000273158<strong>Global</strong>CMSSW_X_Y_Z<strong>RECO.root ./
scp <username>@cmslpc40.fnal.gov:/uscms_data/d1/oneogi/JaneHistograms/instantaneous_luminosity/DQM_V0001_R000273725</username></strong>Global<strong>CMSSW_X_Y_Z</strong>RECO.root ./
scp <username>@cmslpc40.fnal.gov:/uscms_data/d1/oneogi/JaneHistograms/instantaneous_luminosity/DQM_V0001_R000274172<strong>Global</strong>CMSSW_X_Y_Z__RECO.root ./</username></username>

scp

<username>@cmslpc40.fnal.gov:/uscms_data/d1/oneogi/GraphOverlayMacros/abstractionDemo.C ./
scp <username>@cmslpc40.fnal.gov:/uscms_data/d1/oneogi/GraphOverlayMacros/Overlay_Abstraction.C ./</username></username>

root -l Overlay_Abstraction.C

```
Replace <username> with your own username

As to how the function works, the full function uses the following parameters in this order:

**Canvas** - *\*Canvas* - Pointer to the canvas object on which the graph is to be drawn

**pad** - *Int_t* - Pad in which the graph is to be drawn

**isZoomed** - *bool* - A boolean that states whether any zooming is to occur

**zoomRange** - *Double_t[2]* - A 2 number array that sets the range in which zooming is to occur. Has no effect if previous boolean is false or if range outside full range of graphs

**isNormalized** - *bool* - A boolean that states whether the graph is to be normalized

**isLogScale** - *bool* - A boolean that states whether the graph is in linear or log scale

**files** - *vector<TFile \*\>* - A vector containing the list of files that the graphs are to be drawn from. Each file corresponds to the path in the same index.

**paths** - *vector<TString\>* - A vector containing the list of paths that the graphs are to be drawn from. Each path should start from the root of the folder sturcture in the relevant file and go down to the variable.

**colors** - *vector<Color_t\>* - A vector containing the list of the colors that the graphs are to be drawn in

**lineWidths** - *vector<Width_t\>* - A vector containing the widths of each graph

**lineStyles** - *vector<Style_t\>* - A vector containing the line style of each graph

**legendEntries** - *vector<TString\>* - A vector containing the legend entries for each graph

**titles** - *TString[3]* - A 3 String array that contains the titles. The first is the main title, the second the x-axis title and the third the y-axis title

**statPositions** - *vector<vector <Double_t\>\>* - A vector containing a list of vectors with 4 elements which spcify the coordinates of each statistics box in the order <fX1NDC, fY1NDC, fX2NDC, fY2NDC>

**statStyles** - *Style_t* - A code that describes what the statistics boxes contain

**legendPosition** - *Double_t[4]* - A 4 element array that has the coordinates of the legend in the order <fX1NDC, fY1NDC, fX2NDC, fY2NDC>

**filename** - *TString* - The filename that the canvas is to be saved in

Code skeleton for the bare basics to run the function

``C++
#include "Overlay_Abstraction.C"
//importing the files
vector<TFile *> files {<filename1>, <filename2>, .....<filenameN>};

//writing file paths
vector<TString> paths {<path1>, <path2>, .....<pathN>};

//style choices
vector<Color_t> colors {<color1>, <color2>, ..... <colorN>};
vector<Width_t> lineWidths {<width1>, <width2>, ..... <widthN>};
vector<Style_t> lineStyles {<style1>, <style2>, ..... <styleN>};

//legend
vector<TString> legendEntries {<entry1>, <entry2>, ..... <entryN>};
Double_t legendPosition[4] = {fX1NDC, fY1NDC, fX2NDC, fY2NDC};

vector<vector <Double_t>> statPositions {{fX1NDC, fY1NDC, fX2NDC, fY2NDC}, {fX1NDC, fY1NDC, fX2NDC, fY2NDC},.....{fX1NDC, fY1NDC, fX2NDC, fY2NDC}};

TCanvas * Canvas = new TCanvas(<Canvas Name>,"",<height>,<Width>);

TString titles[] = {<title>, <x-title>, <y-title>};

DrawOverlay(Canvas, 1, <zoom>, <zoomrange>, <normalize>, <log scale>, files, paths, colors, lineWidths, lineStyles, legendEntries, titles, statPositions, <StatisticsStyle>, legendPosition, <fileName>);
```
