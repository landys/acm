// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	const double pi = 3.1415926;
	int re = 0;
	cin >> re;
	int count = 0;
	while (--re >= 0)
	{
		count++;
		double x = 0.0, y = 0.0;
		cin >> x >> y;
		double s = pi * (x * x + y * y) / 2;
		int n = int(s / 50) + 1;

		cout << "Property " << count << ": This property will begin eroding in year " << n << ".\n";
	}
	cout << "END OF OUTPUT." << endl;

	return 0;
}	///:~