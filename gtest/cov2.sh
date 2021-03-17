#! bash -uvx
bash -uvx ./inst.sh

rm -f test01.exe test01.gcda
g++ -std=c++20 -DSTRCONV_CPP98 -fprofile-arcs -ftest-coverage -o test01 test01.cpp -lgtest_main -lgtest -lcrypto
./test01.exe

gcov test01.gcda
#code strconv.h.gcov

lcov -c -d . -o test01.lcov
rm -rf ./info.tmp
genhtml test01.lcov -o ./info.tmp
find ./info.tmp -name strconv.h.gcov.html -exec start {} \;
