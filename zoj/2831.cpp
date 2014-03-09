// Time Limit Exceeded

// Maybe bugs in string operation, like substr, string(s, i, j)
// both getline, string.substr is Ok, tested
// But still Restricted Function, ????

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

#define X 'X'
#define X1 "X"
#define X2 "XX"
#define X3 "XXX"
#define X4 "XXXX"
#define X5 "XXXXX"
#define X6 "XXXXXX"
#define X7 "XXXXXXX"
#define WS1 " "
#define WS2 "  "
#define WS3 "   "
#define WS4 "    "
#define WS5 "     "
#define WS6 "      "
#define WS7 "       "
#define WS8 "        "

#define A91 "  XXXX  "
#define A92 " XX  XX "
#define A93 " XX  XX "
#define A94 " XX  XX "
#define A95 "   XXXX "
#define A96 "     XX "
#define A97 "    XX  "
#define A98 " XXXX   "

#define A81 "  XXXX  "
#define A82 " XX  XX "
#define A83 " XX  XX "
#define A84 "  XXXX  "
#define A85 " XX  XX "
#define A86 " XX  XX "
#define A87 " XX  XX "
#define A88 "  XXXX  "

#define A71 " XXXXXX "
#define A72 " X   XX "
#define A73 "     XX "
#define A74 "    XX  "
#define A75 "    XX  "
#define A76 "    XX  "
#define A77 "   XX   "
#define A78 "   XX   "

#define A61 "   XXXX "
#define A62 "  XX    "
#define A63 " XX     "
#define A64 " XXXXX  "
#define A65 " XX  XX "
#define A66 " XX  XX "
#define A67 " XX  XX "
#define A68 "  XXXX  "

#define A51 "  XXXXX "
#define A52 "  XX    "
#define A53 "  XXXX  "
#define A54 "  X  XX "
#define A55 "     XX "
#define A56 "     XX "
#define A57 " X   XX "
#define A58 "  XXXX  "

#define A41 "    XX  "
#define A42 "   XXX  "
#define A43 "   XXX  "
#define A44 "  X XX  "
#define A45 " X  XX  "
#define A46 " XXXXXX "
#define A47 "    XX  "
#define A48 "  XXXXX "


#define A01 "  XXXX  "
#define A02 " XX  XX "
#define A03 " XX  XX "
#define A04 " XX  XX "
#define A05 " XX  XX "
#define A06 " XX  XX "
#define A07 " XX  XX "
#define A08 "  XXXX  "

#define A11 "   XX   "
#define A12 " XXXX   "
#define A13 "   XX   "
#define A14 "   XX   "
#define A15 "   XX   "
#define A16 "   XX   "
#define A17 "   XX   "
#define A18 " XXXXXX "

#define A21 "  XXXX  "
#define A22 " XX  XX "
#define A23 " XX  XX "
#define A24 "     XX "
#define A25 "    XX  "
#define A26 "   XX   "
#define A27 "  XX    "
#define A28 " XXXXXX "

#define A31 "  XXXX  "
#define A32 " X   XX "
#define A33 "     XX "
#define A34 "   XXX  "
#define A35 "     XX "
#define A36 "     XX "
#define A37 " X   XX "
#define A38 "  XXXX  "

using namespace std;

void print(int n)
{
	string ss[8];
	stack<int> st;
	while (n / 10 != 0)
	{
		int k = n % 10;
		st.push(k);
		n = n / 10;
	}
	st.push(n);

	while (!st.empty())
	{
		switch (st.top())
		{
		case 0:
			ss[0] += A01;
			ss[1] += A02;
			ss[2] += A03;
			ss[3] += A04;
			ss[4] += A05;
			ss[5] += A06;
			ss[6] += A07;
			ss[7] += A08;
			break;
		case 1:
			ss[0] += A11;
			ss[1] += A12;
			ss[2] += A13;
			ss[3] += A14;
			ss[4] += A15;
			ss[5] += A16;
			ss[6] += A17;
			ss[7] += A18;
			break;
		case 2:
			ss[0] += A21;
			ss[1] += A22;
			ss[2] += A23;
			ss[3] += A24;
			ss[4] += A25;
			ss[5] += A26;
			ss[6] += A27;
			ss[7] += A28;
			break;
		case 3:
			ss[0] += A31;
			ss[1] += A32;
			ss[2] += A33;
			ss[3] += A34;
			ss[4] += A35;
			ss[5] += A36;
			ss[6] += A37;
			ss[7] += A38;
			break;
		case 4:
			ss[0] += A41;
			ss[1] += A42;
			ss[2] += A43;
			ss[3] += A44;
			ss[4] += A45;
			ss[5] += A46;
			ss[6] += A47;
			ss[7] += A48;
			break;
		case 5:
			ss[0] += A51;
			ss[1] += A52;
			ss[2] += A53;
			ss[3] += A54;
			ss[4] += A55;
			ss[5] += A56;
			ss[6] += A57;
			ss[7] += A58;
			break;
		case 6:
			ss[0] += A61;
			ss[1] += A62;
			ss[2] += A63;
			ss[3] += A64;
			ss[4] += A65;
			ss[5] += A66;
			ss[6] += A67;
			ss[7] += A68;
			break;
		case 7:
			ss[0] += A71;
			ss[1] += A72;
			ss[2] += A73;
			ss[3] += A74;
			ss[4] += A75;
			ss[5] += A76;
			ss[6] += A77;
			ss[7] += A78;
			break;
		case 8:
			ss[0] += A81;
			ss[1] += A82;
			ss[2] += A83;
			ss[3] += A84;
			ss[4] += A85;
			ss[5] += A86;
			ss[6] += A87;
			ss[7] += A88;
			break;
		case 9:
			ss[0] += A91;
			ss[1] += A92;
			ss[2] += A93;
			ss[3] += A94;
			ss[4] += A95;
			ss[5] += A96;
			ss[6] += A97;
			ss[7] += A98;
			break;
		}

		st.pop();
	}

	for (int j=0; j<8; j++)
	{
		cout << ss[j] << endl;
	}
}

