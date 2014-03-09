// AC

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool isGood(string& s1, string& s2)
{
	int n1 = s1.length();
	int n2 = s2.length();
	if (n1+1 < n2)
	{
		return false;
	}
	int i = find(s2.begin(), s2.end(), '*') - s2.begin();
	return (equal(s1.begin(), s1.begin()+i, s2.begin()) && 
		equal(s1.begin()+(n1-(n2-i-1)), s1.end(), s2.begin()+(i+1)));
	// Restricted Function ?????
	// return (s1.substr(0, i) == s2.substr(0, i) && s1.substr(n1-(n2-i-1), n1) == s2.substr(i+1, n2));
}

int main()
{
	//ifstream cin("input.txt");

	int n;
	int c = 0;
	while (cin >> n)
	{
		if (++c != 1)
		{
			cout << endl;
		}
		vector<string> v;
		string s;
		for (int t=0; t<n; t++)
		{
			cin >> s;
			v.push_back(s);
		}
		
		int m;
		cin >> m;
		for (int i=0; i<m; i++)
		{
			cin >> s;
			bool f = false;
			for (int j=0; j<v.size(); j++)
			{
				if (isGood(v[j], s))
				{
					if (f)
					{
						cout << ", ";
					}
					cout << v[j];
					f = true;
				}
			}
			if (!f)
			{
				cout << "FILE NOT FOUND";
			}
			cout << endl;
		}
	}

	return 0;
}
