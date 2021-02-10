#include "gtest/gtest.h"
#include "strconv.h"
#include "str-md5.h"

#include <string>
#include <sstream>

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
TEST(MyTestCase, Test008) { // utf8 <--> utf8
    std::string utf8 = U8("string漢字=한자");
    std::string utf8b = cp_to_utf8(utf8, CP_UTF8);
    EXPECT_EQ(U8("string漢字=한자"), utf8b);
    std::string utf8c = utf8_to_cp(utf8, CP_UTF8);
    EXPECT_EQ(U8("string漢字=한자"), utf8c);
}
TEST(MyTestCase, Test009) {
     // format (1)
    std::string utf8 = U8("string漢字=한자");
    std::string msg = format("msg: %s", utf8.c_str());
    EXPECT_EQ(U8("msg: string漢字=한자"), msg);
    std::wstring wide = WIDE("string漢字=한자");
    std::wstring msgw = format(L"msg: %s", wide.c_str());
    EXPECT_EQ(WIDE("msg: string漢字=한자"), msgw);
#ifdef __cpp_char8_t
    std::u8string char8 = u8"string漢字=한자";
    std::string msgc8 = format(u8"msg: %s", char8.c_str());
    EXPECT_EQ(U8("msg: string漢字=한자"), msgc8);
#endif
}
TEST(MyTestCase, Test010) {
    // format (2)
    std::stringstream ss1;
    std::string utf8 = U8("string漢字=한자");
    format(ss1, "msg: %s", utf8.c_str());
    std::string msg = ss1.str();
    EXPECT_EQ(U8("msg: string漢字=한자"), msg);
    std::stringstream ss2;
    std::wstring wide = WIDE("string漢字=한자");
    format(ss2, L"msg: %s", wide.c_str());
    std::string msgw = ss2.str();
    EXPECT_EQ(U8("msg: string漢字=한자"), msgw);
#ifdef __cpp_char8_t
    std::stringstream ss3;
    std::u8string char8 = u8"string漢字=한자";
    format(ss3, u8"msg: %s", char8.c_str());
    std::string msgc8 = ss3.str();
    EXPECT_EQ(U8("msg: string漢字=한자"), msgc8);
#endif
}
TEST(MyTestCase, Test011) {
     // formatA (1)
    std::string utf8 = U8("string漢字=한자");
    std::string msg = formatA("msg: %s", utf8.c_str());
    EXPECT_EQ("msg: string\x8A\xBF\x8E\x9A=??", msg);
    std::wstring wide = WIDE("string漢字=한자");
    std::string msgw = formatA(L"msg: %s", wide.c_str());
    EXPECT_EQ("msg: string\x8A\xBF\x8E\x9A=??", msgw);
#ifdef __cpp_char8_t
    std::u8string char8 = u8"string漢字=한자";
    std::string msgc8 = formatA(u8"msg: %s", char8.c_str());
    EXPECT_EQ("msg: string\x8A\xBF\x8E\x9A=??", msgc8);
#endif
}
TEST(MyTestCase, Test012) {
    // formatA (2)
    std::stringstream ss1;
    std::string utf8 = U8("string漢字=한자");
    formatA(ss1, "msg: %s", utf8.c_str());
    std::string msg = ss1.str();
    EXPECT_EQ("msg: string\x8A\xBF\x8E\x9A=??", msg);
    std::stringstream ss2;
    std::wstring wide = WIDE("string漢字=한자");
    formatA(ss2, L"msg: %s", wide.c_str());
    std::string msgw = ss2.str();
    EXPECT_EQ("msg: string\x8A\xBF\x8E\x9A=??", msgw);
#ifdef __cpp_char8_t
    std::stringstream ss3;
    std::u8string char8 = u8"string漢字=한자";
    formatA(ss3, u8"msg: %s", char8.c_str());
    std::string msgc8 = ss3.str();
    EXPECT_EQ("msg: string\x8A\xBF\x8E\x9A=??", msgc8);
#endif
}
TEST(MyTestCase, Test013) { // unicode_ostream (1)
    std::stringstream ss;
    unicode_ostream aout(ss);
    std::wstring wide = WIDE("wstring漢字=한자");
    std::string utf8 = U8("string漢字=한자");
    aout << 1234 << wide << utf8;
    std::string msg = ss.str();
    EXPECT_EQ("1234wstring\x8A\xBF\x8E\x9A=??string\x8A\xBF\x8E\x9A=??", msg);
}
TEST(MyTestCase, Test014) { // unicode_ostream (2)
    std::stringstream ss;
    unicode_ostream aout(ss);
    const wchar_t *wide = WIDE("wstring漢字=한자");
    const char *utf8 = U8("string漢字=한자");
    aout << 1234 << wide << utf8;
    std::string msg = ss.str();
    EXPECT_EQ("1234wstring\x8A\xBF\x8E\x9A=??string\x8A\xBF\x8E\x9A=??", msg);
}
TEST(MyTestCase, Test015) { // unicode_ostream (3)
#ifdef __cpp_char8_t
    std::stringstream ss;
    unicode_ostream aout(ss);
    std::u8string u8str = u8"u8string漢字=한자";
    const char8_t *char8 = u8"char8漢字=한자";
    aout << 1234 << u8str << char8;
    std::string msg = ss.str();
    EXPECT_EQ("1234u8string\x8A\xBF\x8E\x9A=??char8\x8A\xBF\x8E\x9A=??", msg);
#endif
}
TEST(MyTestCase, Test016) { // unicode_ostream (4)
    std::stringstream ss;
    unicode_ostream aout(ss, CP_UTF8);
    std::wstring wide = WIDE("wstring漢字=한자");
    std::string utf8 = U8("string漢字=한자");
    aout << 1234 << wide << utf8;
    std::string msg = ss.str();
    EXPECT_EQ("1234wstring漢字=한자string漢字=한자", msg);
}
TEST(MyTestCase, Test017) { // unicode_ostream (5)
    std::stringstream ss;
    unicode_ostream aout(ss, CP_UTF8);
    const wchar_t *wide = WIDE("wstring漢字=한자");
    const char *utf8 = U8("string漢字=한자");
    aout << 1234 << wide << utf8;
    std::string msg = ss.str();
    EXPECT_EQ(U8("1234wstring漢字=한자string漢字=한자"), msg);
}
TEST(MyTestCase, Test018) { // unicode_ostream (6)
#ifdef __cpp_char8_t
    std::stringstream ss;
    unicode_ostream aout(ss, CP_UTF8);
    std::u8string u8str = u8"u8string漢字=한자";
    const char8_t *char8 = u8"char8漢字=한자";
    aout << 1234 << u8str << char8;
    std::string msg = ss.str();
    EXPECT_EQ("1234u8string漢字=한자char8漢字=한자", msg);
#endif
}
