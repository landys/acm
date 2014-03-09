#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		int m;
		cin >> m;
		
		int t=0;
		while (m > 0)
		{
			if (m & 1)
			{
				cout << t << ((m >> 1) > 0 ? ' ' : '\n');
			}
			t++;
			m >>= 1;
		}
	}

	return 0;
}