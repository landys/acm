// Accept

#include <iostream>
#include <cmath>
using namespace std;

int sum(long n)
{
	int sum = 0;

	while (n / 10 != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	sum += n;

	return sum;
}

bool prime(const long& n)
{
	long k = (long)sqrt(double(n));
	bool flag = true;

	for (long j=2; j<=k; j++)
	{
		if (n % j == 0)
		{
			flag = false;
			break;
		}
	}
	
	return flag;
}

bool smith(long n)
{
	if (prime(n))
	{
		return false;
	}

	long k = (long)sqrt(double(n));
	int s = sum(n);
	bool flag = true;
	for (long i=2; i<=k && s>0; i++)
	{
		while (n % i == 0)
		{
			s -= sum(i);
			n /= i;
		}
	}
	if (n != 1 && s > 0)
	{
		s -= sum(n);
		n = 1;
	}
	if (s != 0 || n != 1)
	{
		flag = false;
	}
	
	return flag;
}


int main()
{
	long n = 0;

	while (cin >> n && n != 0)
	{
		while (!smith(++n));
		cout << n << endl;
	}

	return 0;
}
