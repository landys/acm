//Time Limit Exceeded

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

int comp(const Book& a, const Book& b)
{
	if (a.price < b.price)
	{
		return -1;
	}
	else if (a.price > b.price)
	{
		return 1;
	}
	return 0;
}

void BookSort(Book* bb, int n)
{
	int i, j;

	for (i=1; i<n; i++)
	{
		Book temp;
		temp.name = bb[i].name;
		temp.year = bb[i].year;
		temp.price = bb[i].price;
		for (j=i-1; j>=0; j--)
		{
			if (comp(temp, bb[j]) == -1)
			{
				bb[j+1].name = bb[j].name;
				bb[j+1].year = bb[j].year;
				bb[j+1].price = bb[j].price;
			}
			else
			{
				break;
			}
		}
		bb[j+1].name = temp.name;
		bb[j+1].year = temp.year;
		bb[j+1].price = temp.price;
	}

	cout << bb[0].name << " " << bb[0].year << endl;
}

int main(void)
{
//	fstream cin("input.txt");
	Book* bb = new Book[60000];
	int i = -1;
	int j = 0;

	string ss = "";
	while (cin >> ss)
	{
		if (ss == "PUT")
		{
			i++;
			cin >> bb[i].name >> bb[i].year >> bb[i].price;
		}
		else
		{
			if (i - j == -1)
			{
				cout << "EMPTY QUEUE!" << endl;
			}
			else if (i - j == 0)
			{
				cout << bb[0].name << " " << bb[0].year << endl;
				bb = &bb[1];
				j++;
			}
			else 
			{
				BookSort(bb, i+1-j);
				bb = &bb[1];
				j++;
			}
		}
	}

	return 0;
}