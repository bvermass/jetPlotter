#!/bin/bash

headdir=$(pwd)

if g++ -std=c++0x -o a_jetplotter.out ${headdir}"/test/main.cc" `root-config --cflags --glibs` ; then
    echo -e "\n//////////////////////////"
    echo -e "//COMPILATION SUCCESSFUL//"
    echo -e "//////////////////////////\n"

    ./a_jetplotter.out

    rm a_jetplotter.out
else
    echo -e "\n//////////////////////"
    echo -e "//COMPILATION FAILED//"
    echo -e "//////////////////////\n"
fi
