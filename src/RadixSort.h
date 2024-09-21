#pragma once
#include <vector>
#include <string>

template <typename T>
class RadixSort {
public:
    void sort(std::vector<std::vector<T>>& data, int columnIndex);
};

// Specialization for std::string
template <>
void RadixSort<std::string>::sort(std::vector<std::vector<std::string>>& data, int columnIndex);
