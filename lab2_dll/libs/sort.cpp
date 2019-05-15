/* SORT.CPP */

#include "sort.h"

//void sort_file(std::vector<int>& numbers)
//{
//	std::sort(numbers.begin(), numbers.end());
//}

void selectionSort(std::vector<int> &vec) 
{
	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		for (int next = fill + 1; next != vec.size(); ++next) {

			if (vec[next] < vec[pos_min])
				pos_min = next;

		}
		if (fill != pos_min)
			std::swap(vec[pos_min], vec[fill]);

	}
}

/* END OF FILE */
