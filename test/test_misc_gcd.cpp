#include <gtest/gtest.h>
#include "misc.h"

using namespace mz;

TEST(GCD, HandlesZeroAsFirstArgument)
{
    EXPECT_THROW(greatest_common_divisor(0,0), std::runtime_error);    
}

TEST(GCD, HandlesBaseConditionCorrectly)
{
    const int baseCondition = 0;
    const int gcdExamples[3]{1, 10, 43};

    EXPECT_EQ(greatest_common_divisor(gcdExamples[0], baseCondition), gcdExamples[0]);
    EXPECT_EQ(greatest_common_divisor(gcdExamples[1], baseCondition), gcdExamples[1]);
    EXPECT_EQ(greatest_common_divisor(gcdExamples[2], baseCondition), gcdExamples[2]);
}

TEST(GCD, HandlesPositiveNumbersFirstArgGreaterThandSecondArg)
{
    const int testCase0[3]{10,3,1};
    const int testCase1[3]{10,4,2};
    const int testCase2[3]{10,5,5};
    const int testCase3[3]{1680, 640, 80};

    EXPECT_EQ(greatest_common_divisor(testCase0[0], testCase0[1]), testCase0[2]);
    EXPECT_EQ(greatest_common_divisor(testCase1[0], testCase1[1]), testCase1[2]);
    EXPECT_EQ(greatest_common_divisor(testCase2[0], testCase2[1]), testCase2[2]);
    EXPECT_EQ(greatest_common_divisor(testCase3[0], testCase3[1]), testCase3[2]);
}

TEST(GCD, HandlesPositiveNumbersFirstArgLesserThandSecondArg)
{
    const int testCase0[3]{3,10,1};
    const int testCase1[3]{4,10,2};
    const int testCase2[3]{5,10,5};
    const int testCase3[3]{640, 1680, 80};

    EXPECT_EQ(greatest_common_divisor(testCase0[0], testCase0[1]), testCase0[2]);
    EXPECT_EQ(greatest_common_divisor(testCase1[0], testCase1[1]), testCase1[2]);
    EXPECT_EQ(greatest_common_divisor(testCase2[0], testCase2[1]), testCase2[2]);
    EXPECT_EQ(greatest_common_divisor(testCase3[0], testCase3[1]), testCase3[2]);
}

TEST(GCD, HandlesNegativeNumbers)
{
    const int testCase0[3]{3,-10,1};
    const int testCase1[3]{-4,10,2};
    const int testCase2[3]{-5,-10,5};
    const int testCase3[3]{640, -1680, 80};

    EXPECT_EQ(greatest_common_divisor(testCase0[0], testCase0[1]), testCase0[2]);
    EXPECT_EQ(greatest_common_divisor(testCase1[0], testCase1[1]), testCase1[2]);
    EXPECT_EQ(greatest_common_divisor(testCase2[0], testCase2[1]), testCase2[2]);
    EXPECT_EQ(greatest_common_divisor(testCase3[0], testCase3[1]), testCase3[2]);
}