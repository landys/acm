// AC

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int k = 1;
		int m = 1;
		while (m % n != 0)
		{
			k++;
			m = m % n * 10 + 1;
		}

		cout << k << endl;
	}
	
	return 0;
}	///:~