#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-toolchain \
	$MINGW_PACKAGE_PREFIX-gtest \
	$MINGW_PACKAGE_PREFIX-openssl

rm -f md5-A.exe
g++ -std=c++20 -o md5-A md5-A.cpp -lgtest_main -lgtest -lcrypto
./md5-A.exe
