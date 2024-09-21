#include "QuickSort.h"

template <typename T>
void QuickSort<T>::sort(std::vector<T>& data, int columnIndex) {
	quickSort(data, 0, data.size() - 1, columnIndex);
}

template <typename T>
void QuickSort<T>::quickSort(std::vector<std::vector<T>>& data, int low, int high, int columnIndex) {
	if (low < high) {
		int pi = partition(data, low, high, columnIndex);
		quickSort(data, low, pi - 1, columnIndex);
		quickSort(data, pi + 1, high, columnIndex);
	}
}

template <typename T>
int QuickSort<T>::partition(std::vector < std::vector<T>>& data, int low, int high, int columnIndex) {
	T piviot = data[high][columnIndex];
	int i = low - 1;

	for (int j = low; j < high; ++j) {
		if(data[j][columnIndex] <= piviot) {
			++i;
			std::swap(data[i], data[j]);
		}
	}

	std::swap(data[i + 1], data[high]);

	return i + 1;
}


template class QuickSort<int>;
template class QuickSort<float>;
template class QuickSort<double>;
template class QuickSort<std::string>;

