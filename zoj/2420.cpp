// WA

#include <iostream>
// #include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// ifstream cin("input.txt");
	enum Weekday {Sun, Mon, Tue, Wed, Thur, Fri, Sat} weekday;

	int n;
	while (cin >> n && n >= 0)
	{
		bool flag = true;
		int nn = n;

		int y = (n / (((365 * 4 + 1) * 25 - 1) * 4 + 1)) * 400;
		n %= ((365 * 4 + 1) * 25 - 1) * 4 + 1;
		if (n >= (365 * 4 + 1) * 25)
		{
			n -= (365 * 4 + 1) * 25;
			y += (n / ((365 * 4 + 1) * 25 - 1)) * 100 + 100;
			n %= (365 * 4 + 1) * 25 - 1;
			
			if (n >= (365 * 4))
			{
				n -= (365 * 4);
				y += n / (365 * 4 + 1) * 4 + 4;
				n %= (365 * 4 + 1);
				if (n >= 366)
				{
					n -= 366;
					y += n / 365 + 1;
					n = n % 365;
					flag = false;
				}
			}
			else
			{
				y += n / 365;
				n %= 365;
				flag = false;
			}
		}
		else
		{
			y += (n / (365 * 4 + 1)) * 4;
			n %= (365 * 4 + 1);
			if (n >= 366)
			{
				n -= 366;
				y += n / 365 + 1;
				n %= 365;
				flag = false;
			}
		}
		
		y += 2000;
		int m = 0;
		if (flag && n >= 61)	// when n == 60, give a additional case
		{
			n--;
		}

		if (n < 31)
		{
			m = 1;
		}
		else if (n < 59 || (flag && n == 59))
		{
			n -= 31;
			m = 2;
		}
		else if (flag && n == 60)
		{
			n = 0;
			m = 3;
		}
		else if (n < 90)
		{
			n -= 59;
			m = 3;
		}
		else if (n < 120)
		{
			n -= 90;
			m = 4;
		}
		else if (n < 151)
		{
			n -= 120;
			m = 5;
		}
		else if (n < 181)
		{
			n -= 151;
			m = 6;
		}
		else if (n < 212)
		{
			n -= 181;
			m = 7;
		}
		else if (n < 243)
		{
			n -= 212;
			m = 8;
		}
		else if (n < 273)
		{
			n -= 243;
			m = 9;
		}
		else if (n < 304)
		{
			n -= 273;
			m = 10;
		}
		else if (n < 334)
		{
			n -= 304;
			m = 11;
		}
		else
		{
			n -= 334;
			m = 12;
		}

		int d = n + 1;

		weekday = Weekday((nn + int(Sat)) % 7);
		string str = "";
		switch (weekday)
		{
		case Sun:
			str = "Sunday";
			break;
		case Mon:
			str = "Monday";
			break;
		case Tue:
			str = "Tuesday";
			break;
		case Wed:
			str = "Wednesday";
			break;
		case Thur:
			str = "Thursday";
			break;
		case Fri:
			str = "Friday";
			break;
		case Sat:
			str = "Saturday";
			break;
		}

		cout << y << '-' << setw(2) << setfill('0') << m << '-'
			 << setw(2) << setfill('0') << d << ' ' << str << endl;
	}

	return 0;
}	///:~