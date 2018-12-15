#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a;
    cout << "Enter a: ";
    cin >> a;

    double z1 = 2 * pow(sin(3 * M_PI - 2 * a), 2) * pow(cos(5 * M_PI + 2 * a), 2);
    double z2 = (1.0 / 4.0) - (1.0 / 4.0) * sin((5 * M_PI / 2) - 8 * a);

    cout << "\nz1 = " << z1 << "\nz2 = " << z2 << endl;

    return 0;
}