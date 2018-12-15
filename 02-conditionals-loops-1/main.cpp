#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const double kEps = 1e-15;

    double a, b, c, xn, xk, dx;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter xk >= xn: ";
    cin >> xk;
    cout << "Enter dx > 0: ";
    cin >> dx;

    if (dx <= 0 || xn > xk)
    {
        cout << "\nInvalid input variables.\n";
        cout << "Must be: (dx > 0) and (xk >= xn).\n";
        return 1;
    }

    cout << string(37, '-') << endl;
    cout << "|        x        |        F        |\n";
    cout << string(37, '-') << endl;

    cout << fixed;
    cout.precision(3);

    for (double x = xn; x <= xk; x += dx)
    {
        cout << "|" << setw(12) << x << setw(6) << "|";

        double f;
        if (x < 0 && abs(b) >= kEps)
        {
            f = a * x * x + b;
        }
        else if (x > 0 && abs(b) < kEps)
        {
            if (abs(x - c) >= kEps)
            {
                f = (x - a) / (x - c);
            }
            else
            {
                cout << "  division by 0  |\n";
                continue;
            }
        }
        else
        {
            if (abs(c) >= kEps)
            {
                f = x / c;
            }
            else
            {
                cout << "  division by 0  |\n";
                continue;
            }
        }

        int ac = static_cast<int>(a);
        int bc = static_cast<int>(b);
        int cc = static_cast<int>(c);
        if ((ac | bc) & (ac | cc))
            cout << setw(12) << f << setw(7);
        else
            cout << setw(10) << static_cast<int>(f) << setw(9);
        cout << "|\n";
    }
    cout << string(37, '-');

    return 0;
}