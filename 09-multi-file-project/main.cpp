#include "functions.h"

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