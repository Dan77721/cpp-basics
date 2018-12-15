#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

template <class T>
T** ReadMatrix(string file_name, int num_rows, int num_cols);

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols);

template <class T>
int NumRowsWithoutZeroes(T** matrix, int num_rows, int num_cols);

template <class T>
T* FlattenMatrix(T** matrix, int num_rows, int num_cols);

template <class T>
void SortArrayDescending(T* arr, int size);

template <class T>
int FindEqualNeighborsId(T* arr, int size);

template <class T>
int Execute(string file_name);

int main()
{
	string select;
selection:
	cout << "Select the data type (0-integer, 1-double, 2-float): ";
	cin >> select;
	if (select == "0")
    {
		Execute<int>("int.txt");
	}
	else if (select == "1")
    {
		Execute<double>("double.txt");
	}
	else if (select == "2")
    {
		Execute<float>("float.txt");
	}
	else
    {
		cout << "Error input! (Only 0, 1 or 2).\n\n";
		goto selection;
	}

	return 0;
}

template <class T>
int Execute(string file_name)
{
    int num_rows = 4;
    int num_cols = 5;

    T** matrix = ReadMatrix<T>(file_name, num_rows, num_cols);
    if (!matrix) return 1;

    cout << "\nMatrix:\n";
    PrintMatrix(matrix, num_rows, num_cols);
    cout << endl;

    cout << "\nNumber of rows without zeroes: ";
    cout << NumRowsWithoutZeroes(matrix, num_rows, num_cols) << endl;

    int flat_arr_size = num_rows * num_cols;
    T* arr = FlattenMatrix(matrix, num_rows, num_cols);
    SortArrayDescending(arr, flat_arr_size);
    int repeating = FindEqualNeighborsId(arr, flat_arr_size);
    cout << "\nThe largest number occurring more than once: ";
    if (repeating != -1)
        cout << arr[repeating] << endl;
    else
        cout << "\nNo repeating numbers.\n";

    delete[] arr;
    for (int i = 0; i < num_rows; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}

template <class T>
T** ReadMatrix(string file_name, int num_rows, int num_cols)
{
    ifstream fin(file_name);
    if (!fin.is_open())
    {
        cout << "\nCan't open file " << file_name << "!\n";
        return nullptr;
    }

    T** matrix = new T*[num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new T[num_cols];
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
    }
    fin.close();
    return matrix;
}

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols)
{
    cout << string(5 * num_cols + 1, '-');
    for (int i = 0; i < num_rows; i++)
    {
        cout << "\n|";
        for (int j = 0; j < num_cols; j++)
            cout << setw(3) << matrix[i][j] << setw(2) << "|";
    }
    cout << endl << string(5 * num_cols + 1, '-');
}

template <class T>
int NumRowsWithoutZeroes(T** matrix, int num_rows, int num_cols)
{
    int num_rows_without_zeroes = num_rows;
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            if (matrix[i][j] == 0)
            {
                num_rows_without_zeroes--;
                break;
            }
    return num_rows_without_zeroes;
}

template <class T>
T* FlattenMatrix(T** matrix, int num_rows, int num_cols)
{
    T* arr = new T[num_rows * num_cols];
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            arr[i * num_cols + j] = matrix[i][j];
    return arr;
}

template <class T>
void SortArrayDescending(T* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

template <class T>
int FindEqualNeighborsId(T* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] == arr[i + 1])
            return i;
    return -1;
}