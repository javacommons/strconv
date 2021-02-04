#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-toolchain \
	$MINGW_PACKAGE_PREFIX-gtest \
	$MINGW_PACKAGE_PREFIX-openssl

g++ -std=c++11 -o test01 test01.cpp -lgtest_main -lgtest
./test01.exe
