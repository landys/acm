#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream cin("input.txt");

	int a[16] = {0};
	int b[15] = {0};
	int n = 0;

	while (cin >> a[n] && a[n] != -1)
	{
		n++;
		if (a[n] == 0)
		{
			sort(a, n);
			int ja = 0;
			int jb = 0;
			for (int i=0; i<n-1; i++)
			{
				for (int jj=ja; jj<jb; jj++)
				{
					if (a[i] * 2 < a[jj])
					{
						ja = jj;
					}
					if (a[i] * 2 == a[jj])
					{
					}
				}
				b[j] = a[i] * 2;
				if (b[j] > a[n-1])
				{

				}
			}
		}
	}
}	///:~