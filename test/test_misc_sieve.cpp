#include <gtest/gtest.h>
#include "misc.h"

using namespace mz;

TEST(EratosthenesSieve, HandlesZeroAsInput)
{
    EXPECT_THROW(eratosthenes_sieve(0), std::runtime_error);
}

TEST(EratosthenesSieve, HandlesNegativeNumberAsInput)
{
    EXPECT_THROW(eratosthenes_sieve(-1), std::runtime_error);
}

TEST(EratosthenesSieve, HandlesSmallInputArgument)
{
    auto result_input_2 = eratosthenes_sieve(2);
    auto result_input_5 = eratosthenes_sieve(5);
    auto result_input_10 = eratosthenes_sieve(10);

    std::vector<int> compare_input_2{2};
    std::vector<int> compare_input_5{2,3,5};
    std::vector<int> compare_input_10{2,3,5,7};

    EXPECT_EQ(result_input_2, compare_input_2);
    EXPECT_EQ(result_input_5, compare_input_5);
    EXPECT_EQ(result_input_10, compare_input_10);
}
TEST (EratosthenesSieve, HandlesBigInputArgument)
{
    auto result_input_500 = eratosthenes_sieve(500);
    std::vector<int> compare_input_500{
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
        101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
        211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
        307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
        401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};

    EXPECT_EQ(result_input_500, compare_input_500);
}