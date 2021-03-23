#include "wcwidth.c"

#include "strconv.h"
#include <iomanip>

int main()
{
    unicode_ostream uout(std::cout, GetConsoleCP());
    std::wstring ws = L"漢字=한자";
    uout << mk_wcswidth_cjk(ws.c_str(), ws.size()) << std::endl;
}