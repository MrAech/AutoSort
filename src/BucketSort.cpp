#include "BucketSort.h"


template <typename T>
void BucketSort<T>::sort(std::vector<std::vector<T>>& data, int columnIndex) {
    size_t n = data.size();
    if (n <= 0) return;

    T minValue = data[0][columnIndex];
    T maxValue = data[0][columnIndex];

    for (const auto& row : data) {
        if (row[columnIndex] < minValue) {
            minValue = row[columnIndex];
        }
        if (row[columnIndex] > maxValue) {
            maxValue = row[columnIndex];
        }
    }


    std::vector<std::vector<std::vector<T>>> buckets(n);


    for (const auto& row : data) {
        int bucketIndex = static_cast<int>((row[columnIndex] - minValue) / (maxValue - minValue + 1) * n);
        buckets[bucketIndex].push_back(row);
    }


    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end(), [columnIndex](const std::vector<T>& a, const std::vector<T>& b) {
            return a[columnIndex] < b[columnIndex];
            });
    }


    int index = 0;
    for (const auto& bucket : buckets) {
        for (const auto& row : bucket) {
            data[index++] = row;
        }
    }
}


template class BucketSort<int>;
template class BucketSort<float>;
template class BucketSort<double>;
