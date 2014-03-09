// AC

#include <iostream>
// #include <fstream>
#include <vector>
using namespace std;

class Color
{
public:
	Color(int r = 0, int g = 0, int b = 0) : red(r), green(g), blue(b) {}
	friend ostream& operator<<(ostream& os, const Color& color)
	{
		os << "(" << color.red << "," << color.green << "," << color.blue << ")";
		return os;
	}
	friend double dist(const Color&, const Color&);
private:
	int red;
	int green;
	int blue;
};

/* ostream& operator<<(ostream& os, const Color& color)
{
	os << "(" << color.red << "," << color.green << "," << color.blue << ")";
	return os;
} */

double dist(const Color& left, const Color& right)
{
	return double((left.red-right.red)*(left.red-right.red)+(left.green-right.green)*(left.green-right.green)+(left.blue-right.blue)*(left.blue-right.blue));
}	

int main()
{
	// fstream cin("input.txt");
	vector<Color> v;
	int r, g, b;
	for (int i=0; i<16; i++)
	{
		cin >> r >> g >> b;
		Color cc(r, g, b);
		v.push_back(cc);
	}
	while (cin >> r >> g >> b && r != -1)
	{
		Color cc(r, g, b);
		double dmin = 255*255*3+1;
		int k = 0;
		for (int j=0; j<v.size(); j++)
		{
			double d = dist(cc, v[j]);
			if (d < dmin)
			{
				dmin = d;
				k = j;
			}
		}
		cout << cc << " maps to " << v[k] << endl;
	}

	return 0;
}	///:~