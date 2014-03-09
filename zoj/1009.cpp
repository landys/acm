// AC
// algorithm: simulate

#include <iostream>
//#include <fstream>
#include <string>
//#include <vector>
using namespace std;

const string AA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string aa = "abcdefghijklmnopqrstuvwxyz";

void rotate(string& rot, int n)
{
	int i;
	char c = rot[n-1];
	for (i=n-1; i>=1; i--)
	{
		rot[i] = AA[i] + (rot[i-1] - AA[i-1]);
	}
	rot[0] = AA[0] + (c - AA[n-1]);
	for (i=0; i<n; i++)
	{
		if (rot[i] < AA[0])
		{
			rot[i] = rot[i] + n;	
		}
		if (rot[i] > AA[n-1])
		{
			rot[i] = rot[i] - n;
		}
	}
}

int main()
{
//	ifstream cin("input.txt");
	
	string rot1, rot2, rot3;
	int c = 0;
	int n, m;
	string cr, pl;
	int i;
	cin >> n;
	while (n != 0)
	{
		if (c != 0)
		{
			cout << endl;
		}
		cout << "Enigma " << ++c << ":" << endl;

		cin >> rot1 >> rot2 >> rot3;
		cin >> m;
		while (--m >= 0)
		{
			string r1 = rot1;	// initialization
			string r2 = rot2;
			string r3 = rot3;
			int i1 = 0;
			int i2 = 0;
			int i3 = 0;

			cin >> cr;
			pl = cr;
			for (i=0; i<cr.length(); i++)
			{
//				cout << "r1=" << r1 << endl;
				// decode
				pl[i] = aa[r1.find(AA[r2.find(AA[r3.find(cr[i])])])];
				
				rotate(r1, n);	// rotate roter1
				if (++i1 == n)
				{
					i1 = 0;
					rotate(r2, n);	// rotate roter2;
					if (++i2 == n)
					{
						i2 = 0;
						rotate(r3, n);	// rotate roter3;
						i3 = (i3 + 1) % n;
					}
				}
			}

			cout << pl << endl;
		}

		cin >> n;
	}
	return 0;
}
