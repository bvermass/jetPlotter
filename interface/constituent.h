//////////////////////////////////////////////////////////////////////////////////////////
// Header for class constituent which represents a single PF particle in a jet or event //
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef constituent_h
#define constituent_h

#include <TROOT.h>
#include <iostream>

class constituent
{
    public:
        double Pt;
        double Eta;
        double Phi;
        int PdgId; // 99 means a jet
        int Charge;
        double Dxy;
        double Dz;
        double DxyErr;
        double DzErr;
        int NHits;
        int NPixelHits;
        bool HasTrack;

        constituent(double pt = 0., double eta = 0., double phi = 0., int pdgId = 0, int charge = 0, double dxy = 0., double dz = 0., double dxyErr = 0., double dzErr = 0., int nhits = 0, int npixelhits = 0, bool hastrack = false)
        {
            Pt         = pt;
            Eta        = eta;
            Phi        = phi;
            PdgId      = pdgId;
            Charge     = charge;
            Dxy        = dxy;
            Dz         = dz;
            DxyErr     = dxyErr;
            DzErr      = dzErr;
            NHits      = nhits;
            NPixelHits = npixelhits;
            HasTrack   = hastrack;
        }
};

#endif
