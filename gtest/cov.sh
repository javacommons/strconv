#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-toolchain \
	$MINGW_PACKAGE_PREFIX-gtest \
	$MINGW_PACKAGE_PREFIX-lcov \
	$MINGW_PACKAGE_PREFIX-openssl

rm -f test01.exe
g++ -std=c++20 -fprofile-arcs -ftest-coverage -o test01 test01.cpp -lgtest_main -lgtest -lcrypto
./test01.exe
gcov test01.gcda
