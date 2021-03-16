#! bash -uvx
./inst.sh
qmake qttest.pro && make && release/qttest.exe
