#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-toolchain \
	$MINGW_PACKAGE_PREFIX-gtest \
	$MINGW_PACKAGE_PREFIX-openssl

#cp -p ../strconv.h $MINGW_PREFIX/include/
bash -uvx ./inst.sh

rm -f test01-c++98.exe
g++ -std=c++20 -DSTRCONV_CPP98 -o test01-c++98 test01.cpp -lgtest_main -lgtest -lcrypto
./test01-c++98.exe
