#pragma once
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
class SelectionSort {
public:
	
	void sort(std::vector<std::vector<T>>& data, int columnIndex);
};