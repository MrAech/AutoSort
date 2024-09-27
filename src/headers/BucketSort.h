#pragma once

#include <vector>

class BucketSort {
public:
    static void sort(std::vector<float>& arr);  // For floats
    static void sort(std::vector<double>& arr); // For doubles

private:
    static void bucketSort(std::vector<float>& arr);
    static void bucketSort(std::vector<double>& arr);
};
