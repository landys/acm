// AC

#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
	//ifstream cin("input.txt");

	int n = 0;
	int imax = 0;
	int hum[5842] = {1, 0};
	int p[] = {2, 3, 5, 7};
	int ih[4] = {0};
	while (cin >> n && n != 0)
	{
		while (imax < n - 1)
		{
			int min = 2000000001;
			for (int i=0; i<4; i++)
			{
				if (hum[ih[i]] * p[i] <= hum[imax])
				{
					ih[i]++;
				}
				if (min > hum[ih[i]] * p[i])
				{
					min = hum[ih[i]] * p[i];
				}
			}
			hum[++imax] = min;
		}

		cout << "The " << n;
		if (n % 100 != 11 && n % 10 == 1)
		{
			cout << "st";
		}
		else if (n % 100 != 12 && n % 10 == 2)
		{
			cout << "nd";
		}
		else if (n % 100 != 13 && n % 10 == 3)
		{
			cout << "rd";
		}
		else
		{
			cout << "th";
		}
		cout << " humble number is " << hum[n-1] << ".\n";
	}

	return 0;
}