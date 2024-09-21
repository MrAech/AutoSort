#include "RadixSort.h"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

// Helper function to get the maximum length of strings in the specified column
int getMaxLength(const std::vector<std::vector<std::string>>& data, int columnIndex) {
    int maxLength = 0;
    for (const auto& row : data) {
        if (row[columnIndex].length() > maxLength) {
            maxLength = row[columnIndex].length();
        }
    }
    return maxLength;
}

// Function to perform counting sort based on the digit represented by exp
void countingSort(std::vector<std::vector<std::string>>& data, int columnIndex, int exp) {
    std::vector<std::vector<std::string>> output(data.size());
    int count[256] = { 0 };

    for (const auto& row : data) {
        count[row[columnIndex].length() > exp ? row[columnIndex][exp] : 0]++;
    }

    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    for (int i = data.size() - 1; i >= 0; i--) {
        int idx = data[i][columnIndex].length() > exp ? data[i][columnIndex][exp] : 0;
        output[count[idx] - 1] = data[i];
        count[idx]--;
    }

    for (int i = 0; i < data.size(); i++) {
        data[i] = output[i];
    }
}

// General Radix Sort Implementation
template <typename T>
void RadixSort<T>::sort(std::vector<std::vector<T>>& data, int columnIndex) {
    // General implementation would go here (if applicable)
}

// Specialized Radix Sort Implementation for std::string
template <>
void RadixSort<std::string>::sort(std::vector<std::vector<std::string>>& data, int columnIndex) {
    int maxLength = getMaxLength(data, columnIndex);
    for (int exp = maxLength - 1; exp >= 0; exp--) {
        countingSort(data, columnIndex, exp);
    }
}

// Explicit template instantiation
template class RadixSort<int>;
template class RadixSort<float>;
template class RadixSort<double>;
template class RadixSort<std::string>;
