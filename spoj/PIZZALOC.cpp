/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)
#define S(n)		scanf("%d",&n)
#define vi			vector<int>
#define PB			push_back

int main()
	{
		int  k,r,m,i,j,n;
		S(k);S(r);S(m);
		vi x(m);
		vi y(m);
		FOR(i,0,m)	
			{
				S(x[i]);
				S(y[i]);
			}
		S(n);
		vi sx(n);
		vi sy(n);
		vi num(n);
		FOR(i,0,n)
			{
				S(sx[i]);
				S(sy[i]);
				S(num[i]);
			}
		int ans=0;
		vi per(m);
		FOR(i,0,m-k)	per[i]=0;
		FOR(i,m-k,m)	per[i]=1;
		int co=0;
		vi adj[m];
		FOR(i,0,m)
			{
				FOR(j,0,n)
					{
						if(((x[i]-sx[j])*(x[i]-sx[j]) +(y[i]-sy[j])*(y[i]-sy[j]))<=r*r)	adj[i].PB(j);
					}
			}
		bool B[n];
		FOR(i,0,n)	B[i]=false;
		FOR(i,0,m)
			{
				if(per[i])
						{
							FOR(j,0,adj[i].size())	B[adj[i][j]]=true;
						}
			}
		FOR(i,0,n)	co+=B[i]*num[i];
		ans=max(ans,co);
		while(next_permutation(per.begin(),per.end()))
				{
					co=0;
					FOR(i,0,n)	B[i]=false;
					FOR(i,0,m)
						{
							if(per[i])
								{
									FOR(j,0,adj[i].size())	B[adj[i][j]]=true;
								}		
						}	
					FOR(i,0,n)	co+=B[i]*num[i];
					ans=max(ans,co);
				}
			cout<<ans<<endl;
		return 0;
	}