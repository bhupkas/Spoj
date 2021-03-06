/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define PB		push_back
#define LL		long long 

bool P[10000];
vector<int> p;

void pre()
	{
		int i,j;
		FOR(i,0,10000)	P[i]=true;
		P[0]=P[1]=false;
		for(i=2;i*i<10000;i++)
			{
				if(P[i])
					{
						for(j=i;j<=10000/i;j++)
							P[i*j]=false;
					}
			}
		FOR(i,2,10000)	if(P[i])	p.PB(i);
	}

int fun(int n)
	{
		int i,j,ans=1,co;
		while(!(n&1))	n>>=1;
		for(i=0;p[i]*p[i]<=n;i++)
			{
				if(n%p[i]==0)
					{
						co=0;
						while(n%p[i]==0)
							{
								co++;
								n/=p[i];
							}
						ans=ans*(co+1);	
					}
			}
		if(n>2)	ans=ans*2;
		return 2*ans;
	}

int main()
	{
		pre();
		int n;
		cin>>n;
		while(n)
			{
				cout<<fun(n)<<endl;
				cin>>n;
			}
		return 0;
	}
