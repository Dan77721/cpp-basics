#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

#define Row 4
#define Col 5

using namespace std;

template <class Type>
void ReadArray(Type a, string name) {
	ifstream fin(name + ".txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
	}
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			fin >> a[i][j];
		}
	}
	fin.close();
}

template <class Type>
int RowWithoutZeroes(Type arr[Row][Col]) {
	const double kEps = 1e-15;
	int with_zeros = 0;
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			if (abs(arr[i][j]) < kEps) {
				with_zeros += 1;
				break;
			}
		}
	}
	return (Row - with_zeros);
}

template <class Type>
bool SolutionGuarantee(Type a[], int const N) {
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

template <class Type>
Type MaxRepeatingNumber(Type a[], int const N) {
	Type result = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == a[i + 1]) {
			result = a[i];
			break;
		}
	}
	return result;
}

template <class Type>
void PrintArray(Type arr[Row][Col]) {
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

template <class TypeAr>
void begin(string name) {
	TypeAr arr[Row][Col];
	ReadArray(arr, name);
	PrintArray(arr);

	cout << "Number of rows without zeroes: ";
	cout << RowWithoutZeroes(arr) << endl << endl;

	cout << "The largest number occurring more than once: ";

	int const N = Row * Col;
	TypeAr a[N];
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
}

int main() {
error:
	cout << "Select the data type (0-integer, 1-double, 2-float): ";
	string select;
	cin >> select;
	if (select == "0") {
		begin<int>("int");
	}
	else if (select == "1") {
		begin<double>("double");
	}
	else if (select == "2") {
		begin<float>("float");
	}
	else {
		cout << "Error input! (Only 0/1/2)" << endl;
		goto error;
	}
	return 0;
}