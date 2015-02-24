/* bhupkas */
#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
#define SIZE1 100000
#define SIZE2 2000007
bool P[SIZE2];
int A[2*SIZE1];
int N;
pair<int,int> segtree[4*SIZE1+10];
void pre()
	{
		int i,j;
		for(i=0;i<SIZE2;i++)	P[i]=true;
		P[0]=P[1]=false;
		for(i=2;i*i<SIZE2;i++)
			{
				if(P[i])
					{
						for(j=i;j<=SIZE2/i;j++)
							P[i*j]=false;
					}
			}
	}
void build(int idx)
	{
		if(idx>=N-1)
			{
				if(P[A[idx-N+1]])	
					{
						segtree[idx].first=1;
						segtree[idx].second=1;
					}
				else
					{
						segtree[idx].first=0;
						segtree[idx].second=-1;
					}
				return;
			}
		build(2*idx+1);
		build(2*idx+2);
		segtree[idx].first=segtree[2*idx+1].first+segtree[2*idx+2].first;
		if(segtree[2*idx+1].second==1 && segtree[2*idx+2].second==1)	segtree[idx].second=1;
		else if(segtree[2*idx+1].second==-1 && segtree[2*idx+2].second==-1)	segtree[idx].second=-1;
		else segtree[idx].second=0;
	}
void update(int l,int r,int cl,int cr,int idx,int v)
	{
		if(cl>=l && cr<=r)
			{
				if(P[v])
					{
						segtree[idx].second=1;
						segtree[idx].first=cr-cl+1;
					}
				else
					{
						segtree[idx].second=-1;
						segtree[idx].first=0;
					}
				return;
			}
		int mid=(cl+cr)/2;
		if(r<cl || l>cr)	return;
		else
			{
				if(segtree[idx].second==1)
					{
						segtree[2*idx+1].second=1;
						segtree[2*idx+2].second=1;
						segtree[2*idx+1].first=mid-cl+1;
						segtree[2*idx+2].first=cr-mid;
					}
				if(segtree[idx].second==-1)
					{
						segtree[2*idx+1].second=-1;
						segtree[2*idx+2].second=-1;
						segtree[2*idx+1].first=0;
						segtree[2*idx+2].first=0;
					}
				update(l,r,cl,mid,2*idx+1,v);
				update(l,r,mid+1,cr,2*idx+2,v);
				segtree[idx].first=segtree[2*idx+1].first+segtree[2*idx+2].first;
				if(segtree[2*idx+1].second==1 && segtree[2*idx+2].second==1)	segtree[idx].second=1;
				else if(segtree[2*idx+1].second==-1 && segtree[2*idx+2].second==-1)	segtree[idx].second=-1;
				else segtree[idx].second=0;
				return;
			}
	}
pair<int,int> query(int l,int r,int cl,int cr,int idx)
	{
		if(cl>=l && cr<=r)
			return make_pair(segtree[idx].first,cr-cl+1);
		if(r<cl || l>cr)	return make_pair(0,0);
		int mid=(cl+cr)/2;
		pair<int,int> le,ri,ans;
		le=query(l,r,cl,mid,2*idx+1);
		ri=query(l,r,mid+1,cr,2*idx+2);
		if(segtree[idx].second==1)
			return make_pair(le.second+ri.second,le.second+ri.second);
		if(segtree[idx].second==-1)
			return make_pair(0,le.second+ri.second);
		return make_pair(le.first+ri.first,le.second+ri.second);
	}
int main()
	{
		pre();
		int tc,t,x,y,b,i,j,n,v,q;
		scanf("%d",&t);
		pair<int,int> ans;
		for(tc=1;tc<=t;tc++)
			{
				scanf("%d %d",&n,&q);
				N=1;
				while(N<n)	N<<=1;
				for(i=0;i<n;i++)	scanf("%d",&A[i]);
				for(i=n;i<N;i++)	A[i]=0;
				build(0);
				printf("Case %d:\n",tc);
				//for(i=0;i<2*N-1;i++)	cout<<segtree[i].first<<","<<segtree[i].second<<" ";
				//cout<<endl;
				while(q--)
					{
						scanf("%d",&b);
						if(b)
							{
								scanf("%d %d",&x,&y);
								x--;
								y--;
								ans=query(x+N-1,y+N-1,N-1,2*N-2,0);
								printf("%d\n",ans.first);
							}
						else
							{
								scanf("%d %d %d",&x,&y,&v);
								x--;
								y--;
								update(x+N-1,y+N-1,N-1,2*N-2,0,v);
								//for(i=0;i<2*N-1;i++)	cout<<segtree[i].first<<","<<segtree[i].second<<" ";
								//cout<<endl;
							}
					}
			}
		return 0;
	}