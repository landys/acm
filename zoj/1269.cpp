// WA

#include <iostream>
// #include <fstream>
using namespace std;

bool coconut(int n, int k)
{
	bool flag = true;
	for (int i=0; i<k; i++)
	{
		if (n < 2 || (n - 1) % k != 0)
		{
			flag = false;
			break;
		}
		n = n - 1 - (n - 1) / k;
	}
	if (flag && (n % k != 0 || n == 0))
	{
		flag = false;
	}

	return flag;
}

int main()
{
	// ifstream cin("input.txt");
	int n;
	while (cin >> n && n != -1)
	{
		for (int i=2; i<=n-3*i; i++)
		{
			if (coconut(n, i))
			{
				cout << n << " coconuts, " << i << " people and 1 monkey" << endl;
				break;
			}
		}
		if (i > n - 3 * i)
		{
			cout << n << " coconuts, no solution" << endl;
		}
	}

	return 0;
}