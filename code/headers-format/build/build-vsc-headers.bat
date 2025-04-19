@echo off
REM Compiles all .cpp files with g++ (C++20), runs successful builds, and waits for keypress
REM Output goes to ../output folder

setlocal enabledelayedexpansion

set FAILURES=0
set OUTPUT_DIR=..\output

REM Create output directory if it doesn't exist
if not exist "%OUTPUT_DIR%" mkdir "%OUTPUT_DIR%"

for %%f in (..\*.cpp) do (
    echo ------------------------------
    echo Compiling %%f...
    
    REM Compile with common warnings enabled
    g++ -std=c++20 -Wall -Wextra -pedantic -o "%OUTPUT_DIR%\%%~nf.exe" "%%f"
    
    if errorlevel 1 (
        echo [ERROR] Failed to compile %%f
        set /A FAILURES+=1
    ) else (
        echo [SUCCESS] Compiled %%f
        echo Running %%~nf.exe...
        echo ------------------------------
        
        REM Run the program and wait for keypress
        "%OUTPUT_DIR%\%%~nf.exe"
        echo ------------------------------
        pause
    )
    echo.
)

echo ===============================
echo COMPILATION SUMMARY:
echo A total of %FAILURES% files failed to compile
echo Executables are in: %OUTPUT_DIR%
echo ===============================
pause