/* bhupkas */

#include "stdio.h"
#include "iostream"
#include "set"
#include "algorithm"
#include "vector"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define I(a)		insert(a)
#define PB			push_back

int main()
	{
		int ans,t,n1,n2,i,j,te;
		cin>>t;
		vector<int> v1,v2;
		while(t--)
			{
				v1.clear();v2.clear();
				ans=(int)1e9;
				cin>>n1;
				FOR(i,0,n1)	
					{
						cin>>te;
						v1.PB(te);
					}
				cin>>n2;
				FOR(j,0,n2)
					{
						cin>>te;
						v2.PB(te);
					}
				FOR(i,0,n1)
					{
						FOR(j,0,n2)
							{
								ans=min(ans,abs(v1[i]-v2[j]));
							}
					}

				cout<<ans<<endl;
			}
		return 0;
	}