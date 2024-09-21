#pragma once
#include <vector>
#include <algorithm>
#include <cmath>

template <typename T>
class RadixSort {
public:
	void sort(std::vector<std::vector<T>>& data, int columnIndex);
};