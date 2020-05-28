#include <stdexcept>
#include "misc.h"

namespace mz {

std::vector<int> eratosthenes_sieve(short limit)
{
    if (limit < 1)
        throw std::runtime_error("input argument is lower than the smallest prime number");

    std::vector<bool> primes(limit - 1, true);

    int firstPrime = 2;

    for (int i = 0, j = firstPrime; i < limit; ++i, ++j) {
        if (primes[i]) {
            for (int k = j + i; k < limit; k += j)
                primes[k] = false;
        }
    }

    std::vector<int> result;

    // reserving 1/5 of limit to avoid many dynamic memory allocations
    result.reserve(limit / 5);

    for (int i = 0; i < primes.size(); ++i)
        if (primes[i])
            result.push_back(firstPrime + i);

    result.shrink_to_fit();

    return result;
}

int greatest_common_divisor(int a, int b)
{
    if (a != 0) {
        if (b == 0)
            return a;

        return greatest_common_divisor(b, std::abs(a) % std::abs(b));
    }

    throw std::runtime_error("greatest_common_divisor: can't divide by 0 (first arg)\n");
}

}  // namespace mz