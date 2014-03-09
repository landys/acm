// AC

#include <iostream>
//#include <fstream>
#include <string>
using namespace std;

int main()
{
	//ifstream cin("input.txt");

	string s = "";
	string t = "";

	while (cin >> s >> t)
	{
		int ns = s.length();
		int nt = t.length();
		if (ns > nt)
		{
			cout << "No" << endl;
			continue;
		}

		int j = 0;
		for (int i=0; i<nt; i++)
		{
			if (s[j] == t[i])
			{
				j++;
				if (j == ns)
				{
					break;
				}
			}
		}
		if (j == ns)
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