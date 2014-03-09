#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	char c[1000000];
	char tmp;
	int row[1000000];
	int col[1000000];

	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> tmp;
		int j = int(tmp - 'A');
		c[j] = tmp;
		cin >> row[j] >> col[j];
	}

	int stack[1000000];
	int a, b;
	string temp;
	
	while (cin >> temp)
	{
		int count = n;
		int top = -1;
		int sum = 0;
		int i = 0;

		while (true)
		{
			if (temp[i] == '(')
			{
				i++;
				continue;
			}
			if (temp[i] == ')')
			{
				b = stack[top--];
				a = stack[top];
				if (col[a] != row[b])
				{
					cout << "errer" << endl;
					break;
				}
				sum += row[a] * col[a] * col[b];
				stack[top] = count;
				row[count] = row[a];
				col[count] = col[b];
				count++;
			}
			else if (temp[i] <= 'Z' && temp[i] >= 'A')
			{
				stack[++top] = int(temp[i] - 'A');
			}
			if (!temp[++i])
			{
				cout << sum << endl;
				break;
			}
		}
	}

	return 0;
}