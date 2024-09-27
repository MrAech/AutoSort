#pragma once

#include <vector>
#include <string>
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "BucketSort.h"
#include "RadixSort.h"
#include "Helpers.h"

class SortingManager {
public:
    template<typename T>
    void sort(std::vector<T>& data);

    template<typename T>
    void sortCSVData(const std::vector<std::string>& csvData);

private:
    template<typename T>
    void determineSortMethod(std::vector<T>& data);
};
