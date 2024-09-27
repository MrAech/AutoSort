#pragma once

#include <vector>
#include <string>

class SelectionSort {
public:
    static void sort(std::vector<int>& arr);
    static void sort(std::vector<float>& arr);
    static void sort(std::vector<double>& arr);
    static void sort(std::vector<std::string>& arr);
};
