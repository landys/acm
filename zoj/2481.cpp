// AC

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	//ifstream cin("input.txt");

	int n;
	cin >> n;
	int i, j, t;
	while (n != 0)
	{
		set<int> s;
		for (i=0; i<n; i++)
		{
			cin >> t;
			s.insert(t);
		}
		set<int>::iterator it=s.begin();
		cout << *it;
		for (++it; it!=s.end(); ++it)
		{
			cout << " " << *it;	
		}
		cout << endl;

		cin >> n;
	}
	
	return 0;
}
