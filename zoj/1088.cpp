// Accept

#include <iostream>
using namespace std;

bool cut_off(const int& n, const int& m, const int& last)
{
	int *a = new int[n];
	for (int i=0; i<n-1; i++)
	{
		a[i] = i + 1;
	}
	a[n-1] = 0;

	bool flag = true;
	int k = n - 1;
	int j = 0;
	while (a[j] != j)
	{
		if (j == last)
		{
			flag = false;
			break;
		}
		a[k] = a[j];
		for (int t=0; t<m; t++)
		{
			k = j;
			j = a[j];
		}
	}

	delete []a;
	return flag;
}

int main()
{
	int n;
	while (cin >> n && n > 0)
	{
		int m;
		for (m=2; !cut_off(n, m, 1); m++);
		cout << m << endl;
	}

	return 0;
}	///:~