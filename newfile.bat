REM @echo off 
setlocal enabledelayedexpansion 
set problem[0]=A
set problem[1]=B
set problem[2]=C
set problem[3]=D
set problem[4]=E
set problem[5]=F

for /l %%n in (0,1,%2) do ( 
   type NUL > %1!problem[%%n]!.cpp 
)