#include <iostream> //Input/Output 
#include <cstdlib> //rand()
#include <ctime> // rand()
#include <iomanip> //std::setw()
#include <string> //string()

using std::cout;
using std::endl;

struct MaxAndMin
{
	int max_el,//max element
		min_el,//min element
		id_max,//index of max
		id_min;//index of min

};

int SumSubzeroElements(int array[], int size);

int ProductBetweenMaxAndMin(int array[], int max, int min);

void PrintArray(int array[], int const size);

void SortArray(int array[], int const size);

void GenerateArray(int array[], int const size);

MaxAndMin FindMaxAndMin(int array[], int const size);