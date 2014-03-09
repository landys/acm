// Accept

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int p, s;
	int t = 0;
	string str = "";
	
	while (cin >> p >> s && p != 0)
	{
		t++;
		int k = s - p;
		if (s == 1)
		{
			str = "Hole-in-one.";
		}
		else if (k <= -3)
		{
			str = "Double Eagle.";
		}
		else if (k == -2)
		{
			str = "Eagle.";
		}
		else if (k == -1)
		{
			str = "Birdie.";
		}
		else if (k == 0)
		{
			str = "Par.";
		}
		else if (k == 1)
		{
			str = "Bogey.";
		}
		else 
		{
			str = "Double Bogey.";
		}
		cout << "Hole #" << t << endl << str << endl << endl;
	}
	
	return 0;
}	///:~
