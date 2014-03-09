// AC

// #include <fstream>
#include <iostream>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int n;
	while (cin >> n && n > 0)
	{
		int u, d;
		cin >> u >> d;

		if ((n -= u) <= 0)
		{
			cout << 1 << endl;
			continue;
		}

		int t = 1;
		double temp = double(n) / (u - d);
		t += 2 * int(temp);
		if (temp - int(temp) > 1e-14)
		{
			t += 2;
		}
		cout << t << endl;
	}

	return 0;
}	//:~