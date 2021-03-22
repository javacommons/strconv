#include "strconv.h"
#include <iomanip>

int main()
{
    unicode_ostream uout(std::cout, GetConsoleCP());
    uout << std::left << std::setw(20) << U8("あいうえお") << 123 << std::endl;
    uout << std::left << std::setw(20) << U8("あいう") << 456 << std::endl;
}