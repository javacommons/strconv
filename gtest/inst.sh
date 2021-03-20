#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-gcc \
	$MINGW_PACKAGE_PREFIX-openssl \
	$MINGW_PACKAGE_PREFIX-nlohmann-json \
	$MINGW_PACKAGE_PREFIX-gtest \
	lcov
cp -p ../strconv.h $MINGW_PREFIX/include/
rm -rf nlohmann
cp -rp $MINGW_PREFIX/include/nlohmann .
