/* bhupkas */
/* DP */
#include"iostream"
#include"stdio.h"
#include"map"
#include"vector"
using namespace std;
int main()
	{
		int te,n,t,i,j,si;
		vector<int> v;
		vector<int> temp;
		long long ans;
		map<int,bool> mymap;
		map<int,bool>::iterator it;
		cin>>t;
		while(t--)
			{
				ans=0;
				cin>>n;
				mymap.clear();
				v.clear();
				for(i=0;i<n;i++)
					{	
						cin>>te;
						v.push_back(te);
					}
				mymap[v[0]]=true;
				for(i=1;i<n;i++)
					{
						temp.clear();
						si=(int)mymap.size();
						for(j=0,it=mymap.begin();j<si;j++,it++)
							temp.push_back((*it).first+v[i]);
						for(j=0,it=mymap.begin();j<si;j++,it++)
							mymap[temp[j]]=true;
						mymap[v[i]]=true;
					}
				for(it=mymap.begin();it!=mymap.end();it++)
					ans+=(*it).first;
				cout<<ans<<endl;
			}
		return 0;
	}