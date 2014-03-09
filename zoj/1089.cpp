// Accept

#include <iostream>
using namespace std;

int a[49], b[7];

void place(int n, int t)
{
	if (t == -1)
	{
		return;
	}

	if (t == 6)
	{
		for (int i=0; i<6; i++)
		{
			cout << a[b[i]] << ((i != 5) ? ' ' : '\n');
		}
		place(n, --t);
	}
	else if (++b[t] == n+1+t-6)
	{
		b[t] = t;
		place(n, --t);
	}
	else if (t != 0 && b[t] <= b[t-1])
	{
		place(n, t);
	}
	else
	{
		place(n, ++t);
	}
}

int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		for (int i=0; i<n; i++)
		{
			cin >> a[i];
		}
		for (int j=0; j<7; j++)
		{
			b[j] = j;
		}
		place(n, 6);

		cin >> n;
		if (n != 0)
		{
			cout << endl;
		}
	}

	return 0;
}	///:~