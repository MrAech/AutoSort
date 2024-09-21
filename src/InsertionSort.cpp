#include "InsertionSort.h"

template <typename T>
void InsertionSort<T>::sort(std::vector<std::vector<T>>& data, int columnIndex) {
    size_t size = data.size();

    // Perform Insertion Sort
    for (size_t i = 1; i < size; ++i) {
        std::vector<T> key = data[i]; // Element to be inserted
        size_t j = i - 1;

        // Move elements of data[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && data[j][columnIndex] > key[columnIndex]) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key; // Insert the key in its correct position
    }
}

// Explicit instantiation for the supported types
template class InsertionSort<std::string>;
template class InsertionSort<int>;
template class InsertionSort<float>;
template class InsertionSort<double>;
