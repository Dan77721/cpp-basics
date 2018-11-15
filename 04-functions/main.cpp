#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

double CalcLn(int iter, double x, double ln2)
{
	double ln1 = 1.0 / ((2 * iter + 1) * (pow(x, 2 * iter + 1))) + ln2;
	return ln1;
}

bool HaveErrors(double x1, double dx, double x2)
{
	if (x1 <= 1) {
		cout << "error";
		return 1;
	}
	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
		return 1;
	}
	if (x1 > x2) {
		cout << "\nInvalid x2. Must be: x2 >= x1.\n";
		return 1;
	}
	return 0;
}


int main()
{
	double x1, x2, dx;
	double ln1, ln2;
	double eps = 1e-15;
	const int kMaxIter = 100;
	cout << "ln(x+1/x-1),  x > 1" << endl;
	cout << "Enter x1: ";
	cin >> x1;
	cout << "Enter x2: ";
	cin >> x2;
	cout << "Enter dx: ";
	cin >> dx;
	if (HaveErrors(x1, dx, x2))
		return 2;
	cout << string(75, '-') << endl;
	cout << "|         x         ";
	cout << "|   ln(x+1/x-1)mine ";
	cout << "|   ln(x+1/x-1)cmath ";
	cout << "| iterations |\n";
	cout << string(75, '-') << endl;

	cout << fixed;
	cout.precision(6);

	int iter;
	for (double x = x1; x <= x2; x += dx)
	{
		cout << "|" << setw(15) << x;
		ln2 = 0;
		iter = 0;
		while (iter <= kMaxIter)
		{
			ln1 = CalcLn(iter, x, ln2);

			if (abs(abs(ln1) - abs(ln2)) < eps)
				break;
			ln2 = ln1;
			iter++;
		}

		if (kMaxIter >= iter)
		{
			cout << "    |" << setw(14) << ln1 * 2;
			cout << "     |" << setw(16) << log((x + 1) / (x - 1));
			cout << "    |" << setw(7) << iter << "     |" << endl;
		}
		else
		{
			cout << "    |" << setw(14) << "MAX_ITER";
			cout << "     |" << setw(16) << "MAX_ITER";
			cout << "    |" << setw(7) << "  MAX_ITER" << "  |" << endl;
		}

	}
	cout << string(75, '-') << endl;
	return 0;
}