#!/bin/bash

headdir=$(pwd)

if g++ -std=c++0x -o a_jetplotter.out ${headdir}"/test/main.cc" `root-config --cflags --glibs` ; then
    echo -e "\n//////////////////////////"
    echo -e "//COMPILATION SUCCESSFUL//"
    echo -e "//////////////////////////\n"

    while IFS='' read -r line || [[ -n "$line" ]]; do
        if [[ ! "$line" =~ [^[:space:]] ]] || [[ "${line:0:1}" = "#" ]]; then
            echo -e ""
        else
            counter=0
            for val in $line; do 
                if [ $counter -eq 0 ]; then
                    inputfile=$val
                    counter=1
                elif [ $counter -eq 1 ]; then
                    plotdirname=$val
                    counter=2
                elif [ $counter -eq 2 ]; then
                    nplots=$val
                    counter=3
                fi
            done
             
            echo "inputfile     :  "$inputfile
            echo "plotdirname   :  "$plotdirname
            echo "nplots        :  "$nplots

            ./a_jetplotter.out $inputfile $plotdirname $nplots
        fi
    done < "$1"
    rm a_jetplotter.out
else
    echo -e "\n//////////////////////"
    echo -e "//COMPILATION FAILED//"
    echo -e "//////////////////////\n"
fi
