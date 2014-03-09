// AC
// Minimum Spanning Tree -- Kruskal Algorithm
#include <iostream>
//#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class House
{
public:
	string name;
	int parent;
	int me;
};

class Distance
{
public:
	string h1;
	string h2;
	double d;
};

bool operator>(const Distance& left, const Distance& right)
{
	return left.d > right.d;
}

bool operator==(const House& left, const House& right)
{
	return left.name == right.name;
}

int findUnion(const vector<House>& vh, const string& name)
{
	House h;
	h.name = name;
	vector<House>::const_iterator it = find(vh.begin(), vh.end(), h);
	if (it == vh.end())
	{
		cout << "Cannot happen!" << endl;
		return 0;
	}
	int me = it->me;
	while (me != vh[me].parent)
	{
		me = vh[me].parent;
	}
	return me;
}

int main()
{
//	ifstream cin("input.txt");
	double k = 0.0;
	cin >> k;

	int m = 0;
	cin >> m;
	vector<House> vh;
	vh.reserve(m);

	int i;
	House hh;
	for (i=0; i<m; i++)
	{
		cin >> hh.name;
		hh.parent = i;
		hh.me = i;
		vh.push_back(hh);
	}

	int n = 0;
	cin >> n;
	priority_queue<Distance, vector<Distance>, greater<Distance> > pq;
	Distance dd;
	for (i=0; i<n; i++)
	{
		cin >> dd.h1 >> dd.h2 >> dd.d;
		pq.push(dd);
	}

//	for (i=0; i<vh.size(); i++)
//	{
//		cout << vh[i].name << ", " << vh[i].me << ", " << vh[i].parent << endl;
//	}
//	while (!pq.empty())
//	{
//		dd = pq.top();
//		cout << dd.h1 << ", " << dd.h2 << ", " << dd.d << endl;
//		pq.pop();
//	}

	int count = 0;	// number of edge contained
	double sum = 0.0;
	while (!pq.empty() && count < m - 1)
	{
		dd = pq.top();
		pq.pop();
		int r1 = findUnion(vh, dd.h1);
		int r2 = findUnion(vh, dd.h2);
		if (r1 != r2)
		{
			sum += dd.d;
			if (sum > k)
			{
				cout << "Not enough cable" << endl;
				return 0;
			}
			count++;
			vh[r1].parent = r2;
		}
	}

	if (count == m - 1)
	{
		cout << "Need " << fixed << setprecision(1) << sum << " miles of cable" << endl;
	}
	else
	{
		cout << "Not enough cable" << endl;
	}

	return 0;
}
