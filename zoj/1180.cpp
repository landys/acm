// Accept

#include <iostream>
using namespace std;

inline long f(long j)
{
	long sum = j;

	while (j / 10 > 0)
	{
		sum += j % 10;
		j /= 10;
	}
	sum += j;

	return sum;
}


int main(void)
{
	int *a = new int[1000001];
	long i;

	for (i=1; i<=1000000; i++)
	{
		a[i] = 0;
	}

	for (i=1; i<=1000000; i++)
	{
		if (a[i] == 0)
		{
			cout << i << endl;
			long j = i;
			while (true)
			{
				j = f(j);
				if (j > 1000000 || a[j] == 1)
				{
					break;
				}
				a[j] = 1;
			}
		}
	}

	return 0;
}