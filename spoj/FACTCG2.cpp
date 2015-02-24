#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
vector<int> p;
bool P[10000];
void pre()
	{
		int i,j;
		for(i=0;i<10000;i++)	P[i]=true;
		P[0]=P[1]=false;
		for(i=2;i*i<10000;i++)
			{
				if(P[i])
					{
						for(j=i;j<=10000/i;j++)
							P[i*j]=false;
					}
			}
		for(i=2;i<10000;i++)
			if(P[i])	p.push_back(i);
	}
int main()
	{
		pre();
		int t,n,i,j;
		vector<int> ans;
		while(scanf("%d",&n)!=EOF)
			{
				ans.clear();
				ans.push_back(1);
				for(i=0;p[i]*p[i]<=n;i++)
					{
						if(n%p[i]==0)
							{
								while(n%p[i]==0)
								{
									ans.push_back(p[i]);
									n/=p[i];
								}
							}
					}
				if(n!=1)	ans.push_back(n);
				for(i=0;i<ans.size()-1;i++)
					cout<<ans[i]<<" x ";
				cout<<ans[i]<<endl;
			}
		return 0;
	}