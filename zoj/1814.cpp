// AC

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

void print(const string& s, bool f)
{
	if (f)
	{
		cout << s << " is surprising." << endl;
	}
	else
	{
		cout << s << " is NOT surprising." << endl;
	}
}

int main()
{
	ifstream cin("input.txt");
	string s;
	string t;
	cin >> s;
	set<string> ss;
	while (s != "*")
	{
		bool f = true;
		for (int i=0; i<=(int)(s.length())-2; i++)
		{
			ss.clear();
			for (int j=0; j<(int)(s.length())-i-1; j++)
			{
				t = s[j];
				t += s[j+i+1];
				if (ss.find(t) != ss.end())
				{
					f = false;
					break;
				}
				ss.insert(t);
			}
			if (!f)
			{
				break;
			}
		}
		print(s, f);
		cin >> s;
	}

	return 0;
}