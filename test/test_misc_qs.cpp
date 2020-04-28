#include <gtest/gtest.h>
#include "misc.h"

using namespace mz;
using std::array;

TEST(QSRange, HandlesEmptyArray)
{
    array<int, 0> arr;

    EXPECT_THROW(quick_sort(arr, 0, 0), std::runtime_error);
}

TEST(QSRange, HandlesOneElemArrayCorrectly)
{
    array<int, 1> arr{0};
    const array<int, 1> arrCopy{arr};

    EXPECT_EQ(arr, arrCopy);
    quick_sort(arr, 0, 0);
    EXPECT_EQ(arr, arrCopy);
}

TEST(QSRange, HandlesSortingWithSecondRangeArgumentLesserThanArrayLenght)
{
    array<int, 10> arr{3, 9, 1, 0, 7, 2, 4, 6, 5, 8};
    const array<int, 10> arrSorted{0, 1, 2, 3, 4, 7, 9, 6, 5, 8};

    EXPECT_NE(arr, arrSorted);

    quick_sort(arr, 0, 6);
    EXPECT_EQ(arr, arrSorted);
}

TEST(QSRange, HandlesSortingWithFirstRangeArgumentGreaterThanZero)
{
    array<int, 10> arr{3, 9, 1, 0, 7, 2, 4, 6, 5, 8};
    const array<int, 10> arrSorted{3, 9, 1, 0, 2, 4, 5, 6, 7, 8};

    EXPECT_NE(arr, arrSorted);

    quick_sort(arr, 3, 9);
    EXPECT_EQ(arr, arrSorted);
}

TEST(QSRange, HandlesSortingWithFirstRangeArgGT0AndSecondRangeArgLTArrayLenght)
{
    array<int, 10> arr{3, 9, 1, 0, 7, 2, 4, 6, 5, 8};
    const array<int, 10> arrSorted{3, 9, 0, 1, 2, 4, 6, 7, 5, 8};

    EXPECT_NE(arr, arrSorted);

    quick_sort(arr, 2, 7);
    EXPECT_EQ(arr, arrSorted);
}

TEST(QSRange, HandlesSortingWithSecondRangeArgumentGreaterThanArrayLenght)
{
    array<int, 10> arr{3, 9, 1, 0, 7, 2, 4, 6, 5, 8};

    EXPECT_THROW(quick_sort(arr, 0, 10), std::runtime_error);
}

TEST(QSRange, HandlesSortingWithFirstRangeArguemtnLesserThanZero)
{
    array<int, 3> arr{3, 2, 1};

    EXPECT_THROW(quick_sort(arr, -1, 2), std::runtime_error);
}

TEST(QSRange, HandlesSortingWithSecondAndBothRangeArguemtnLesserThanZero)
{
    array<int, 3> arr{3, 2, 1};

    EXPECT_THROW(quick_sort(arr, 0, -1), std::runtime_error);
    EXPECT_THROW(quick_sort(arr, -1, -1), std::runtime_error);
}

TEST(QS, HandlesEmptyArrayCorrectly)
{
    array<int, 0> arr;
    const array<int, 0> arrCopy{arr};

    EXPECT_EQ(arr, arrCopy);
    quick_sort(arr);
    EXPECT_EQ(arr, arrCopy);
}

TEST(QS, HandlesOneElemArrayCorrectly)
{
    array<int, 1> arr{0};
    const array<int, 1> arrCopy{arr};

    EXPECT_EQ(arr, arrCopy);
    quick_sort(arr);
    EXPECT_EQ(arr, arrCopy);
}

TEST(QS, HandlesTwoElemArraySorting)
{
    array<int, 2> arr{2, 1};
    const array<int, 2> arrSorted{1, 2};

    EXPECT_NE(arr, arrSorted);

    quick_sort(arr);
    EXPECT_EQ(arr, arrSorted);
}

TEST(QS, HandlesThreeElemArraySorting)
{
    array<int, 3> arr{3, 2, 1};
    const array<int, 3> arrSorted{1, 2, 3};

    EXPECT_NE(arr, arrSorted);

    quick_sort(arr);
    EXPECT_EQ(arr, arrSorted);
}

TEST(QS, HandlesTenElemArraySorting)
{
    array<int, 10> arr{3, 9, 1, 0, 7, 2, 4, 6, 5, 8};
    const array<int, 10> arrSorted{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    EXPECT_NE(arr, arrSorted);

    quick_sort(arr);
    EXPECT_EQ(arr, arrSorted);
}
