#include "../headers/InsertionSort.h"


void InsertionSort::sort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        size_t j = i - 1;
        while (j < arr.size() && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void InsertionSort::sort(std::vector<float>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        float key = arr[i];
        size_t j = i - 1;
        while (j < arr.size() && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void InsertionSort::sort(std::vector<double>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        double key = arr[i];
        size_t j = i - 1;
        while (j < arr.size() && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void InsertionSort::sort(std::vector<std::string>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        std::string key = arr[i];
        size_t j = i - 1;
        while (j < arr.size() && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
