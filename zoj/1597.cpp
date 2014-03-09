// WA

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

void swap(double& x, double& y)
{
	double temp = x;
	x = y;
	y = temp;
}

int main()
{
	const double pi = 3.1415926;
	ifstream cin("input.txt");
	double x1, y1, r1, x2, y2, r2;

	while (cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2)
	{
		if (r1 > r2)	// make r2 >= r1
		{
			swap(x1, x2);
			swap(y1, y2);
			swap(r1, r2);
		}
		double s = 0.0;
		double d2 = pow(x1-x2, 2) + pow(y1-y2, 2);
		double d = sqrt(d2);
		if (d <= r2 - r1)
		{
			s = pi * r1 * r1;
		}
		else if (d >= r1 + r2)
		{
			s = 0.0;
		}e
		else
		{
			double cosa1 = (r1 * r1 + d2 - r2 * r2) / (2 * r1 * d);
			double cosa2 = (r2 * r2 + d2 - r1 * r1) / (2 * r2 * d);
			double a1 = acos(cosa1);
			double a2 = acos(cosa2);
			double sin2a1 = 2 * cosa1 * sqrt(1 - cosa1 * cosa1);
			double sin2a2 = 2 * cosa2 * sqrt(1 - cosa2 * cosa2);
			s = r1 * r1 * (a1 - sin2a1 / 2) + r2 * r2 * (a2 - sin2a2 / 2);
		}

		cout << fixed << setprecision(3) << s << endl;
	}

	return 0;
}	///:~