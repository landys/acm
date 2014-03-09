// AC

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

class Corrector	
{
public:
	vector<string> dict;
	vector<string> candi;

	void input()
	{
		int tmp;
		cin>>tmp;
		while(tmp>0)
		{
			string tmpStr;
			cin>>tmpStr;
			dict.push_back(tmpStr);
			tmp--;
		}
	}

	void printResult()
	{
		int i;
		sort(candi.begin(), candi.end());
		for(i=0; i<candi.size()-1; ++i)
			cout<<candi[i]<<",";
		cout<<candi[i]<<endl;
	}

	void findCandi(string src)
	{
		candi.clear();
		vector<string>::iterator it;
		it = find(dict.begin(), dict.end(), src);
		if(it!=dict.end())
		{
			candi.push_back(*it);
			return;
		}
		int i;
		for(i=0; i<src.size()-1; i++)
		{
			char tmpChar;
			tmpChar = src[i];
			src[i] = src[i+1];
			src[i+1] = tmpChar;
			
			it = find(dict.begin(), dict.end(), src);
			if(it!=dict.end())
				candi.push_back(*it);

			tmpChar = src[i];
			src[i] = src[i+1];
			src[i+1] = tmpChar;
		}
		if(candi.size()==0)
			candi.push_back(src);
	}

	void go()
	{
		int tmp;
		cin>>tmp;
		while(tmp>0)
		{
			string src;
			cin>>src;
			findCandi(src);
			printResult();
			tmp--;
		}
	}
};

int main()
{
	int num;
	cin>>num;
	int i;
	for(i=0; i<num; i++)
	{
		if(i!=0)
			cout<<endl;
		Corrector cr;
		cr.input();
		cr.go();
	}
	return 1;
}
