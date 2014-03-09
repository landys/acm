// AC

#include <iostream>
// #include <fstream>
#include <string>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	int re = 0;
	cin >> re;
	while (--re >= 0)
	{
		int n = 0;
		cin >> n;
		cin.ignore();
		string s1 = "";
		string s2 = "";
		getline(cin, s1);
		getline(cin, s2);
		int i = 0;
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		{
			i++;
		}
		int t = n * (s2.length() - i + s1.length() - i);
		if (s1[i] == '\0')
		{
			t = n * (s2.length() - s1.length());
		}
		else if (s2[i] == '\0')
		{
			t = n * (s1.length() - s2.length());
		}
		cout << t << endl;
	}

	return 0;
}	///:~