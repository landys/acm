// AC

#include <iostream>
// #include <fstream>
#include <cmath>
using namespace std;

int main()
{
	// ifstream cin("input.txt");

	int n = 0;
	bool f[3000];
	while (cin >> n)
	{
		for (int j=0; j<n; j++)
		{
			f[j] = false;
		}
		int a, b;
		cin >> a;
		bool flag = true;
		for (int i=1; i<n; i++)
		{
			cin >> b;
			int k;
			if ((k = abs(a-b)) <= 0 || k >= n)
			{
				flag = false;
				break;
			}
			else if (f[k])
			{
				flag = false;
				break;
			}
			f[k] = true;
			a = b;
		}
		cin.ignore(100000, '\n');
		if (flag)
		{
			cout << "Jolly" << endl;
		}
		else
		{
			cout << "Not jolly" << endl;
		}
	}

	return 0;
}	///:~