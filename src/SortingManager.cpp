#include "SortingManager.h"

template <typename T>

void SortingManager::sort(std::vector<std::vector<T>>& data, int columnIndex, DataType Datatype) {
		switch(Datatype){
		case Datatype::STRING:
			if(checkIfNearlySorted(data,columnIndex)){
				InsertionSort::sort(data,columnIndex);
			}
			else if(checkForDuplicates(data,columnIndex)){
				RadixSort::sort(data,columnIndex);
			}
			else{
				MergeSort::sort(data,columnIndex);
			}
			break;
		case Datatype::INT:
			if(checkIfNearlySorted(data,columnIndex)){
				BubbleSort::sort(data,columnIndex);
			}
			else if(checkForDuplicates(data,columnIndex)){
				BucketSort::sort(data,columnIndex);
			}
			else{
				QuickSort::sort(data,columnIndex);
			}
			break;
		case Datatype::FLOAT:
			if(checkIfNearlySorted(data,columnIndex)){
				SelectionSort::sort(data,columnIndex);
			}
			else if(checkForDuplicates(data,columnIndex)){
				MergeSort::sort(data,columnIndex);
			}
			else{
				RadixSort::sort(data,columnIndex);
			}
			break;
		case Datatype::DOUBLE:
			if(checkIfNearlySorted(data,columnIndex)){
				QuickSort::sort(data,columnIndex);
			}
			else if(checkForDuplicates(data,columnIndex)){
				BubbleSort::sort(data,columnIndex);
			}
			else{
				BucketSort::sort(data,columnIndex);
			}
			break;
	}
}

template <typename T>
bool SortingManager::checkIfNearlySorted(const std::vector<std::vector<T>>& data, int columnIndex) {
	int outofOrderCount = 0;
	size_t size = data.size();

	for (size_t i = 1; i < size; ++i) {
		if (data[i - 1][columnIndex] > data[i][columnIndex]) {
			outofOrderCount++;
		}
	}

	if (outofOrderCount <= 0.1 * size) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
bool SortingManager::checkForDuplicates(const std::vector<std::vector<T>>& data, int columnIndex) {
	std::set<T> uniqueValues;

	for (const auto& row : data) {
		uniqueValues.insert(row[columnIndex]);
	}

	return uniqueValues.size() < data.size();
}

template void SortingManager::sort(std::vector<std::vector<std::string>>& data, int columnIndex, DataType dataType);
template void SortingManager::sort(std::vector<std::vector<int>>& data, int columnIndex, DataType dataType);
template void SortingManager::sort(std::vector<std::vector<float>>& data, int columnIndex, DataType dataType);
template void SortingManager::sort(std::vector<std::vector<double>>& data, int columnIndex, DataType dataType);

