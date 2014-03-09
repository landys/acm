// AC

#include <iostream>
//#include <fstream>
using namespace std;

//#define FILENAME "autoinput.txt"

struct Tile
{
	int t;
	int r;
	int b;
	int l;
	int num;
};

void printRes(bool flag, int count)
{
	if (flag)
	{
		cout << "Game " << count << ": Possible" << endl;
	}
	else
	{
		cout << "Game " << count << ": Impossible" << endl;
	}
}

bool nextJudge(int n, int& irow, int& icol)
{
	if (icol+1 == n)
	{
		if (irow+1 == n)
		{
			return true;
		}
		else
		{
			irow++;
			icol = 0;
		}
	}
	else
	{
		icol++;
	}
	return false;
}
bool judgeGame(Tile* a, int n, int m, int g[5][5], int irow, int icol)
{
	int cur = 0;
	while (true)
	{
		if (irow == 0 && icol == 0)
		{
			return false;
		}
		else if (irow == 0)
		{
			int i = 0;
			for (i=cur; i<m; i++)
			{
				if (a[i].num > 0 && a[g[irow][icol-1]].r == a[i].l)
				{
					g[irow][icol] = i;
					a[i].num--;
					if (nextJudge(n, irow, icol))
					{
						return true;
					}
					cur = 0;
					break;
				}
			}
			if (i == m)
			{
				cur = g[irow][icol-1] + 1;	
				a[g[irow][icol-1]].num++;
				icol--;
			}
		}
		else if (icol == 0)
		{
			int i = 0;
			for (i=cur; i<m; i++)
			{
				if (a[i].num > 0 && a[g[irow-1][icol]].b == a[i].t)
				{
					g[irow][icol] = i;
					a[i].num--;
					if (nextJudge(n, irow, icol))
					{
						return true;
					}
					cur = 0;
					break;
				}
			}
			if (i == m)
			{
				cur = g[irow-1][n-1] + 1;	
				a[g[irow-1][n-1]].num++;
				irow--;
				icol = n - 1;
			}
		}
		else
		{
			int i = 0;
			for (i=cur; i<m; i++)
			{
				if (a[i].num > 0 && a[g[irow-1][icol]].b == a[i].t && a[g[irow][icol-1]].r == a[i].l)
				{
					g[irow][icol] = i;
					a[i].num--;
					if (nextJudge(n, irow, icol))
					{
						return true;
					}
					cur = 0;
					break;
				}
			}
			if (i == m)
			{
				cur = g[irow][icol-1] + 1;	
				a[g[irow][icol-1]].num++;
				icol--;
			}
		}
	}
}

int main(void)
{
//	ifstream cin(FILENAME);
	int n = 0;
	int count = 0;
	int g[5][5];	// index
	cin >> n;
//	cout << n << endl;	//////////////////////////////////////
	while (n > 0)
	{
		count++;
		int m = n * n;
		Tile* a = new Tile[m];
		//m = readTiles(a, m);
		int t, r, b, l;
		int top = 0;
		for (int i=0; i<m; i++)
		{
			cin >> t >> r >> b >> l;
			int j = 0;
			for (j=0; j<top; j++)
			{
				if (a[j].t==t && a[j].r==r && a[j].b==b && a[j].l==l)
				{
					a[j].num++;
					break;
				}
			}
			if (j == top)
			{
				a[top].t = t;
				a[top].r = r;
				a[top].b = b;
				a[top].l = l;
				a[top].num = 1;
				top++;
			}
		}
		
		m = top;
/*////////////////////
		cout << "The result of readTiles" << endl;
		cout << "m=" << m << endl;
		for (int i=0; i<m; i++)
		{
			cout << a[i].t << ", " << a[i].r << ", " << a[i].b << ", " << a[i].l << ", num=" << a[i].num << endl;
		}
///////////////////*/
		if (n == 1)
		{
			printRes(true, count);
		}
		else
		{
			bool flag = false;
			for (int i=0; i<m; i++)
			{
				g[0][0] = i;
				a[i].num--;
				if (judgeGame(a, n, m, g, 0, 1))
				{
					flag = true;
					break;
				}
			}
			printRes(flag, count);
			delete a;
		}
		cin >> n;
		if (n != 0)
		{
			cout << endl;
		}
	}

	return 0;
}
//////

