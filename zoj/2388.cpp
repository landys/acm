// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// fstream cin("input.txt");
	int n;
	cin >> n;
	while (--n >= 0)
	{
		int s, d;
		cin >> s >> d;
		if (s < d || (s + d) % 2 != 0)
		{
			cout << "impossible" << endl;
			continue;
		}
		cout << (s+d)/2 << " " << (s-d)/2 << endl;
	}

	return 0;
}	///:~