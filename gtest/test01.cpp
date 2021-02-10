#include "gtest/gtest.h"
#include "strconv.h"
#include "str-md5.h"

TEST(MyTestCase, Test001) { // ansi <--> wide
    std::wstring ws = L"string漢字=한자";
    std::string ansi = wide_to_ansi(ws);
    EXPECT_EQ("string\x8A\xBF\x8E\x9A=??", ansi);
    EXPECT_EQ(L"string漢字=??", ansi_to_wide(ansi));
}
TEST(MyTestCase, Test002) { // sjis <--> wide
    std::wstring ws = L"string漢字=한자";
    std::string sjis = wide_to_sjis(ws);
    EXPECT_EQ("string\x8A\xBF\x8E\x9A=??", sjis);
    EXPECT_EQ(L"string漢字=??", sjis_to_wide(sjis));
}
TEST(MyTestCase, Test003) {
    EXPECT_EQ("d2963cadb891061db3454921e70dad0f", md5(utf8_to_wide(U8("string漢字=한자"))));
#ifdef __cpp_char8_t
    EXPECT_EQ("d2963cadb891061db3454921e70dad0f", md5(char8_to_wide(u8"string漢字=한자")));
#endif
}
TEST(MyTestCase, Test004) {
    EXPECT_EQ("bff149abecaa1998db2c8fd3f5c9ef9e", md5(wide_to_utf8(L"string漢字=한자")));
#ifdef __cpp_char8_t
    EXPECT_EQ("bff149abecaa1998db2c8fd3f5c9ef9e", md5(wide_to_char8(L"string漢字=한자")));
#endif
}
TEST(MyTestCase, Test005) { // ansi <--> utf8
    std::string utf8 = U8("string漢字=한자");
    std::string ansi = utf8_to_ansi(utf8);
    EXPECT_EQ("string\x8A\xBF\x8E\x9A=??", ansi);
    EXPECT_EQ(U8("string漢字=??"), ansi_to_utf8(ansi));
#ifdef __cpp_char8_t
    std::u8string char8 = u8"string漢字=한자";
    ansi = char8_to_ansi(char8);
    EXPECT_EQ("string\x8A\xBF\x8E\x9A=??", ansi);
    EXPECT_EQ(U8("string漢字=??"), char8_to_utf8(ansi_to_char8(ansi)));
    EXPECT_EQ("83aba05703b74f191eb49687fe3cc510", md5(ansi_to_char8(ansi)));
#endif
}
TEST(MyTestCase, Test006) { // sjis <--> utf8
    std::string utf8 = U8("string漢字=한자");
    std::string sjis = utf8_to_sjis(utf8);
    EXPECT_EQ("string\x8A\xBF\x8E\x9A=??", sjis);
    EXPECT_EQ(U8("string漢字=??"), sjis_to_utf8(sjis));
#ifdef __cpp_char8_t
    std::u8string char8 = u8"string漢字=한자";
    sjis = char8_to_sjis(char8);
    EXPECT_EQ("string\x8A\xBF\x8E\x9A=??", sjis);
    EXPECT_EQ(U8("string漢字=??"), char8_to_utf8(sjis_to_char8(sjis)));
    EXPECT_EQ("83aba05703b74f191eb49687fe3cc510", md5(sjis_to_char8(sjis)));
#endif
}
TEST(MyTestCase, Test007) { // utf8 <--> char8
#ifdef __cpp_char8_t
    std::u8string char8 = u8"string漢字=한자";
    std::string utf8 = char8_to_utf8(char8);
    EXPECT_EQ(U8("string漢字=한자"), utf8);
    std::u8string char8b = utf8_to_char8(utf8);
    EXPECT_EQ(U8("string漢字=한자"), std::string((const char*)utf8.c_str()));
#endif
}
