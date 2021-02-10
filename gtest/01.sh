#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-toolchain \
	$MINGW_PACKAGE_PREFIX-gtest \
	$MINGW_PACKAGE_PREFIX-openssl

rm -f test01-c++20.exe
g++ -std=c++20 -o test01-c++20 test01.cpp -lgtest_main -lgtest -lcrypto
./test01-c++20.exe

rm -f test01-c++14.exe
g++ -std=c++14 -o test01-c++14 test01.cpp -lgtest_main -lgtest -lcrypto
./test01-c++14.exe
