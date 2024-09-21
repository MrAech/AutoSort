#pragma once
#include <vector>
#include <string>

template <typename T>
class QuickSort {
public:
	void sort(std::vector<std::vector<T>>& data, int columnIndex);
private:	
	void quickSort(std::vector<std::vector<T>>& data, int low, int high, int columnIndex);
	int partition(std::vector<std::vector<T>>& data, int low, int high, int columnIndex);

};