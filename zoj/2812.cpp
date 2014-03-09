// AC

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream cin("input.txt");
	string s;
	getline(cin, s);
	while (s != "#")
	{
		int sum = 0;
		for (int i=0; i<s.length(); i++)
		{
			if (s[i] == ' ')
			{
				continue;
			}
			sum += (i+1)*(s[i]-'A'+1);
		}
		cout << sum << endl;
		getline(cin, s);
	}

	return 0;
}