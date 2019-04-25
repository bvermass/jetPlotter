////////////////////////////////// 
// Source code for class jetMap //
//////////////////////////////////
#include "../interface/jetMap.h"

void jetMap::Draw(TCanvas *c, TString plotdirname, int counter, int nplots)
{
    TString outputdirname = make_dir_filename(plotdirname, counter);
    
    std::vector<TMarker> markers;
    for(unsigned i = 0; i < nConstituents; i++){
        markers.push_back(TMarker(Constituents[i].Eta, Constituents[i].Phi, 22));
        markers[i].SetMarkerStyle(get_markerstyle(Constituents[i].PdgId));
        markers[i].SetMarkerColor(get_markercolor(Constituents[i].PdgId));
        markers[i].SetMarkerSize(get_markersize(Constituents[i].Pt));
    }

    TString plottitle = "Jet Image " + std::to_string(counter);
    TH1F* frame = c->DrawFrame(Eta_min, Phi_min, Eta_max, Phi_max, plottitle);
    frame->GetXaxis()->SetTitle("eta");
    frame->GetYaxis()->SetTitle("phi");
    for(int i = 0; i < markers.size(); i++){
        markers[i].Draw();
    }
    TMarker muonmarker      = make_marker(Eta_min + 0.02, Phi_max + 0.015, 13, 1.3);
    TMarker electronmarker  = make_marker(Eta_min + 0.18, Phi_max + 0.015, 11, 1.3);
    TMarker photonmarker    = make_marker(Eta_min + 0.37, Phi_max + 0.015, 22, 1.3);
    TMarker chadronmarker   = make_marker(Eta_min + 0.55, Phi_max + 0.015, 211, 1.3);
    TMarker nhadronmarker   = make_marker(Eta_min + 0.77, Phi_max + 0.015, 130, 1.3);
    muonmarker.Draw();
    electronmarker.Draw();
    photonmarker.Draw();
    chadronmarker.Draw();
    nhadronmarker.Draw();
    TText* legend = new TText(Eta_min + 0.04, Phi_max + 0.005, "muon      electron      photon      ch.hadron      n.hadron");
    legend->SetTextSize(0.035);
    zever->Draw("same");
    c->Modified();

    TString outputfilename     = outputdirname + "/jetImage_" + std::to_string(counter) + ".pdf";
    c->Print(outputfilename);
    TString all_outputfilename = outputdirname + "/jetImages.pdf";
    if(counter == 0) all_outputfilename += "(";
    else if(counter == nplots - 1) all_outputfilename += ")";
    c->Print(all_outputfilename);
}

// Might move these functions to a drawing class maybe?
TString jetMap::make_dir_filename(TString plotdirname, int counter)
{
    TString outputfilename = "/user/bvermass/public/jetPlotter/plots/" + plotdirname; +
    gSystem->Exec("mkdir -p " + outputfilename);
    return outputfilename;
}

int jetMap::get_markerstyle(int pdgid)
{
    pdgid = fabs(pdgid);
    if(pdgid == 11 || pdgid == 13 || pdgid == 211) return 20;
    else if(pdgid == 22 || pdgid == 130) return 24;
    else return 22;
}

int jetMap::get_markercolor(int pdgid)
{
    pdgid = fabs(pdgid);
    if(pdgid == 11 || pdgid == 22) return kRed;
    if(pdgid == 13) return kBlue;
    if(pdgid == 211 || pdgid == 130) return kBlack;
    return kGreen;
}

double jetMap::get_markersize(double pt)
{
    return (std::max(0., std::min(50., pt))*9./50. + 1);
}

TMarker jetMap::make_marker(double x, double y, int pdgid, int markersize)
{
    TMarker marker(x, y, get_markerstyle(pdgid));
    marker.SetMarkerColor(get_markercolor(pdgid));
    marker.SetMarkerSize(markersize);
    return marker;
}
