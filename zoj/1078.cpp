// AC

#include <iostream>
using namespace std;

int check(int n, int i);

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		int flag = 0;
		for (int i=2; i<=16; i++)
		{
			if(!check(n, i))
			{
				continue;
			}
			flag++;
			if (flag == 1)
			{
				cout << "Number " << n <<" is palindrom in basis " << i;	
			}
			else if (flag > 1)
			{
				cout << " " << i;
			}
		}
		if (!flag)
		{
			cout << "Number " << n << " is not a palindrom";
		}
		cout << endl;
	}

	return 0;
}

int check(int n, int i)
{
	int c[16];
	int count = 0;
	int j = 0;
	
	while (n != 0)
	{
		c[j++] = n % i;
		n = n / i;
	}

	for (int t=0; t<j/2; t++)
	{
		if (c[t] != c[j-1-t])
		{
			return 0;
		}
	}
	return 1;
}
