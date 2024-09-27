#include "../headers/QuickSort.h"
#include <vector>
#include <string>

void QuickSort::sort(std::vector<int>& arr) {
    if (arr.size() < 2) return; // No need to sort
    sort(arr, 0, arr.size() - 1);
}

void QuickSort::sort(std::vector<float>& arr) {
    if (arr.size() < 2) return; // No need to sort
    sort(arr, 0, arr.size() - 1);
}

void QuickSort::sort(std::vector<double>& arr) {
    if (arr.size() < 2) return; // No need to sort
    sort(arr, 0, arr.size() - 1);
}

void QuickSort::sort(std::vector<std::string>& arr) {
    if (arr.size() < 2) return; // No need to sort
    sort(arr, 0, arr.size() - 1);
}

int QuickSort::partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int QuickSort::partition(std::vector<float>& arr, int low, int high) {
    float pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int QuickSort::partition(std::vector<double>& arr, int low, int high) {
    double pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

int QuickSort::partition(std::vector<std::string>& arr, int low, int high) {
    std::string pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort::sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

void QuickSort::sort(std::vector<float>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

void QuickSort::sort(std::vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

void QuickSort::sort(std::vector<std::string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}
