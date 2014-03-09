// AC

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double a, b, c, d, e, f, r;
	double x0, y0;
	const double pi = 3.141592653589793;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		if (y1 == y2)
		{
			double temp = y2;
			y2 = y3;
			y3 = temp;
			temp = x2;
			x2 = x3;
			x3 = temp;
		}
		else if (y2 == y3)
		{
			double temp = y2;
			y2 = y1;
			y1 = temp;
			temp = x2;
			x2 = x1;
			x1 = temp;
		}
		a = (y1 + y2) / 2;
		b = (x1 - x2) / (y2 - y1);
		c = (x1 + x2) / 2;
		d = (y3 - y1) / 2;
		e = (x3 - x2) / (y2 - y3);
		f = (x2 + x3) / 2;
		x0 = (d + b * c - e * f) / (b - e);
		y0 = b * (x0 - c) + a;
		r = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
		printf("%.2f\n", (pi * 2 * r));
	}

	return 0;
}	///:~