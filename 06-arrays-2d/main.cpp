#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

#define Row 4
#define Col 5

using namespace std;

int RowWithoutZeroes(int arr[Row][Col]) {
	int with_zeros = 0;
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			if (abs(arr[i][j]) == 0) {
				with_zeros += 1;
				break;
			}
		}
	}
	return (Row - with_zeros);
}

bool SolutionGuarantee(int a[], int const N) {
	bool check = false;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == a[i + 1]) {
			check = true;
			break;
		}
	}
	return check;
}

int MaxRepeatingNumber(int a[], int const N) {
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == a[i + 1]) {
			result = a[i];
			break;
		}
	}
	return result;
}

void Printarray(int arr[Row][Col]) {
	cout << "array: " << endl;
	cout << string(26, '-') << endl;
	for (int i = 0; i < Row; i++) {
		cout << "|";
		for (int j = 0; j < Col; j++) {
			cout << setw(3) << arr[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << string(26, '-') << endl << endl;
}

int main() {
	int arr[Row][Col];


	ifstream fin("file.txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
		return 1;
	}
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			fin >> arr[i][j];
		}
	}
	fin.close();

	Printarray(arr);

	cout << "Number of rows without zeroes: ";
	cout << RowWithoutZeroes(arr) << endl << endl;

	cout << "The largest number occurring more than once: ";

	int const N = Row * Col;
	int a[N];
	int n = 0;
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
		{
			a[n] = arr[i][j];
			n++;
		}


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (a[j] < a[j + 1])
				swap(a[j], a[j + 1]);

	if (SolutionGuarantee(a, N))
		cout << MaxRepeatingNumber(a, N) << endl << endl;
	else
		cout << "Error: no identical numbers" << endl << endl;

	return 0;
}