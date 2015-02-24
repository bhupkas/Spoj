/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)
#define LL			long long 
#define PB			push_back

int main()
	{
		int n,x,y,i,j,te;
		int dp[100005];
		vector<int> v;
		cin>>n;
		while(n--)
			{
				v.clear();
				cin>>x>>y;
				te=y-x;
				if(te<=1)	{cout<<-1<<endl;	continue;}
				for(i=2;i*i<=x;i++)
					if(x%i==0)	{v.PB(i);	v.PB(x/i);}	
				FOR(i,0,te+1)	dp[i]=1000000000;
				FOR(i,0,v.size())
					dp[v[i]]=1;
				FOR(i,v[0]+1,te+1)
					{
						FOR(j,0,v.size())
							{
								dp[i]=min(dp[i],dp[i-v[j]]+1);	
							}
					}
				FOR(i,0,v.size())	cout<<v[i]<<" ";
				cout<<endl;
				FOR(i,0,te+1)	cout<<dp[i]<<" ";
				cout<<endl;
				if(dp[te]==1000000000)	cout<<-1<<endl;
				else			cout<<dp[te]<<endl;
			}
		return 0;
	}
