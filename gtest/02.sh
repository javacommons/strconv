#! bash -uvx
bash -uvx ./inst.sh

rm -f test01-c++98.exe
g++ -std=c++20 -DSTRCONV_CPP98 -o test01-c++98 test01.cpp -lgtest_main -lgtest -lcrypto
./test01-c++98.exe
