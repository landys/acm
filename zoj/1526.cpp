// AC

#include <iostream>
//#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	//ifstream cin("input.txt");
	int re = 0;
	cin >> re;
	while (--re >= 0)
	{
		int n = 0;
		double s = 0;
		cin >> n;
		for (int j=2; j<=n; j++)
		{
			s += log10(double(j));
		}
		int t = int(s) + 1;
		cout << t << endl;
	}

	return 0;
}	///:~