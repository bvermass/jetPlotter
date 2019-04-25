/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Header for class jetMap that describes the jet or event that you wish to plot. Also provides the plot functionality //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef jetmap_h
#define jetmap_h

#include <iostream>
#include <memory>

#include <TROOT.h>
#include <TSystem.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TMarker.h>

#include "../interface/constituent.h"

class jetMap
{
    public:
        unsigned nConstituents;
        std::unique_ptr<constituent[]> Constituents;
        //unsigned nJets;
        //std::unique_ptr<constituent[]> Jets;
        double Eta_min;
        double Eta_max;
        double Phi_min;
        double Phi_max;

        jetMap(unsigned constituent_size, double *Pt, double *Eta, double *Phi, double *Mass, int *PdgId, int *Charge, double *dxySig, double *dzSig, int *NHits, int *NPixelHits, bool *HasTrack)
            : nConstituents{constituent_size}, Constituents{new constituent[nConstituents]}
        {
            double Eta_mean = 0;
            double Phi_mean = 0;
            for(unsigned i = 0; i < nConstituents; i++){
                Constituents[i] = constituent(*(Pt + i), *(Eta + i), *(Phi + i), *(Mass + i), *(PdgId + i), *(Charge + i), *(dxySig + i), *(dzSig + i), *(NHits + i), *(NPixelHits + i), *(HasTrack + i));
                Eta_mean += *(Eta + i);
                Phi_mean += *(Phi + i);
            }
            Eta_mean /= nConstituents;
            Phi_mean /= nConstituents;
            Eta_min = Eta_mean - 0.5;
            Phi_min = Phi_mean - 0.5;
            Eta_max = Eta_mean + 0.5;
            Phi_max = Phi_mean + 0.5;
        }

        void Draw(TCanvas *c, TString plotdirname, int counter, int nplots);
        TString make_dir_filename(TString plotdirname, int counter);
        int get_markerstyle(int pdgid);
        int get_markercolor(int pdgid);
        double get_markersize(double pt);
};

#endif
