// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int n;
	while (cin >> n && n != 0)
	{
		int row = -1, col = -1;
		int num;
		bool flag = true;
		int *a = new int[n];
		for (int ii=0; ii<n; ii++)
		{
			a[ii] = 0;
		}
		int i = 0;
		for (i=0; i<n; i++)
		{
			int s = 0;
			for (int j=0; j<n; j++)
			{
				cin >> num;
				s += num;
				a[j] += num;
			}
			if (s % 2 != 0)
			{
				if (row != -1)
				{
					flag = false;
					break;
				}
				row = i;
			}
		}
		while (++i < n)
		{
			cin.ignore(101, '\n');
		}

		if (flag)
		{
			for (int jj=0; jj<n; jj++)
			{
				if (a[jj] % 2 != 0)
				{
					if (row == -1 || col != -1)
					{
						flag = false;
						break;
					}
					col = jj;
				}
			}
		}

		if (flag)
		{
			if (row == -1)
			{
				cout << "OK" << endl;
			}
			else
			{
				cout << "Change bit (" << row+1 << "," << col+1 << ")" << endl;
			}
		}
		else
		{
			cout << "Corrupt" << endl;
		}

		delete []a;
	}

	return 0;
}	///:~