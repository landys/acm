// AC

// n=1 : 1                              +  0
// n=2 : 1 + 3                          +  1
// n=3 : 1 + 3 + 6                      +  3
// n=4 : 1 + 3 + 6 + 10                 +  1 + 6
// n=5 : 1 + 3 + 6 + 10 + 15            +  3 + 10
// n=6 : 1 + 3 + 6 + 10 + 15 + 21       +  1 + 6 + 15
// n=7 : 1 + 3 + 6 + 10 + 15 + 21 + 28  +  3 + 10 + 21

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int s = n * (n + 1) * (n + 2) /6 ;
		int m = n / 2;
		if (n % 2 == 0)
		{
			s += m * (m + 1) * (4 * m - 1) / 6;
		}
		else
		{
			s += m * (m + 1) * (4 * m + 5) / 6;
		}

		cout << s << endl;
	}

	return 0;
}	///:~