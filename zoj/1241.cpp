// AC

#include <iostream>
// #include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int a, b, c;
	int count = 0;
	while (cin >> a >> b >> c && a != 0)
	{
		count++;
		double s = 0.0;

		cout << "Triangle #" << count << endl;
		if (c == -1)
		{
			s = sqrt(double(a * a + b * b));
			cout << "c = " << fixed << setprecision(3) << s << endl << endl;
		}
		else if (a == -1 && c > b)
		{
			s = sqrt(double(c * c - b * b));
			cout << "a = " << fixed << setprecision(3) << s << endl << endl;
		}
		else if (b == -1 && c > a)
		{
			s = sqrt(double(c * c - a * a));
			cout << "b = " << fixed << setprecision(3) << s << endl << endl;
		}
		else
		{
			cout << "Impossible." << endl << endl;
			continue;
		}
	}

	return 0;
}	///:~