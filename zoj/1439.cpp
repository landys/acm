// AC

#include <iostream>
// #include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	double x1, y1, z1, x2, y2, z2, x3, y3, z3;
	while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3)
	{
		// double c2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
		// double b2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3) + (z1 - z3) * (z1 - z3);
		// double a2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) + (z3 - z2) * (z3 - z2);
		double c2 = pow(x1-x2, 2) + pow(y1-y2, 2) + pow(z1-z2, 2); 
		double b2 = pow(x1-x3, 2) + pow(y1-y3, 2) + pow(z1-z3, 2); 
		double a2 = pow(x3-x2, 2) + pow(y3-y2, 2) + pow(z3-z2, 2); 

		double a = sqrt(a2);
		double b = sqrt(b2);
		double c = sqrt(c2);
		double cosa = (b2 + c2 - a2) / (b * c * 2);
		double sina = sqrt(1 - cosa * cosa);
		double r1 = a / (2 * sina);
		double r2 = b * c * sina / (a + b + c);

		cout << fixed << setprecision(3) << (r2 * r2) / (r1 * r1) << endl;
	}
	return 0;
}	///:~

/* // WA

#include <iostream>
#include <cmath>
// #include <fstream>
#include <iomanip>
using namespace std;

void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	// ifstream cin("input.txt");
	int x1, y1, z1, x2, y2, z2, x3, y3, z3;
	while (cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3)
	{
		if (x1 == x2 && x2 == x3)
		{
			swap(x1, z1);
			swap(x2, z2);
			swap(x3, z3);
		}
		else if (y1 == y2 && y2 == y3)
		{
			swap(y1, z1);
			swap(y2, z2);
			swap(y3, z3);
		}

		// circum circle

		if (y1 == y2)
		{
			swap(y2, y3);
			swap(x2, x3);
		}
		else if (y2 == y3)
		{
			swap(y1, y2);
			swap(x1, x2);
		}
		double a = double(y1 + y2) / 2;
		double b = double(x1 - x2) / (y2 - y1);
		double c = double(x1 + x2) / 2;
		double d = double(y3 - y1) / 2;
		double e = double(x3 - x2) / (y2 - y3);
		double f = double(x2 + x3) / 2;
		double x0 = (d + b * c - e * f) / (b - e);
		double y0 = b * (x0 - c) + a;
		double r1 = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
		
		// inscribed circle

		int ab2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		int ac2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
		int bc2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
		// double ac2 = pow(double(x3-x1), 2) + pow(double(y3-y1), 2);
		// double bc2 = pow(double(x3-x2), 2) + pow(double(y3-y2), 2);
		double cosb = double(ab2 + bc2 - ac2) / (2 * sqrt(double(ab2)) * sqrt(double(bc2)));
		double cosa = double(ab2 + ac2 - bc2) / (2 * sqrt(double(ab2)) * sqrt(double(ac2)));
		double cotb2 = sqrt((1 + cosb) / (1 - cosb));
		double cota2 = sqrt((1 + cosa) / (1 - cosa));
		double r2 = sqrt(double(ab2)) / (cotb2 + cota2);

		cout << fixed << setprecision(3) << ((r2 / r1) * (r2 / r1)) << endl;
	}

	return 0;
}	///:~ */