// AC

#include <iostream>
// #include <fstream>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int n;
	while (cin >> n && n != 0)
	{
		bool a[26];
		for (int i=0; i<26; i++)
		{
			a[i] = false;
		}

		char c;
		int t = 0, s = 0;
		while (cin.peek() != '\n')
		{
			cin >> c;
			
			int k = c - 'A';
			if (a[k] == false)
			{
				a[k] = true;
				t++;
				if (t > n)
				{
					s++;
				}
			}
			else
			{
				a[k] = false;
				t--;
			}
		}

		if (s)
		{
			cout << s << " customer(s) walked away." << endl;
		}
		else
		{
			cout << "All customers tanned successfully." << endl;
		}
	}

	return 0;
}	///:~