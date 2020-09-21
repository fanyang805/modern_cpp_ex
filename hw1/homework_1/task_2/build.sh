#!/usr/bin/env bash
echo "create directory build"
mkdir build

echo "compile two objects needed for building the library"
c++ -c -I ./include -Idir/ ./src/sum.cpp -o ./build/sum.o
c++ -c -I ./include -Idir/ ./src/subtract.cpp -o ./build/subtract.o

echo "create the library"
ar rcs ./build/libipb_arthmetic.a ./build/sum.o ./build/subtract.o 

echo "link the program"
c++ -std=c++17 -I ./include -Idir/ ./src/main.cpp -L ./build/ -lipb_arthmetic -o ./results/main

echo "copy library to results"

cp ./build/libipb_arthmetic.a ./results/lib/