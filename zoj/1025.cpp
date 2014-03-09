// AC

#include <iostream>
// #include <fstream>
using namespace std;

int k = 0;

class Stick
{
public:
	int len;
	int w;
	Stick() : len(0), w(0) {}
};

class Node
{
public:
	Node(const int& xx = 0) : x(xx), next(0) {}
	int x;
	Node* next;
};

class List
{
public:
	List(Node* h = 0);
	void insert(const int& x);
	~List();
private:
	Node* head;
};

List::List(Node *h) : head(h) {}

List::~List()
{
	Node* p = head;
	while (head != 0)
	{
		head = head->next;
		delete p;
		p = head;
	}
}

void List::insert(const int& x)
{
	
	if (!head)
	{
		Node* pp = new Node(x);
		head = pp;
		k++;
		return;
	}

	Node* p = head;
	Node* p2 = head;
	while (p)
	{
		if (p->x <= x)
		{
			p->x = x;
			break;
		}
		p2 = p;
		p = p->next;
	}
	if (!p)
	{
		Node* pp = new Node(x);
		p2->next = pp;
		k++;
	}
}


/* void swap(Stick& a, Stick& b)
{
	a.len ^= b.len ^= a.len ^= b.len;
	a.w ^= b.w ^= a.w ^= b.w;
} */

void insertsort(Stick* a, int m, int n)
{
	for (int i=m+1; i<=n; i++)
	{
		Stick temp = a[i];
		int j = 0;
		for (j=i-1; j>=m && a[j].len>temp.len; j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = temp;
	}
}

/* int mid(Stick& a, Stick& b, Stick& c)
{
	if (a.len > b.len)
	{
		swap(a, b);
	}
	if (a.len > c.len)
	{
		swap(a, c);
	}
	if (b.len > c.len)
	{
		swap(b, c);
	}

	return b.len;
}

void quicksort(Stick* a, int m, int n)
{
	if (n - m < 10)
	{
		insertsort(a, m, n);
	}
	else
	{
		int pivot = mid(a[m], a[(n-m)/2], a[n]);
		swap(a[(n-m)/2], a[n-1]);
		int i = m;
		int j = n - 1;
		while (true)
		{
			while (++i < j - 1)
			{
				if (a[i].len > pivot)
				{
					break;
				}
			}
			while (--j > i + 1)
			{
				if (a[--j].len < pivot)
				{
					break;
				}
			}
			if (i < j)
			{
				swap(a[i], a[j]);
			}
			else 
			{
				break;
			}
		}
		swap(a[i], a[n-1]);
		quicksort(a, 0, i-1);
		quicksort(a, i+1, n);
	}
} */

int main()
{
	// ifstream cin("input.txt");
	int re = 0;
	cin >> re;
	while (--re >= 0)
	{
		int n = 0;
		cin >> n;
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}

		Stick *a = new Stick[n];
		for (int i=0; i<n; i++)
		{
			cin >> a[i].len >> a[i].w;
		}
		// quicksort(a, 0, n-1);
		insertsort(a, 0, n-1);

		k = 0;
		List list;
		for (int j=0; j<n; j++)
		{
			list.insert(a[j].w);
		}
		cout << k << endl;
		delete []a;
	}

	return 0;
}	///:~