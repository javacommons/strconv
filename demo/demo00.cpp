#include "strconv.h"

int main()
{
    format(std::cout, "GetConsoleCP():%u\n", GetConsoleCP());
    format(std::cout, "GetConsoleOutputCP():%u\n", GetConsoleOutputCP());
    return 0;
}
