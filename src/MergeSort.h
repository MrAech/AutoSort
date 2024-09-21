#pragma once
#include <vector>
#include <string>

template <typename T>
class MergeSort {
public:
	void sort(std::vector<std::vector<T>>& data, int columnIndex);
private:
	void mergeSort(std::vector<std::vector<T>>& data, int left, int right, int columnIndex);
	void merge(std::vector<std::vector<T>>& data, int left, int middle, int right, int columnIndex);
};
