// AC

// enumerate + greedy

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int a[5][6];
int r[5][6];

void press(int i, int j)
{
	r[i][j] = 1;
	a[i][j] ^= 1;
	if (i>0)
	{
		a[i-1][j] ^= 1;
	}
	if (i<4)
	{
		a[i+1][j] ^= 1;
	}
	if (j>0)
	{
		a[i][j-1] ^= 1;
	}
	if (j<5)
	{
		a[i][j+1] ^= 1;
	}
}

void print(int c)
{
	cout << "PUZZLE #" << c << endl;
	for (int i=0; i<5; i++)
	{
		cout << r[i][0];
		for (int j=1; j<6; j++)
		{
			cout << " " << r[i][j];
		}
		cout << endl;
	}
}

// void print()
// {
// 	cout << "************" << endl;
// 	for (int i=0; i<5; i++)
// 	{
// 		cout << a[i][0];
// 		for (int j=1; j<6; j++)
// 		{
// 			cout << " " << a[i][j];
// 		}
// 		cout << endl;
// 	}
// 	
// }

int main()
{
//	ifstream cin("input.txt");
	int n;
	cin >> n;
	int i, j, k;
	int t[5][6];
	for (int c=1; c<=n; c++)
	{
		for (i=0; i<5; i++)
		{
			for (j=0; j<6; j++)
			{
				cin >> t[i][j];
			}
		}
		for (k=0; k<64; k++)	// enumerate 64 press of first line
		{
			copy((int*)t, (int*)t+5*6, (int*)a);
			fill((int*)r, (int*)r+5*6, 0);

			for (j=0; j<6; j++)
			{
				if ((k & (1 << j)) != 0)
				{
					press(0, j);
				}
			}
// 			print();
// 			print(c);
			for (i=1; i<5; i++)
			{
				for (j=0; j<6; j++)
				{
					if (a[i-1][j] != 0)
					{
						press(i, j);
					}
				}
			}
// 			print();
// 			print(c);
			if (find((int*)a+4*6, (int*)a+5*6, 1) == (int*)a+5*6)
			{
				print(c);
				break;
			}
		}
	}

	return 0;
}
