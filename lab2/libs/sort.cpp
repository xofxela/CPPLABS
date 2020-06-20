/* SORT.CPP */

#include "sort.h"

void sort_file(std::vector<int>& numbers)
{
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sort file successful" << std::endl;
}

/* END OF FILE */
