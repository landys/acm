// AC
// 00 00 : 37

#include <iostream>
#include <cmath>
//#include <fstream>
using namespace std;

class Node
{
public:
	int e;
	Node* next;

	Node() : e(0), next(0) {}
};

class Hashtable
{
public:
	Hashtable() : tablesize(0), list(0) {}
	//virtual ~Hashtable() { delete []list; }
	void initial(int size)
	{
		tablesize = nextprime(size);
		list = new Node* [tablesize];
		for (int i=0; i<tablesize; i++)
		{
			list[i] = new Node;
		}
	}
	//void empty()
	//{
		//for (int i=0; i<tablesize; i++)
		//{
		//Node* p = list[i];
			//Node* pp = p;
			///while (pp != 0)
			//{
			//	pp = p->next;
			//	delete p;
			//}
	//	}
	//}
	Node* find(const int& x)
	{
		Node* p = list[hash(x)];
		while (p != 0 && p->e != x)
		{
			p = p->next;
		}
		return p;
	}
	void insert(const int& x)
	{
		Node* p = find(x);
		if (!p)
		{
			Node* pp = new Node;
			pp->e = x;
			Node* p = list[hash(x)];
			pp->next = p->next;
			p->next = pp;
		}
	}
private:
	int tablesize;
	Node **list;
	bool isprime(const int& x)
	{
		if (x == 1)
		{
			return false;
		}
		bool flag = true;
		int k = sqrt(x);
		for (int i=2; i<=k; i++)
		{
			if (x % i == 0)
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
	int nextprime(const int& x)
	{
		for (int i=x; !isprime(i); i++);
		return i;
	}
	int hash(const int& x)
	{
		return ((x * 27) % tablesize);
	}
};

int main()
{
	//ifstream cin("input.txt");
	int n;
	int *a = new int[500000];
	
	int k = 0; 
	a[0] = 0;
	Hashtable t;
	t.initial(500000);

	while (cin >> n && n != -1)
	{
		if (n <= k)
		{
			cout << a[n] << endl;
			continue;
		}

		while (++k <= n)
		{
			bool flag = true;
			a[k] = a[k-1] - k;
			if (a[k] <= 0)
			{
				flag = false;
			}
			else 
			{
				if (t.find(a[k]))
				{
					flag = false;				
				}
			}
			if (!flag)
			{
				a[k] = a[k-1] + k;
			}
			t.insert(a[k]);
		}
		k--;
		
		cout << a[n] << endl;
	}
	//delete []a;
	// t.empty();
	return 0;
}	///:~*/


/*// AC
// 00 00 : 09

#include <iostream>
//#include <fstream>
using namespace std;

class Flag
{
public:
	bool flag;
	Flag() : flag(false) {}
};

int main()
{
	//ifstream cin("input.txt");
	int n;
	int *a = new int[500000];
	Flag *b = new Flag[3012501];
	
	int k = 0; 
	a[0] = 0;

	while (cin >> n && n != -1)
	{
		if (n <= k)
		{
			cout << a[n] << endl;
			continue;
		}

		while (++k <= n)
		{
			bool flag = true;
			a[k] = a[k-1] - k;
			if (a[k] <= 0 || b[a[k]].flag)
			{
				a[k] = a[k-1] + k;
			}
			b[a[k]].flag = true;
		}
		k--;
		
		cout << a[n] << endl;
	}

	//delete []a;
	// t.empty();
	return 0;
}	///:~*/