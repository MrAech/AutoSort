#pragma once

#include <string>
#include <vector>
#include <stdexcept>

class Helpers {
public:
    static int stringToInt(const std::string& str);
    static float stringToFloat(const std::string& str);
    static double stringToDouble(const std::string& str);

    template<typename T>
    static std::vector<T> convertStringsToTypes(const std::vector<std::string>& strData);

    static bool hasDuplicates(const std::vector<int>& data);
    static bool hasDuplicates(const std::vector<float>& data);
    static bool hasDuplicates(const std::vector<double>& data);
    static bool hasDuplicates(const std::vector<std::string>& data);

    static bool isNearlySorted(const std::vector<int>& data);
    static bool isNearlySorted(const std::vector<float>& data);
    static bool isNearlySorted(const std::vector<double>& data);
    static bool isNearlySorted(const std::vector<std::string>& data);
};
