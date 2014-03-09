// AC

#include <iostream>
// #include <fstream>
#include <string>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int n;
	cin >> n;
	int count = 0;
	while (--n >= 0)
	{
		count++;
		string str = "";
		string s = "";
		cin >> str;
		for (int i=0; i<str.length(); i++)
		{
			if (str[i] == 'Z')
			{
				s += "A";
			}
			else
			{
				s += char(str[i] + 1);
			}
		}

		cout << "String #" << count << endl << s << endl << endl;
	}

	return 0;
}	///:~