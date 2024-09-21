#include "BucketSort.h"

// Constructor
template <typename T>
BucketSort<T>::BucketSort(int numBuckets) : numBuckets(numBuckets) {}

// Default bucket index for numeric types
template <typename T>
int BucketSort<T>::getBucketIndex(const T& value) {
    return static_cast<int>(value) % numBuckets;  // For integers, floats, and doubles
}

// Specialization for std::string
template <>
int BucketSort<std::string>::getBucketIndex(const std::string& value) {
    return value.length() % numBuckets;  // Use length for string indexing
}

// Sorting function
template <typename T>
void BucketSort<T>::sort(std::vector<std::vector<T>>& data, int columnIndex) {
    if (data.empty()) return;

    // Dynamically adjust number of buckets based on data size
    numBuckets = std::max(1, static_cast<int>(std::sqrt(data.size())));

    // Create buckets
    std::vector<std::vector<std::vector<T>>> buckets(numBuckets);

    for (const auto& row : data) {
        int bucketIndex = getBucketIndex(row[columnIndex]);
        buckets[bucketIndex].push_back(row);
    }

    // Sort individual buckets
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end(),
            [columnIndex](const std::vector<T>& a, const std::vector<T>& b) {
                return a[columnIndex] < b[columnIndex];
            });
    }

    // Combine buckets back into the original data
    data.clear();
    for (const auto& bucket : buckets) {
        data.insert(data.end(), bucket.begin(), bucket.end());
    }
}

// Explicit template instantiations
template class BucketSort<int>;
template class BucketSort<float>;
template class BucketSort<double>;
template class BucketSort<std::string>;
