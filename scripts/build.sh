#!/bin/bash

CMAKE=$(/usr/local/bin/cmake-3.28.1/)

NINJA=$(~/Documents/ninja_)

mkdir -p ./cmake-build-release
$CMAKE -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PRAGRAM=$NINJA -G Ninja -S . -B ./cmake-build-release

$CMAKE --build ./cmake-build-release --target clean -j 4
$CMAKE --build ./cmake-build-release --target all -j 4

mkdir -p ./build-debug --target clean -j 4
$CMAKE -DMAKE_BUILD_TYPE=Debug -DMAKE_NAME_PRAGRAM=$NINJA -G Ninja -S . -B ./cmake-build-debug

$CMAKE --build ./cmake-build-debug --target clean -j 4
$CMAKE --build ./cmake-build-debug --target all -j 4
