#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int** ReadMatrix(string file_name, int num_rows, int num_cols);
void PrintMatrix(int** matrix, int num_rows, int num_cols);
int NumRowsWithoutZeroes(int** matrix, int num_rows, int num_cols);
int* FlattenMatrix(int** matrix, int num_rows, int num_cols);
void SortArrayDescending(int* arr, int size);
int FindEqualNeighborsId(int* arr, int size);

int main()
{
    int num_rows = 4;
    int num_cols = 5;

    int** matrix = ReadMatrix("matrix.txt", num_rows, num_cols);
    if (!matrix) return 1;

    cout << "Matrix:\n";
    PrintMatrix(matrix, num_rows, num_cols);
    cout << endl;

    cout << "\nNumber of rows without zeroes: ";
    cout << NumRowsWithoutZeroes(matrix, num_rows, num_cols) << endl;

    int flat_arr_size = num_rows * num_cols;
    int* arr = FlattenMatrix(matrix, num_rows, num_cols);
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

int** ReadMatrix(string file_name, int num_rows, int num_cols)
{
    ifstream fin(file_name);
    if (!fin.is_open())
    {
        cout << "\nCan't open file " << file_name << "!\n";
        return nullptr;
    }

    int** matrix = new int*[num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        matrix[i] = new int[num_cols];
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
    }
    fin.close();
    return matrix;
}

void PrintMatrix(int** matrix, int num_rows, int num_cols)
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

int NumRowsWithoutZeroes(int** matrix, int num_rows, int num_cols)
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

int* FlattenMatrix(int** matrix, int num_rows, int num_cols)
{
    int* arr = new int[num_rows * num_cols];
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            arr[i * num_cols + j] = matrix[i][j];
    return arr;
}

void SortArrayDescending(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int FindEqualNeighborsId(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] == arr[i + 1])
            return i;
    return -1;
}