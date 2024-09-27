#include "../headers/BucketSort.h"
#include <algorithm>
#include <vector>

void BucketSort::sort(std::vector<float>& arr) {
    bucketSort(arr);
}

void BucketSort::sort(std::vector<double>& arr) {
    bucketSort(arr);
}

void BucketSort::bucketSort(std::vector<float>& arr) {
    // Implement bucket sort for floats
    if (arr.empty()) return;

    // Find maximum and minimum values
    float maxVal = *std::max_element(arr.begin(), arr.end());
    float minVal = *std::min_element(arr.begin(), arr.end());

    // Create buckets
    int bucketCount = static_cast<int>(maxVal - minVal) + 1;
    std::vector<std::vector<float>> buckets(bucketCount);

    // Distribute the elements into buckets
    for (const float& num : arr) {
        int bucketIndex = static_cast<int>(num - minVal);
        buckets[bucketIndex].push_back(num);
    }

    // Sort each bucket and concatenate the results
    arr.clear();
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

void BucketSort::bucketSort(std::vector<double>& arr) {
    // Implement bucket sort for doubles (similar logic)
    if (arr.empty()) return;

    double maxVal = *std::max_element(arr.begin(), arr.end());
    double minVal = *std::min_element(arr.begin(), arr.end());

    int bucketCount = static_cast<int>(maxVal - minVal) + 1;
    std::vector<std::vector<double>> buckets(bucketCount);

    for (const double& num : arr) {
        int bucketIndex = static_cast<int>(num - minVal);
        buckets[bucketIndex].push_back(num);
    }

    arr.clear();
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}
