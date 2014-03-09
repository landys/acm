// AC
// make an exact array of the parentheses then look back for left parentheses for each right parentheses

#include <iostream>
//#include <fstream>
using namespace std;

int main(void)
{
	//ifstream cin("input.txt");
	int m, n;
	
	int a[40];	// 0--(   1--)   2--matched (
	cin >> m;
	while (--m >= 0)
	{
		cin >> n;
		int t = 0;
		int t1 = 0;
		int top = -1;
		for (int i=0; i<n; i++)
		{
			cin >> t;
			int c = t - t1;
			for (int j=0; j<c; j++)
			{
				a[++top] = 0;
			}
			t1 = t;
			a[++top] = 1;
			int count = 1;
			for (int j=top-1; j>=0; j--)
			{
				if (a[j] == 0)
				{
					a[j] = 2;
					break;
				}
				else if (a[j] == 1)
				{
					count++;
				}
			}
			if (i != n-1)
			{
				cout << count << " ";
			}
			else
			{
				cout << count << endl;
			}
		}
	}
	
	return 0;
}
