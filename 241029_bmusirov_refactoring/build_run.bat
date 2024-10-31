@echo off
chcp 1251 > log
del log

set CPP_FILES="io.cpp main.cpp merge.cpp merge_sort.cpp random_array.cpp"
set EXE=merge_sort.exe
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

if exist %EXE% del %EXE%

g++ "%CHARSET%" "%CPP_FILES%" -o %EXE%

%EXE%
