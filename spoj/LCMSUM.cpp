/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

#define LL 		long long
#define FOR(i,a,b)	for(i=a;i<b;i++)
#define PB		push_back
#define MAX 		1000005

LL phi[MAX+5];
LL A[MAX+5];


void pre_phi()
	{
		int Lim=MAX; 
		for(int i = 1 ;i <= Lim ; i++ ) phi[i]=i;
		for(int i=2 ; i<= Lim ; i++ )
		 if (phi[i] == i)
		for(int j = 2*i ; j <= Lim ; j += i) phi[j] -=  phi[j]/ i ;	
		for(int i=2 ; i<= Lim ; i++) if ( phi[i]==i) phi[i] = i-1;
	}

void pre()
	{
		int i,j;
		for(i=1;i<=MAX;i++) 
			for (j=i;j<=MAX;j+=i) 
				A[j]+= i*phi[i];
	}

int main()
	{	
		pre_phi();
		pre();
		int t,n;
		scanf("%d",&t);
		while(t--)
			{
				scanf("%d",&n);
				printf("%lld\n",(1+(LL)A[n])*n/2);
			}
		return 0;
	}
