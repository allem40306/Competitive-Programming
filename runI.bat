@echo off
 
 
cls
echo COMPILING...
g++  -O2 -std=c++11 -Wall %1 -DDBG
 
if %ERRORLEVEL% EQU 0 (
    echo FINISH COMPILE %1
    a.exe < test.in
)