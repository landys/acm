// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int re;
	cin >> re;
	while (--re >= 0)
	{
		int m, n;
		cin >> m >> n;

		if (m < n)
		{
			cout << "NO BRAINS" << endl;
		}
		else
		{
			cout << "MMM BRAINS" << endl;
		}
	}

	return 0;
}	///:~