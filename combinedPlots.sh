#!/bin/bash

./cmake-build-release/Bsc_ITP_MX.exe 6 0 2 5000 -1 silent
./cmake-build-release/Bsc_ITP_MX.exe 8 0 2 5000 -1 silent
./cmake-build-release/Bsc_ITP_MX.exe 10 0 2 5000 -1 silent
./cmake-build-release/Bsc_ITP_MX.exe 12 0 2 500 -1 silent
#./cmake-build-release/Bsc_ITP_MX.exe 14 0 2 50 -1 silent

python plotDeltaE.py
python plotSpecificHeatJConst.py
python plotSpecificHeatTConst.py
python plotSusceptibilityJConst.py