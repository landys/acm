// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// fstream cin("input.txt");
	int n;
	while (cin >> n)
	{
		int t = 0;
		int k = 1;
		int kk = 0;
		for (int i=0; i<n; i++)
		{
			cin >> kk;
			if (kk != k)
			{
				t++;
			}
			k = (k == 0);
		}
		cout << ((t > n - t) ? (n - t) : t) << endl;
	}

	return 0;
}	///:~