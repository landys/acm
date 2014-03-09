// WA, too big integer

#include <iostream>
#include <fstream>
using namespace std;

long long int a[101] = {0};
bool flag[101];

long long int f(int n)
{
	if (flag[n])
	{
		return a[n];
	}
	else
	{
		long long int k = 0;
		for (int i=0; i<n/2; i++)
		{
			k += 2 * f(i) * f(n-1-i);
		}
		if (n % 2 != 0)
		{
			k += f(n/2) * f(n/2);
		}
		a[n] = k;
		flag[n] = true;
		return k;
	}
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	
	for (int i=2; i<101; i++)
	{
		flag[i] = false;
	}
	a[0] = 1;
	a[1] = 1;
	flag[0] = true;
	flag[1] = true;

	int n = 0;
	while (cin >> n && n != -1)
	{
		cout << f(n) << endl;
	}
	return 0;
}
