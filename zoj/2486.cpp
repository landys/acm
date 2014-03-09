#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool divide(int* p, int& len, int n)
{
	bool ff = false;
	int c = 0;
	int temp[102] = {0};
	int tmp_len = len;
	for (int i=len-1; i>=0; i--)
	{
		temp[i] = p[i];
		int k = c * 10 + p[i];
		p[i] = k / n;
		if (!ff && p[i] == 0)
		{
			ff = true;
			len--;
		}
		c = k % n;
	}
	if (c != 0)
	{
		len = tmp_len;
		for (int j=0; j<len; j++)
		{
			p[j] = temp[j];
		}
	}
	return c == 0;
}

int main()
{
	ifstream cin("input.txt");
	int n = 0;
	while (cin >> n)
	{
		string ss = "";
		cin >> ss;
		int p[102] = {0};
		int len = ss.length();
		for (int i=0; i<len; i++)
		{
			p[len-1-i] = ss[i] - '0';
		}
		
		int k = 1;
		for (int j=2; !(len==1 && p[0]==1); j++)
		{
			if (divide(p, len, j))
			{
				k *= j;
				for (int jj=0; jj<n-1; jj++)
				{
					divide(p, len, j);
				}
				j--;
			}
		}
		cout << k << endl;
	}

	return 0;
}	//:~