#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
typedef long long LL;
int main()
	{
		vector<LL> v;
		vector<LL> sum;
		LL b,n,i,j,q,x,l,r,si;
		cin>>n;
		for(i=0;i<n;i++)	v.push_back(0);
		for(i=n-1;i>=0;i--)
			cin>>v[i];
		sum.push_back(v[0]);
		for(i=1;i<n;i++)
			sum.push_back(sum[i-1]+v[i]);
		cin>>q;
		while(q--)
			{
				cin>>b;
				if(b&1)
				{
					cin>>l>>r;
					si=(LL)sum.size();
					//cout<<si<<endl;
					if(si-r==0)	cout<<sum[si-l]<<endl;
					else 	cout<<sum[si-l]-sum[si-r-1]<<endl;
				}
				else
				{
					cin>>x;
					v.push_back(x);
					si=(LL)sum.size();
					sum.push_back(sum[si-1]+x);
				}
			}
		return 0;	
	}