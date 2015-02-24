/* bhupkas */

#include "stdio.h"
#include "iostream"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)

int main()
	{
		int t,i,j,n,r,x,k,y,ans,tc;
		int A[55][55],B[55][55];
		cin>>t;
		FOR(tc,1,t+1)
			{
				cin>>n;
				FOR(i,0,n)
					FOR(j,0,n)
						cin>>A[i][j];
				FOR(i,0,n)
					FOR(j,0,n)
						B[i][j]=A[i][j];
				FOR(k,0,n)
					FOR(i,0,n)
						FOR(j,0,n)
							if(B[i][k]+B[k][j]<B[i][j])	B[i][j]=B[i][k]+B[k][j];
				cin>>r;
				ans=0;
				while(r--)
					{
						cin>>x>>y;
						ans+=B[x-1][y-1];
					}
				cout<<"Case #"<<tc<<": "<<ans<<endl;
			}
		return 0;
	}
