if .%USERDOMAIN% == .RAMUNE goto :savasPC
Rem MIF kompiuteris
path C:\msys64\ucrt64\bin\g++.exe;%path%
mingw32-make.exe
goto :toliau
:savasPC
make
:toliau
tree.exe > tree.txt