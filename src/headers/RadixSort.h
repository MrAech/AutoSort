#pragma once

#include <vector>

class RadixSort {
public:
    static void sort(std::vector<int>& arr); // Only for integers

private:
    static void countingSort(std::vector<int>& arr, int exp);
};
