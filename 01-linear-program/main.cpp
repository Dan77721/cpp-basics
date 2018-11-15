#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	const double PI = 3.1415926535897932384626433832795;
	double a;
	double z1, z2;
	cout << "Enter a: ";
	cin >> a;
	z1 = 2 * (pow(sin(3 * PI - 2 * a), 2))*(pow(cos(5 * PI + 2 * a), 2));
	z2 = 1.0 / 4.0 - 1.0 / 4.0 * sin(5.0 / 2.0 * PI - 8.0 * a);
	cout << "z1 = " << z1 << "\nz2 = " << z2;
	return 0;
}