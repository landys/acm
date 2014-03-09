// AC

// #include <fstream>
#include <iostream>
using namespace std;

int main()
{
	// fstream cin("input.txt");
	int n;
	while (cin >> n && n > 0)
	{
		int a = 0;
		int b = 0;
		int t = n * 5;
		for (int i=0; i<n; i++)
		{
			cin >> b;
			if (a < b)
			{
				t += (b - a) * 6;
			}
			else if (a > b)
			{
				t += (a - b) * 4;
			}
			a = b;
		}

		cout << t << endl;
	}

	return 0;
}	///:~