#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <BuildType>"
    exit 1
fi

BUILD_TYPE=$1

rm -rf build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ..
cmake --build --config $BUILD_TYPE .
