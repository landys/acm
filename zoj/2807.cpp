// AC

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (--n >= 0)
	{
		int k;
		cin >> k;
		int* a = new int[k];
		for (int i=0; i<k; i++)
		{
			cin >> a[i];
		}
		cout << accumulate(a, a+k, 0)-k+1 << endl;
	}
	return 0;
}
