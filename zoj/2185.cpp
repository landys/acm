// AC

#include <iostream>
#include <cmath>
// #include <fstream>
using namespace std;

int main()
{
	// fstream cin("input.txt");
	int n;
	while (cin >> n)
	{
		int k = int((sqrt(double(1+8*n)) - 1) / 2);
		int d = n - k * (k + 1) / 2;
		int a, b;
		if (d == 0)
		{
			a = k;
			b = 1;
		}
		else
		{
			a = d;
			b = k + 2 - d;
			k++;
		}
		if (k % 2 == 0)
		{
			cout << "TERM " << n <<" IS " << a << "/" << b << endl;
		}
		else
		{
			cout << "TERM " << n <<" IS " << b << "/" << a << endl;
		}
	}
	return 0;
}	///:~


/* #include<iostream> 
#include <fstream>
using namespace std; 


int main() 
{ 
	fstream cin("input.txt");
	int n, m ; 
	while( cin >> n ) 
	{ 
		m = n; 
		int sum = 1; 
		while( n - sum > 0 ) 
		{ 
			n -= sum; 
			sum++; 
		} 
		if( sum%2 == 0 ) 
		{ 
			cout << "TERM " << m << " IS " << n << "/" << sum - (n-1) << endl; 
		} 
		else 
		{ 
			cout << "TERM " << m << " IS " << sum - (n-1) << "/" << n << endl; 
		} 

	} 
}*/	///:~