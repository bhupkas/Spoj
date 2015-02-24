/* bhupkas */
/* Sieve of sum of divisors */
#include"iostream"
#include"stdio.h"
using namespace std;
typedef long long LL;
#define SIZE 1000005
LL divisorSum[SIZE+10];
LL a[SIZE+10];
void pre()
	{
		int i,j;
		for (i = 1; i <= SIZE; i++) 
            for (j = i; j <= SIZE; j += i) 
                    divisorSum[j] += i;
		a[0]=a[1]=0;
		for(i=2;i<=SIZE;i++)
			a[i]=a[i-1]+divisorSum[i]-i;
	}
int main()
	{
		pre();
		int t,n;
		scanf("%d",&t);
		while(t--)
			{
				scanf("%d",&n);
				printf("%lld\n",a[n]);
			}
		return 0;
	}