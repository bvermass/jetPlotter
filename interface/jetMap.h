/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Header for class jetMap that describes the jet or event that you wish to plot. Also provides the plot functionality //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef jetmap_h
#define jetmap_h

#include <TROOT.h>
#include <iostream>
#include <memory>

#include "../interface/constituent.h"

class jetMap
{
    public:
        int nConstituents;
        std::unique_ptr<constituent[]> Constituents;
        //int nJets;
        //std::unique_ptr<constituent[]> Jets;
        double Eta_min;
        double Eta_max;
        double Phi_min;
        double Phi_max;

        jetMap(int constituent_size)
            : nConstituents{constituent_size}, Constituents{new constituent[nConstituents]}
        {
            for(int i = 0; i < nConstituents; i++){
                Constituents[i] = constituent(1., 0., 0., 0, 0., 0., 1);
            }
        }
};

#endif
