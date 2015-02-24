#include"iostream"
#include"stdio.h"
#include"math.h"
#include"algorithm"
using namespace std;
typedef unsigned long long LL;
int a,b,k;
bool fun(LL temp)
	{
	a=0;b=0;
	bool flag=false;
	int i,j;
	while(temp)
		{
		if(temp&1)
			{
			if(flag)	a++;
			else		b++;
			}
		temp>>=1;
		if(flag)	flag=false;
		else		flag=true;
		}
	if(abs(a-b) == k)	return true;
	return false;
	}	
int main()	
	{
	int t,co,j;
	LL m,n,i;
	scanf("%d",&t);
	while(t--)
		{
		co=0;
		scanf("%llu %llu %d",&m,&n,&k);
		for(i=m;i<=n;i++)
			{
			if(fun(i))	co++;	
			}
		printf("%d\n",co);
		}
	return 0;
	}
