#pragma once
#include <vector>
#include <algorithm>
template <typename T>
class BucketSort {
public:
	void sort(std::vector<std::vector<T>>& data, int columnIndex);
};