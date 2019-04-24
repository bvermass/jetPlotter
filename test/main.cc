//Include c++ libraries
#include <iostream>

//Include root header files
#include <TString.h>
#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

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
    TTreeReaderArray<int>    raJetConstituentsNumberOfHits(reader, "_JetConstituentsNumberOfHits");
    TTreeReaderArray<int>    raJetConstituentsNumberOfPixelHits(reader, "_JetConstituentsNumberOfPixelHits");
    TTreeReaderArray<bool> raJetConstituentsHasTrack(reader, "_JetConstituentsHasTrack");

    int counter = 0;
    while (reader.Next() && counter < nplots) {
        bool JetIsFromHNL = *rvJetIsFromHNL;
        unsigned nJetConstituents = *rvNJetConstituents;

        jetMap jetmap1(nJetConstituents);
        std::cout << "jetmap initialized: " << jetmap1.nConstituents << std::endl;
        for(int i = 0; i < raJetConstituentPt.GetSize(); i++){
            if(raJetConstituentPt[i] == 0) continue;
            std::cout << raJetConstituentPt[i] << " ";
        }std::cout << std::endl;
        counter++;
    }

    return 0;
}
#endif
