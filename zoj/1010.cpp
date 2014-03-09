// AC

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

bool isEqual(double x, double y)
{
	if (fabs(x-y) <= 1e-8)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isMid(double x, double y, double x1, double y1, double x2, double y2)
{
	if (((x1-x)*(x-x2) > 0 || (y1-y)*(y-y2) > 0) || ((x==x1 && y==y1) || (x==x2 && y==y2)))
	{
		// (x, y) between (x1, y1) and (x2, y2), including the two ends
		return true;
	}
	return false;
}

// line (x,y)--(x1,y1) and (x,y)--(x2,y2)
bool isOverlap(double x, double y, double x1, double y1, double x2, double y2)
{
	if (isEqual((x1-x)*(y2-y), (x2-x)*(y1-y))
		&& (isMid(x1, y1, x, y, x2, y2) || isMid(x2, y2, x, y, x1, y1)))
	{
		return true;
	}
	return false;
}

// line (x1,y1)--(x2,y2) and (x3,y3)--(x4,y4)
bool isIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double y12 = y1 - y2;
	double x12 = x1 - x2;
	double y34 = y3 - y4;
	double x34 = x3 - x4;


	if ((x12==0 && x34==0) || (x12!=0 && x34!=0 && isEqual(y12*x34, y34*x12)))
	{
		// parallel or overlap
		if (((x1==x2 && x2==x3) || isEqual(y12*(x3-x1), (y3-y1)*x12))
			&& (isMid(x1, y1, x3, y3, x4, y4) || isMid(x2, y2, x3, y3, x4, y4)
			|| isMid(x3, y3, x1, y1, x2, y2) || isMid(x4, y4, x1, y1, x2, y2)))
		{
			// overlap
			return true;
		}
		return false;
	}

	// (x,y) is the point of intersection
	double x;
	double y;
	if (x12 == 0)
	{
		x = x1;
		double a2 = y34 / x34;
		y = a2 * x + y3 - a2 * x3;
	}
	else if (x34 == 0)
	{
		x = x3;
		double a1 = y12 / x12;
		y = a1 * x + y1 - a1 * x1;
	}
	else
	{
		double a1 = y12 / x12;
		double b1 = y1 - a1 * x1;
		double a2 = y34 / x34;
		double b2 = y3 - a2 * x3;
		x = (b2 - b1) / (a1 - a2);
		y = a1 * x + b1;
	}
	return (isMid(x, y, x1, y1, x2, y2) && isMid(x, y, x3, y3, x4, y4));
}

int main()
{
	//ifstream cin("input.txt");
	int n;
	int i, j;
	cin >> n;
	int count = 0;
	while (n != 0)
	{
		count++;
		if (n <= 2)
		{
			double temp;
			// read unuseful data
			for (i=0; i<n; i++)
			{
				cin >> temp >> temp;
			}
			cout << "Figure " << count << ": Impossible" << endl;
			cin >> n;
			if (n != 0)
			{
				cout << endl;
			}
			continue;
		}

		double* x = new double[n];
		double* y = new double[n];
		double s = 0.0;	// area

		cin >> x[0] >> y[0];
		cin >> x[1] >> y[1];
		s += (x[1]-x[0]) * (y[1]+y[0]) / 2;
		bool flag = false;
		for (i=2; i<=n; i++)
		{
			int a;
			if (i != n)
			{
				cin >> x[i] >> y[i];
				a = i;
			}
			else
			{
				a = 0;
			}

			// check two neighbouring lines
			if (isOverlap(x[i-1], y[i-1], x[a], y[a], x[i-2], y[i-2]))
			{
				flag = true;
				break;
			}

			for (j=1; j<i-1; j++)
			{
				if (i == n && j == 1)
				{
					continue;
				}

				// check two non-neighbouring lines
				if (isIntersect(x[i-1], y[i-1], x[a], y[a], x[j-1], y[j-1], x[j], y[j]))
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
			s += (x[a]-x[i-1]) * (y[a]+y[i-1]) / 2;
		}
		if (flag)
		{
			cout << "Figure " << count << ": Impossible" << endl;
		}
		else
		{
			cout << "Figure " << count << ": " << fixed << setprecision(2) << fabs(s) << endl;
		}

		// read unuseful data
		for (i++; i<n; i++)
		{
			cin >> x[i] >> y[i];
		}
		delete x;
		delete y;

		cin >> n;
		if (n != 0)
		{
			cout << endl;
		}
	}
	return 0;
}


