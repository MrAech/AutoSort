#include "SelectionSort.h"



template <typename T>
void SelectionSort<T>::sort(std::vector<std::vector<T>>& data, int columnIndex) {
    size_t n = data.size();


    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIndex = i;

        for (size_t j = i + 1; j < n; ++j) {
            if (data[j][columnIndex] < data[minIndex][columnIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(data[i], data[minIndex]);
        }
    }
}


template class SelectionSort<int>;
template class SelectionSort<float>;
template class SelectionSort<double>;
template class SelectionSort<std::string>;
