// AC

#include <iostream>
// #include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int re = 0;
	cin >> re;
	while (--re >= 0)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		string* s = new string[m];
		int* a = new int[m];
		for (int k=0; k<m; k++)
		{
			a[k] = 0;
		}
		for (int i=0; i<m; i++)
		{
			cin >> s[i];
			for (int j=0; j<n-1; j++)
			{
				for (int jj=j+1; jj<n; jj++)
				{
					if (s[i][j] > s[i][jj])
					{
						a[i]++;
					}
				}
			}
		}

		int* b = new int[m];
		for (int ii=0; ii<m; ii++)
		{
			b[ii] = ii;
		}
		for (int j=1; j<m; j++)
		{
			int temp = a[j];
			int btemp = b[j];
			int jj = 0;
			for (jj=j-1; jj>=0&&temp<a[jj]; jj--)
			{
				a[jj+1] = a[jj];
				b[jj+1] = b[jj];				
			}
			a[jj+1] = temp;
			b[jj+1] = btemp;
		}

		for (int t=0; t<m; t++)
		{
			cout << s[b[t]] << endl;
		}
		if (re != 0)
		{
			cout << endl;
		}
		delete []a;
		delete []b;
		delete []s;
	}

	return 0;
}	///:~