// AC

// Rember expresion like !!!!!!!V, two ! equals none

#include <stack>
#include <iostream>
//#include <fstream>
#include <string>

using namespace std;

void print(int i, bool f)
{
	if (f)
	{
		cout << "Expression " << i << ": V" << endl;
	}
	else
	{
		cout << "Expression " << i << ": F" << endl;
	}
}

// int cmpPriority(char a, char b)
// {
// 	if (a == b)
// 	{
// 		return 0;
// 	}
// 	else if (a == '!')
// 	{
// 		return 1;
// 	}
// 	else if (b == '!')
// 	{
// 		return -1;
// 	}
// 	else if (a == '&')
// 	{
// 		return 1;
// 	}
// 	else
// 	{
// 		return -1;
// 	}
// 	
// }

bool calc(char op, bool a, bool b=false)
{
	switch (op)
	{
	case '!':
		return (!a);
		break;
	case '|':
		return (a || b);
		break;
	case '&':
		return (a && b);
		break;
	}
	return false;
}

int main()
{
	//ifstream cin("input.txt");
	
	string s;
	int count = 0;
	while (getline(cin, s))
	{
		int n = s.length();
		stack<char> sc;
		sc.push('*');
		stack<bool> sb;
		bool re = true;
		for (int i=0; i<n; i++)
		{
			switch (s[i])
			{
			case '(':
				sc.push('(');
				break;
			case 'V':
				sb.push(true);
				break;
			case 'F':
				sb.push(false);
				break;
			case ')':
				while (sc.top() != '(')
				{
					if (sc.top() == '!')
					{
						re = calc('!', sb.top());
						sb.pop();
						sb.push(re);
					}
					else
					{
						bool a = sb.top();
						sb.pop();
						bool b = sb.top();
						sb.pop();
						re = calc(sc.top(), a, b);
						sb.push(re);
					}
					sc.pop();
				}
				sc.pop();
				break;
			case '!':
				if (sc.top() == '!')
				{
					sc.pop();
				}
				else
				{
					sc.push('!');
				}
				break;
			case '|':
				if (sc.top() == '*' || sc.top() == '(')
				{
					sc.push('|');
				}
				else
				{
					while (sc.top() != '*' && sc.top() != '(')
					{
						if (sc.top() == '!')
						{
							re = calc(sc.top(), sb.top());
							sb.pop();
							sb.push(re);
						}
						else
						{
							bool a = sb.top();
							sb.pop();
							bool b = sb.top();
							sb.pop();
							re = calc(sc.top(), a, b);
							sb.push(re);
						}
						sc.pop();
					}
					sc.push('|');
				}
				break;
			case '&':
				if (sc.top() == '*' || sc.top() == '(' || sc.top() == '|')
				{
					sc.push('&');
				}
				else
				{
					while (sc.top() != '*' && sc.top() != '(' && sc.top() != '|')
					{
						if (sc.top() == '!')
						{
							re = calc(sc.top(), sb.top());
							sb.pop();
							sb.push(re);
						}
						else
						{
							bool a = sb.top();
							sb.pop();
							bool b = sb.top();
							sb.pop();
							re = calc(sc.top(), a, b);
							sb.push(re);
						}
						sc.pop();
					}
					sc.push('&');
				}
				break;
			}
		}
		while (sc.top() != '*')
		{
			if (sc.top() == '!')
			{
				re = calc(sc.top(), sb.top());
				sb.pop();
				sb.push(re);
			}
			else
			{
				bool a = sb.top();
				sb.pop();
				bool b = sb.top();
				sb.pop();
				re = calc(sc.top(), a, b);
				sb.push(re);
			}
			sc.pop();
		}
		
		if (!sb.empty())
		{
			print(++count, sb.top());
		}
		
	}

	return 0;
}