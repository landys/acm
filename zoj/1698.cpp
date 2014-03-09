// AC

#include <iostream>
//#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void print(const string& ss, bool f)
{
	if (f)
	{
		cout << "<" << ss << "> is acceptable." << endl;
	}
	else
	{
		cout << "<" << ss << "> is not acceptable." << endl;
	}
}

int main()
{
	//ifstream cin("input.txt");

	string ss;
	char a[] = {'a', 'e', 'i', 'o', 'u'};

	cin >> ss;
	while (ss != "end")
	{
		bool flag1 = false;
		int f[2] = {0};
		int fi = 0;
		char t = '\0';
		for (int i=0; i<ss.length(); i++)
		{
			if (find(a, a+5, ss[i]) != a+5)
			{
				flag1 = true;
				if (fi == 1)
				{
					f[fi] = 0;
					fi = 0;
				}
				if (++f[fi] == 3)
				{
					break;
				}
			}
			else
			{
				if (fi == 0)
				{
					f[fi] = 0;
					fi = 1;
				}
				if (++f[fi] == 3)
				{
					break;
				}
			}
			if (t == ss[i])
			{
				if (!(t == 'e' || t == 'o'))
				{
					f[0] = 3;
					break;
				}
			}
			t = ss[i];
		}

		print(ss, flag1 && (f[0] != 3) && (f[1] != 3));

		cin >> ss;
	}
	return 0;
}
