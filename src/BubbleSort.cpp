#include "BubbleSort.h"

template <typename T>
void BubbleSort<T>::sort(std::vector<std::vector<T>>& data, int columnIndex) {
	size_t size = data.size();
	for (size_t i = 0; j < size - i; ++i) {
		bool swapped = false;
		for (size_t j = 0; j < size - i - 1; ++j) {
			if (data[j][columnIndex] > data[j + 1][columnIndex]) {
				std::swap(data[j], data[j + 1]);
				swapped = true;
			}
		}
	}

	if (!swapped) {
		break;
	}
}

template class BubbleSort<int>;
template class BubbleSort<float>;
template class BubbleSort<double>;
template class BubbleSort<std::string>;