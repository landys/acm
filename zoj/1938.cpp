// Accept

#include <iostream>
using namespace std;

const int Length = 100;

void multi(unsigned long* a, unsigned long n)
{
	int in = 0;
	for (int i=0; i<Length; i++)
	{
		a[i] = a[i] * n + in;
		in = a[i] / 10;
		a[i] %= 10;
	}
}

void divi(unsigned long* a, unsigned long n)
{
	int out = 0;
	int i = Length;
	while (a[--i] == 0);
	for (; i>=0; i--)
	{
		a[i] += out * 10;
		out = a[i] % n;
		a[i] /= n;
	}
}

int main()
{
	unsigned long n, k;
	while (cin >> n >> k && n != 0)
	{
		unsigned long a[Length] = {1, 0};

		if (k > n - k)	// don't forget, or maybe time limit exceeded
		{
			k = n - k;
		}
		unsigned long t = n;
		while (t > n - k)
		{
			multi(a, t--);
		}
		while (k)
		{
			divi(a, k--);
		}

		int i = Length;
		while (a[--i] == 0);
		while (i >= 0)
		{
			cout << a[i--];
		}
		cout << endl;
	}

	return 0;
}

/* #include<iostream> 
using namespace std; 

int main() 
{ 
   unsigned long long x,x1,x2,xi,temp,xx; 

   while(cin >> x1 >> x2 ,!(x1==0&&x2==0)){ 
      x=1; 
      temp=1; 
      xx=x1-x2; 
      if(xx<x2) 
         x2=xx; 
      for(xi=1;xi<=x2;xi++,x1--){ 
         x=x*x1; 
         if(x%xi==0) 
            x=x/xi; 
         else 
            temp=temp*xi; 
      } 
      x=x/temp; 
      cout << x << endl ; 
   } 
   return 0; 
} */

/* #include<iostream> 
#include<string> 
using namespace std; 

const int len=100; 
int a[len]; 

void multi(int m) 
{ 
   int in=0; 
   for(int i=0;i<len;i++){ 
      a[i]=a[i]*m+in; 
      in=a[i]/10; 
      a[i]%=10; 
   } 
} 
void divi(int m) 
{ 
   int in=0; 
   for(int i=len-1;i>=0;i--){ 
      a[i]+=in*10; 
      in=a[i]%m; 
      a[i]/=m; 
   } 
} 
int main() 
{ 
   int k,n,t,i; 
   while(cin>>n>>k){ 
      if(k==0 && n==0)break; 
      memset(a,0,sizeof(a)); 
      t=n; i=0; 
      if(k>n/2)k=n-k; 
      while(t>0){ 
         a[i++]=t%10; 
         t/=10; 
      } 
      t=n; 
      while(--t>n-k) 
         multi(t); 
      while(k) 
         divi(k--); 
      i=len-1; 
      while(a[i]==0) i--; 
      for(;i>=0;i--)cout<<a[i]; 
      cout<<endl; 
   } 
   return 0; 
} */

/* #include <iostream> 

using namespace std; 

int main(void){ 
    long n,k,i; 
    while(cin>>n>>k){ 
        if(n==0&&k==0) break; 
        double num=1; 
        if(k>n/2) k=n-k; 
        for(i=1;i<=k;i++){ 
            num*=(double)(n-k+i)/i*1.000000000001; 
        } 
        cout<<(long)num<<endl; 
    } 
    return 0; 
} */

/* #include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
double i,j,n,k; 
double ans; 
main() 
{ 
  scanf("%lf %lf",&n,&k); 
  while (!(n==0&&k==0)){ 
    if (k+k>n) k=n-k; 
    ans=1; 
    i=n-k+1; 
    j=1; 
    while (i<=n||j<=k){ 
      while (ans<1e14&&i<=n) ans*=i++; 
      while (ans>1&&j<=k) ans/=j++; 
    } 
    printf("%0.0lf\n",ans); 
    scanf("%lf %lf",&n,&k); 
  } 
  return 0; 
} */