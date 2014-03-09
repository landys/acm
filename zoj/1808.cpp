#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Tree
{
public:
	Tree(Tree* ll = 0, Tree* rr = 0) : l(ll), r(rr) { flag = false; }
	virtual ~Tree()
	{
		delete l;
		delete r;
	}
	Tree* left() { return l; }
	Tree* right() { return r; }
	bool mark() { return flag; }
	void change() { flag = true; }
	void ladd(Tree* t) { l = t; }
	void radd(Tree* t) { r = t; }
private:
	Tree* l;
	Tree* r;
	bool flag;
};

int main()
{
	ifstream cin("input.txt");

	string s = "";
	Tree t;
	int k = 0;
	while (getline(cin, s))
	{
		if (s[0] == '9')
		{
			k++;
			cout << "Set " << k << " is immediately decodable" << endl;
			(t.left())->clear();
			(t.right())->clear();
			continue;
		}
		int i = 0;
		Tree* tt = &t;
		while (s[i])
		{
			if (s[i] == '0')
			{
				if (tt->left() == 0)
				{
					Tree* p = new Tree;
					tt->ladd(p);
				}
				else
				{
					if (tt->mark() || i == s.length() - 1)	// s[i+1] == '\0'
					{
						k++;
						cout << "Set " << k << " is not immediately decodable" << endl;
						//////////////////////
						break;
					}
				}
				if (s[++i] == '\0')
				{
					tt->change();
					tt = tt->left();
				}
			}
			else
			{
				if (tt->right() == 0)
				{
					Tree* p = new Tree;
					tt->radd(p);
				}
				else
				{
					if (tt->mark() || i == s.length() - 1)	// s[i+1] == '\0'
					{
						k++;
						cout << "Set " << k << " is not immediately decodable" << endl;
						///////////////////////
						break;
					}
				}
				if (s[++i] == '\0')
				{
					tt->change();
					tt = tt->right();
				}
			}
		}

	}

	return 0;
}	///:~