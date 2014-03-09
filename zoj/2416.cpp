// Accept

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int re;
	cin >> re;
	while (--re >= 0)
	{
		string a, b;
		cin >> a >> b;
		
		int min = 100;
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<4; j++)
			{
				for (int k=0; k<4; k++)
				{
					for (int t=0; t<4; t++)
					{
						if (!(i == j || i == k || i == t || j == k || j == t || k == t))
						{
							int s = 0;
							s += (i > j) + (i > k) + (i > t) + (j > k) + (j > t) + (k > t);
							int aa = abs(a[i]-b[0]), bb = abs(a[j]-b[1]), cc = abs(a[k]-b[2]), dd = abs(a[t]-b[3]);
							if (aa >= 5)
							{
								aa = 9 - aa;
							}
							if (bb >= 5)
							{
								bb = 9 - bb;
							}
							if (cc >= 5)
							{
								cc = 9 - cc;
							}
							if (dd >= 5)
							{
								dd = 9 - dd;
							}
							s += aa + bb + cc + dd;
							if (s < min)
							{
								min = s;
							}
						}
					}
				}
			}
		}
		cout << min << endl;
	}

	return 0;
}	///:~