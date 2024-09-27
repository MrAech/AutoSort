#pragma once

#include <vector>
#include <string>

class QuickSort {
public:
    static void sort(std::vector<int>& arr);
    static void sort(std::vector<float>& arr);
    static void sort(std::vector<double>& arr);
    static void sort(std::vector<std::string>& arr);

private:
    static int partition(std::vector<int>& arr, int low, int high);
    static int partition(std::vector<float>& arr, int low, int high);
    static int partition(std::vector<double>& arr, int low, int high);
    static int partition(std::vector<std::string>& arr, int low, int high);
    static void sort(std::vector<int>& arr, int low, int high);
    static void sort(std::vector<float>& arr, int low, int high);
    static void sort(std::vector<double>& arr, int low, int high);
    static void sort(std::vector<std::string>& arr, int low, int high);
};
