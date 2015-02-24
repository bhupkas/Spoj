/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)			for(i=a;i<b;i++)
#define MP					make_pair
#define LL					long long
#define PLL					pair<LL,LL>
#define PB					push_back
#define so(v)				sort(v.begin(),v.end())
#define FF					first
#define SS					second

int main()
	{
		LL tc,a,b,n,x,y,i,j,ma=-1,mi=100000000LL,curr=0;
		FOR(tc,0,10)
			{
				cin>>a>>b;
				vector<PLL> v;
				a=a*2;
				b=b*2;
				v.PB(MP(a,0));
				v.PB(MP(b,0));
				curr=0;
				cin>>n;
				FOR(i,0,n)
					{
						cin>>x>>y;
						v.PB(MP((2*x)-1,1));
						v.PB(MP((2*y)+1,-1));
					}
				sort(v.begin(),v.end());
				mi=n;ma=0;
				FOR(i,0,v.size())
					{
						if(v[i].FF>=a && v[i].FF<=b)
							{
								ma=max(ma,curr);
								mi=min(mi,curr);
							}
						curr+=v[i].SS;
					}
				cout<<mi<<" "<<ma<<endl;
			}
		return 0;
	}