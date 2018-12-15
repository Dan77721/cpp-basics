#include "functions.h"

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