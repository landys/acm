// AC

#include <iostream>
using namespace std;

int f(int n, int k)
{
	int s = 0;
	while (n != 0)
	{
		s += n % k;
		n /= k;
	}

	return s;
}

int main()
{
	for (int n=2992; n<=9999; n++)
	{
		int m = f(n, 10);
		if (m == f(n, 16) && m == f(n, 12))
		{
			cout << n << endl;
		}
	}

	return 0;
}	///:~