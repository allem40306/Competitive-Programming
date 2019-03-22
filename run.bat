@echo off
 
 
cls
echo COMPILING...
g++ -std=c++11 -Wall %1 -DDBG
 
echo FINISH COMPILE %1
if %ERRORLEVEL% EQU 0 (
    a.exe
)