/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "vector"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define LL		long long 
#define MOD		1000000007

LL modpow (LL a, LL b, LL mod)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

int main()
	{
		LL n,l,i,j,ans,inv;
		cin>>n>>l;
		while(n && l)
			{
				if(n==1)	{cout<<l<<endl;	continue;}
				ans = modpow(n,l,MOD);
				ans=ans-1;
				ans%=MOD;
				inv=modpow(n-1,MOD-2,MOD);
				ans= (ans*n)%MOD;
				ans=(ans*inv)%MOD;
				cout<<ans<<endl;
				cin>>n>>l;
			}
		return 0;
	}
