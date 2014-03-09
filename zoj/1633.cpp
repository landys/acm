// AC

// f(1) = 4;
// f(2) = 3;
// f(n) = f(n-1) + f(n-2)
// s1 = "^__^"
// s2 = "T.T"
// s3 = s2 + s1 = "T.T^__^"
// sn = s2 + s1

#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

#define big_num unsigned long long
const big_num MAX_NUM = 9223372036854775807;

big_num a[100] = {0};	// a[91] is enough

//class GreaterThanN
//{
//public:
//	bool operator()(const big_num& x, const big_num& n) const
//	{
//		return x > n;
//	}
//};

int main()
{
	a[1] = 4;
	a[2] = 3;
	int i;
	string ss = "T.T^__^";
	for (i=2; a[i]<MAX_NUM; i++)
	{
		a[i+1] = a[i] + a[i-1];
	}
	int k = i + 1;
	big_num n;
	while (cin >> n)
	{
		if (n <= 7)
		{
			cout << ss[n-1] << endl;
			continue;
		}
		big_num *p = find_if(a, a+k, bind2nd(greater_equal<big_num>(), n));
		for (p--; p!=a+2; p--)
		{
			if (n > *p)
			{
				n -= *p;
			}
		}
		cout << ss[n-1] << endl;
	}

	return 0;
}