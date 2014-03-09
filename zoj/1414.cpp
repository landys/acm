// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// fstream cin("input.txt");
	int n;
	cin >> n;
	while ((--n) >= 0)
	{
		int x, y, s;
		cin >> x >> y;
		if (x == y)
		{
			if (x % 2 == 0)
			{
				s = 2 * x;
			}
			else
			{
				s = 2 * x - 1;
			}
		}
		else if (x == y + 2)
		{
			if (y % 2 == 0)
			{
				s = 2 * y + 2;
			}
			else
			{
				s = 2 * y + 1;
			}
		}
		else
		{
			cout << "No Number" << endl;
			continue;
		}

		cout << s << endl;
	}

	return 0;
}	///:~