#include "RadixSort.h"

template <typename T>
int getmax(const std::vector<std::vector<T>>& data, int columnIndex) {
	T maxelement = data[0][columnIndex];
	for (const auto& row : data) {
		if(row[columnIndex] > maxelement) {
			maxelement = row[columnIndex];
		}
	}
	return static_cast<int>(maxelement);
}

template <typename T>
void countingSort(std::vector<std::vector<T>>& data, int columnIndex, int exp) {
	size_t size = data.size();
	std::vector<std::vector<T>> output(size);
	int count[10] = { 0 };

	for (size_t i = 0; i < size; i++) {
		int index = static_cast<int>(data[i][columnIndex]/ exp) % 10;
		count[index]++;
	}

	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		int index = static_cast<int>(data[i][columnIndex] / exp) % 10;
		output[count[index] - 1] = data[i];
		count[index]--;
	}

	for (size_t i = 0; i < size; i++) {
		data[i] = output[i];
	}
}

template <typename T>
void RadixSort<T>::sort(std::vector<std::vector<T>>& data, int columnIndex) {
	int maxelement = getmax(data, columnIndex);
	
	for (int exp = 1; maxelement / exp > 0; exp *= 10) {
		countingSort(data, columnIndex, exp);
	}
}


template class RadixSort<int>;
template class RadixSort<float>;
template class RadixSort<double>;
