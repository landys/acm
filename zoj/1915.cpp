// Accept

#include <iostream>
using namespace std;

int main()
{
	int re;
	cin >> re;
	while (--re >= 0)
	{
		int n;
		int s = 0;
		cin >> n;
		int *a = new int[n];
		for (int i=0; i<n; i++)
		{
			cin >> a[i];
			s += a[i];
		}
		int aver = s / n;
		int k = 0;
		for (int j=0; j<n; j++)
		{
			if (a[j] > aver)
			{
				k++;
			}
		}

		printf("%.3f%%\n", float(100 * k) / float(n));
	}

	return 0;
}	///:~
