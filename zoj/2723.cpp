// AC

// semi-prime.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
//#include <fstream>
#include <math.h>
using namespace std;

bool prime(int num)
{
	if (num == 2)
	{
		return true;
	}

	if(num==1)
	{
		return false;
	}
	
	int i;
	int k = (int)sqrt(double(num));
	for( i = 2; i<=k; i++)
	{
		if(num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	//fstream cin("input.txt");
	int num;
	bool flag;
	
	while(cin>>num)
	{
		if (num <= 3)
		{
			cout<<"No"<<endl;
			continue;
		}
		int i;
		flag = false;
		int k = (int)sqrt(double(num));
		
		for (i=2; i<=k; i++)
		{
			if (prime(i) && num % i == 0)
			{
				if (prime(num/i))
				{
					cout<<"Yes"<<endl;
				}
				else
				{
					cout<<"No"<<endl;
				}
				flag = true;
				break;
			}
		}	
		
		if (!flag)
		{
			cout << "No" << endl;
		}
	}

	
	return 0;
}


