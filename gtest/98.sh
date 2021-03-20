#! bash -uvx
bash -uvx ./inst.sh

rm -f test98.exe
g++ -std=c++98 -o test98 test98.cpp
./test98.exe

rm -f test03.exe
g++ -std=c++03 -o test03 test98.cpp
./test03.exe
