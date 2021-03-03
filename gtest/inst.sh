#! bash -uvx
cp -p ../strconv.h $MINGW_PREFIX/include/
if [ ! -e nlohmann ]; then
  svn export https://github.com/nlohmann/json/trunk/include/nlohmann
  rm -rf $MINGW_PREFIX/include/nlohmann
  cp -rp nlohmann $MINGW_PREFIX/include/
fi
