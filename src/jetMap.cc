////////////////////////////////// 
// Source code for class jetMap //
//////////////////////////////////
#include <TSystem.h>
#include <TAxis.h>
#include <TMarker.h>

#include "../interface/jetMap.h"

void jetMap::Draw(TCanvas *c, TString plotdirname, int counter)
{
    TString outputfilename = make_plot_filename(plotdirname, counter);
    
    std::vector<TMarker> markers;
    for(unsigned i = 0; i < nConstituents; i++){
        markers.push_back(TMarker(Eta_min + 0.2, Phi_min + 0.2, 22));
        markers.push_back(TMarker(Constituents[i].Eta, Constituents[i].Phi, 22));
        //markers[i].SetMarkerStyle(22);
        //markers[i].SetMarkerColor(kBlue);
        //markers[i].SetMarkerSize(3);
    }

    c->DrawFrame(Eta_min, Phi_min, Eta_max, Phi_max, "Jet Image");
    for(int i = 0; i < markers.size(); i++){
        markers[i].Draw();
    }
    //TMarker testmarker(Eta_min + 0.2, Phi_min + 0.2, 22);
    //testmarker.Draw();
    c->Modified();

    c->Print(outputfilename);
    // plot points
    // plot different symbols and colors
    // size depending on pt?
    // plot legend
    // 
}

// Might move this function to a drawing class maybe?
TString jetMap::make_plot_filename(TString plotdirname, int counter)
{
    TString outputfilename = "/user/bvermass/public/jetPlotter/plots/" + plotdirname; +
    gSystem->Exec("mkdir -p " + outputfilename);
    outputfilename += "/jetImage_" + std::to_string(counter) + ".pdf";
    return outputfilename;
}
