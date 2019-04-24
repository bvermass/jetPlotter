#include <iostream>
#include <TString.h>

#include "../interface/jetMap.h"

#ifndef __CINT__
int main(int argc, char * argv[])
{
    TString inputfile   = argv[1];
    TString plotdirname = argv[2];
    int nplots          = atoi(argv[3]);
    
    std::cout << "Trying to initialize jetMap" << std::endl;
    jetMap jetmap1(nplots);
    std::cout << "jetmap initialized: " << jetmap1.nConstituents << std::endl;
    return 0;
}
#endif