// Time Limit Exceeded
// Not think of the same tile
/*#include <iostream>
using namespace std;

struct Tile
{
	int t;
	int r;
	int b;
	int l;
	int rm[25];
	int bm[25];
	int ri;
	int bi;
	int num;
};

void readTiles(Tile* a, int m)
{
	for (int i=0; i<m; i++)
	{
		cin >> a[i].t >> a[i].r >> a[i].b >> a[i].l;
		a[i].ri = 0;
		a[i].bi = 0;
		a[i].num = 1;
	}
}
void printRes(bool flag, int count)
{
	if (flag)
	{
		cout << "Game " << count << ": Possible" << endl;
	}
	else
	{
		cout << "Game " << count << ": Impossible" << endl;
	}
}
void preMatch(Tile* a, int m)
{
	for (int i=0; i<m; i++)
	{
		int ri = 0;
		int bi = 0;
		for (int j=0; j<m; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (a[i].r == a[j].l)
			{
				a[i].rm[ri++] = j;
			}
			if (a[i].b == a[j].t)
			{
				a[i].bm[bi++] = j;
			}
		}
		a[i].rm[ri] = -1;
		a[i].bm[bi] = -1;
	}
}

bool nextJudge(int n, int& irow, int& icol)
{
	if (icol+1 == n)
	{
		if (irow+1 == n)
		{
			return true;
		}
		else
		{
			irow++;
			icol = 0;
		}
	}
	else
	{
		icol++;
	}
	return false;//judgeGame(a, n, g, nrow, ncol);
}
bool judgeGame(Tile* a, int n, int g[5][5], int irow, int icol)
{
	while (true)
	{
		if (irow == 0 && icol == 0)
		{
			return false;
		}
		else
		{
			if (irow == 0)
			{
				bool flag = false;
				while (a[g[irow][icol-1]].rm[a[g[irow][icol-1]].ri] != -1)
				{
					if (a[a[g[irow][icol-1]].rm[a[g[irow][icol-1]].ri]].num > 0)
					{
						g[irow][icol] = a[g[irow][icol-1]].rm[a[g[irow][icol-1]].ri];
						a[g[irow][icol]].ri = 0;
						a[g[irow][icol]].bi = 0;
						a[g[irow][icol]].num = 0;
						a[g[irow][icol-1]].ri++;
						if (nextJudge(n, irow, icol))
						{
							return true;
						}
						flag = true;
						break;
						//return judgeGame(a, n, g, irow, icol); 
					}
					a[g[irow][icol-1]].ri++;
				}
				if (flag)
				{
					continue;
				}
				a[g[irow][icol-1]].num = 1;
				icol--;
				continue;
				//return judgeGame(a, n, g, irow, icol-1);
			}
			else if (icol == 0)
			{
				bool flag = false;
				while (a[g[irow-1][icol]].bm[a[g[irow-1][icol]].bi] != -1)
				{
					if (a[a[g[irow-1][icol]].bm[a[g[irow-1][icol]].bi]].num > 0)
					{
						g[irow][icol] = a[g[irow-1][icol]].bm[a[g[irow-1][icol]].bi];
						a[g[irow][icol]].ri = 0;
						a[g[irow][icol]].bi = 0;
						a[g[irow][icol]].num = 0;
						a[g[irow-1][icol]].bi++;
						if (nextJudge(n, irow, icol))
						{
							return true;
						}
						flag = true;
						break;
						//return judgeGame(a, n, g, irow, icol);
					}
					a[g[irow-1][icol]].bi++;
				}
				if (flag)
				{
					continue;
				}
				if (--a[g[irow-1][icol]].bi == -1)
				{
					for (int i=icol; i<n; i++)
					{
						a[g[irow-1][i]].num = 1;
					}
					irow--;
					continue;
					//return judgeGame(a, n, g, irow-1, icol);
				}
				a[g[irow-1][icol]].bi = 0;
				a[g[irow-1][n-1]].num = 1;
				irow--;
				icol = n - 1;
				continue;
				//return judgeGame(a, n, g, irow-1, n-1);
			}
			else
			{		
				bool flag = false;	
				while (a[g[irow][icol-1]].rm[a[g[irow][icol-1]].ri] != -1)
				{
					if (a[a[g[irow][icol-1]].rm[a[g[irow][icol-1]].ri]].num > 0)
					{
						a[g[irow-1][icol]].bi = 0;
						while (a[g[irow-1][icol]].bm[a[g[irow-1][icol]].bi] != -1)
						{
							if (a[g[irow][icol-1]].rm[a[g[irow][icol-1]].ri] == a[g[irow-1][icol]].bm[a[g[irow-1][icol]].bi])
							{
								g[irow][icol] = a[g[irow][icol-1]].rm[a[g[irow][icol-1]].ri];
								a[g[irow][icol]].ri = 0;
								a[g[irow][icol]].bi = 0;
								a[g[irow][icol]].num = 0;
								a[g[irow][icol-1]].ri++;
								if (nextJudge(n, irow, icol))
								{
									return true;
								}
								flag = true;
								break;
								
								//return judgeGame(a, n, g, irow, icol); 						
							}
							a[g[irow-1][icol]].bi++;
						}
						if (flag)
						{
							break;
						}
					}
					a[g[irow][icol-1]].ri++;
				}
				if (flag)
				{
					continue;
				}

				a[g[irow][icol-1]].num = 1;
				icol--;
				continue;
				//return judgeGame(a, n, g, irow, icol-1);
			}
		}	
	}
}

int main(void)
{
	int n = 0;
	int count = 0;
	int g[5][5];	// index
	cin >> n;
//	cout << n << endl;	//////////////////////////////////////
	while (n > 0)
	{
		count++;
		int m = n * n;
		Tile* a = new Tile[m];
		readTiles(a, m);
/////////////////////
		cout << "The result of readTiles" << endl;
		for (int i=0; i<m; i++)
		{
			cout << a[i].t << ", " << a[i].r << ", " << a[i].b << ", " << a[i].l << endl;
		}
////////////////////
		if (n == 1)
		{
			printRes(true, count);
		}
		else
		{
			preMatch(a, m);
/////////////////////
			cout << "The result of preMatch" << endl;
			for (int i=0; i<m; i++)
			{
				//cout << "a[" << i << "].ri=" << a[i].ri << ", ";
				//cout << "a[" << i << "].bi=" << a[i].bi << endl;
				cout << "rm: " << endl;
				for (int j=0; a[i].rm[j]!=-1; j++)
				{
					cout << a[i].rm[j] << ", ";
				}
				cout << endl << "bm: " << endl;
				for (int j=0; a[i].bm[j]!=-1; j++)
				{
					cout << a[i].bm[j] << ", ";
				}
				cout << endl;
			}
//////////////////////
			bool flag = false;
			for (int i=0; i<m; i++)
			{
				g[0][0] = i;
				a[i].ri = 0;
				a[i].bi = 0;
				a[i].num = 0;
				if (judgeGame(a, n, g, 0, 1))
				{
					flag = true;
					break;
				}
			}
			printRes(flag, count);
			delete a;
		}
		cin >> n;
		if (n != 0)
		{
			cout << endl;
		}
	}

	return 0;
}*/
