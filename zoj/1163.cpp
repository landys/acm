// AC

#include <iostream>
//#include <fstream>
#include <iomanip>

using namespace std;

double a[501][32] = {0};
int b[33] = {0};

double unit_calc(int n, int m);

double calc(int n)
{
	int k = 0;
	for (k=0; b[k]<=n; k++);
	//k--;
	//cout << k << endl;
	double re = 0;
	for (int i=2; i<k; i++)
	{
		re += unit_calc(n, i);
	}
	return re;
}

// n bricks with m columns
double unit_calc(int n, int m)
{
	if (a[n][m] > 0)
	{
		return a[n][m];
	}
	
	if (n < b[m])
	{
		return 0;
	}

	if (m == 2)
	{
		a[n][m] = (n-1)/2;
		return a[n][m];
	}

	if (a[n-m][m-1] == 0)
	{
		a[n-m][m-1] = unit_calc(n-m, m-1);
	}
	if (a[n-m][m] == 0)
	{
		a[n-m][m] = unit_calc(n-m, m);
	}
	
	a[n][m] = a[n-m][m-1] + a[n-m][m];
	return  a[n][m];
}

int main()
{
	//ifstream cin("input.txt");

	int n;
	cin >> n;
	
	int i;
	for (i=1; i<33; i++)
	{
		b[i] = b[i-1] + i;
		//cout << b[i] << endl;
	}

	while (n != 0)
	{
		cout << fixed << setprecision(0) << calc(n) << endl;
		cin >> n;
	}
	
	return 0;
}
