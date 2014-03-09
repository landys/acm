// long long compiled in g++
// AC

#include <iostream>
//#include <fstream>
using namespace std;

int main()
{
	//ifstream cin("input.txt");

	long long a, b;

	while (cin >> a && cin >> b)
	{
		int n = 1;
		long long k = 1;
		long long aa = a;
		while ((aa /= 2) != 0)
		{
			++n;
			k *= 2;
		}

		if (b > 64)
		{
			b = 64;
		}
		for (; b>0; b--)
		{
			if (n == 1)
			{
				break;
			}
			a <<= 1;
			a |= 1;
			while ((a & k) == 0)
			{
				--n;
				k /= 2;
			}
		}
		
		long long kk = k - 1;
		k += kk;
		a &= k;
		cout << a << endl;	
	}
	
	return 0;
}

/*// long long compiled in g++
// Time Limit Exceeded

#include <iostream>
#include <deque>
using namespace std;

int main()
{
	// ifstream cin("input.txt");

	long long a, b;

	while (cin >> a && cin >> b)
	{
		deque<int> dd;
		deque<int>::iterator i;
		
		while (a / 2 != 0)
		{
			dd.push_front(a%2);
			a /= 2;
		}
		dd.push_front(a);
		while (dd.front() == 0 && dd.size() > 1)
		{
			dd.pop_front();
		}

		for (; b>0; b--)
		{
			if (dd.size() == 1)
			{
				break;
			}

			dd.push_back(dd.front());
			dd.pop_front();
			while (dd.front() == 0)
			{
				dd.pop_front();
			}
		}
		a = 0;
		for (i=dd.begin(); i!=dd.end(); i++)
		{
			a = 2 * a + *i;
		}
		cout << a << endl;	
	}
	
	return 0;
}	///:~*/

/*// Time Limit Exceeded
// survivor = 2 * (n - 2 ^ k) + 1

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ifstream cin("input.txt");

	string nstr = "";
	string rstr = "";

	while (cin >> nstr && cin >> rstr)
	{
		int a[3] = {0};
		int b[3] = {0};
		for (int j=nstr.length()-1; j>=0; j--)
		{
			int jj = nstr.length() - 1 - j;
			a[j/9] = a[j/9] * 10 + (nstr[jj] - '0');	// a0 lowest
		}
		for (int t=rstr.length()-1; t>=0; t--)
		{
			int tt = rstr.length() - 1 - t;
			b[t/9] = b[t/9] * 10 + (rstr[tt] - '0');	// a0 lowest
		}

		while (!(b[0] == 0 && b[1] == 0 && b[2] == 0) && !(a[0] == 1 && a[1] == 0 && a[2] == 0))
		{
			if (b[0] == 0)
			{
				b[0] = 99999999;
				if (b[1] == 0)
				{
					b[1] = 99999999;
					b[2]--;
				}
				else
				{
					b[1]--;
				}
			}
			else
			{
				b[0]--;
			}

			int c[3] = {1, 0, 0};
			while (c[2]<a[2] || (c[2]==a[2] && c[1]<a[1]) || (c[2]==a[2] && c[1]==a[1] && c[0]<a[0]))
			{
				c[2] *= 2;
				c[1] *= 2;
				c[0] *= 2;
				if (c[0] > 999999999)
				{
					c[0] -= 1000000000;
					c[1]++;
				}
				if (c[1] > 999999999)
				{
					c[1] -= 1000000000;
					c[2]++;
				}
			}
			a[2] *= 2;
			a[1] *= 2;
			a[0] *= 2;
			if (a[0] > 999999999)
			{
				a[0] -= 1000000000;
				a[1]++;
			}
			if (a[1] > 999999999)
			{
				a[1] -= 1000000000;
				a[2]++;
			}
			a[0]++;

			if (a[0] < c[0])
			{
				a[0] += 1000000000;
				c[1]++;
			}
			if (a[1] < c[1])
			{
				a[1] += 1000000000;
				c[2]++;
			}
			a[0] -= c[0];
			a[1] -= c[1];
			a[2] -= c[2];
		}

		if (a[2] != 0)
		{
			cout << a[2];
 			cout << right << setw(9) << setfill('0') << a[1];
			cout << right << setw(9) << setfill('0') << a[0];
		}
		else if (a[1] != 0)
		{
			cout << a[1];
			cout << right << setw(9) << setfill('0') << a[0];
		}
		else
		{
			cout << a[0];
		}
		cout << endl;
	}
	
	return 0;
}	///:~*/