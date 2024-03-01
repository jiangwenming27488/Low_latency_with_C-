#!/bin/bash


CMAKE=$(/usr/matthew/Doc*)
NINJA=$(matthew/Documents/ninja_)

mkdir -p ./cmake-build-release
$CMAKE -DCMAKE_BUILD_TYPE=Release -DMAKE_MAKE_PROGRAM=$NINJA -G Ninja -S . -B ./cmake-build-release

$CMAKE --build ./cmake-build-release --target all -j 4

mkdir -p ./cmake-build-debug
$CMAKE -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PRAGRAM=$NINJA -G Ninja -S . -B ./cmake-build-debug

$CMAKE --build ./cmake-build-debug --target all -j 4
