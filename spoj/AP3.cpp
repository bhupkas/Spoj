/* bhupkas */

#include"iostream"
#include"stdio.h"
#include"algorithm"
#include"vector"

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define S(n)	scanf("%d",&n)
#define SLL(n)	scanf("%lld",&n)
#define P(n)	printf("%d\n",n );
#define PLL(n)	printf("%lld\n",n );

int main()
	{
		LL t,thr,n,fo,co,a,d,i,sum;
		SLL(t);
		while(t--)
			{
				SLL(thr);
				SLL(fo);
				SLL(sum);
				d=sum-fo-thr;
				a=thr-d<<1;
				n=(sum-a<<1)/d;
				PLL(n);
				FOR(i,0,n)	cout<<a+i*d<<" ";
				cout<<endl;
			}
		return 0;
	}