// AC

#include <iostream>
// #include <fstream>
#include <cmath>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int re = 0, n = 0;
	cin >> re;
	while (--re >= 0)
	{
		cin >> n;
		cout << int(sqrt(double(n))) << endl;
	}

	return 0;
}	///:~