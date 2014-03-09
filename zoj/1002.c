// Accept
// Fire Net

#include <stdio.h>

#define MAX 4
#define MAX_STACK 20

void mark_around(char a[MAX][MAX], int i, int j, int n, char mark);
void unmark_around(char a[MAX][MAX], int i, int j, int n, char mark);

void mark_around(char a[MAX][MAX], int i, int j, int n, char mark)
{
	int ii, jj;
	
	ii = i + 1;
	jj = j;
	while (ii < n && a[ii][jj] != 'X')
	{
		if (a[ii][jj] == '.')
		{
			a[ii][jj] = mark;
		}
		ii++;
	}
	ii = i;
	jj = j + 1;

	while (jj < n && a[ii][jj] != 'X')
	{
		if (a[ii][jj] == '.')
		{
			a[ii][jj] = mark;
		}	
		jj++;
	}
}

void unmark_around(char a[MAX][MAX], int i, int j, int n, char mark)
{
	int ii, jj;

	ii = i + 1;
	jj = j;
	while (ii < n && a[ii][jj] != 'X')
	{
		if (a[ii][jj] == mark)
		{
			a[ii][jj] = '.';
		}
		ii++;
	}
	ii = i; 
	jj = j + 1;

	while (jj < n && a[ii][jj] != 'X')
	{
		if (a[ii][jj] == mark)
		{
			a[ii][jj] = '.';
		}
		jj++;
	}
}

int main(void)
{
	char a[MAX][MAX];
	int n;
	int stack[MAX_STACK];
	int top = -1;
	int i, j;
	int smax = 0, sum = 0;

	scanf("%d", &n);
    getchar();
	while (n != 0)
	{
		for (i=0; i<n; i++)	// initialize array
		{
			for (j=0; j<n; j++)
			{
				a[i][j] = getchar();
			}
			getchar();
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				if (a[i][j] == '.')
				{
					a[i][j] = '*';	// '*' mark a blockhouse
					sum++;
					stack[++top] = i;	// push to stack
					stack[++top] = j;
					mark_around(a, i, j, n, (char)((top-1)/2+'0'));	// mark around
				}
				if (top >= 0 && i == n-1 && j == n-1)	// one way come to end, go back using pop out of stack;
				{
					j = stack[top--];
					i = stack[top--];
					a[i][j] = '.';
					unmark_around(a, i, j, n, (char)((top+1)/2+'0'));	// cancel the mark
					if (smax < sum)
					{
						smax = sum;
					}
					sum--;
					if (i == n-1 && j== n-1 && top >= 0)	// if the last place taken by a blockhouse
					{
						j = stack[top--];
						i = stack[top--];
						a[i][j] = '.'; 
						unmark_around(a, i, j, n, (char)((top+1)/2+'0'));	// cancel the mark
						sum--;
					}
				}
			}
		}
		printf("%d\n", smax);

		smax = sum = 0;
		top = -1;
		scanf("%d", &n);
		getchar();
	}
	
	return 0;
}
