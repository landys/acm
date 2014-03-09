#include <iostream>
#include <fstream>
using namespace std;

class Number
{
	char nn[101];
	Number()
	{
		for (int i=0; i<101; i++)
		{
			nn = '\0';
		}
	}	
	
	Number operator+(const Number& a, const Number& b)
	{
		
	}
};

int main(void)
{
	fstream cin("input.txt");
	
	return 0;
}