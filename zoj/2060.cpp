// AC

#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
	//ifstream cin("input.txt");
	
	int n = 0;
	while (cin >> n)
	{
		if (n % 8 == 2 || n % 8 == 6)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}

	return 0;
}