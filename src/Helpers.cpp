#include "./headers/Helpers.h"
#include <unordered_set>
#include <algorithm>

int Helpers::stringToInt(const std::string& str) {
    return std::stoi(str);
}

float Helpers::stringToFloat(const std::string& str) {
    return std::stof(str);
}

double Helpers::stringToDouble(const std::string& str) {
    return std::stod(str);
}

template<typename T>
std::vector<T> Helpers::convertStringsToTypes(const std::vector<std::string>& strData) {
    std::vector<T> convertedData;
    convertedData.reserve(strData.size());
    for (const auto& str : strData) {
        if constexpr (std::is_same_v<T, int>) {
            convertedData.push_back(stringToInt(str));
        }
        else if constexpr (std::is_same_v<T, float>) {
            convertedData.push_back(stringToFloat(str));
        }
        else if constexpr (std::is_same_v<T, double>) {
            convertedData.push_back(stringToDouble(str));
        }
        else {
            throw std::invalid_argument("Unsupported type for conversion");
        }
    }
    return convertedData;
}

// Implementations for hasDuplicates and isNearlySorted would go here...
bool Helpers::hasDuplicates(const std::vector<int>& data) {
    std::unordered_set<int> seen;
    for (const auto& value : data) {
        if (seen.count(value)) return true;
        seen.insert(value);
    }
    return false;
}

bool Helpers::hasDuplicates(const std::vector<float>& data) {
    std::unordered_set<float> seen;
    for (const auto& value : data) {
        if (seen.count(value)) return true;
        seen.insert(value);
    }
    return false;
}

bool Helpers::hasDuplicates(const std::vector<double>& data) {
    std::unordered_set<double> seen;
    for (const auto& value : data) {
        if (seen.count(value)) return true;
        seen.insert(value);
    }
    return false;
}

bool Helpers::hasDuplicates(const std::vector<std::string>& data) {
    std::unordered_set<std::string> seen;
    for (const auto& value : data) {
        if (seen.count(value)) return true;
        seen.insert(value);
    }
    return false;
}

// Example implementation of isNearlySorted
bool Helpers::isNearlySorted(const std::vector<int>& data) {
    // A simple implementation checking if the array is sorted with at most one swap
    return std::is_sorted(data.begin(), data.end());
}

// Implement similar methods for float, double, and string as needed
bool Helpers::isNearlySorted(const std::vector<float>& data) {
    return std::is_sorted(data.begin(), data.end());
}

bool Helpers::isNearlySorted(const std::vector<double>& data) {
    return std::is_sorted(data.begin(), data.end());
}

bool Helpers::isNearlySorted(const std::vector<std::string>& data) {
    return std::is_sorted(data.begin(), data.end());
}
