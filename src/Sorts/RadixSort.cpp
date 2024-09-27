#include "../headers/RadixSort.h"
#include <algorithm>
#include <vector>

void RadixSort::sort(std::vector<int>& arr) {
    int maxVal = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

void RadixSort::countingSort(std::vector<int>& arr, int exp) {
    const int base = 10;
    std::vector<int> output(arr.size());
    int count[base] = { 0 };

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % base]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}
