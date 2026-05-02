@echo off
echo Compiling project...
gcc src\main.c src\model.c src\matrix.c src\arena.c src\prng.c src\utils.c -Iinclude -o main.exe

if %errorlevel%==0 (
    echo Build succeeded.
    echo Running program...
    main.exe
) else (
    echo Build failed with error code %errorlevel%.
)
