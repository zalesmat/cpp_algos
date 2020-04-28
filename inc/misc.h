#ifndef MZ_MISCELLANEOUS_H_
#define MZ_MISCELLANEOUS_H_

#include <array>

namespace mz {

int greatest_common_divisor(int a, int b);

void quick_sort(int arr[], int low, int high, bool (*cmpr)(int, int) = [](int a, int b) {
    return a < b;
});

auto default_asc_comparator = [](int a, int b) noexcept(noexcept(a < b))
{
    return a < b;
};

template <size_t N>
void quick_sort(std::array<int, N>& arr, bool (*cmpr)(int, int) = default_asc_comparator);

}  // namespace mz

#include "stdarray_qs.inl"

#endif  // !MZ_MISCELLANEOUS_H_