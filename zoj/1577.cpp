// AC

#include <iostream>
//#include <fstream>
#include <cmath>
using namespace std;

bool isprime (int a, int b)
{
	int t;
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	while (a % b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	if (b == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	//ifstream cin("input.txt");
	int m, n;
	while (cin >> m >> n)
	{
		if (n % m != 0)
		{
			cout << 0 << endl;
			continue;
		}
		else if (m == n)
		{
			cout << 1 << endl;
			continue;
		}
		
		int s = 2;
		int k = n / m;
		int t = int(sqrt(double(k)));
		for (int i=2; i<=t; i++)
		{
			if (k % i == 0)
			{
				int j = k / i;
				if (!isprime(j, i))
				{
					continue;
				}
				else
				{
					s += 2;
				}
			}
		}
		
		cout << s << endl;
	}
	return 0;
}	///:~


/* #include<stdio.h> 
main() 
{
	long m,n,i,temp,totol,count; 
   while(scanf("%ld %ld",&m,&n)!=EOF) 
   { 
if(n % m != 0) 
{ 
printf("0\n"); 
continue; 
} 
      temp=n/m; 
      count=0; 
      for(i=2;i<=temp;i++) 
      { 
         if(temp%i==0) 
         count++; 
         while(temp%i==0) 
         temp=temp/i; 
		if(temp == 1) 
			break; 
      } 
      totol=1; 
      for(i=1;i<=count;i++) 
         totol=2*totol; 
      printf("%ld\n",totol); 
   } 
}*/	///:~