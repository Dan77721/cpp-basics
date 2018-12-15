#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void PrintTableHead()
{
    cout << endl << string(72, '-') << endl;
    cout << "|        x        | ln((x+1)/(x-1)) ";
    cout << "| ln((x+1)/(x-1)) |   iterations   |\n";
    cout << "|                 |      (mine)     ";
    cout << "|     (cmath)     |                |\n";
    cout << string(72, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIters)
{
    double ln = 0;
    for (n = 0; n <= kMaxIters; n++)
    {
        double nth_term = 2 * (1 / ((2 * n + 1) * pow(x, 2 * n + 1)));
        ln += nth_term;
        if (abs(nth_term) < eps) break;
    }
    return ln;
}

void PrintTableRow(double x, double func, int n, const int kMaxIters)
{
    cout << "|" << setw(13) << x << setw(5) << "|";
    if (n <= kMaxIters)
        cout << setw(13) << func << setw(5);
    else
        cout << " limit exceeded! ";
    cout << "|" << setw(13) << log((x + 1) / (x - 1)) << setw(5);
    cout << "|" << setw(9) << n << setw(9) << "|\n";
}

int main()
{
    const int kMaxIters = 10000;

    double xn, xk, dx, eps;
    cout << "|x| > 1\n";
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter xk >= xn: ";
    cin >> xk;
    cout << "Enter dx > 0: ";
    cin >> dx;
    cout << "Enter eps > 0: ";
    cin >> eps;

    if ((abs(xn) <= 1) || (abs(xk) <= 1) || (xk < xn) || (dx <= 0) || (eps <= 0))
    {
        cout << "\nWrong input data!\n";
        return 1;
    }
    
    PrintTableHead();
    cout << fixed;

    for (; xn <= xk; xn += dx)
    {
        int n;
        double ln = ComputeSeries(xn, eps, n, kMaxIters);
        PrintTableRow(xn, ln, n, kMaxIters);
    }
    cout << string(72, '-') << endl;

    return 0;
}