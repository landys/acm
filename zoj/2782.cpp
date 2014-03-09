// AC

#include <iostream>
//#include <fstream>
#include <string>

using namespace std;

int main()
{
	//fstream cin("input.txt");

	int c = 0;
	cin >> c;
	string a[20];
	string b[20];
	bool fa[20];
	bool fb[20];
	int i, j;
	while (--c >= 0)
	{
		int m, n;
		cin >> m >> n;
		
		for (i=0; i<m; i++)
		{
			cin >> a[i];
		}
		for (i=0; i<m; i++)
		{
			fa[i] = false;
			fb[i] = false;
		}
		int ai, bi;
		for (i=0; i<n; i++)
		{
			cin >> ai >> bi;
			fa[--ai] = true;
			fb[--bi] = true;
			b[bi] = a[ai];
		}
		for (i=0, j=-1; i<m; i++)
		{
			if (!fa[i])
			{
				while (fb[++j]);
				b[j] = a[i];
			}
		}

		for (i=0; i<m-1; i++)
		{
			cout << b[i] << " ";
		}
		cout << b[i] << endl;
	}

	return 0;
}
