#pragma once
#include <vector>
#include <string>

// Inertion Sort class
template <typename T>
class InsertionSort {
public:
	void sort(std::vector<std::vector<T>>& data, int columnIndex);
};