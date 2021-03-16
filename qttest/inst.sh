#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-gcc \
	$MINGW_PACKAGE_PREFIX-qt5 \
	$MINGW_PACKAGE_PREFIX-nlohmann-json \
	make
cp -p ../strconv.h ../strconvQt.h $MINGW_PREFIX/include/
