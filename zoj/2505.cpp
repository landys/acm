// WA

#include <iostream>
//#include <fstream>
using namespace std;

int main(void)
{
	//ifstream cin("input.txt");
	
	int re = 0;
	cin >> re;
	while (--re >= 0)
	{
		int max = 0;
		int a[4097] = {0};
		int n = 0;
		int temp = 0;
		cin >> n;
		while (--n >= 0)
		{
			cin >> temp;
			if (a[temp] == 0)
			{
				a[temp] = 1;
				if (max < temp)
				{
					max = temp;
				}
			}
			else
			{
				a[temp] = 0;
			}
		}
		int i = max;
		while (i > 0 && a[i] == 0)
		{
			--i;
		}
		cout << i << endl;
	}

	return 0;
}	///:~