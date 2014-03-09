// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int re = 0;
	cin >> re;
	while (--re >= 0)
	{
		int n = 0, m = 0;
		int k = 0;
		while (cin >> n >> m && n != 0)
		{
			k++;
			int t = 0;
			for (int a=1; a<=n-2; a++)
			{
				for (int b=a+1; b<=n-1; b++)
				{
					if ((a*a+b*b+m) % (a*b) == 0)
					{
						t++;
					}
				}
			}

			cout << "Case " << k << ": " << t << endl;
		}
		if (re > 0)
		{
			cout << endl;
		}
	}

	return 0;
}	///:~