#include <iostream>

#include "../interface/jetMap.h"

#ifndef __CINT__
int main(int argc, char * argv[])
{
    std::cout << "Trying to initialize jetMap" << std::endl;
    jetMap jetmap1(1);
    std::cout << "jetmap initialized: " << jetmap1.nConstituents << std::endl;
    return 0;
}
#endif
