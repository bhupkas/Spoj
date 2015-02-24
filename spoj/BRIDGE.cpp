/* bhupkas */
#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
bool f(pair<int,int> p1,pair<int,int> p2)
	{
		if(p1.first==p2.first)	return p1.second<p2.second;
		return p1.first<p2.first;
	}
int main()
	{
		int ma,t,n,i,j,te1,te2;
		vector<int> v1,v2;
		vector< pair<int,int> > v;
		pair<int,int> dp[1005];
		cin>>t;
		while(t--)
			{
				v1.clear();
				v2.clear();
				v.clear();
				cin>>n;
				for(i=0;i<n;i++)
					{
						cin>>te1;
						v1.push_back(te1);
					}
				for(i=0;i<n;i++)
					{
						cin>>te1;
						v2.push_back(te1);
					}
				for(i=0;i<n;i++)	v.push_back(make_pair(v1[i],v2[i]));
				sort(v.begin(),v.end(),f);
				dp[0]=make_pair(v[0].second,1);
				for(i=1;i<n;i++)	
					{
						j=i-1;
						ma=0;
						while(j>=0)
							{
								if(dp[j].first<=v[i].second)	ma=max(ma,dp[j].second);
								j--;
							}
						dp[i]=make_pair(v[i].second,ma+1);
					}
				ma=-1;
				for(i=0;i<n;i++);
					//cout<<dp[i].first<<" "<<dp[i].second<<endl;
				for(i=0;i<n;i++)
					ma=max(ma,dp[i].second);
				cout<<ma<<endl;
			}
		return 0;
	}