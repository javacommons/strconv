#include "gtest/gtest.h"
#include "../strconv.h"
#include "str-md5.h"

TEST(MyTestCase, Test001) {
    EXPECT_EQ("d2963cadb891061db3454921e70dad0f", md5(utf8_to_wide(U8("string漢字=한자"))));
#ifdef __cpp_char8_t
    EXPECT_EQ("d2963cadb891061db3454921e70dad0f", md5(char8_to_wide(u8"string漢字=한자")));
#endif
}
TEST(MyTestCase, Test002) {
    EXPECT_EQ("bff149abecaa1998db2c8fd3f5c9ef9e", md5(wide_to_utf8(L"string漢字=한자")));
#ifdef __cpp_char8_t
    EXPECT_EQ("bff149abecaa1998db2c8fd3f5c9ef9e", md5(wide_to_char8(L"string漢字=한자")));
#endif
}
TEST(MyTestCase, Test003) {
    EXPECT_EQ("ea703e7aa1efda0064eaa507d9e8ab7e", md5(u8"hoge"));
}
