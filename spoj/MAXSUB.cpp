/* bhupkas */

#include"iostream"
#include"stdio.h"
#include"algorithm"

using namespace std;

typedef long long LL;
#define MOD (LL)(1e9+7)
#define S(n)	scanf("%d",&n)
#define SLL(n)	scanf("%lld",&n)

LL po(LL n)
	{
		if(n==0)	return 1;
		if(n==1)	return 2;
		LL re=po(n/2);
		re=(re*re)%MOD;
		if(n&1)	return (re<<1)%MOD;
		return re%MOD;
	}

bool f(LL a,LL b)
	{
		return b<a;
	}
int main()
	{
		int t;
		LL A[50005];
		S(t);
		LL n,i,j,sum,co1,co,ans;
		while(t--)
			{
				SLL(n);
				co=0;
				co1=0;
				ans=1;
				sum=0;
				for(i=0;i<n;i++)	{SLL(A[i]);	if(A[i]==0)	co++;}
				sort(A,A+n,f);
				sum=A[0];
				i=1;
				while(A[i]>0 && i<n)	{sum+=A[i];	i++;}
				if(i!=1)	co1=1;
				else	for(i=0;i<n;i++)	if(A[i]==sum)	co1++;		
				ans=(co1*po(co))%MOD;
				cout<<sum<<" "<<ans<<endl;
			}
		return 0;
	}