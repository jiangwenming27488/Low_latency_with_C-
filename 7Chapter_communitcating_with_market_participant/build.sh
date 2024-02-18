#!/bin/bash

#TODO - point these to the corecct binary locations on you systme 

CMAKE=$(/usr/local/bin/cmake)
NINJA=$(matthew/Documents/ninja_)

mkdir -p cmake-build-release
$CMAKE -DMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=$NINJA -G Ninja -S . =B cmake-build-release 

$CMAKE --build cmake-build-release --target clean -j 4
$CMAKE --build cmake-build-release --target all -j 4
