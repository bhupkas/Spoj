/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define LL		long long 
#define PB		push_back

int main()
	{
		LL n,i,j,ans,te;
		vector<LL> A;
		cin>>n;
		while(n)
			{
				A.clear();	
				ans=0;
				FOR(i,0,n)
					{
						cin>>te;
						A.PB(te);
					}
				FOR(i,n/2,n)	ans+=A[i];
				cout<<ans<<endl;	
				cin>>n;
			}
		return 0;
	}
