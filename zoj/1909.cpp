// not completed

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream cin("input.txt");
	int re = 0;
	cin >> re;
	while (--re >= 0)
	{
		int m = 0;
		cin >> m;

		int s = 0;
		int *a = new int[m];
		for (int i=0; i<m; i++)
		{	
			cin >> a[i];
			s += a[i];
		}
		if (s % 4 != 0)
		{
			cout << "no" << endl;
			continue;
		}
		
		int av = s / 4;

		if (square(a, av))
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}

	return 0;
}	///:~