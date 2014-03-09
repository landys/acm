// AC

// width-first search

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

class Node
{
public:
	int i;
	int j;
	int n;
	Node(int i=0, int j=0, int n=0)
	{
		this->i = i;
		this->j = j;
		this->n = n;
	}
};

int main()
{
	//ifstream cin("input.txt");

	const int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
		{1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
	
	char t1, t2, t3, t4;
	int bi, bj, ei, ej;
	int i;
	while (cin >> t1 >> t2 >> t3 >> t4)
	{
		if (t1==t3 && t2==t4)
		{
			cout << "To get from " << t1 << t2 << " to " << t3 << t4 << " takes " << 0 << " knight moves." << endl;
			continue;
		}
		
		bi = t1 - 'a';
		bj = t2 - '1';
		ei = t3 - 'a';
		ej = t4 - '1';	
		int flag[8][8] = {0};
		queue<Node> qu;
		Node n(bi, bj);
		flag[bi][bj] = 1;
		qu.push(n);
		int step = -1;
		while (!qu.empty())
		{
			n = qu.front();
			qu.pop();
			for (i=0; i<8; i++)
			{
				int ii = n.i + dir[i][0];
				int jj = n.j + dir[i][1];
				if (ii==ei && jj==ej)
				{
					step = n.n + 1;
				}
				if (ii>=0 && ii<8 && jj>=0 && jj<8 && flag[ii][jj]==0)
				{
					qu.push(Node(ii, jj, n.n+1));
				}
			}
			if (step != -1)
			{
				break;
			}
		}

		cout << "To get from " << t1 << t2 << " to " << t3 << t4 << " takes " << step << " knight moves." << endl;

	}
	
	return 0;
}
