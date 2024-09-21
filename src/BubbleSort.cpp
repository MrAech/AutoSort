#include "BubbleSort.h"
#include <algorithm> // for std::swap

// General template implementation for types like int, float, double
template <typename T>
void BubbleSort<T>::sort(std::vector<std::vector<T>>& data, int columnIndex) {
    size_t size = data.size();
    bool swapped;
    for (size_t i = 0; i < size - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (data[j][columnIndex] > data[j + 1][columnIndex]) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Specialization for std::string
void BubbleSort<std::string>::sort(std::vector<std::vector<std::string>>& data, int columnIndex) {
    size_t size = data.size();
    bool swapped;
    for (size_t i = 0; i < size - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (data[j][columnIndex].compare(data[j + 1][columnIndex]) > 0) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Explicit template instantiations for the types you want
template class BubbleSort<int>;
template class BubbleSort<float>;
template class BubbleSort<double>;
