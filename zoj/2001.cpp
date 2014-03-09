// Accept

#include <iostream>
using namespace std;

int reverse(int n)
{
	if (n == 0)
	{
		return 0;
	}

	while (n % 10 == 0)
	{
		n /= 10;
	}

	int m = 0;
	while (n != 0)
	{
		m = (m * 10 + n % 10);
		n /= 10;
	}

	return m;
}

int main()
{
	int re;
	cin >> re;

	while (--re >= 0)
	{
		int m, n;
		cin >> m >> n;
		int s = reverse(m) + reverse(n);
		cout << reverse(s) << endl;
	}

	return 0;
}	///:~