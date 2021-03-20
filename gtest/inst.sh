#! bash -uvx
pacman -S --needed --noconfirm \
	$MINGW_PACKAGE_PREFIX-gcc \
	$MINGW_PACKAGE_PREFIX-openssl \
	$MINGW_PACKAGE_PREFIX-nlohmann-json \
	$MINGW_PACKAGE_PREFIX-gtest \
	lcov \
	svn

cp -p ../strconv.h $MINGW_PREFIX/include/

sts=0
diff -r $MINGW_PREFIX/include/nlohmann ./nlohmann || sts=$?
echo sts=$sts
if [ $sts -ne 0 ]; then
  rm -rf nlohmann
  cp -rp $MINGW_PREFIX/include/nlohmann .
fi

svn export --force https://github.com/louisdx/cxx-prettyprint/trunk/prettyprint.hpp
