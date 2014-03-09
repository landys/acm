// AC

#include <iostream>
#include <iomanip>
#include <cmath>
// #include <fstream>
using namespace std;

bool isprime(int m, int n)
{
	if (m < n)
	{
		n ^= m ^= n ^= m;
	}
	while (m % n != 0)
	{
		int t = n;
		n = m % n;
		m = t;
	}
	return (n == 1);
}

int main()
{
	// ifstream cin("input.txt");

	int n;
	while (cin >> n && n != 0)
	{
		int a[50] = {0};
		for (int i=0; i<n; i++)
		{
			cin >> a[i];
		}

		int k = 0;
		for (int ii=0; ii<n-1; ii++)
		{
			for (int jj=ii+1; jj<n; jj++)
			{
				if (isprime(a[ii], a[jj]))
				{
					k++;
				}
			}
		}

		if (k == 0)
		{
			cout << "No estimate for this data set." << endl;
		}
		else
		{
			cout << fixed << setprecision(6) << sqrt((double(n)*double(n-1)*3)/k) << endl;
		}
	}

	return 0;
}	///:~