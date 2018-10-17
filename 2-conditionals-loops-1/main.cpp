#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double Xf, Xl, dX, a, b, c, f, X;
	int expression;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter X first: ";
	cin >> Xf;
	cout << "Enter X last: ";
	cin >> Xl;
	cout << "Enter dX: ";
	cin >> dX;
	cout << "-------------------------------------" << endl;
	cout << "|        X        |        F        |" << endl;
	cout << "-------------------------------------" << endl;
	if ((int(a) | int(b) & (int(a) | int(c)))) expression = 1;
	else expression = 0;
	cout.precision(3);
	cout << fixed;
	for (X = Xf; X <= Xl; X += dX) {
		cout  << "|" << setw(12) << X ;
		if (X < 0 && b != 0) f = a * X * X + b;
		else if (X > 0 && b == 0) {
			if (X - c != 0) f = (X - a) / (X - c);
			else {
				cout << "ERROR" << endl;
				break;
			}
		}
		else if (c != 0) f = X / c;
		else {
			cout << "ERROR" << endl;
			break;
		}
		cout << "     |" ;
		cout.width(12);
		if (expression == 1) cout << f ;
		else cout << int(f) ;
	}
	cout << "     |" << endl;
	cout << "-------------------------------------";
	return 0;
}
