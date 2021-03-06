/* bhupkas */
/* Longest Non-decreasing Sequence Segment Tree */
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

int power[23],level;
int pur[100001],seg[1<<18];
void constant()
{
	int s=1;
	power[0]=1;
	while(s!=23)
		power[s]=power[s-1]<<1,s++;
}
void obtain(int n)
{
	level=0;
	int x=n;
	while(x!=0)
		x>>=1,level++;
	if(power[level-1]!=n)
		level++;
}
int bs11(int low,int high,int k)//returns the index of that number which is equal to or just larger than it
{
	int mid=(low+high)/2;
	if(pur[mid]==k)
		return mid;
	else if(pur[mid]<k)
		return bs11(mid+1,high,k);
	else
		return bs11(low,mid-1,k);
}
int Query(int b,int e,int i,int j,int node)
{
	int c1,c2,c3;
	if(b>j || e<i)
		return 0;
	if(b>=i && e<=j)
		return seg[node];
	c2=node<<1;c3=(b+e)>>1;
	return max(Query(b,c3,i,j,c2),Query(c3+1,e,i,j,c2+1));
}


int main()
	{
		constant();
		int val,ma,t,n,i,j,te1,te2,c,index,node;
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
				for(i=0;i<n;i++)	pur[i]=v[i].second;
				obtain(n);				
				sort(pur,pur+n);
				for(j=1;j<power[level];j++)	seg[j]=0;
				for(j=0;j<n;j++)
					{	
						index=bs11(0,n-1,v[j].second);
						val=1+Query(1,power[level-1],1,index+1,1);
						node=index+power[level-1];
						seg[node]=val;
						node>>=1;
						while(node!=0)
						{
							c=node<<1;
							seg[node]=max(seg[c],seg[c+1]);
							node>>=1;
						}
					}
				printf("%d\n",seg[1]);

				/*
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
				*/
			}
		return 0;
	}