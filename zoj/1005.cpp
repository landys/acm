// AC

#include <iostream>
using namespace std;

#define FILL(x) cout << "fill " << #x << endl;
#define EMPTY(x) cout << "empty " << #x << endl;
#define POUR(x, y) cout << "pour " << #x << " " << #y << endl;

int main(void)
{
	int ca, cb, n;
	int a, b;

	while (cin >> ca >> cb >> n)
	{
		a = b = 0;
		
		while (a != n && b != n)
		{
			if (b == 0)
			{
				FILL(B);
				b = cb;
			}
			else if (a == ca)
			{
				EMPTY(A);
				a = 0;
			}
			else
			{
				POUR(B, A);
				if (a + b >= ca)
				{
					b = a + b - ca;
					a = ca;
				}
				else
				{
					a = a + b;
					b = 0;
				}
			}
		}

		cout << "success" << endl;
	}
	
	return 0;
}