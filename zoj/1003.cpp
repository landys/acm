// AC

#include <iostream>
// #include <fstream>
using namespace std;

bool Factor[101];

bool scanfactor(int n, int m)
{
	if (n == 1)
	{
		return true;
	}

	while (m >= 2)
	{
		if (!Factor[m] && n % m == 0)
		{
			break;
		}
		m--;
	}
	if (m < 2)
	{
		return false;
	}

	if (scanfactor(n / m, m - 1))
	{
		return true;
	}

	return scanfactor(n, m - 1);
}

bool ispossible(int a, int b, int m)
{
	if (a == 1)
	{
		return scanfactor(b, 100);
	}
	
	while (m >= 2 && a % m != 0)
	{
		m--;
	}
	if (m < 2)
	{
		return false;
	}
	
	Factor[m] = true;
	if (ispossible(a / m, b, m-1))
	{
		return true;
	}
	
	Factor[m] = false;
	return ispossible(a, b, m-1);
}

int main()
{
	// ifstream cin("input.txt");
	int a, b;
	while (cin >> a >> b)
	{
		for (int i=0; i<101; i++)
		{
			Factor[i] = false;
		}
		if (a < b)
		{
			a ^= b ^= a ^= b;
		}

		if (b > 100 && !scanfactor(b, 100))
		{
			cout << a << endl;
			continue;
		}
		
		if (ispossible(a, b, 100))
		{
			cout << a << endl;
			continue;
		}
		cout << b << endl;

		getchar();
	}

	return 0;
}	///:~
		

/* // Time limit exceeded

#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	ifstream cin("input.txt");
	long a, b, tempa, tempb;
	int win = 0;
	int flag = 0;
	int stack[100];
	int stack2[100];
	int list[101];
	int top = -1;
	int top2 = -1;
	int i, j;

    while (cin >> a >> b)
	{
		if (a < b)
		{
			tempa = b;
			b = a;
			a = tempa;
		}
		
		for (int t=0; t<101; t++)
		{
			list[t] = t;
		}
		tempa = a;
		tempb = b;
		win = 0;
		flag = 0;
		top = top2 = -1;
		
		i = 2;
		while (win == 0)
		{
			while (1)
			{
				if (list[i] != 1 && tempb % list[i] == 0)
				{
					tempb /= list[i];
					list[i] = 1;
					stack[++top] = i;
					if (tempb == 1)
					{
						break;
					}
				}
				if (tempb <= i || i == 100)
				{
					if (top < 0)
					{
						break;
					}
					tempb *= stack[top];
					list[stack[top]] = stack[top];
					i = stack[top--] + 1;
				}
				i++;
			}
			if (tempb != 1)
			{
				if (flag == 1)
				{
					if (top < 0)
					{
						win = 2;
						break;
					}
					else
					{
					    list[stack[top]] = stack[top];
						tempb *= stack[top];
						i = stack[top--] + 1;
						continue;
					}
				}
				else
				{
					win = 1;
					break;
				}
			}
			
			tempa = a;
			for (j=2; ; j++)
			{
				if (list[j] != 1 && tempa % list[j] == 0)
				{
					tempa /= list[j];
					stack2[++top2] = list[j];
					if (tempa == 1)
					{
						win = 1;
						break;
					}
				}
				if (tempa <= j || j == 100)
				{
					if (top2 < 0)
					{
						break;
					}
					tempa *= stack2[top2];
					j = stack2[top2--] + 1;
				}
			}
			if (tempa != 1)
			{
				flag = 1;
			}
		}

		if (win == 1)
		{
			cout << a << endl;
		}
		else
		{
			cout << b << endl;
		}
	}

	return 0;
} */

