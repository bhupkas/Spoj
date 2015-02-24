/* bhupkas */
/* phi sieve and gcd(1,n) + gcd(2,n) +gcd(3,n) +.......+ gcd(n-1,n)	sieve */
#include"iostream"
#include"stdio.h"
using namespace std;
#define SIZE1 1000015
typedef long long LL;
LL g[SIZE1];
int phi[SIZE1];
#define SIZE SIZE1-2
void pre()
	{
		int i,j;
		for(i=2,phi[1]=1; i<SIZE; i++)
			{
				if(!phi[i])
				{
					phi[i] = i-1;
					for(j=(i<<1); j<SIZE; j+=i)
					{
						if(!phi[j]) phi[j] = j;
						phi[j] = phi[j]/i*(i-1);
					}
				}
			}
		for(i=1; i<SIZE; i++)
			for(j=2; i*j<SIZE; j++)
				g[i*j] += (LL)i*(LL)phi[j];
		for(i=2;i<SIZE;i++)
			g[i]+=g[i-1];
	}
int main()
	{
		pre();
		int t,n,i;
		scanf("%d",&n);
		while(n!=0)
			{
				printf("%lld\n",g[n]);
				scanf("%d",&n);
			}
		return 0;
	}