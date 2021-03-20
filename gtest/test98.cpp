#include "strconv.h"

int main()
{
    unicode_ostream uout(std::cout);
    uout << L"abc漢字" << std::endl;
    return 0;
}
