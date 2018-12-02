#include "functions.h"

int main()
{
	int const kArraySize = 10;
	int array[kArraySize];

	GenerateArray(array, kArraySize);

	cout << "Starting Array :" << endl;
	PrintArray(array, kArraySize);

	cout << "Sum of subzero elements : ";
	cout << SumSubzeroElements(array, kArraySize);
	cout << endl << endl;

	cout << "Product between the max and min modulo elements : ";
	MaxAndMin M = FindMaxAndMin(array, kArraySize);
	if (abs(M.id_max - M.id_min) > 1)
		cout << ProductBetweenMaxAndMin(array, M.id_max, M.id_min);
	else
		cout << "Error: no elements between max and min";
	cout << endl << endl;

	SortArray(array, kArraySize);
	cout << "Sorted array:" << endl;
	PrintArray(array, kArraySize);

	return 0;
}