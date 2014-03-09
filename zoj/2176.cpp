// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// fstream cin("input.txt");
	int n;
	while (cin >> n && n != -1)
	{
		int s, t1, t2 = 0;
		int d = 0;
		while (--n >= 0)
		{
			cin >> s >> t1;
			d += (t1 - t2) * s;
			t2 = t1;
		}

		cout << d << " miles" << endl;
	}
	return 0;
}	///:~