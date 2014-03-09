// AC
// HTML

#include <iostream>
//#include <fstream>
#include <string>
using namespace std;

int main()
{
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	string s = "";
	int k = 0;
	while (cin >> s)
	{
		if (s == "<br>")
		{
			cout << endl;
			k = 0;
		}
		else if (s == "<hr>")
		{
			if (k != 0)
			{
				cout << endl;
				k = 0;
			}
			for (int i=0; i<80; i++)
			{
				cout << '-';
			}
			cout << endl;
		}
		else
		{
			if (s.length() > 80 - k - 1)
			{
				cout << endl;
				k = 0;
			}
			else if (k > 0)
			{
				cout << ' ';
				k++;
			}
			cout << s;
			k += s.length();
			if (k == 80)
			{
				cout << endl;
				k = 0;
			}
		}
	}
	if (k != 0)
	{
		cout << endl;
		k = 0;
	}

	return 0;
}	///:~
