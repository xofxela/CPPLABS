#ifndef SORT_H_
#define SORT_H_

#include <vector>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

extern "C" 
{
	__declspec(dllexport) void mergeSort(std::vector<int> &array);
	__declspec(dllexport) void merge(
		std::vector<int> &array,
		std::vector<int> &L,
		std::vector<int> &R
	);
}
#endif // SORT_H_
