#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
int main()
	{
		int tc,t,n,A[100005],u,i,j;
		vector<int> v[1001];
		cin>>t;
		for(tc=1;tc<=t;tc++)
			{
				cin>>n>>u;
				for(i=0;i<n;i++)	
					cin>>A[i];
				for(i=0;i<1001;i++)	v[i].clear();
				for(i=0;i<n;i++)
					{
						v[A[i]/u].push_back(A[i]%u);
					}
				for(i=0;i<1001;i++)
					sort(v[i].begin(),v[i].end());
				cout<<"Scenario #"<<tc<<":"<<endl;
				for(i=0;i<1001;i++)
					{
						if(v[i].size())
							{
								cout<<i<<" | ";
								for(j=0;j<v[i].size();j++)
									cout<<v[i][j]<<" ";
								cout<<endl;
							}
					}
			}
		return 0;
	}