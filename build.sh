#!/bin/bash

outputFile="City_Simulator"
compilerArgs="-O2 -I./headers"
linkerArgs="-lncurses -lpthread"

#uncomment the below line to search recursively through folders
#cppfiles=$(find "*.cpp" -print)
#re-add the $cppfiles var to the compiler line if uncommented




clang++ $compilerArgs *.cpp  -o ./$outputFile $linkerArgs

#./$outputFile
