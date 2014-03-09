// AC

#include <iostream>
//#include <fstream>

using namespace std;

int A, B;
int f(int n)
{
	if (n < 3)
	{
		return 1;
	}
	int t1 = 1;
	int t2 = 1;
	int t;
	for (int i=3; i<=n; i++)
	{
		t = (A * t1 + B * t2) % 7;
		t2 = t1;
		t1 = t;
	}

	return t;
}

int main()
{
	//ifstream cin("input.txt");
	
	int n;
	int a[7][7];	// a[i][j] is the length of one repeat when A=i, B=j
	for (A=0; A<7; A++)
	{
		for (B=0; B<7; B++)
		{
			int k3 = f(3);
			int k4 = f(4);
			int k5 = f(5);
			int k6 = f(6);
			if (k3 == k4 && k4 == k5)
			{
				a[A][B] = 1;
				continue;
			}
			for (n=7; !(k5==k3&&k6==k4); n++)
			{
				k5 = k6;
				k6 = f(n);
			}
			a[A][B] = n - 5;
		}
	}

// 	for (A=0; A<7; A++)
// 	{
// 		for (B=0; B<7; B++)
// 		{
// 			cout << a[A][B] << ",";
// 		}
// 		cout << endl;
// 	}

	cin >> A >> B >> n;
	while (A != 0)
	{
		A %= 7;	// ((A+7*ka)*f(n-1)+(B+7*kb)*f(n-2))%7 = (A*f(n-1)+B*f(n-2))%7
		B %= 7;
		if (n < 3)
		{
			cout << 1 << endl;
		}
		else
		{
			n %= a[A][B];
			while (n < 3)
			{
				n += a[A][B];
			}
			cout << f(n) << endl;
		}
		cin >> A >> B >> n;
	}

	return 0;
}

/*
#include <iostream> 
using namespace std; 

int a[7][7]={ 
   1,1,6,12,6,12,8, 
   1,16,6,24,48,21,6, 
   3,6,48,24,48,21,6, 
   6,16,48,42,6,1,8, 
   3,16,48,21,1,6,8, 
   6,6,48,1,48,24,14, 
   2,16,1,24,48,42,3, 
}; 


int  main() 
{ 
   int A,i,B,n,t,f1,f2,temp; 

   while(1) 
   { 
      cin>>A>>B>>n; 
      if(n==1 || n==2) 
      { 
         cout<<1<<endl; 
         continue; 
      } 
       
      if(A==0 && B==0 && n==0) 
         break; 
      A %= 7; 
      B %= 7; 
      t = a[A][B]; 
      n %= t; 
       
      while(n<3)    
n += t; 
       
      f1 = f2 = 1; 
      for(i=3;i<=n;i++) 
      { 
         temp = (A*f2+B*f1)%7; 
         f1 = f2; 
         f2 = temp; 
      } 
      cout<<temp<<endl; 
   }return 0; 
}
*/
