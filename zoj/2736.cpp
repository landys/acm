// AC

#include <iostream>
#include <string>

using namespace std;

bool isDaffodil(int n)
{
	int sum = n;
	while (n / 10 != 0)
	{
		int t = n % 10;
		sum -= t * t * t;
		n /= 10;
	}
	return sum == n * n * n;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (isDaffodil(n))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	
	return 0;
}