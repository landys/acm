// AC

#include <iostream>
// #include <fstream>
using namespace std;

inline int digit(int n)
{
	int s = 0;
	while (n != 0)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main()
{
	// ifstream cin("input.txt");
	char a[10000];

	while (cin.getline(a, 10000) && a[0] != '0')
	{
		int n = 0;
		int i = 0;
		while (a[i] != '\0')
		{
			n += a[i++] - '0';
		}
		while (n / 10 != 0)
		{
			n = digit(n);
		}
		cout << n << endl;
	}

	return 0;
}	///:~