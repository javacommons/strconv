#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-gcc \
	$MINGW_PACKAGE_PREFIX-qt5 \
	make
cp -p ../strconv*.h $MINGW_PREFIX/include/
