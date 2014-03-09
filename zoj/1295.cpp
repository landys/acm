// Accept

/* #include <iostream>
#include <string>
using namespace std;

void reverse(const char* str, int j)
{
	if (str[j+1] != '\0')
	{
		reverse(str, j+1);
	}
	cout << str[j];
}
	

int main(void)
{
	int n;
	cin >> n;
	char str[80];
	cin.ignore();

	for (int i=0; i<n; i++)
	{
		cin.getline(str, 80);
		reverse(str, 0);
		cout << endl;
	}

	return 0;
}
*/

#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	char str[80];
	cin.ignore();

	for (int i=0; i<n; i++)
	{
		cin.getline(str, 80);
		int j = 0;
		while (str[j++] != '\0');
		for (int t=j-2; t>=0; t--)
		{
			cout << str[t];
		}
		cout << endl;
	}

	return 0;
}