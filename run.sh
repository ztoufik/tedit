#!/bin/env bash
executable="build/tedit"
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug 
cmake --build  build 
./build/src/tedit
#(cd ./build/test/ && ctest -V)
