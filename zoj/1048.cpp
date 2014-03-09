// AC

#include <iostream>
// #include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	// fstream cin("input.txt");
	double a, s = 0.0;
	for (int i=0; i<12; i++)
	{
		cin >> a;
		s += a;
	}

	double temp = s / 12;
	double aver = double(int(temp*100)) / 100;
	if (temp - aver >= 0.005)
	{
		aver += 0.01;
	}
	
	cout << "$" << fixed << setprecision(2) << aver << endl;
	return 0;
}	///:~