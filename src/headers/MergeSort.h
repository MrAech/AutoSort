#pragma once

#include <vector>
#include <string>

class MergeSort {
public:
    static void sort(std::vector<int>& arr);
    static void sort(std::vector<float>& arr);
    static void sort(std::vector<double>& arr);
    static void sort(std::vector<std::string>& arr);

private:
    static void merge(std::vector<int>& arr, int left, int mid, int right);
    static void merge(std::vector<float>& arr, int left, int mid, int right);
    static void merge(std::vector<double>& arr, int left, int mid, int right);
    static void merge(std::vector<std::string>& arr, int left, int mid, int right);


    static void mergesort(std::vector<int>& arr, int left, int right);
    static void mergesort(std::vector<float>& arr, int left, int right);
    static void mergesort(std::vector<double>& arr, int left, int right);
    static void mergesort(std::vector<std::string>& arr, int left, int right);
};
