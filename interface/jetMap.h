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
#include <TText.h>
#include <TH1F.h>
#include <TH2F.h>

#include "../interface/constituent.h"

class jetMap
{
    public:
        unsigned nConstituents;
        std::unique_ptr<constituent[]> Constituents;
        //unsigned nJets;
        //std::unique_ptr<constituent[]> Jets;
        bool   FixedFrameSize;
        double Eta_min;
        double Eta_max;
        double Phi_min;
        double Phi_max;

        jetMap(unsigned constituent_size, double *Pt, double *Eta, double *Phi, double *Mass, int *PdgId, int *Charge, double *dxySig, double *dzSig, int *NHits, int *NPixelHits, bool *HasTrack, bool fixedframesize)
            : nConstituents{constituent_size}, Constituents{new constituent[nConstituents]}, FixedFrameSize{fixedframesize}
        {
            double Eta_mean = 0;
            double Phi_mean = 0;
            double Eta_minparticle = 5;
            double Phi_minparticle = 5;
            double Eta_maxparticle = -5;
            double Phi_maxparticle = -5;
            for(unsigned i = 0; i < nConstituents; i++){
                Constituents[i] = constituent(*(Pt + i), *(Eta + i), *(Phi + i), *(Mass + i), *(PdgId + i), *(Charge + i), *(dxySig + i), *(dzSig + i), *(NHits + i), *(NPixelHits + i), *(HasTrack + i));
                Eta_mean += *(Eta + i);
                Phi_mean += *(Phi + i);
                Eta_minparticle = std::min(Eta_minparticle, *(Eta + i));
                Phi_minparticle = std::min(Phi_minparticle, *(Phi + i));
                Eta_maxparticle = std::max(Eta_maxparticle, *(Eta + i));
                Phi_maxparticle = std::max(Phi_maxparticle, *(Phi + i));
            }
            Eta_mean /= nConstituents;
            Phi_mean /= nConstituents;
            if(fixedframesize){
                Eta_min = Eta_mean - 0.5;
                Phi_min = Phi_mean - 0.5;
                Eta_max = Eta_mean + 0.5;
                Phi_max = Phi_mean + 0.5;
            }else {
                Eta_min = Eta_minparticle - 0.1;
                Phi_min = Phi_minparticle - 0.1;
                Eta_max = Eta_maxparticle - 0.1;
                Phi_max = Phi_maxparticle - 0.1;
            }
        }

        void Draw(TCanvas *c, TString plotdirname, int counter, int nplots);
        TString make_dir_filename(TString plotdirname, int counter);
        int get_markerstyle(int pdgid);
        int get_markercolor(int pdgid);
        double get_markersize(double pt);
        TMarker make_marker(double x, double y, int pdgid, int markersize);
};

#endif
