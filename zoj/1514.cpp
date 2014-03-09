// AC

#include <iostream>
// #include <fstream>
#include <cstring>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int m, n;
	while (cin >> n >> m && n != 0)
	{
		int *a = new int[n+1];
		for (int j=0; j<n+1; j++)
		{
			a[j] = 0;
		}
		
		int num;
		int t = 0;
		for (int i=0; i<m; i++)
		{
			cin >> num;
			if (a[num] == 0)
			{
				a[num] = 1;
			}
			else if (a[num] == 1)
			{
				t++;
				a[num] = 2;
			}
		}
		cout << t << endl;
	}

	return 0;
}	///:~