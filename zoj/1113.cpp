// AC

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "n e" << endl;
	cout << "- -----------" << endl;
	double s = 1.0;
	double e = 1.0;
	cout << 0 << " " << e << endl;
	for (int i=1; i<10; i++)
	{
		s *= i;
		e += 1 / s;
		if (i == 1 || i == 2)
		{
			cout << i << " " << e << endl;
		}
		else
		{
			cout << i << " " << fixed << setprecision(9) << e << endl;
		}
	}
	return 0;
}	///:~