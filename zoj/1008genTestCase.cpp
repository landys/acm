#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void genTestCase(int n, ofstream& out)
{
	int a[5][5][4];
	out << n << endl;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (i==0 && j==0)
			{
				a[i][j][0] = abs(rand()) % 10;
				a[i][j][1] = a[i][j][0];//abs(rand()) % 10;
				a[i][j][2] = a[i][j][0];//abs(rand()) % 10;
				a[i][j][3] = a[i][j][0];//abs(rand()) % 10;
			}
			else if (i == 0)
			{
				a[i][j][3] = a[i][j-1][1];
				a[i][j][0] = a[i][j][3];//abs(rand()) % 10;
				a[i][j][1] = a[i][j][0];//abs(rand()) % 10;
				a[i][j][2] = a[i][j][0];//abs(rand()) % 10;
				
			}
			else if (j == 0)
			{
				a[i][j][0] = a[i-1][j][2];
				a[i][j][1] = abs(rand()) % 10;
				a[i][j][2] = a[i][j][0];//abs(rand()) % 10;
				a[i][j][3] = abs(rand()) % 10;
			}
			else
			{
				a[i][j][0] = a[i-1][j][2];
				a[i][j][1] = abs(rand()) % 10;
				a[i][j][2] = abs(rand()) % 10;
				a[i][j][3] = a[i][j-1][1];
			}
		}
	}
	for (int j=n-1; j>=0; j--)
	{
		for (int i=n-1; i>=0; i--)
		{
			for (int t=0; t<4; t++)
			{
				out << a[i][j][t];
				if (t == 3)
				{
					out << endl;
				}
				else
				{
					out << " ";
				}
			}
		}
	}
}

int main(void)
{
	ofstream out("autoinput.txt");
	for (int i=0; i<100; i++)
	{
		for (int j=1; j<=5; j++)
		{
			genTestCase(j, out);
		}
	}
	out << 0 << endl;

	return 0;
}
