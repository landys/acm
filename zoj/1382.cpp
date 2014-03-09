// AC

#include <iostream>
using namespace std;

int main()
{
	int re;
	cin >> re;
	while (--re >= 0)
	{
		int n;
		cin >> n;
		int k = 0;
		while (n % 2 == 0)
		{
			k++;
			n /= 2;
		}

		cout << n << " " << k << endl;
	}

	return 0;
}	///:~