#pragma once
#include <vector>
#include <string>
#include <set>
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "BucketSort.h"

// Enum to define supported data types
enum class DataType {
    STRING,
    INT,
    FLOAT,
    DOUBLE,
};

// Sorting Manager class
class SortingManager {
public:
    template <typename T>
    void sort(std::vector<std::vector<T>>& data, int columnIndex, DataType dataType);

private:
    template <typename T>
    bool checkIfNearlySorted(const std::vector<std::vector<T>>& data, int columnIndex);

    template <typename T>
    bool checkForDuplicates(const std::vector<std::vector<T>>& data, int columnIndex);
};
