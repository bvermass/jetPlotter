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
        double Mass;
        int PdgId; // 99 means a jet
        int Charge;
        double DxySig; // Change these to dxy, dz, dxyerr and dzerr when available
        double DzSig;
        int NHits;
        int NPixelHits;
        bool HasTrack;

        constituent(double pt = 0., double eta = 0., double phi = 0., double mass = 0., int pdgId = 0, int charge = 0, double dxySig = 0., double dzSig = 0., int nhits = 0, int npixelhits = 0, bool hastrack = false)
        {
            Pt         = pt;
            Eta        = eta;
            Phi        = phi;
            Mass       = mass;
            PdgId      = pdgId;
            Charge     = charge;
            DxySig     = dxySig;
            DzSig      = dzSig;
            NHits      = nhits;
            NPixelHits = npixelhits;
            HasTrack   = hastrack;
        }
};

#endif
