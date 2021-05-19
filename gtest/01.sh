#! bash -uvx
bash -uvx ./inst.sh

rm -f test01-c++14.exe
g++ -std=c++14 -o test01-c++14 test01.cpp -lgtest_main -lgtest -lcrypto
./test01-c++14.exe --bar © -f 123 -d

rm -f test01-c++20.exe
g++ -std=c++20 -o test01-c++20 test01.cpp -lgtest_main -lgtest -lcrypto
./test01-c++20.exe --bar © -f 123 -d
