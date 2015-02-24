/* bhupkas , DIJSTRA ,spoj,HIGHWAYS*/
#include"stdio.h"
#include"iostream"
#include"vector"
#include"algorithm"
#include"utility"	
#include"set"
#include<cstdlib>
using namespace std;
#define pp pair<int,int>
#define inf 1e9
int main()
	{
	int source,n,m,i,j,dis,te1,te2,t,des;
	cin>>t;
	while(t--)
		{
		cin>>n>>m>>source>>des;
		set <pp> myset;
		myset.clear();
		int DIS[n];
		vector <pp>  v[n];
		for(i=0;i<n;i++)	v[i].clear();
		for(i=0;i<m;i++)
			{
			cin>>te1>>te2>>dis;
			te1--;te2--;
			v[te1].push_back(pp(te2,dis));
			v[te2].push_back(pp(te1,dis));
			}
		source--;des--;
		for(i=0;i<n;i++)	DIS[i]=inf;
		DIS[source]=0;
		myset.insert(pp(0,source));
		set<pp>::iterator it;
		int te3,te4,si;
		while(!myset.empty())
			{
				it=myset.begin();
				te4=(*it).second;
				si=v[te4].size();
				myset.erase(myset.begin());
				for(j=0;j<si;j++)
					{
					if(DIS[te4]+v[te4][j].second < DIS[v[te4][j].first])	
						{
						if(myset.find(pp(DIS[v[te4][j].first],v[te4][j].first))!=myset.end())
							myset.erase(pp(DIS[v[te4][j].first],v[te4][j].first));
						DIS[v[te4][j].first]=DIS[te4]+v[te4][j].second;
						myset.insert(pp(DIS[v[te4][j].first],v[te4][j].first));
						}
					}
			}
		if(DIS[des]==inf)	cout<<"NONE"<<endl;
		else			cout<<DIS[des]<<endl;
		}
	return 0;
	}
