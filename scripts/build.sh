#!/usr/bin/env bash

./scripts/clean.sh
mkdir build bin
cd build
cmake ../
make
cp socsim ../bin/