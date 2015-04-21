#!/usr/bin/env bash

./clean.sh
mkdir build bin
cd build
cmake ../
make
cp socsim ../bin/