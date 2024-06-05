#!/bin/bash


./cmake-build-release/trading_main 1 MAKER \ 
	100 0.6 150 300 -100 \
	60 0.6 150 300 -100 \ 
	150 0.5 250 600 -100 \ 
	200 0.4 500 3000 -100 \
	1000 0.9 5000 3000 -100 \ 
	50 0.7 150 300 -100 \
	100 0.3 250 300 -100 &

sleep 5

./cmake-build-release/trading_main 5 RANDOM & 
sleep 5

wait
