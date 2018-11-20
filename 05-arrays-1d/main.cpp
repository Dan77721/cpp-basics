#include <iostream>
#include <cstdlib>  
#include <ctime> 
#include <iomanip> 
#include <string> 

using namespace std;

struct MaxAndMin
{
	int max_el,
		min_el,
		id_max,
		id_min;

};

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
	if (min > max) 
		swap(min, max);
	for (int i = min + 1; i < max; i++)
	{
		result *= array[i];
	}
	return result;

}

void PrintArray(int array[], int size) {
	cout << string(61, '-') << endl;
	cout << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(2) << "[" << i << "]" << setw(2) << "|";
	}

	cout << "<- Index";
	cout << endl << string(61, '-') << endl << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(3) << array[i] << setw(3) << "|";
	}

	cout << "<- array[i]";
	cout << endl;
	cout << string(61, '-') << endl;
	cout << endl;
}

void SortArray(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] < array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

int main() {
	int const kArraySize = 10;
	int array[kArraySize];
	MaxAndMin M;

	srand((unsigned)time(NULL));

	
	array[0] = int(pow(-1, rand() % 2))*(rand() % 20);
	M.max_el = M.min_el = abs(array[0]);
	M.id_min = M.id_max = 0;
	for (int i = 1; i < kArraySize; i++) {
		array[i] = int(pow(-1, rand() % 2))*(rand() % 20); 
		if (abs(array[i]) < M.min_el) {
			M.min_el = abs(array[i]);
			M.id_min = i;
		}
		if (abs(array[i]) > M.max_el) {
			M.max_el = abs(array[i]);
			M.id_max = i;
		}
	}
	cout << "Starting Array :" << endl;
	PrintArray(array, kArraySize);

	cout << "Sum of subzero elements : ";
	cout << SumSubzeroElements(array, kArraySize);
	cout << endl << endl;

	cout << "Product between the max and min modulo elements : ";
	if (abs(M.id_max - M.id_min) > 1)
		cout << ProductBetweenMaxAndMin(array, M.id_max, M.id_min);
	else
		cout << "Error: no elements between max and min";
	cout << endl << endl;

	cout << "Sorted Array :" << endl;
	SortArray(array, kArraySize);
	PrintArray(array, kArraySize);

	return 0;
}