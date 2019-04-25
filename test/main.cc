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
    TTreeReaderArray<double> raJetConstituentMass(reader, "_JetConstituentMass");
    TTreeReaderArray<int>    raJetConstituentPdgId(reader, "_JetConstituentPdgId");
    TTreeReaderArray<int>    raJetConstituentCharge(reader, "_JetConstituentCharge");
    TTreeReaderArray<double> raJetConstituentdxySig(reader, "_JetConstituentdxySig");
    TTreeReaderArray<double> raJetConstituentdzSig(reader, "_JetConstituentdzSig");
    TTreeReaderArray<int>    raJetConstituentNumberOfHits(reader, "_JetConstituentsNumberOfHits");
    TTreeReaderArray<int>    raJetConstituentNumberOfPixelHits(reader, "_JetConstituentsNumberOfPixelHits");
    TTreeReaderArray<bool> raJetConstituentHasTrack(reader, "_JetConstituentsHasTrack");

    // Put this in some drawing class at a necessary point
    TCanvas *c = new TCanvas("c", "", 900, 800);
    gStyle->SetOptStat(0);
    gPad->SetTicks(1,1);

    int counter = 0;
    while (reader.Next() && counter < nplots) {
        bool JetIsFromHNL = *rvJetIsFromHNL;
        unsigned nJetConstituents = *rvNJetConstituents;

        jetMap jetmap1(nJetConstituents, &raJetConstituentPt[0], &raJetConstituentEta[0], &raJetConstituentPhi[0], &raJetConstituentMass[0], &raJetConstituentPdgId[0], &raJetConstituentCharge[0], &raJetConstituentdxySig[0], &raJetConstituentdzSig[0], &raJetConstituentNumberOfHits[0], &raJetConstituentNumberOfPixelHits[0], &raJetConstituentHasTrack[0], true);
        jetmap1.Draw(c, plotdirname, counter, nplots);
        counter++;
    }

    return 0;
}
#endif
