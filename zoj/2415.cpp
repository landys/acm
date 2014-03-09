// Runtime Error SIGSEGV
// perimeter not correct


#include <iostream>
#include <cstdio>
using namespace std;

struct Type
{
	double area;
	double perimeter;
};

struct Node
{
	bool up;
	bool down;
	bool left;
	bool right;
};

int a[26][26];

int find(int);

int main()
{
	const double pi = 3.141593;
	
	const Type base = {4.0 * 2.0 + pi, 4.0 * 2.0 + 2.0 * pi};

	Type type[5];
	type[0].area = 0.0;
	type[0].perimeter = 0.0;
	// !type[1].area = 3 / 4 * pi + 1;	// Wrong
	type[1].area = 3.0 / 4.0 * pi + 1.0;
	type[1].perimeter = 3.0 / 4.0 * 2.0 * pi + 2.0;
	type[2].area = pi;
	type[2].perimeter = 2.0 * pi;
	type[3].area = type[2].area + pi / 2.0 + 2.0;
	type[3].perimeter = type[2].perimeter + pi + 2.0 + 2.0;
	type[4].area = 2.0 * type[2].area + 2.0 * 2.0;
	type[4].perimeter = 2.0 * type[2].perimeter + 2.0 * 4.0;
	

	int n = 0;
	while (cin >> n && n != 0)
	{
		Node node[26][26];	// determine b partly
		int b[26][26];	// b[][] = {-1, 0, 1, 2, 3, 4}, using as index of type
		for (int rr=0; rr<26; rr++)
		{
			for (int cc=0; cc<26; cc++)
			{
				a[rr][cc] = 26 * rr + cc;
				b[rr][cc] = -1;
				node[rr][cc].up = node[rr][cc].down = node[rr][cc].left = node[rr][cc].right = false;
			}
		}
		double area[26*26] = {0.0};
		double perimeter[26*26] = {0.0};
		
		for (int i=0; i<n; i++)
		{
			int row1, col1;
			int row2, col2;
			char temp;

			cin >> temp >> col1;
			row1 = int(temp - 'a');
			col1--;
			cin >> temp >> col2;
			row2 = int(temp - 'a');
			col2--;

			b[row1][col1]++;
			b[row2][col2]++;
			if (row1 == row2)
			{
				if (col1 > col2)
				{
					node[row1][col1].left = node[row2][col2].right = true;
					if ((b[row1][col1] == 1 && node[row1][col1].right) || b[row1][col1] == 2)
					{
						b[row1][col1]++;
					}
					if ((b[row2][col2] == 1 && node[row2][col2].left) || b[row2][col2] == 2)
					{
						b[row2][col2]++;
					}
				}
				else
				{
					node[row1][col1].right = node[row2][col2].left = true;
					if ((b[row1][col1] == 1 && node[row1][col1].left) || b[row1][col1] == 2)
					{
						b[row1][col1]++;
					}
					if ((b[row2][col2] == 1 && node[row2][col2].right) || b[row2][col2] == 2)
					{
						b[row2][col2]++;
					}
				}
			}
			else
			{
				if (row1 > row2)
				{
					node[row1][col1].up = node[row2][col2].down = true;
					if ((b[row1][col1] == 1 && node[row1][col1].down) || b[row1][col1] == 2)
					{
						b[row1][col1]++;
					}
					if ((b[row2][col2] == 1 && node[row2][col2].up) || b[row2][col2] == 2)
					{
						b[row2][col2]++;
					}
				}
				else
				{
					node[row1][col1].down = node[row2][col2].up = true;
					if ((b[row1][col1] == 1 && node[row1][col1].up) || b[row1][col1] == 2)
					{
						b[row1][col1]++;
					}
					if ((b[row2][col2] == 1 && node[row2][col2].down) || b[row2][col2] == 2)
					{
						b[row2][col2]++;
					}
				}
			}			

			int x = find(row1 * 26 + col1 + 26 * 26) - 26 * 26;
			int y = find(row2 * 26 + col2 + 26 * 26) - 26 * 26;
			if (a[x/26][x%26] != a[y/26][y%26])
			{
				area[a[y/26][y%26]] += area[a[x/26][x%26]];
				perimeter[a[y/26][y%26]] += perimeter[a[x/26][x%26]];
				area[a[x/26][x%26]] = 0.0;
				perimeter[a[x/26][x%26]] = 0.0;
				a[x/26][x%26] = y + 26 * 26;
			}
			area[a[y/26][y%26]] += base.area;
			perimeter[a[y/26][y%26]] += base.perimeter;
		}

		for (int r=0; r<26; r++)
		{
			for (int c=0; c<26; c++)
			{
				if (b[r][c] > 0)
				{
					int x = find(r * 26 + c + 26 * 26) - 26 * 26;
					area[a[x/26][x%26]] -= type[b[r][c]].area;
					perimeter[a[x/26][x%26]] -= type[b[r][c]].perimeter;
				}
			}
		}

		double maxarea = 0.0;
		double maxperimeter = 0.0;
		for (int k=0; k<26*26; k++)
		{
			if (maxarea < area[k])
			{
				maxarea = area[k];
			}	
			if (maxperimeter < perimeter[k])
			{
				maxperimeter = perimeter[k];
			}
		}

		printf("%.3f %.3f\n", maxarea, maxperimeter);
	}

	return 0;
}

int find(int x)
{
	while (a[(x-26*26)/26][(x-26*26)%26] >= 26 * 26)
	{
		x = a[(x-26*26)/26][(x-26*26)%26];
	}

	return x;
}

/* int find(int x)
{
	if (a[(x-26*26)/26][(x-26*26)%26] < 26 * 26)
	{
		return x;
	}
	else
	{
		return (a[(x-26*26)/26][(x-26*26)%26] = find(a[(x-26*26)/26][(x-26*26)%26]));
	}
} */	///:~