#!/bin/bash
export LD_LIBRARY_PATH=:.
rm -f ./pong
g++ main.cpp engine.cpp -L. -lvipgfx -o pong
./pong
