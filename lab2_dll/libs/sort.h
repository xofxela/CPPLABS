#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <vector>
#include <algorithm>
extern "C" 
{
	__declspec(dllexport) void sort_file(std::vector<int>& numbers);
}
#endif // SORT_H_
