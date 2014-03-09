// AC

#include <iostream>
using namespace std;

int main(void)
{
	int a[31];
	a[0] = 1;
	for (int i=1; i<31; i++)
	{
		a[i] = a[i-1]*2;
	}	
	int n = 0;
	cin >> n;
	while (n > 0)
	{
		int i = 0;
		for (i=0; i<31; i++)
		{
			if (a[i] >= n)
			{
				cout << i << endl;
				break;
			}
		}
		if (i == 31)
		{
			cout << 31 << endl;
		}
		cin >> n;
	}
	
	return 0;
}
