#! bash -uvx
./inst.sh
qmake qttest.pro && make clean && make && release/qttest.exe
