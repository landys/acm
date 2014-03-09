// AC

#include <iostream>
// #include <fstream>
#include <string>
// #include <cstring>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");
	string s1 = "";
	string s2 = "";
	while (cin >> s1 >> s2)
	{
		char s[200];
		// memset(s, '\0', 200);
		for (int ii=0; ii<200; ii++)
		{
			s[ii] = '\0';
		}
		
		int k = 198;
		int in = 0;
		for (int i=s1.length()-1, j=s2.length()-1; i>=0 || j>=0; i--, j--)
		{
			int x = 0, y = 0;
			if (i < 0)
			{
				x = 0;
			}
			else if (s1[i] <= '9' && s1[i] >= '0')
			{
				x = s1[i] - '0';
			}
			else
			{
				x = s1[i] - 'a' + 10;
			}
			if (j < 0)
			{
				y = 0;
			}
			else if (s2[j] <= '9' && s2[j] >= '0')
			{
				y = s2[j] - '0';
			}
			else
			{
				y = s2[j] - 'a' + 10;
			}
			int z = x + y + in;
			in = 0;
			if (z >= 20)
			{
				z -= 20;
				in = 1;
			}
			if (z <= 9)
			{
				s[k] = char(z + '0');
			}
			else
			{
				s[k] = char(z - 10 + 'a');
			}
			k--;
		}
		if (in == 1)
		{
			s[k--] = '1';
		}
		while (s[++k] == '0');
		if (k == 199)
		{
			cout << '0' << endl;
		}
		else
		{
			// cout << &s[k] << endl;
			while (s[k] != '\0')
			{
				cout << s[k++];
			}
			cout << endl;
		}
	}

	return 0;
}	///:~