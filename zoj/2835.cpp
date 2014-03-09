// AC

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main()
{
	//ifstream cin("input.txt");
	
	int n;
	int i, j;
	
	cin >> n;
	while (n != 0)
	{
		int a[10][10] = {0};
		set<int> s;
		bool f = true;
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				cin >> a[i][j];	
				if (f)
				{
					if (s.find(a[i][j]) != s.end())
					{
						f = false;
					}
					else
					{
						s.insert(a[i][j]);
					}
				}
			}
		}
		if (!f)
		{
			cout << "No" << endl;
			cin >> n;
			continue;
		}

		int sum = 0;
		int sum2 = 0;
		for (i=0; i<n; i++)
		{
			sum += a[i][i];	
			sum2 += a[i][n-1-i];
		}
		if (sum != sum2)
		{
			cout << "No" << endl;
			cin >> n;
			continue;
		}

		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				a[i][n] += a[i][j];
				a[n][j] += a[i][j];
			}
		}
		for(i=0; i<n; i++)
		{
			if (a[i][n] != sum)
			{
				f = false;
				break;
			}
			if (a[n][i] != sum)
			{
				f = false;
				break;
			}
		}
		if (f)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		cin >> n;
	}
	
	return 0;
}
