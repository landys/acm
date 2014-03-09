// AC

#include <iostream>
// #include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int s;
	string n = "";
	while (cin >> s && s != 0)
	{
		cin.ignore();
		cin >> n;

		int i, j;

		char **a = new char*[2*s+3];
		int size = (s+2+1)*(n.length());
		for (j=0; j<2*s+3; j++)
		{
			a[j] = new char[size];
			memset(a[j], ' ', size*sizeof(char));
			a[j][size-1] = '\0';	// necessary
		}
		
		for (i=0; i<n.length(); i++)
		{
			switch (n[i])
			{
			case '0':
				for (j=1; j<s+1; j++)
				{
					a[0][i*(s+3)+j] = '-';
					a[2*s+2][i*(s+3)+j] = '-';
					a[j][i*(s+3)] = '|';
					a[j+s+1][i*(s+3)] = '|';
					a[j][i*(s+3)+s+1] = '|';
					a[j+s+1][i*(s+3)+s+1] = '|';
				}
				break;
			case '1':
				for (j=1; j<s+1; j++)
				{
					a[j][i*(s+3)+s+1] = '|';
					a[j+s+1][i*(s+3)+s+1] = '|';
				}
				break;
			case '2':
				for (j=1; j<s+1; j++)
				{
					a[0][i*(s+3)+j] = '-';
					a[s+1][i*(s+3)+j] = '-';
					a[2*s+2][i*(s+3)+j] = '-';
					a[j+s+1][i*(s+3)] = '|';
					a[j][i*(s+3)+s+1] = '|';
				}
				break;
			case '3':
				for (j=1; j<s+1; j++)
				{
					a[0][i*(s+3)+j] = '-';
					a[s+1][i*(s+3)+j] = '-';
					a[2*s+2][i*(s+3)+j] = '-';
					a[j][i*(s+3)+s+1] = '|';
					a[j+s+1][i*(s+3)+s+1] = '|';
				}
				break;
			case '4':
				for (j=1; j<s+1; j++)
				{
					a[s+1][i*(s+3)+j] = '-';
					a[j][i*(s+3)] = '|';
					a[j][i*(s+3)+s+1] = '|';
					a[j+s+1][i*(s+3)+s+1] = '|';
				}
				break;
			case '5':
				for (j=1; j<s+1; j++)
				{
					a[0][i*(s+3)+j] = '-';
					a[s+1][i*(s+3)+j] = '-';
					a[2*s+2][i*(s+3)+j] = '-';
					a[j][i*(s+3)] = '|';
					a[j+s+1][i*(s+3)+s+1] = '|';
				}
				break;
			case '6':
				for (j=1; j<s+1; j++)
				{
					a[0][i*(s+3)+j] = '-';
					a[s+1][i*(s+3)+j] = '-';
					a[2*s+2][i*(s+3)+j] = '-';
					a[j][i*(s+3)] = '|';
					a[j+s+1][i*(s+3)] = '|';
					a[j+s+1][i*(s+3)+s+1] = '|';
				}
				break;
			case '7':
				for (j=1; j<s+1; j++)
				{
					a[0][i*(s+3)+j] = '-';
					a[j][i*(s+3)+s+1] = '|';
					a[j+s+1][i*(s+3)+s+1] = '|';
				}
				break;
			case '8':
				for (j=1; j<s+1; j++)
				{
					a[0][i*(s+3)+j] = '-';
					a[s+1][i*(s+3)+j] = '-';
					a[2*s+2][i*(s+3)+j] = '-';
					a[j][i*(s+3)] = '|';
					a[j+s+1][i*(s+3)] = '|';
					a[j][i*(s+3)+s+1] = '|';
					a[j+s+1][i*(s+3)+s+1] = '|';
				}
				break;
			case '9':
				for (j=1; j<s+1; j++)
				{
					a[0][i*(s+3)+j] = '-';
					a[s+1][i*(s+3)+j] = '-';
					a[2*s+2][i*(s+3)+j] = '-';
					a[j][i*(s+3)] = '|';
					a[j][i*(s+3)+s+1] = '|';
					a[j+s+1][i*(s+3)+s+1] = '|';
				}
				break;
			}
		}
		for (j=0; j<2*s+3; j++)
		{
			cout << a[j] << endl;
		}
		cout << endl;
	}

	return 0;
}	///:~