string mysubstr(string& s, int i, int j)
{
	//Restricted Function??
	//return string(s, i, j);
	return string(s.begin()+i, s.begin()+(i+j));
}

int main()
{
	//ifstream cin("input.txt");

	int n;
	cin >> n;
	string s[8];
	getline(cin, s[0]);	// get rid of '\n'
	int i, j;
	while (--n >= 0)
	{
		for (i=0; i<8; i++)
		{
			getline(cin, s[i]);
			s[i] = s[i] + WS8;	// eight whitespaces
			//cout << s[i] << endl;
		}

		int k = 0;
		int n = s[0].length();
		int a[2] = {0, 0}; // operator
		int ai = 0;	// a[0]
		bool isRead = false;
		i = 0;
		while (i < n)
		{
			isRead = false;
			for (i=k; i<n; i++)		// row 4
			{
				if (s[4][i] == X)
				{
					if (mysubstr(s[4], i, 7) == X7)	// +
					{
						isRead = true;
						ai = 1;
						k = i + 7;
					}
					else if (mysubstr(s[4], i, 5) == X5)	// 9
					{
						isRead = true;
						a[ai] = a[ai] * 10 + 9;
						k = i + 5;
					}
					break;
				}
			}

			if (isRead)
				continue;
			for (i=k; i<n; i++)
			{
				if (s[0][i] == X)
				{
					if (mysubstr(s[0], i, 6) == X6)	// 7
					{
						isRead = true;
						a[ai] = a[ai] * 10 + 7;
						k = i + 6;
					}
					else if (mysubstr(s[0], i, 5) == X5)	// 5
					{
						isRead = true;
						a[ai] = a[ai] * 10 + 5;
						k = i + 5;
					}
					break;
				}
			}

			if (isRead)
				continue;
			for (i=k; i<n; i++)
			{
				if (s[3][i] == X)
				{
					if (mysubstr(s[3], i, 5) == X5)	// 6
					{
						isRead = true;
						a[ai] = a[ai] * 10 + 6;
						k = i + 6;
					}
					else if (mysubstr(s[3], i, 4) == X4)	// 8
					{
						isRead = true;
						a[ai] = a[ai] * 10 + 8;
						k = i + 5;
					}
					break;
				}
			}

			if (isRead)
				continue;
			for (i=k; i<n; i++)
			{
				if (s[1][i] == X)
				{
					if (mysubstr(s[1], i, 4) == X4)	// 1
					{
						isRead = true;
						a[ai] = a[ai] * 10 + 1;
						k = i + 6;
					}
					else if (mysubstr(s[1], i, 3) == X3)	// 4
					{
						isRead = true;
						a[ai] = a[ai] * 10 + 4;
						k = i + 4;
					}
					break;
				}
			}

			if (isRead)
				continue;
			for (i=k; i<n; i++)
			{
				if (s[3][i] == X)
				{
					if (mysubstr(s[3], i, 3) == X3)	// 3
					{
						isRead = true;
						a[ai] = a[ai] * 10 + 3;
						k = i + 4;
					}
					break;
				}
			}

			if (isRead)
				continue;
			for (i=k; i<n; i++)
			{
				if (s[7][i] == X)
				{
					if (mysubstr(s[7], i, 6) == X6)	// 2
					{
						isRead = true;
						a[ai] = a[ai] * 10 + 2;
						k = i + 6;
					}
					else if (mysubstr(s[7], i, 4) == X4)	// 0
					{
						isRead = true;
						a[ai] = a[ai] * 10;
						k = i + 5;
					}
					break;
				}
			}
		}

		print(a[0] + a[1]);
		//print(s[0].substr(0, 6).length());
		if (n != 0)
		{
			cout << endl;
		}
	}

	return 0;
}