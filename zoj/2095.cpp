// Time Limit Exceeded

/* #include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int re;
	cin >> re;

	while (--re >= 0)
	{
		int n;
		cin >> n;
		
		int sum = 1;

		int i = 1;
		int m = sqrt(n);
		while (n % (++i) != 0 && i <= m);
		if (i == m + 1)
		{
			cout << sum << endl;
			continue;
		}
		else
		{
			sum += i;
		}
	
		int k = n / i;
		for (++i; i<=k; i++)
		{
			if (n % i == 0)
			{
				sum += i;
			}
		}
		
		cout << sum << endl;
	}

	return 0;
} */	///:~