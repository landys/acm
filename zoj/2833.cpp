// AC

#include <stdio.h>
#define MAXSIZE 100001

class DisSet
{
public:
	int father[MAXSIZE];
	int friNum[MAXSIZE];
	int size;

	DisSet()
	{
		int i;
		for(i=0; i<MAXSIZE; i++)
		{
			father[i] = 0;
			friNum[i] = 1;
		}
	}

	void addOne(int a, int b)
	{
		int aDad;
		aDad = a;
		while(father[aDad]>0)
			aDad = father[aDad];
		int bDad;
		bDad = b;
		while(father[bDad]>0)
			bDad = father[bDad];

		if(aDad==bDad)
		{
			if(a!=aDad)
				father[a] = aDad;
			if(b!=bDad)
				father[b] = bDad;
		}
		else if(friNum[aDad]>friNum[bDad])
		{
			father[bDad] = aDad;
			friNum[aDad] += friNum[bDad];
		}
		else
		{
			father[aDad] = bDad;
			friNum[bDad] += friNum[aDad];
		}
	}

	void queryOne(int src)
	{
		while(father[src]>0)
			src = father[src];
		printf("%d\n", friNum[src]);
	}

	void go(int size, int qNum)
	{
		while(qNum>0)
		{
			char qName;
			int tmp1, tmp2;
			scanf("%c", &qName);
			switch(qName)
			{
			case 'M':
				scanf("%d%d", &tmp1, &tmp2);
				addOne(tmp1, tmp2);
				break;
			case 'Q':
				scanf("%d", &tmp1);
				queryOne(tmp1);
				break;
			}
			getchar();
			qNum--;
		}
	}
};

int main()
{
	int tmp1, tmp2;
	int num; num = 1;
	while(scanf("%d%d", &tmp1, &tmp2)!=EOF)
	{
		if(num!=1)
			printf("\n");
		printf("Case %d:\n", num);
		getchar();
		DisSet ds;
		ds.go(tmp1, tmp2);
		num++;
	}
	return 1;
}