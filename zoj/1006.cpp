// AC

#include <iostream>
// #include <fstream>
using namespace std;

#define N 80

int main(void)
{
	// ifstream cin("input.txt");
	int k;
	int pc[N], cc[N];
	char pt[N], ct[N];
	int n;
	int i;

	cin >> k;
	while (k > 0)
	{
		n = -1;
		cin >> ct;
		while (ct[++n] != '\0')
		{
			if (ct[n] == '_')
			{
				cc[n] = 0;
			}
			else if (ct[n] == '.')
			{
				cc[n] = 27;
			}
			else
			{
				cc[n] = ct[n] - 'a' + 1;
			}
		}
		
		for (i=0; i<n; i++)
		{
			pc[(k*i)%n] = (cc[i] + i) % 28;
		}

		for (i=0; i<n; i++)
		{
			if (pc[i] == 0)
			{
				pt[i] = '_';
			}
			else if (pc[i] == 27)
			{
				pt[i] = '.';
			}
			else
			{
				pt[i] = pc[i] - 1 + 'a';
			}
		}
		pt[n] = '\0';
		cout << pt << endl;

		cin >> k;
	}

	return 0;
}

