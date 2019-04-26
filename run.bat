@echo off
 
 
cls
echo COMPILING...
g++ -std=c++11 -Wall %1 -DDBG
 
if %ERRORLEVEL% EQU 0 (
    echo FINISH COMPILE %1
    a.exe
)