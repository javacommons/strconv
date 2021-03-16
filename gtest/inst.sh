#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-nlohmann-json \
	subversion
cp -p ../strconv.h $MINGW_PREFIX/include/
