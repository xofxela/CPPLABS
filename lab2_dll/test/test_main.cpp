#include <windows.h>
#include <cstdio>
#include "gtest/gtest.h"

typedef void(*DllFunc)(std::vector<int>&);
DllFunc pDllFunc = NULL;

namespace {
    TEST(SortTest, Order)
    {
        std::vector<int> numbers = {5, 4, 3, 2, 1};
        std::vector<int> numbersSorted = {1, 2, 3, 4, 5};
		pDllFunc(numbers);

        EXPECT_EQ(numbersSorted, numbers);
    }
	TEST(SortTest, EqualElement)
	{
		std::vector<int> numbers = { 5, 4, 3, 2, 1 };
		pDllFunc(numbers);

		EXPECT_EQ(numbers[1], 2);
	}
    TEST(SortTest, GreaterValue)
    {
        std::vector<int> numbers = {5, 4, 3, 2, 1};
		pDllFunc(numbers);

        EXPECT_GE(numbers[1], numbers[0]);
    }
    TEST(SortTest, LessValue)
    {
        std::vector<int> numbers = {5, 4, 3, 2, 1};
		pDllFunc(numbers);

        EXPECT_LT(numbers[0], numbers[1]);
    }
    TEST(SortTest, IsExists)
    {
        std::vector<int> numbers = {5, 4, 3, 2, 1};
		pDllFunc(numbers);
        for(unsigned int i=0; i<numbers.size(); i++)
        {
            EXPECT_TRUE(&numbers[i] != NULL);
        }
    }
}  // namespace

GTEST_API_ int main(int argc, char **argv)
{
	HINSTANCE h = LoadLibrary("..\\libs\\Debug\\sort.dll");
	if (!h) 
	{
		printf("Error - can`t find sort.dll\n");
		return -1;
	}
	DllFunc pDllFunc = (DllFunc) GetProcAddress(h, "sort_file");

	if (!pDllFunc) 
	{
		printf("Error - No function sort_file() in sort.dll\n");
		return -1;
	}

	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	FreeLibrary(h);
	return 0;
}


