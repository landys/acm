// AC
// Numerical Summation of a Series
// problem: 
// F(x) = Sum { k=1..inf, 1/(k*(k+x)) } 
// compute F(x) for x = 0.000, 0.001, 0.002, ..., 2.000, with error < 0.5e-12 

#include <cstdio>
#include <cmath>

#define SIZE 2001
#define N 1000
#define D 0.001

void Series_Sum(double sum[])
{
	int i = 0;
	int j = 0;
	int jj = 0;
	int k = 0;
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
 	int limit3 = int(pow(5.0e12, 0.5)) + 2;
 	int limit4 = int(pow((2.0e12)/3, ((double)1)/3)) + 2;
 	int limit5 = int(pow(1.5e12, 0.25)) + 2;
// 	int limit3 = 400000;
// 	int limit4 = 20000;
// 	int limit5 = 2000;
	
	double temp[N+1];
	double temp1[N];
	double dd = 2 * D * D;
	double ddd = 6 * D * D * D;
	y = 0.0;
	for (i=1; i<=2; i++)
	{  
		y += 1.0 / i;
		sum[i*N] = 1.0 / i * y;
		
		temp[N-1] = 0.0;
		x = double(i) - D;
		for (k=1; k<=limit3; k++)
		{
			temp[N-1] += D / (k * (k + x) * (k + x + D));
		}
		sum[i*N-1] = sum[i*N] + temp[N-1];
		
		x -= D;
		temp1[N-2] = 0.0;
		
		for (k=1; k<=limit4; k++)
		{
			temp1[N-2] += dd / (k * (k + x) * (k + x + D) * (k + x + 2 * D));
		}
		temp[N-2] = temp[N-1] + temp1[N-2];
		sum[i*N-2] = sum[i*N-1] + temp[N-2];
		
		for (j=N-3; j>0; j--)
		{
			jj = i * N + j - N;
			x = jj * D;
			z = 0.0;
		
			for (k=1; k<=limit5; k++)
			{
				z += ddd / (k * (k + x) * (k + x + D) * (k + x + 2 * D) * (k + x + 3 * D));
			}
			temp1[j] = temp1[j+1] + z;
			temp[j] = temp[j+1] + temp1[j];
			sum[jj] = sum[jj+1] + temp[j];
		}
	}
	z = 0.0;
    for (k=1; k<=limit3; k++)
	{
		z += D / ((k + D) * k * k);
	}
    sum[0] = sum[1] + z; 
}


int main()
{
	double sum[SIZE] = {0.0};
//    FILE* ff = fopen("output.txt", "w");
	
    Series_Sum(sum);
	
    for (int i=0; i<SIZE; i++)
	{
//        fprintf(ff, "%5.3f %16.12f\n", i * D, sum[i]);
		printf("%5.3f %16.12f\n", i * D, sum[i]);
	}
    return 0;
}

