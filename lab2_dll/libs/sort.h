#ifndef SORT_H_
#define SORT_H_

#include <vector>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

extern "C" 
{
	__declspec(dllexport) void selectionSort(std::vector<int> &vec);
}
#endif // SORT_H_
