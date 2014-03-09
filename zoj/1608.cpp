// AC

#include <iostream>
//#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	//fstream cin("input.txt");

	double a, b, r1, r2;

	while (cin >> a >> b >> r1 >> r2)
	{
		if (2 * r1 + 0.01 > a || 2 * r1 + 0.01 > b || 2 * r2 + 0.01 > a || 2 * r2 + 0.01 > b)
		{
			cout << "No" << endl;
			continue;
		}
		
		double d = sqrt((a-r1-r2)*(a-r1-r2) + (b-r1-r2)*(b-r1-r2));
		if (d < r1 + r2 + 0.01)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}

	return 0;
}