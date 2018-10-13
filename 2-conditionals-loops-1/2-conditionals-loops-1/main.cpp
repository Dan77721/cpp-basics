#include <iostream>
#include <cmath>

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
	if ((int(a) | int(b) & (int(a) | int(c)))) expression = 1;
	else expression = 0;
	for (X = Xf; X <= Xl; X += dX) {
		cout << "X = " << X << " F = ";
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
		if (expression == 1) cout << f << endl;
		else cout << int(f) << endl;
	}
	return 0;
}
