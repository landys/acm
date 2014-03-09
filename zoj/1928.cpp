// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int a, b, c, d;
	while (cin >> a >> b >> c >> d && !(a == 0 && b == 0 && c == 0 && d == 0))
	{
		int sum = 3 * 360;
		int t = a - b;
		if (t < 0)
		{
			t += 40;
		}
		sum += t * 9;
		t = c - b;
		if (t < 0)
		{
			t += 40;
		}
		sum += t * 9;
		t = c - d;
		if (t < 0)
		{
			t += 40;
		}
		sum += t * 9;
		cout << sum << endl;
	}

	return 0;
}	///:~