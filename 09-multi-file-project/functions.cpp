#include "functions.h"

int SumSubzeroElements(int array[], int size) {
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] < 0)
			result += array[i];
	}
	return result;
}

int ProductBetweenMaxAndMin(int array[], int max, int min) {
	int result = 1;
	if (min > max) //for going begin min to max
		std::swap(min, max);
	for (int i = min + 1; i < max; i++)
	{
		result *= array[i];
	}
	return result;
}

void SortArray(int array[], int const size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] < array[j + 1]) {
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

void PrintArray(int array[], int const size) {
	cout << std::string(61, '-') << endl;
	cout << "|";

	for (int i = 0; i < size; i++) {
		cout << std::setw(2) << "[" << i << "]" << std::setw(2) << "|";
	}

	cout << "<- Index";
	cout << endl << std::string(61, '-') << endl << "|";

	for (int i = 0; i < size; i++) {
		cout << std::setw(3) << array[i] << std::setw(3) << "|";
	}

	cout << "<- array[i]";
	cout << endl;
	cout << std::string(61, '-') << endl;
	cout << endl;
}

void GenerateArray(int array[], int const size) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
		array[i] = int(pow(-1, rand() % 2))*(rand() % 20); //[-19..19]
}

MaxAndMin FindMaxAndMin(int array[], int const size) {
	MaxAndMin result;
	result.max_el = result.min_el = abs(array[0]);
	result.id_min = result.id_max = 0;
	for (int i = 1; i < size; i++) {
		if (abs(array[i]) < result.min_el) {
			result.min_el = abs(array[i]);
			result.id_min = i;
		}
		if (abs(array[i]) > result.max_el) {
			result.max_el = abs(array[i]);
			result.id_max = i;
		}
	}
	return result;
}