// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int n = 0;
	cin >> n;
	while (n != 0)
	{
		int* a = new int[n];
		int* b = new int[n];
		for (int ii=0; ii<n; ii++)
		{
			cin >> a[ii];
		}
		for (int j=0; j<n; j++)
		{
			cin >> b[j];
		}
		int sa = 0, sb = 0;
		for (int i=0; i<n; i++)
		{
			if (a[i] > b[i])
			{
				if (a[i]-b[i] == 1)
				{
					if (a[i] == 2)
					{
						sb += 6;
					}
					else
					{
						sb += a[i] + b[i];
					}
				}
				else
				{
					sa += a[i];
				}
			}
			else if (a[i] < b[i])
			{
				if (b[i]-a[i] == 1)
				{
					if (b[i] == 2)
					{
						sa += 6;
					}
					else
					{
						sa += a[i] + b[i];
					}
				}
				else
				{
					sb += b[i];
				}
			}
		}
		cout << "A has " << sa << " points. B has " << sb << " points." << endl;
		cin >> n;
		if (n != 0)
		{
			cout << endl;
		}
	}

	return 0;
}	///:~