/* #include <fstream>
#include <iostream> 
#include <cstring> 
using namespace std; 

int a, b; 
bool upheld; 
int tag[101]; 

void judge(int x, int down) 
{ 
   if (!upheld) 
      return; 
   if (down <= 0 || x <= 1) 
      return; 
   if (x <= 100 && tag[x] == 0) 
   { 
      upheld = false; 
      return; 
   } 
   int i; 
   for (i = down; i >= 2; --i) 
    if (x % i == 0 && x / i != i && tag[i] == 0) 
   { 
      judge(x, i - 1); 
      judge(x / i, i - 1); 
   } 
   return; 
} 
void dfs(int x, int down) 
{ 
   if (!upheld) 
      return; 
   if (down <= 0) 
      return; 
   if (x <= 100 && tag[x] == 0) 
   { 
      tag[x] = 1; 
      judge(a, 100); 
      tag[x] = 0; 
   } 
   int i; 
   for (i = down; i >= 2; --i) 
   if (x % i == 0 && x / i != i) 
   { 
      tag[i] = 0; 
      dfs(x, i - 1); 
      tag[i] = 1; 
      dfs(x / i, i - 1); 
      tag[i] = 0; 
   } 
   return; 
} 
void dfs1(int x, int down) 
{ 
   if (upheld) 
      return; 
   if (down <= 0) 
      return; 
   if (x <= 100 && tag[x] == 0) 
   { 
      upheld = true; 
      return; 
   } 
   int i; 
   for (i = down; i >= 2; --i) 
   { 
      if (x % i == 0 && x / i != i) 
      { 
         tag[i] = 0; 
         dfs1(x, i - 1); 
         tag[i] = 1; 
         dfs1(x / i, i - 1); 
         tag[i] = 0; 
      } 
   } 
   return; 
} 
int main() 
{ 
	ifstream cin("input.txt");
   while (cin >> a >> b) 
   { 
      if (a > b) 
         a ^= b ^= a ^= b; 
      if (a == b) 
      { 
         cout << a << endl; 
         continue; 
      } 
      memset(tag, 0, sizeof(tag)); 
      upheld = false; 
      dfs1(a, 100); 
      if (upheld) 
      { 
         memset(tag, 0, sizeof(tag)); 
          upheld = true; 
          dfs(b, 100); 
      } 
      if (upheld) 
         cout << a << endl; 
      else 
         cout << b << endl; 
   } 
   return 0; 
} */

/*#include <iostream> 
#include <fstream>
#include <cmath> 
using namespace std; 

const int MAX = 100; 
bool UsedBalloon[MAX+1]; 

bool CanFactor(int i, int b) 
{ 
	if (b == 1) { 
		return true; 
	} 
	else { 
		while (i <= MAX) { // find a possible factor of b 
			if ( (!UsedBalloon[i]) && ((b % i) == 0) ) { 
				break; 
			} 
			else { 
				i++; 
			} 
		} 
		if (i > MAX) return false; 

// try the factor i 
		if (CanFactor(i+1, b / i)) { 
			return true; 
		} 
		else { 
// i can not be a factor 
			return CanFactor(i + 1, b); 
		} 
	} 
} 

bool IsPossible(int i, int a, int b) 
{ 
	if (i > MAX) return false; 
	if (a == 1) return (CanFactor(1, b)); // try to factor b 

	while (i <= MAX) { // find a possible factor of a 
		if ((a % i) == 0) { 
		break; 
		} 
		else { 
			i++; 
		} 
	} 
	if (i > MAX) return false; 
	UsedBalloon[i] = true; 
	if (IsPossible(i + 1, a / i, b)) return true; // try a factor i of a 
	UsedBalloon[i] = false; 
	return (IsPossible(i + 1, a, b)); // try not use i as factor of a 
} 

int GetWinner(int a, int b) 
{ 
	for (int i = 0; i < MAX + 1; i++) { 
		UsedBalloon[i] = false; 
	} 

	if (a < b) { // make sure b is the chanllenge 
		int tmp = a; 
		a = b; 
		b = tmp; 
	} 
	if ((CanFactor(1, b) == false) && (b > 100)) { // chanllenge is lying. 
		return a; 
	} 
	else if (IsPossible(1, a, b)) { // is it possible? 
		return a; // chanllenge fail. 
	} 
	else { 
		return b; // it's impossible, chanllenge win. 
	} 
} 

int main() 
{ 
	int a, b; 
	
	ifstream cin("input.txt");
	while (cin >> a >> b) { 
		cout << GetWinner(a, b) << endl; 
	} 
	return 0; 
}*/
