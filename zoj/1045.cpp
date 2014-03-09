// AC

#include <iostream>
using namespace std;

void print(int x)
{
	cout << x << " card(s)" << endl;
}

int main()
{
	float f;
	int i;
	cin >> f;
	while (f > 0.00)
	{
		float s = 0;
		for (i=2; s<f; i++)
		{
			s += float(1) / i;
		}
		print(i-2);
		cin >> f;
	}

	return 0;
}
