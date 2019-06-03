//Include c++ libraries
#include <iostream>

//Include root header files
#include <TString.h>
#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <TCanvas.h>
#include <TStyle.h>

#include "../interface/jetMap.h"

#ifndef __CINT__
int main(int argc, char * argv[])
{
    TString filename    = argv[1];
    TString plotdirname = argv[2];
    int nplots          = atoi(argv[3]);
    
    TFile *input = new TFile(filename, "open");
    TTreeReader reader("HNLtagger_tree");

    TTreeReaderValue<bool>     rvJetIsFromHNL(reader, "_JetIsFromHNL");
    TTreeReaderValue<unsigned> rvNJetConstituents(reader, "_nJetConstituents");

    TTreeReaderArray<double> raJetConstituentPt(reader, "_JetConstituentPt");
    TTreeReaderArray<double> raJetConstituentEta(reader, "_JetConstituentEta");
    TTreeReaderArray<double> raJetConstituentPhi(reader, "_JetConstituentPhi");
    TTreeReaderArray<int>    raJetConstituentPdgId(reader, "_JetConstituentPdgId");
    TTreeReaderArray<int>    raJetConstituentCharge(reader, "_JetConstituentCharge");
    TTreeReaderArray<double> raJetConstituentdxy(reader, "_JetConstituentdxy");
    TTreeReaderArray<double> raJetConstituentdz(reader, "_JetConstituentdz");
    TTreeReaderArray<double> raJetConstituentdxyErr(reader, "_JetConstituentdxyErr");
    TTreeReaderArray<double> raJetConstituentdzErr(reader, "_JetConstituentdzErr");
    TTreeReaderArray<int>    raJetConstituentNumberOfHits(reader, "_JetConstituentNumberOfHits");
    TTreeReaderArray<int>    raJetConstituentNumberOfPixelHits(reader, "_JetConstituentNumberOfPixelHits");
    TTreeReaderArray<bool>   raJetConstituentHasTrack(reader, "_JetConstituentHasTrack");

    // Put this in some drawing class at a necessary point
    TCanvas *c = new TCanvas("c", "", 900, 800);
    gStyle->SetOptStat(0);
    gPad->SetTicks(1,1);

    int counter = 0;
    while (reader.Next() && counter < nplots) {
        bool JetIsFromHNL = *rvJetIsFromHNL;
        unsigned nJetConstituents = *rvNJetConstituents;

        jetMap jetmap1(nJetConstituents, &raJetConstituentPt[0], &raJetConstituentEta[0], &raJetConstituentPhi[0], &raJetConstituentPdgId[0], &raJetConstituentCharge[0], &raJetConstituentdxy[0], &raJetConstituentdz[0], &raJetConstituentdxyErr[0], &raJetConstituentdzErr[0], &raJetConstituentNumberOfHits[0], &raJetConstituentNumberOfPixelHits[0], &raJetConstituentHasTrack[0], true);
        if(jetmap1.Check_for_phi_discontinuity()) jetmap1.Rotate_constituents_over_phi();
        jetmap1.Draw(c, plotdirname, counter, nplots);
        counter++;
    }

    return 0;
}
#endif
