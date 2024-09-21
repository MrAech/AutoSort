#include "SortingManager.h"

template <typename T>
void SortingManager::sort(std::vector<std::vector<T>>& data, int columnIndex, DataType dataType) {
    size_t size = data.size();
    bool isNearlySorted = checkIfNearlySorted(data, columnIndex);
    bool hasDuplicates = checkForDuplicates(data, columnIndex);

    switch (dataType) {
    case DataType::STRING:
        if (size < 1000) {
            if (isNearlySorted) {
                InsertionSort<T>().sort(data, columnIndex);
            }
            else if (hasDuplicates) {
                BubbleSort<T>().sort(data, columnIndex);
            }
            else {
                SelectionSort<T>().sort(data, columnIndex);
            }
        }
        else if (size < 10000) {
            MergeSort<T>().sort(data, columnIndex);
        }
        else {
            QuickSort<T>().sort(data, columnIndex);
        }
        break;

    case DataType::INT:
        if (size < 1000) {
            if (isNearlySorted) {
                InsertionSort<T>().sort(data, columnIndex);
            }
            else if (hasDuplicates) {
                BubbleSort<T>().sort(data, columnIndex);
            }
            else {
                SelectionSort<T>().sort(data, columnIndex);
            }
        }
        else if (size < 10000) {
            MergeSort<T>().sort(data, columnIndex);
        }
        else {
            RadixSort<T>().sort(data, columnIndex);
        }
        break;

    case DataType::FLOAT:
        if (size < 1000) {
            if (isNearlySorted) {
                InsertionSort<T>().sort(data, columnIndex);
            }
            else if (hasDuplicates) {
                BubbleSort<T>().sort(data, columnIndex);
            }
            else {
                SelectionSort<T>().sort(data, columnIndex);
            }
        }
        else if (size < 10000) {
            QuickSort<T>().sort(data, columnIndex);
        }
        else {
            BucketSort<T>().sort(data, columnIndex);
        }
        break;

    case DataType::DOUBLE:
        if (size < 1000) {
            if (isNearlySorted) {
                InsertionSort<T>().sort(data, columnIndex);
            }
            else if (hasDuplicates) {
                BubbleSort<T>().sort(data, columnIndex);
            }
            else {
                SelectionSort<T>().sort(data, columnIndex);
            }
        }
        else if (size < 10000) {
            MergeSort<T>().sort(data, columnIndex);
        }
        else {
            RadixSort<T>().sort(data, columnIndex);
        }
        break;
    }
}

template <typename T>
bool SortingManager::checkIfNearlySorted(const std::vector<std::vector<T>>& data, int columnIndex) {
    int outOfOrderCount = 0;
    size_t size = data.size();

    for (size_t i = 1; i < size; ++i) {
        if (data[i - 1][columnIndex] > data[i][columnIndex]) {
            outOfOrderCount++;
        }
    }

    // If 10% or less elements are out of order, consider it nearly sorted
    return (outOfOrderCount <= 0.1 * size);
}

template <typename T>
bool SortingManager::checkForDuplicates(const std::vector<std::vector<T>>& data, int columnIndex) {
    std::set<T> uniqueValues;

    for (const auto& row : data) {
        uniqueValues.insert(row[columnIndex]);
    }

    // If the number of unique elements is less than the size, there are duplicates
    return uniqueValues.size() < data.size();
}

// Explicit template instantiation
template void SortingManager::sort(std::vector<std::vector<std::string>>& data, int columnIndex, DataType dataType);
template void SortingManager::sort(std::vector<std::vector<int>>& data, int columnIndex, DataType dataType);
template void SortingManager::sort(std::vector<std::vector<float>>& data, int columnIndex, DataType dataType);
template void SortingManager::sort(std::vector<std::vector<double>>& data, int columnIndex, DataType dataType);
