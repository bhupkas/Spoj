#include"iostream"
#include"stdio.h"
using namespace std;
typedef long long LL;
LL expon(LL a,LL b)
	{
		if(b==0)	return 1;
		if(b==1)	return a;
		LL te=expon(a,b/2);
		if(b&1)	return te*te*a;
		return te*te;
	}
int main()
	{
		LL n,i,j,ter,ans;
		int t;
		scanf("%d",&t);
		while(t--)
			{
				ans=0;
				scanf("%lld",&n);
				n--;
				ter=n/3;
				ans= ans+((2*3 + (ter-1)*3)*(ter)/2);
				ter=n/5;
				ans= ans+((2*5 + (ter-1)*5)*(ter)/2);
				ter=n/15;
				ans= ans-((2*15 + (ter-1)*15)*(ter)/2);
				printf("%lld\n",ans );
			}
		return 0;
	}