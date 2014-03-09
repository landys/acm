// AC

#include <iostream>
// #include <fstream>
#include <string>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	string str = "";
	const double pi = 3.14159;
	while (cin >> str && str != "ENDOFINPUT")
	{
		int r, n, a;
		cin >> r >> n >> a;
		if (a > 180)
		{
			a = 360 - a;
		}
		if (a == 0)
		{
			cout << "YES " << n << endl;
			cin >> str;
			continue;
		}

		double d = pi * r * a / 180 * 2;
		int s = 5 * n;
		if (d <= s)
		{
			cout << "YES " << n - 1 - int(d / 5) << endl;
		}
		else
		{
			cout << "NO " << s << endl;
		}
		cin >> str;
	}

	return 0;
}	///:~