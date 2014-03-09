#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int re;
	cin >> re;
	while (--re >= 0)
	{
		int n;
		string s = "";
		cin >> n;
		cin.ignore();
		cin >> s;
		int k1 = 0, k2 = 0;
		int s1 = 0, s2 = 0;
		for (int i=0; i<s.length/2; i++)
		{
			if (s[i] != '?')
			{
				s1 += s[i] - '0';
			}
			else
			{
				k1++;
			}
		}
		for (int j=s.length/2; j<s.length; j++)
		{
			if (s[i] != '?')
			{
				s2 += s[i] - '0';
			}
			else
			{
				k2++;
			}
		}
		
		int s12 = s1 - s2;

	}

	return 0;
}	///:~