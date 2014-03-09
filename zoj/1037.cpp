// AC

#include <iostream>
// #include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int re = 0;
	cin >> re;
	int count = 0;
	while (--re >= 0)
	{
		count++;

		int m, n;
		cin >> m >> n;
		double s = 0.0;
		if (m % 2 == 0 || n % 2 == 0)
		{
			s = m * n;
		}
		else
		{
			s = m * n + 0.414;
		}
		cout << "Scenario #" << count << ":" << endl;
		cout << fixed << setprecision(2) << s << endl << endl;
	}

	return 0;
}	///:~