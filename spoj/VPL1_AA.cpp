#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
#include"map"
using namespace std;
bool P[10000007];
int M[10000007];
vector<int> p;
void pre()
	{
		int i,j;
		for(i=0;i<10000007;i++)
				P[i]=true;
		P[0]=P[1]=false;
		for(i=2;i*i<10000007;i++)
			{
				if(P[i])
					{
						for(j=i;j<=10000007/i;j++)
							P[i*j]=false;
					}
			}
		M[0]=M[1]=1;
		for(i=2;i<10000007;i++)
			{
				M[i]=i;
				if(P[i])	
						p.push_back(i);
			}
		for(i=0;p[i]*p[i]<10000007;i++)
			{
				for(j=p[i];j<10000007/p[i];j++)
					M[p[i]*j]=p[i];
			}
	}
int main()
	{
		pre();
		map<int,int> mymap;
		int tc,t,n,i,j,co,ans1,ans2;
		int A[100005];
		scanf("%d",&t);
		for(tc=1;tc<=t;tc++)
			{
				mymap.clear();
				ans1=-1;
				ans2=-1;
				co=0;
				scanf("%d",&n);
				for(i=0;i<n;i++)
					scanf("%d",&A[i]);
				for(i=0;i<n;i++)
					{
						if(P[A[i]])
							{
								co++;
								mymap[A[i]]++;
							}
						else
							{
								if(A[i]==0)	continue;
								ans1=max(ans1,co);
								co=0;
								while(A[i]!=1)
									{
										mymap[M[A[i]]]--;
										A[i]/=M[A[i]];
									}
							}
					}
				ans1=max(ans1,co);
				co=0;
				for(i=0;i<n;i++)
					{
						if(mymap[A[i]]>0&&P[A[i]])	co++;
						else 				{ans2=max(ans2,co);	co=0;}
					}
				ans2=max(ans2,co);
				cout<<"Scenario #"<<tc<<": "<<ans1<<" > "<<ans2<<endl;
			}
		return 0;
	}