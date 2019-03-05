#include <cstdio>
#include "sort.h"
#include "gtest/gtest.h"

namespace {
    TEST(SortTest, Order)
    {
        std::vector<int> numbers = {5, 4, 3, 2, 1};
        std::vector<int> numbersSorted = {1, 2, 3, 4, 5};
        sort_file(&numbers);

        EXPECT_EQ(numbersSorted, numbers);
    }
    TEST(SortTest, GreaterValue)
    {
        std::vector<int> numbers = {5, 4, 3, 2, 1};
        sort_file(&numbers);

        EXPECT_GE(numbers[1], numbers[0]);
    }
    TEST(SortTest, LessValue)
    {
        std::vector<int> numbers = {5, 4, 3, 2, 1};
        sort_file(&numbers);

        EXPECT_LT(numbers[0], numbers[1]);
    }
    TEST(SortTest, IsExists)
    {
        std::vector<int> numbers = {5, 4, 3, 2, 1};
        sort_file(&numbers);
        for(unsigned int i=0; i<numbers.size(); i++)
            {
                EXPECT_TRUE(&numbers[i] != NULL);
            }
    }
}  // namespace

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
