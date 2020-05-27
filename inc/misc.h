#ifndef MZ_MISCELLANEOUS_H_
#define MZ_MISCELLANEOUS_H_

#include <array>
#include <vector>

// definitions in misc.cpp
namespace mz {

std::vector<int> eratosthenes_sieve(short limit);

int greatest_common_divisor(int a, int b);

}  // namespace mz

// definitions outside misc.cpp
namespace mz {

auto default_asc_comparator = [](int a, int b) noexcept(noexcept(a < b))
{
    return a < b;
};

template <size_t N>
void quick_sort(std::array<int, N>& arr, bool (*cmpr)(int, int) = default_asc_comparator);

} // namespace mz

#include "stdarray_qs.inl"

#endif  // !MZ_MISCELLANEOUS_H_