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
        int Charge;
        double DxySig; // Change these to dxy, dz, dxyerr and dzerr when available
        double DzSig;
        int PdgId; // 99 means a jet

        constituent(double pt = 0., double eta = 0., double phi = 0., int pdgId = 0, int charge = 0, double dxySig = 0., double dzSig = 0.)
        {
            Pt      = pt;
            Eta     = eta;
            Phi     = phi;
            PdgId   = pdgId;
            Charge  = charge;
            DxySig  = dxySig;
            DzSig   = dzSig;
        }
};

#endif
