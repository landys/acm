// AC

#include <iostream>
// #include <fstream>
#include <string>
using namespace std;

void convert(int* a, const string& s)
{
	for (int i=0; i<s.length(); i++)
	{
		a[i] = s[i] - '0';
	}
}

bool divide(int* a, int n, int b)
{
	int x = 0;
	for (int j=0; j<n; j++)
	{
		x += a[j];
	}
	int carryin = 0;
	for (int i=0; i<n; i++)
	{
		a[i] += carryin * b;
		carryin = a[i] % x;
		a[i] /= x;
	}
	
	return (carryin == 0);
}
	
int main()
{
	// ifstream cin("input.txt");
	int re = 0;
	cin >> re;
	while (--re >= 0)
	{
		int b = 0;
		while (cin >> b && b != 0)
		{
			string s = "";
			cin >> s;
			int *a = new int[s.length()];
			convert(a, s);
			if (divide(a, s.length(), b))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
			delete []a;
		}
		if (re != 0)
		{
			cout << endl;
		}
	}

	return 0;
}	///:~