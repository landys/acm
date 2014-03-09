// AC

#include <iostream>
//#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

#define PRIME_NUM 3512
const int MAX_NUM = 32767;

bool isPrime(int n) // n>=2
{
	int k = (int)(sqrt(double(n)));
	for (int i=2; i<=k; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	//ifstream cin("input.txt");

	int i;
	int n = 0;
	int pr[PRIME_NUM] = {0};
	for (i=2; i<=MAX_NUM; i++)
	{
		if (isPrime(i))
		{
			pr[n++] = i;
		}
	}

	int m;
	cin >> m;
	while (m != 0)
	{
		int k = 0;
		for (int i=0; i<n && pr[i]<=m/2; i++)
		{
			if (find(pr+i, pr+n, m-pr[i]) != pr+n)
			{
				k++;
			}
		}
		cout << k << endl;
		cin >> m;
	}

	return 0;
}
