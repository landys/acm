#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
string OutIm = "Impossible\n";

class CVertex;
class CLine{
public:
	double x;
	double y;
	double d;
	int iS;
	int iE;
};
class CVertex{
public:
	double x;
	double y;

	bool operator == (const CVertex& r){
		if (this->x == r.x)
		{
			return true;
		}else
			return false;
	}
	bool operator < (const CVertex& r)
	{
		if (this->x < r.x)
		{
			return true;
		}else
			return false;
	}
	bool operator <= (const CVertex& r)
	{
		if (this->x <= r.x)
		{
			return true;
		}else
			return false;
	}
};

bool IsCross(vector<CLine>& arrLines, vector<CVertex>& arrVertexes){

	for (int i = 0; i < arrLines.size(); i++)
	{
		double dA1 = arrLines[i].y;
		double dB1 = arrLines[i].x;
		double dD1 = arrLines[i].d;
		double dXMax1 = max(arrVertexes[arrLines[i].iS].x, arrVertexes[arrLines[i].iE].x);
		double dXMin1 = min(arrVertexes[arrLines[i].iS].x, arrVertexes[arrLines[i].iE].x);
		double dYMax1 = max(arrVertexes[arrLines[i].iS].y, arrVertexes[arrLines[i].iE].y);
		double dYMin1 = min(arrVertexes[arrLines[i].iS].y, arrVertexes[arrLines[i].iE].y);

		for (int j = i + 2; j < arrLines.size(); j++)
		{
			if ( i == 0 && (j == arrLines.size() - 1) )
			{
				continue;
			}
			double dA2 = arrLines[j].y;
			double dB2 = arrLines[j].x;
			double dD2 = arrLines[j].d;
			double dCrossX = (dD1 * dA2 - dD2 * dA1) / (dB1 * dA2 - dB2 * dA1);
			double dCrossY = (dD1 * dB2 - dD2 * dB1) / (dA1 * dB2 - dA2 * dB1);
			double dXMax2 = max(arrVertexes[arrLines[j].iS].x, arrVertexes[arrLines[j].iE].x);
			double dXMin2 = min(arrVertexes[arrLines[j].iS].x, arrVertexes[arrLines[j].iE].x);
			double dYMax2 = max(arrVertexes[arrLines[j].iS].y, arrVertexes[arrLines[j].iE].y);
			double dYMin2 = min(arrVertexes[arrLines[j].iS].y, arrVertexes[arrLines[j].iE].y);

			if ( ((dCrossX <= dXMax1 && dCrossY <= dYMax1 ) && (dCrossX >= dXMin1 && dCrossY >= dYMin1)) &&
				((dCrossX <= dXMax2 && dCrossY <= dYMax2 ) && (dCrossX >= dXMin2 && dCrossY >= dYMin2)) )
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ifstream cin("input.txt");
	int count = 0, n = 1;

	while (1){
		cin >> count;
		if (count == 0)
		{
			break;
		}
		if (n > 1)
		{
			printf("\n");
		}
		printf("Figure %d: ", n++);
		vector< CVertex > arrVertex;
		for (int i = 0; i < count; i++)
		{
			double x = 0.0, y = 0.0;
			cin >> x >> y;
			CVertex vertex;
			vertex.x = x;
			vertex.y = y;
			arrVertex.push_back(vertex);
		}

		if (count <= 2)
		{
			printf("Impossible\n");
			continue;
		}

		vector< CLine > arrLines;
		for (int i = 0; i < count; i++)
		{
			CLine curline;
			curline.y = arrVertex[(i+1)%count].x - arrVertex[i].x;
			curline.x = arrVertex[i].y - arrVertex[(i+1)%count].y;
			curline.d = arrVertex[(i+1)%count].x*arrVertex[i].y - arrVertex[i].x*arrVertex[(i+1)%count].y;
			curline.iS = i;
			curline.iE = (i+1)%count;
			arrLines.push_back(curline);
		}

		if (IsCross(arrLines, arrVertex))
		{
			printf("Impossible\n");
			continue;
		}

		double dArea = 0.0;

		for (int i = 0; i < arrLines.size(); i++)
		{
			if (arrLines[i].y == 0.0)
			{
				continue;
			}
			double dXE = arrVertex[arrLines[i].iE].x;
			double dXS = arrVertex[arrLines[i].iS].x;
			double dA = arrLines[i].y;
			double dB = arrLines[i].x;
			double dD = arrLines[i].d;
			double dA1 = dXE*(dD - dB * dXE / 2) / dA;
			double dA2 = dXS*(dD - dB * dXS / 2) / dA;

			dArea += dA1 - dA2;
		}	
		
		if (dArea == 0.0)
		{
			printf("Impossible\n");
		}else{
			printf("%.2lf\n", fabs(dArea));
		}
	}
	return 0;
}