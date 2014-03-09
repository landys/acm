// AC

#include <iostream>
//#include <fstream>

using namespace std;


int main(void)
{
	//ifstream cin("input.txt");
	int a[7] = {3, 5, 6, 9, 10, 12, 15};
	int n;
	while (cin >> n)
	{
		cout << 15 * ((n - 1) / 7) + a[(n - 1) % 7] << endl;
	}
	
	return 0;
}