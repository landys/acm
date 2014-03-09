// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int row, col, entry;
	while (cin >> row >> col >> entry && row != 0)
	{
		char a[10][10];
		int b[10][10];
		for (int i=0; i<row; i++)
		{
			for (int j=0; j<col; j++)
			{
				cin >> a[i][j];
				b[i][j] = 0;
			}
		}

		int ii = 0;
		int jj = entry - 1;
		int t = 0;
		int k = 0;
		bool flag = true;
		while (flag)
		{
			t++;
			if (b[ii][jj] != 0)
			{
				k = t - b[ii][jj];
				t = b[ii][jj] - 1;
				break;
			}
			b[ii][jj] = t;
			switch (a[ii][jj])
			{
			case 'N':
				if (ii == 0)
				{
					flag = false;
					break;
				}
				ii--;
				break;
			case 'S':
				if (ii == row - 1)
				{
					flag = false;
					break;
				}
				ii++;
				break;
			case 'W':
				if (jj == 0)
				{
					flag = false;
					break;
				}
				jj--;
				break;
			case 'E':
				if (jj == col - 1)
				{
					flag = false;
					break;
				}
				jj++;
				break;
			}
		}

		if (!k)
		{
			cout << t << " step(s) to exit" << endl;
		}
		else
		{
			cout << t << " step(s) before a loop of " << k << " step(s)" << endl;
		}
	}

	return 0;
}	///:~