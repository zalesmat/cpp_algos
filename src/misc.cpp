#include <stdexcept>
#include "misc.h"

namespace mz {

int greatest_common_divisor(int a, int b)
{
    if (a != 0) {
        if (b == 0)
            return a;

        return greatest_common_divisor(b, std::abs(a) % std::abs(b));
    }

    throw std::runtime_error("greatest_common_divisor: can't divide by 0 (first arg)\n");
}

int qs_partition(int arr[], int low, int high, bool (*cmpr)(int, int))
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (cmpr(arr[j], pivot)) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high, bool (*cmpr)(int, int))
{
    if (low < high) {
        int newPivot = qs_partition(arr, low, high, cmpr);

        quick_sort(arr, low, high - 1);
        quick_sort(arr, low + 1, high);
    }
}

}  // namespace mz