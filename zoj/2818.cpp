// AC

#include <iostream>
//#include <fstream>
#include <cmath>

using namespace std;

int main()
{
	//ifstream cin("input.txt");
	int a, b, n;
	cin >> b >> n;
	while (b != 0)
	{
		a = (int)(pow((double)b, 1.0/n));
		if (fabs(pow((double)(a+1), (double)n)-b) < fabs(pow((double)a, (double)n)-b))
		{
			a++;
		}
		cout << a << endl;
		cin >> b >> n;
	}
	return 0;
}
