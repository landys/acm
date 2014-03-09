#include <iostream>
using namespace std;

int main()
{
	int s;
	int t = 0;
	cin >> s;
	while (s != 0)
	{
		t++;
		double temp = double(s) / 2 * 1.5;
		s = int(temp);
		if (temp - s >= 0.5)
		{
			s++;
		}

		int n = s / (30000 * 62);
		if (s % (30000 * 62) != 0)
		{
			n++;
		}
		cout << "File #" << t << "\nJohn needs " << n << " floppies." << endl << endl;
		cin >> s;
	}
	
	return 0;
}	///:~