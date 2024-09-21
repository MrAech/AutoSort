#include "MergeSort.h"


template <typename T>
void MergeSort<T>::sort(std::vector<std::vector<T>>& data, int columnIndex) {
	mergeSort(data, 0, data.size() - 1, columnIndex);
}

template <typename T>
void MergeSort<T>::mergeSort(std::vector<std::vector<T>>& data, int left, int right, int columnIndex) {
	if (left < right) {
		int middle = left + (right - left) / 2;

		mergeSort(data, left, middle, columnIndex);
		mergeSort(data, middle + 1, right, columnIndex);

		merge(data, left, middle, right, columnIndex);
	}
}

template <typename T>
void MergeSort<T>::merge(std::vector<std::vector<T>>& data, int left,int middle, int right, int columnIndex) {
	int n1 = middle - left - 1;
	int n2 = right - middle;

	std::vector<std::vector<T>> leftArray(n1), rightArray(n2);

	for(int i =0; i < n1; i++)
		leftArray[i] = data[left + i];
	for(int j = 0 ; j < n2; j++)
		rightArray[j] = data[middle + j + 1];


	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftArray[i][columnIndex] <= rightArray[j][columnIndex]) {
			data[k] = leftArray[i];
			i++;
		}
		else {
			data[k] = rightArray[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		data[k] = leftArray[i];
		i++;
		k++;
	}
	while(j<n2){
		data[k] = rightArray[j];
		j++;
		k++;
	}
}


template class MergeSort<int>;
template class MergeSort<std::string>;
template class MergeSort<double>;
template class MergeSort<float>;
