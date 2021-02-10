#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-toolchain \
	$MINGW_PACKAGE_PREFIX-gtest \
	$MINGW_PACKAGE_PREFIX-lcov \
	$MINGW_PACKAGE_PREFIX-openssl

rm -f test01.exe test01.gcda
g++ -std=c++20 -fprofile-arcs -ftest-coverage -o test01 test01.cpp -lgtest_main -lgtest -lcrypto
./test01.exe
gcov test01.gcda
#code strconv.h.gcov
#lcov -c -d . -o test01.lcov.info
#genhtml test01.lcov.info -o ./info.tmp
lcov -c -d . -o test01.lcov
genhtml test01.lcov -o ./info.tmp
#start info.tmp/include/strconv.h.gcov.html
start info.tmp/c/Users/javac/.software/msys64/mingw32/include/strconv.h.gcov.html
