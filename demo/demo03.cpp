#include "strconv.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class CMyClass
{
    time_t t;
    int count;

public:
    CMyClass()
    {
        this->t = std::time(nullptr);
        this->count = 0;
    }
    int CountUp()
    {
        return ++this->count;
    }
    friend unicode_ostream &operator<<(unicode_ostream &stream, const CMyClass &value);
};

unicode_ostream &operator<<(unicode_ostream &stream, const CMyClass &value)
{
    struct tm *ptm = std::localtime(&value.t);
    stream << u8"[作成日時=" << std::put_time(ptm, "%Y-%m-%d %H:%M:%S");
    stream << u8"、カウント=" << value.count << "]";
    return stream;
};

int main()
{
#ifdef ANSI_ONLY
    unicode_ostream aout(cout);
#else
    unicode_ostream aout(cout, GetConsoleOutputCP()); // chcp 65001 とすると「한자」が「??」に化けずに表示される
#endif
    CMyClass mc;
    mc.CountUp();
    mc.CountUp();
    aout << mc << endl;
    double pi = 4 * atan(1.0);
    aout << u8"π(1)=" << pi << endl;
    aout << u8"π(2)=" << format("%.2f", pi) << endl;

    aout << 1 << u8" char*漢字=한자 " << std::string(u8" string漢字=한자 ") << 1.2345 << endl;
    aout << 2 << L" wchar_t*漢字=한자 " << std::wstring(L" wstring漢字=한자 ") << 1.2345 << endl;

    double A = 100;
    double B = 2001.5251;

    // 書式指定(A) hex の代わりに setbase(16) を使うこともできます
    aout << hex << left << showbase << nouppercase;
    // 実際の印字処理(A)
    aout << (long long)A << endl;

    // 書式指定(B) setbase(10) の代わりに dec を使うこともできます
    aout << setbase(10) << right << setw(15)
         << setfill('_') << showpos
         << fixed << setprecision(2);
    // 実際の印字処理(B)
    aout << B << endl;

    return 0;
}
