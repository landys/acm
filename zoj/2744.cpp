// Time Limit Exceeded

#include <iostream>
#include <fstream>
#include <string>
//#include <algorithm>
//#include <iterator>

using namespace std;

int main()
{
	//ifstream cin("input.txt");

	string s;
	while (cin >> s)
	{
		int n = s.length();
		int re = n;
		for (int i=2; i<=n; i++)
		{
			for (int j=0; j<=n-i; j++)
			{
				int f = false;
				for (int t=0; t<=i/2; t++)
				{
					if (s[j+t] != s[j+i-1-t])
					{
						f = true;
						break;
					}
				}
				if (!f)
				{
					re++;
				}
			}	
		}
		cout << re << endl;
	}

	return 0;
}