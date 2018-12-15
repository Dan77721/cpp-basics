#include <iostream>

using namespace std;

struct MinMaxIndices
{
    int min_i, max_i;
};

void PrintArray(double* arr, const int kArraySize);
bool NegativeElementExists(double* arr, const int kArraySize);
double SumNegativeElements(double* arr, const int kArraySize);
MinMaxIndices FindMinMaxIndices(double* arr, const int kArraySize);
double ProductRangeElements(double* arr, int begin, int end);
void SortArray(double* arr, const int kArraySize);

int main()
{
    const int kArraySize = 10;
    double arr[kArraySize] = { 3, -7, 1, 0.1, -.9, 8, -6, .2, -5, .4 };

    cout << "Initial array:\n";
    PrintArray(arr, kArraySize);
    cout << endl;

    cout << "\nSum of negative elements = ";
    if (NegativeElementExists(arr, kArraySize))
        cout << SumNegativeElements(arr, kArraySize) << endl;
    else
        cout << "\nNo negative elements in the array.\n";

    MinMaxIndices mmi = FindMinMaxIndices(arr, kArraySize);
    int min_index = mmi.min_i;
    int max_index = mmi.max_i;
    cout << "\nProduct of elements between min and max = ";
    if (abs(min_index - max_index) > 1)
    {
        if (min_index < max_index)
            cout << ProductRangeElements(arr, min_index, max_index) << endl;
        else
            cout << ProductRangeElements(arr, max_index, min_index) << endl;
    }
    else
    {
        cout << "\nNo elements between min and max.\n";
    }

    SortArray(arr, kArraySize);
    cout << "\nSorted array:\n";
    PrintArray(arr, kArraySize);
    cout << endl;

    return 0;
}

void PrintArray(double* arr, const int kArraySize)
{
    cout << "[";
    for (int i = 0; i < kArraySize; i++)
        cout << arr[i] << ((i < kArraySize - 1) ? (", ") : ("]"));
}

bool NegativeElementExists(double* arr, const int kArraySize)
{
    for (int i = 0; i < kArraySize; i++)
        if (arr[i] < 0)
            return 1;
    return 0;
}

double SumNegativeElements(double* arr, const int kArraySize)
{
    double sum = 0;
    for (int i = 0; i < kArraySize; i++)
        if (arr[i] < 0)
            sum += arr[i];
    return sum;
}

MinMaxIndices FindMinMaxIndices(double* arr, const int kArraySize)
{
    int min_i = 0, max_i = 0;
    for (int i = 1; i < kArraySize; i++)
    {
        if ((arr[i]) > (arr[min_i])) min_i = i;
        if ((arr[i]) < (arr[max_i])) max_i = i;
    }
    return MinMaxIndices{ min_i, max_i };
}

double ProductRangeElements(double* arr, int begin, int end)
{
    double product = 1;
    for (int i = begin + 1; i < end; i++)
        product *= arr[i];
    return product;
}

void SortArray(double* arr, const int kArraySize)
{
    for (int i = 0; i < kArraySize - 1; i++)
        for (int j = 0; j < kArraySize - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}