#include "./headers/SortingManager.h"

template<typename T>
void SortingManager::determineSortMethod(std::vector<T>& data) {
    size_t size = data.size();

    if constexpr (std::is_same_v<T, int>) {
        if (size < 1000) {
            if (Helpers::isNearlySorted(data)) {
                InsertionSort::sort(data);
            }
            else if (Helpers::hasDuplicates(data)) {
                BubbleSort::sort(data);
            }
            else {
                SelectionSort::sort(data);
            }
        }
        else if (size < 10000) {
            MergeSort::sort(data);
        }
        else {
            RadixSort::sort(data); // Use RadixSort for large arrays of integers
        }
    }
    else if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
        if (size < 1000) {
            if (Helpers::isNearlySorted(data)) {
                InsertionSort::sort(data);
            }
            else if (Helpers::hasDuplicates(data)) {
                BubbleSort::sort(data);
            }
            else {
                SelectionSort::sort(data);
            }
        }
        else if (size < 10000) {
            QuickSort::sort(data); // For larger floats/doubles, use QuickSort
        }
        else {
            BucketSort::sort(data); // For very large floats/doubles, use BucketSort
        }
    }
    else if constexpr (std::is_same_v<T, std::string>) {
        if (size < 1000) {
            if (Helpers::isNearlySorted(data)) {
                InsertionSort::sort(data);
            }
            else if (Helpers::hasDuplicates(data)) {
                BubbleSort::sort(data);
            }
            else {
                SelectionSort::sort(data);
            }
        }
        else if (size < 10000) {
            MergeSort::sort(data); // For strings, you can choose MergeSort
        }
        else {
            QuickSort::sort(data); // Or QuickSort for larger strings
        }
    }
}

template<typename T>
void SortingManager::sort(std::vector<T>& data) {
    determineSortMethod(data);
}

template<typename T>
void SortingManager::sortCSVData(const std::vector<std::string>& csvData) {
    auto convertedData = Helpers::convertStringsToTypes<T>(csvData);
    sort(convertedData);
}

// Explicit template instantiation for supported types
template void SortingManager::sort<int>(std::vector<int>& data);
template void SortingManager::sort<float>(std::vector<float>& data);
template void SortingManager::sort<double>(std::vector<double>& data);
template void SortingManager::sort<std::string>(std::vector<std::string>& data);
