// AC

#include <iostream>
//#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(void)
{
//	ifstream cin("input.txt");
	
	int i, j;
	string ss;
	int n, k;
	bool f = false;
	while (cin >> n)
	{
		if (f)
		{
			cout << endl;
		}
		else
		{
			f = true;
		}
		map<string, int> m;
		map<string, int>::iterator it;
		for (i=0; i<n; i++)
		{
			cin >> ss;
			it = m.find(ss);
			if (it == m.end())
			{
				m[ss] = 1;
			}
			cin >> k;
			for (j=0; j<k; j++)
			{
				cin >> ss;
				m[ss] = 2;
			}
		}

		vector<string> ve;
		for (it=m.begin(); it!=m.end(); it++)
		{
			if (it->second == 1)
			{
				ve.push_back(it->first);
			}
		}
		sort(ve.begin(), ve.end());
		for (i=0; i<ve.size(); i++)
		{
			cout << ve[i] << endl;
		}
	}
	
	return 0;
}