namespace mz {

template <size_t N>
int qs_partition(std::array<int, N>& arr, size_t low, size_t high, bool (*cmpr)(int, int)) noexcept(
    noexcept(std::swap(arr[low], arr[high])) && noexcept(cmpr(arr[low], arr[high])))
{
    int pivot = arr[high];
    int i = static_cast<int>(low) - 1;

    for (size_t j = low; j < high; ++j) {
        if (cmpr(arr[j], pivot)) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <size_t N>
void quick_sort(std::array<int, N>& arr,
                size_t low,
                size_t high,
                bool (*cmpr)(int, int) = default_asc_comparator)
{
    if (high >= N || low >= N)
        throw std::runtime_error("mz::quick_sort: bad range argument");

    if (low < high) {
        int newPivot = qs_partition(arr, low, high, cmpr);

        quick_sort(arr, low, high - 1, cmpr);
        quick_sort(arr, low + 1, high, cmpr);
    }
}

template <size_t N>
void quick_sort(std::array<int, N>& arr, bool (*cmpr)(int, int))
{
    if (arr.size() > 1)
        quick_sort(arr, 0, N - static_cast<size_t>(1), cmpr);
}

}  // namespace mz