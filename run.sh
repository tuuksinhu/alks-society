#!/bin/bash

if [ ! -d "build" ] || [ ! -f "build/CMakeCache.txt" ]; then
    cmake -B build
fi

cmake --build build && ./build/game
