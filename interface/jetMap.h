/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Header for class jetMap that describes the jet or event that you wish to plot. Also provides the plot functionality //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef jetmap_h
#define jetmap_h

#include <iostream>
#include <memory>

#include <TROOT.h>
#include <TCanvas.h>
#include <TH2F.h>
#include <TPad.h>

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
            Eta_min = 5;
            Phi_min = 5;
            for(unsigned i = 0; i < nConstituents; i++){
                Constituents[i] = constituent(*(Pt + i), *(Eta + i), *(Phi + i), *(Mass + i), *(PdgId + i), *(Charge + i), *(dxySig + i), *(dzSig + i), *(NHits + i), *(NPixelHits + i), *(HasTrack + i));
                Eta_min = std::min(Eta_min, *(Eta + i));
                Phi_min = std::min(Phi_min, *(Phi + i));
            }
            Eta_min -= 0.1;
            Phi_min -= 0.1;
            Eta_max = Eta_min + 0.6; // always have a 0.6x0.6 grid
            Phi_max = Phi_min + 0.6;
        }

        void Draw(TCanvas *c, TString plotdirname, int counter);
        TString make_plot_filename(TString plotdirname, int counter);
};

#endif
