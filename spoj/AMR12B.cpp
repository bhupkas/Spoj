/* bhupkas */

#include "iostream"
#include "stdio.h"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)

int D[1000005];

int main()
{
	int t,i,ans,n,m,x,y,temp;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		FOR(i,1,n+1)	D[i]=i-1;
		while(m--)
		{
			cin>>x>>y;
			if(x>y)
				{
					temp=x;
					x=y;
					y=temp;
				}
			D[x]++;
			D[y]--;
		}
		ans=1;
		for(i=n;i>0;i--)
		{
			if(D[i]==n-1)
			{
				ans=2;
				m=i;
				break;
			}
		}
		if(ans==2)
			printf("2 %d\n",m);
		else
			printf("1\n");
	}
	return 0;
} 

