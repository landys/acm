// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// ofstream cout("output.txt");
	for (int a=3; a<=200; a++)
	{
		for (int b=2; b<a; b++)
		{
			for (int c=b; c<a; c++)
			{
				for (int d=c; d<a; d++)
				{
					if (a*a*a == b*b*b + c*c*c + d*d*d)
					{
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
					}
				}
			}
		}
	}

	return 0;
}	///:~