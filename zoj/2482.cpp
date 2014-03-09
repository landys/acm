// AC

#include <iostream>
//#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	//ifstream cin("input.txt");
	int n = 0;
	cin >> n;
	while (--n >= 0)
	{
		int ip[4] = {0};
		for (int i=0; i<32; i++)
		{
			char c;
			cin >> c;
			int k = c - '0';
			if (k != 0)
			{
				ip[i/8] += k * int(pow(double(2), double(7-i%8)));
			}
		}
		for (int j=0; j<4; j++)
		{
			cout << ip[j] << (j==3 ? '\n' : '.');
		}
	}

	return 0;
}	///:~