#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
typedef long long LL;
#define FOR(i,a,b)	for(i=a;i<b;i++)
#define SIZE 100005
pair<LL,LL> segtree[4*SIZE + 10];
LL N,segtreechild[4*SIZE+10];
void build(LL idx)
	{
		if(idx>=N-1)	segtreechild[idx]=1;
		else 	
			{
				build(2*idx+1);
				build(2*idx+2);
				segtreechild[idx]=segtreechild[2*idx+1]+segtreechild[2*idx+2];
			}
	}
void update(LL l,LL r,LL cl,LL cr,LL idx,LL v)
	{
		if(r<cl||l>cr)	return;
		if(cl>=l && cr<=r)		{segtree[idx].second+=v;	return;}
		LL mid=(cl+cr)/2;
		update(l,r,cl,mid,2*idx+1,v);
		update(l,r,mid+1,cr,2*idx+2,v);
		segtree[idx].first=segtree[2*idx+1].first+segtree[2*idx+2].first+segtree[2*idx+1].second*segtreechild[2*idx+1]+segtree[2*idx+2].second*segtreechild[2*idx+2];
	}
pair<LL,LL> query(LL l,LL r,LL cl,LL cr,LL idx)
	{
		pair<LL,LL> p1,p2;
		if(r<cl||l>cr)	return make_pair(0,0);
		if(cl>=l && cr<=r)		{return make_pair(segtree[idx].first + segtree[idx].second*segtreechild[idx],cr-cl+1);}
		LL mid=(cl+cr)/2;
		p1=query(l,r,cl,mid,2*idx+1);
		p2=query(l,r,mid+1,cr,2*idx+2);
		return make_pair(p1.first+p2.first+segtree[idx].second*(p1.second+p2.second),p1.second+p2.second);
	}
int main()
	{
		LL t,n,c,p,q,b,v,i,j;
		cin>>t;
		pair<LL,LL> ans;
		while(t--)
			{
				cin>>n>>c;
				N=1;
				while(N<n)	N<<=1;
				build(0);
				FOR(i,0,2*N-1)	segtree[i]=make_pair(0,0);
				while(c--)
				{
					cin>>b>>p>>q;
						p--;
						q--;
						if(!b)	cin>>v;
						if(!b)	update(p+N-1,q+N-1,N-1,2*N-2,0,v);
						else
						{
							ans=query(p+N-1,q+N-1,N-1,2*N-2,0);
							cout<<ans.first<<endl;
						}
					//FOR(i,0,2*N-1)	cout<<segtree[i].first<<" ";
					//cout<<endl;
					//FOR(i,0,2*N-1)	cout<<segtree[i].second<<" ";
					//cout<<endl;
				}
			}
		return 0;
	}
