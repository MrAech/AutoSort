#pragma once
#include <vector>
#include <string>

template <typename T>
class BubbleSort {
public:
    void sort(std::vector<std::vector<T>>& data, int columnIndex);
};

// Specialization for std::string
template <>
class BubbleSort<std::string> {
public:
    void sort(std::vector<std::vector<std::string>>& data, int columnIndex);
};
