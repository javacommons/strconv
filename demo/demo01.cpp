#include <windows.h>
#include "strconv.h"

int main(int argc, char **argv)
{
  std::string utf8_str = u8"あいう";
  printf("utf8_str.length()=%u\n", utf8_str.length());
  std::wstring wide_str = utf8_to_wide(utf8_str);
  printf("wide_str.length()=%u\n", wide_str.length());
  std::string sjis_str = wide_to_sjis(wide_str);
  printf("sjis_str.length()=%u\n", sjis_str.length());
  printf("sjis_str.c_str()=%s\n", sjis_str.c_str());
  return 0;
}
