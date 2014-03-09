// Accept
// But something wrong, contain 1 as prime number in the problem

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, c;
	int a[500];

	while (cin >> n >> c)
	{
		cout << n << " " << c << ":";
		int count = 0;
		for (int i=1; i<=n; i++)
		{
			int k = sqrt(double(i));
			bool flag = true;
			for (int j=2; j<=k; j++)
			{
				if (i % j == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				a[count++] = i;
			}
		}
		if (count % 2 == 0)
		{
			if (c * 2 >= count)
			{
				for (int t=0; t<count; t++)
				{
					cout << ' ' << a[t];
				}
			}
			else
			{
				for (int t=count/2-c; t<count/2+c; t++)
				{
					cout << ' ' << a[t];
				}
			}
		}
		else
		{
			if (c * 2 - 1 >= count)
			{
				for (int t=0; t<count; t++)
				{
					cout << ' ' << a[t];
				}
			}
			else
			{
				for (int t=(count+1)/2-c; t<(count-1)/2+c; t++)
				{
					cout << ' ' << a[t];
				}
			}
		}
		cout << "\n\n";
	}

	return 0;
}	///:~