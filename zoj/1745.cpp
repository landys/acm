// Accept

#include <iostream>
#include <string>
#include <cmath>
// #include <fstream>
using namespace std;

inline void print(const int& m, const int& n, const string& s)
{
	cout << "Moving from " << m << " to " << n << ": " << s << endl;
}

int main()
{
	// ifstream cin("input.txt");
	int loca = 0;
	cin >> loca;
	while (loca != 5280)
	{
		string s = "";
		int m = 0, n = 0;

		while (cin >> n && n != loca)
		{
			if (abs(m-loca) == abs(n-loca))
			{
				s = "same.";
			}
			else if (abs(m-loca) > abs(n-loca))
			{
				s = "warmer.";
			}
			else
			{
				s = "colder.";
			}
			print(m, n, s);
			m = n;
		}
		print(m, n, "found it!");
		cin >> loca;
		if (loca != 5280)
		{
			cout << endl;
		}
	}

	return 0;
}	///:~