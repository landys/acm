// incompleted

#include <iostream>
#include <deque>
#include <utility>
#include <string>
#include <fstream>
using namespace std;

int Level[10] = {0};
int Current = 0;

int main(void)
{
	ifstream cin("input.txt");
	deque<pair<string, int>> que;
	char temp;

	int i, j;
	for (i=0; i<10; i++)
	{
		Level[i] = 0;
	}
	Current = 0;

	pair<string, int> p;
	cin >> p.first >> p.second;
	que.push_back(p);
	
	while (!que.empty())
	{
		print(que.front(), 	
		if (cin.peek() == '(')
		{
			cin >> temp;
			if (cin.peek() == ')')
			{
				while (!que.empty())
				{
					
				}
			}
		}
					

	}
}