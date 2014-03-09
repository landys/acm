#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	while (cin >> n && n != 0)
	{
		int k = 1;
		while (n / 2 != 0)
		{
			if (n % 2 == 0)
			{
				k *= 2;
			}
			else
			{
				break;
			}
			n /= 2;
		}

		cout << k << endl;
	}

	return 0;
}