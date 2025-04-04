echo off

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

copy ..\%SOURCE_FOLDER%\menu\build_run.bat .\menu
copy ..\%SOURCE_FOLDER%\sortings\src\build_run.bat .\src
copy ..\%SOURCE_FOLDER%\long_number\src\build_run.bat .\src

copy ..\run_tests.bat .