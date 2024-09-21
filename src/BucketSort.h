#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

template <typename T>
class BucketSort {
public:
    BucketSort(int numBuckets = 10);
    void sort(std::vector<std::vector<T>>& data, int columnIndex);

private:
    int numBuckets;

    int getBucketIndex(const T& value);
};

// Specialization for std::string
template <>
int BucketSort<std::string>::getBucketIndex(const std::string& value);
