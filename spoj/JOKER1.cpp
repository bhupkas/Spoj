/* bhupkas */

#include"stdio.h"
#include"iostream"
#include"algorithm"
#include"vector"

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define S(n)	scanf("%d",&n)
#define SLL(n)	scanf("%lld",&n)
#define P(n)	printf("%d\n",n);
#define PLL(n)	printf("%lld\n",n);
#define PB(n)	push_back(n)
#define FOR(i,a,b)	for(i=a;i<b;i++)
#define MOD (LL)(1e9+7)

int main()
	{
		LL i,te,t,n,mi=40000;
		VLL v;
		SLL(t);
		LL ans=1;
		while(t--)
			{
				ans=1;
				v.clear();
				SLL(n);
				FOR(i,0,n)	
					{
						SLL(te);
						v.PB(te);
					}
				sort(v.begin(),v.end());
				for(i=n-1;i>=0;i--)
					{
						v[i]-=i;
						if(v[i]<1)	break;
						ans=(ans*v[i])%MOD;
					}
				if(i!=-1)	printf("0\n");
				else		PLL(ans);
			}
		printf("KILL BATMAN\n");
		return 0;
	}