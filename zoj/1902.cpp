// AC

#include <iostream>
//#include <fstream>
#include <string>
using namespace std;

int main()
{
	//ifstream cin("input.txt");
	
	int m, n;
	cin >> m >> n;
	string* a = new string[m];
	int* b = new int[m];

	for (int j=0; j<m; j++)
	{
		cin >> a[j] >> b[j];
	}

	for (int i=0; i<n; i++)
	{
		int s = 0;
		string str = "";
		while (cin >> str && str != ".")
		{
			for (int ii=0; ii<m; ii++)
			{
				if (a[ii] == str)
				{
					s += b[ii];
					break;
				}
			}
		}

		cout << s << endl;
	}

	return 0;
}