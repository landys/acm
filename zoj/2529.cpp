// AC

#include <iostream>
//#include <fstream>
#include <string>

using namespace std;

const int SIZE = 25;
int radices[SIZE];

bool isPrime(int n)
{
	if (n == 1)
	{
		return false;
	}
	for (int i=2; i<n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

void setRadices()
{
	int n = 1;
	for (int i=0; i<SIZE; i++)
	{
		while (!isPrime(++n));
		radices[i] = n;
		//cout << n << endl;
	}
	
}

void print(int* a, int n)
{
	int i = n - 1;
	while (i > 0 && a[i] == 0)
	{
		i--;
	}
	cout << a[i];
	for (i--; i>=0; i--)
	{
		cout << "," << a[i];
	}
	cout << endl;
}

void str2array(const string& str, int* a)
{
	int n = str.length();
	int i = n - 1;
	int k = 1;
	int t = 0;
	int j = 0;
	while (i >= 0)
	{
		if(str[i] != ',')
		{
			t += k * (str[i] - '0');
			k *= 10;
		}
		else
		{
			a[j++] = t;
			k = 1;
			t = 0;
		}
		i--;
	}
	a[j] = t;
}

void addHog(int* a, int* b, int* c, int n)
{
	int k = 0;
	for (int i=0; i<n; i++)
	{
		c[i] = a[i] + b[i] + k;
		if (c[i] >= radices[i])
		{
			c[i] -= radices[i];
			k = 1;
		}
		else
		{
			k = 0;
		}
	}
}

int main()
{
	//ifstream cin("input.txt");
	setRadices();
	
	string sa;
	string sb;
	while (cin >> sa >> sb)
	{
		//cout << sa << endl << sb << endl;
		int a[SIZE+1] = {0};
		int b[SIZE+1] = {0};
		int c[SIZE+1] = {0};
 		str2array(sa, a);
// 		print(a, SIZE+1);
 		str2array(sb, b);
// 		print(b, SIZE+1);
		addHog(a, b, c, SIZE+1);
		print(c, SIZE+1);
	}
	
	return 0;
}
