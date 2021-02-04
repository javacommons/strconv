// https://a4dosanddos.hatenablog.com/entry/2015/03/01/191730
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

#include <string>
#include <iostream>

std::string md5(const void *data, unsigned long len)
{
    MD5_CTX c;
    unsigned char md[MD5_DIGEST_LENGTH];
    char mdString[33];
    int r, i;

    r = MD5_Init(&c);
    if (r != 1)
    {
        perror("init");
        return "";
    }

    r = MD5_Update(&c, data, len);
    if (r != 1)
    {
        perror("update");
        return "";
    }

    r = MD5_Final(md, &c);
    if (r != 1)
    {
        perror("final");
        return "";
    }

    for (i = 0; i < 16; i++)
        sprintf(&mdString[i * 2], "%02x", (unsigned int)md[i]);

    return mdString;
}

std::string md5(const std::wstring &s)
{
    return md5((const void *)s.c_str(), s.length() * sizeof(wchar_t));
}

std::string md5(const std::string &s)
{
    return md5((const void *)s.c_str(), s.length());
}

#ifdef __cpp_char8_t
std::string md5(const std::u8string &s)
{
    return md5((const void *)s.c_str(), s.length());
}
#endif


#include "gtest/gtest.h"

TEST(MyTestCase, TestMd5Wide) {
    EXPECT_EQ("ea703e7aa1efda0064eaa507d9e8ab7e", md5("hoge"));
}
TEST(MyTestCase, TestMd5) {
    EXPECT_EQ("b6b439042fa9f95648b929a869b3f95d", md5(L"hoge"));
}
TEST(MyTestCase, TestMd5U8) {
    EXPECT_EQ("ea703e7aa1efda0064eaa507d9e8ab7e", md5(u8"hoge"));
}
