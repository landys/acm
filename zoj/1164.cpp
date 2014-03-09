// AC

#include <iostream>
//#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
//#include <iomanip>

using namespace std;
const unsigned G = 34943;
const unsigned R16 = 65536;
const unsigned R8 = 256;

void print(unsigned n)
{
	printf("%.2X %.2X\n", n/R8, n%R8);
// 	unsigned a = n / R8;
// 	unsigned b = n % R8;
// 
// 	if (a < 16)
// 	{
// 		cout << "0";
// 	}
// 	cout << hex << a << " ";
// 	if (b < 16)
// 	{
// 		cout << "0";
// 	}
// 	cout << hex << b << endl;
}

void str2vector(const string& str, vector<unsigned>& ve)
{
	if (str == "")
	{
		return;
	}
	unsigned n = str.length();

	unsigned i = 0;
	if (n % 2 == 1)
	{
		ve.push_back((unsigned)(str[i++]));	
	}
	for (; i<n; i+=2)
	{
		ve.push_back((unsigned)(str[i])*R8 + (unsigned)(str[i+1]));
	}
	ve.push_back(0);
}

int main()
{
//	ifstream cin("input.txt");

	string ss;
	getline(cin, ss);
	while (ss == "")
	{
		print(0);
		getline(cin, ss);
	}
	while (ss[0] != '#')
	{
		vector<unsigned> ve;
		str2vector(ss, ve);
		unsigned left = 0;
		//cout << ss << endl;
		//cout << ve.size() << endl;
		for (unsigned i=0; i<ve.size(); i++)
		{
			//cout << ve[i] << endl;
			left = (ve[i] + left * R16) % G;
		}

		print((G-left)%G);

		getline(cin, ss);
		while (ss == "")
		{
			print(0);
			getline(cin, ss);
		}
	}
	//print(34943);
	return 0;
}