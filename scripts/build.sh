#!/bin/bash

# build the Staples testing application only
cd tests
qmake -v
gcc --version
qmake -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug -o Makefile tests.pro
make
./tests
