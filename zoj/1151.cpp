// Accept

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(void)
{
	int re;
	cin >> re;
	while ((--re) >= 0)
	{
		int n;
		cin >> n;
		string str;
		getline(cin, str);

		for (int i=0; i<n; i++)
		{
			getline(cin, str);
			int j = 0;
			int t = 0;
			while (str[j] != '\0')
			{
				if (str[j] == ' ')
				{
					t = j + 1;
					cout << ' ';
				}
				else if (str[j+1] == ' ' || str[j+1] == '\0')
				{
					for (int k=j; k>=t; k--)
					{
						cout << str[k];
					}
				}
				j++;
			}
			cout << endl;
		}
		if (re != 0)	// necessary here!
		{
			cout << endl;
		}
	}

	return 0;
}