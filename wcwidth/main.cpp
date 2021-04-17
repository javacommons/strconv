#include "wcwidth.c"

#include "strconv.h"
#include <iomanip>
#include <stdint.h>

void display(unicode_ostream &uout, const std::wstring &ws)
{
    std::string native = wide_to_cp(ws, uout.target_cp());
    std::wstring ws2 = cp_to_wide(native, uout.target_cp());
    uout << ws2 << " " << mk_wcswidth(ws2.c_str(), ws2.size()) << " " << format("cp=%u", uout.target_cp()) << std::endl;
}

int main()
{
    uint16_t target_cp = GetConsoleCP();
    unicode_ostream uout(std::cout, target_cp);
    std::wstring ws = L"漢字=한자🦕ｶ";
    //uout << mk_wcswidth_cjk(ws.c_str(), ws.size()) << std::endl;
    display(uout, ws);
    //ws = L"🦕";
    //display(uout, ws);
}