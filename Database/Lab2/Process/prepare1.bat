@echo off
cd /d "%~dp0"
for %%a in ("%cd%") do set "fd=%%~nxa"
for /f "delims=" %%a in ('dir /a-d/b *.csv') do (
    (for /f "delims=" %%b in ('type "%%a"') do (
        echo;%fd%,%%~na,%%b
    ))>"$%%~na.tmp"
    move /y "$%%~na.tmp" "%%a"
)
pause
