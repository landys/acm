// AC

#include <iostream>
#include <string>
// #include <fstream>
using namespace std;

string s1 = "";
string s2 = "";
string io = "";
string temp = "";
int toptemp = -1;

void print()
{
	for (int i=0; i<io.length(); i++)
	{
		cout << io[i] << ' ';
	}
	cout << endl;
}

void stack(int top1, int top2, int topio)
{
	if (top1 == -1)
	{
		if (toptemp > -1)
		{
			return;
		}
		print();
		
		while (top1 == -1)	// when ...ioioio, go on back
		{
			while (io[topio--] == 'o')
			{
				s1[++top1] = s2[--top2];
			}
			if (topio == -1)
			{
				return;
			}
			temp[++toptemp] = s1[top1--];
			s1[top1+1] = '\0';	//////////////////////////
		}
	}
	if (s1[top1] == s2[top2])
	{
		io[++topio] = 'o';
		s1[top1] = '\0';	//////////////////////
		top1--;
		top2++;
		
		while (toptemp >= 0)
		{
			s1[++top1] = temp[toptemp--];
			temp[toptemp+1] = '\0';	////////////////////////////
			io[++topio] = 'i';
		}
	
		stack(top1, top2, topio);
	}
	else
	{
		int t = topio;
		while (io[t--] != 'i');
		for (int i=t+1; i<topio; i++)
		{
			io[i] = io[i+1];
		}
		io[topio--] = '\0';
		if (topio != t && io[topio] == 'o')
		{
			s1[++top1] = s2[top2--];
			io[topio--] = '\0';
		}
		temp[++toptemp] = s1[top1--];
		s1[top1+1] = '\0';	////////////////////
		stack(top1, top2, topio);
	}
}

int main(void)
{
	// ifstream cin("input.txt");
	
	while (cin >> s1 >> s2)
	{
		if (s1.length() != s2.length())
		{
			cout << "[\n]\n";
			continue;
		}
		temp = "";
		toptemp = -1;
		io = "";
		for (int i=0; i<s2.length(); i++)
		{
			io += 'i';
			temp += '\0';
		}
		io += temp;
		cout << '[' << endl;
		stack(s1.length()-1, 0, s2.length()-1);
		cout << ']' << endl;
	}

	return 0;
}	///:~