/* bhupkas */

#include "iostream"
#include "stdio.h"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)
#define MAX 			100005

double A[MAX+5];

void pre()
	{
		int i,j;
		double re;
		A[1]=1;
		FOR(i,2,MAX)
			{
				A[i]=A[i-1]+(double)(1)/(double)(i);
			}
	}

int main()
	{
		pre();
		int t,n,i,j;
		double ans;
		cin>>t;
		while(t--)
			{
				cin>>n;
				printf("%.12lf\n",A[n]);
			}
		return 0;
	}
