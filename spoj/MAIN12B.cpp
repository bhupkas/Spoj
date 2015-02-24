#include"stdio.h"
#include"iostream"
#include"vector"
#include"algorithm"
#include"map"
using namespace std;
bool P[1000005];
vector<int> p;
typedef long long LL;
map<LL,bool> mymap;
void pre()
	{
		int i,j;
		for(i=0;i<1000005;i++)	P[i]=true;
		P[0]=P[1]=false;
		for(i=2;i*i<1000005;i++)
			{
				if(P[i])
					{
						for(j=i;j<=1000005/i;j++)
							P[i*j]=false;
					}
			}
		for(i=2;i<1000005;i++)	if(P[i])	p.push_back(i);
	}
int main()
	{
		pre();
		int tc,i,j,t,n,si,co;
		scanf("%d",&t);
		LL te;
		si=p.size();
		map<long long ,bool>::iterator it;
		for(tc=1;tc<=t;tc++)
			{
				mymap.clear();
				scanf("%d",&n);
				for(i=0;i<n;i++)	
					{
						scanf("%lld",&te);
						if(te==1)	continue;
						for(j=0;p[j]*p[j]<=te && j<si;j++)
							{
								if(te%p[j]==0)
									{
										while(te%p[j]==0)
											{
												te/=p[j];
											}
										mymap[p[j]]=true;
									}
							}
						if(te!=1)	mymap[te]=true;
					}
				printf("Case #%d: %d\n",tc,(int)mymap.size());
				for(it=mymap.begin();it!=mymap.end();it++)
					printf("%lld\n",(*it).first);		
			}
		return 0;
	}