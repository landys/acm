// AC

#include <iostream>
//#include <fstream>

using namespace std;


int main(void)
{
	//ifstream cin("input.txt");
	int n;
	cin >> n;
	while (n != 0)
	{
		cout << n / 2 << endl;

		cin >> n;
	}
	
	return 0;
}