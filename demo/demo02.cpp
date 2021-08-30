#include "strconv.h"
#include <iostream>
#include <string>

int main(void)
{
    std::string nameUtf8 = u8"太郎";
    int age = 15;
    // 以下の3行は同じ意味です。
    std::cout << utf8_to_ansi(format(u8"ハロー、私の名前は %s。 年は %d だ!", nameUtf8.c_str(), age)) << std::endl;
    std::cout << formatA(u8"ハロー、私の名前は %s。 年は %d だ!", nameUtf8.c_str(), age) << std::endl;
    formatA(std::cout, u8"ハロー、私の名前は %s。 年は %d だ!\n", nameUtf8.c_str(), age);
    std::wstring nameWide = L"花子";
    age = 23;
    // 以下の3行は同じ意味です。
    std::cout << wide_to_ansi(format(L"ハロー、私の名前は %s。 年は %d だ!", nameWide.c_str(), age)) << std::endl;
    std::cout << formatA(L"ハロー、私の名前は %s。 年は %d だ!", nameWide.c_str(), age) << std::endl;
    formatA(std::cout, L"ハロー、私の名前は %s。 年は %d だ!\n", nameWide.c_str(), age);
    return 0;
}
