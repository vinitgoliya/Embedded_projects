@echo off
REM Ask for project name
set /p PROJECT_NAME=Enter the project name: 

REM Set the folder location to where the script is saved
set TARGET_DIR=%~dp0

REM Create project folder in the same directory as the script
set PROJECT_PATH="%TARGET_DIR%%PROJECT_NAME%"
mkdir %PROJECT_PATH%

REM Create subfolders in the project folder
mkdir %PROJECT_PATH%\app
mkdir %PROJECT_PATH%\bin
mkdir %PROJECT_PATH%\include
mkdir %PROJECT_PATH%\wsp
mkdir %PROJECT_PATH%\src

REM Create main.c file in app folder
echo // Main application file > %PROJECT_PATH%\app\main.c

REM Optional: Print message
echo Project structure created successfully at %PROJECT_PATH%.

REM Open Keil uVision5 software
start "" "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Keil uVision5.LNK"

pause
