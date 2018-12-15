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