@echo off
@setlocal

set args = %1

if "%arg:,1%" == "/" (
    timecmd.bat a.exe < args > out
    ) else (
    timecmd.bat a.exe < in > out
    )

type out