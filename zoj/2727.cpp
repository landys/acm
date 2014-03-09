// AC
#include <iostream>
//#include <fstream>
#include <string>
using namespace std;

struct Book
{
	string name;
	int year;
	int price;
};

int comp(const Book& a, const Book& b, int type)
{
	int flag = 1;
	if (type == 2)
	{
		if (a.year<b.year || (a.year==b.year&&a.name<b.name) || (a.year==b.year&&a.name==b.name&&a.price<b.price))
		{
			flag = 0;
		}
	}
	else if (type == 3)
	{
		if (a.price<b.price || (a.price==b.price&&a.name<b.name) || (a.price==b.price&&a.name==b.name&&a.year<b.year))
		{
			flag = 0;
		}
	}
	else
	{
		if (a.name<b.name || (a.name==b.name&&a.year<b.year) || (a.name==b.name&&a.year==b.year&&a.price<b.price))
		{
			flag = 0;
		}
	}

	return flag;
}

void BookSort(Book* bb, int n, int type)
{
	int ii[100];
	int i, j;
	for (i=0; i<n; i++)
	{
		ii[i] = i;
	}

	for (i=1; i<n; i++)
	{
		int temp = ii[i];
		for (j=i-1; j>=0; j--)
		{
			if (comp(bb[temp], bb[ii[j]], type) == 0)
			{
				ii[j+1] = ii[j];
			}
			else
			{
				break;
			}
		}
		ii[++j] = temp;
	}

	for (i=0; i<n; i++)
	{
		cout << bb[ii[i]].name << " " << bb[ii[i]].year << " " << bb[ii[i]].price << endl;
	}
}

int main(void)
{
	//fstream cin("input.txt");
	int n;
	cin >> n;
	Book bb[100];
	string ss = "";
	int type = 0;
	while (n != 0)
	{
		for (int i=0; i<n; i++)
		{
			cin >> bb[i].name >> bb[i].year >> bb[i].price;
		}
		cin >> ss;
		if (ss == "Name")
		{
			type = 1;
		}
		else if (ss == "Year")
		{
			type = 2;
		}
		else if (ss == "Price")
		{
			type = 3;
		}
		
		BookSort(bb, n, type);
		cin >> n;
		if (n != 0)
		{
			cout << endl;
		}
	}
	return 0;
}