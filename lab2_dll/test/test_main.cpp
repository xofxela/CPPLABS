#include <windows.h>
#include <cstdio>
#include "gtest/gtest.h"

typedef void(*DllFunc)(std::vector<int>&);
DllFunc pDllFunc = nullptr;

namespace {
    TEST(SortTest, BackOrder)
    {
        std::vector<int> numbers = {5, 4, 3, 2, 1};
        std::vector<int> numbersSorted = {1, 2, 3, 4, 5};
		pDllFunc(numbers);

        EXPECT_EQ(numbersSorted, numbers);
    }
	TEST(SortTest, AlreadySorted)
	{
		std::vector<int> numbers = {1, 2, 3, 4, 5};
		std::vector<int> numbersSorted = {1, 2, 3, 4, 5};
		pDllFunc(numbers);

		EXPECT_EQ(numbersSorted, numbers);
	}
    TEST(SortTest, RandomOrder)
    {
        std::vector<int> numbers = {1, 3, 2, 5, 4};
		std::vector<int> numbersSorted = {1, 2, 3, 4, 5};
		pDllFunc(numbers);

		EXPECT_EQ(numbersSorted, numbers);
    }
    TEST(SortTest, OneSequence)
    {
        std::vector<int> numbers = {1, -1, -1, 1, 1};
		std::vector<int> numbersSorted = {-1, -1, 1, 1, 1};
		pDllFunc(numbers);

		EXPECT_EQ(numbersSorted, numbers);
    }
    TEST(SortTest, EmptyVector)
    {
        std::vector<int> numbers = {};
		std::vector<int> numbersSorted = {};
		pDllFunc(numbers);

		EXPECT_EQ(numbersSorted, numbers);
    }
}  // namespace

GTEST_API_ int main(int argc, char **argv)
{
#if NDEBUG
	HINSTANCE h = LoadLibrary("..\\libs\\Release\\sort.dll");
#else
	HINSTANCE h = LoadLibrary("..\\libs\\Debug\\sort.dll");
#endif
	if (!h) 
	{
		printf("Error - can`t find sort.dll\n");
		return -1;
	}
	pDllFunc = (DllFunc) GetProcAddress(h, "mergeSort");

	if (!pDllFunc) 
	{
		printf("Error - No function mergeSort() in sort.dll\n");
		return -1;
	}

	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	FreeLibrary(h);
	return 0;
}
