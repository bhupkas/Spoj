/* bhupkas */

/* recurrence :: http://mathworld.wolfram.com/DelannoyNumber.html */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

typedef long long LL;

#define MOD (LL)1000003
#define FOR(i,a,b)	for(i=a;i<b;i++)
#define SLL(n)	scanf("%lld",&n)
#define PB		push_back
#define vll		vector<LL>
#define SIZE 1000006

LL ans[SIZE+10];

vll inverseArray(LL n, LL m) 
	{
	    vll modInverse(n + 1,0);
	    modInverse[1] = 1;
	    for(LL i = 2; i <= n; i++)       modInverse[i] = (-(m/i) * modInverse[m % i]) % m + m;
	    return modInverse;
	}

void pre()
	{
		vll I=inverseArray(SIZE,MOD);
		ans[0]=1;
		ans[1]=3;
		ans[2]=13;
		LL i,t1,t2,t3;
		FOR(i,3,SIZE)
			{
				t1=(3*(2*i-1))%MOD;
				t1=(t1*ans[i-1])%MOD;
				t2=((i-1)*ans[i-2])%MOD;
				t3=I[i];
				ans[i]=(t1-t2)%MOD;
				ans[i]=(ans[i]*t3)%MOD;
				while(ans[i]<0)	ans[i]+=MOD;
			}
	}

int main()
	{
		pre();
		LL t,n,i;
		SLL(t);
		while(t--)
			{
				SLL(n);
				printf("%lld\n",(ans[n-1]+MOD)%MOD);
			}
		return 0;
	}