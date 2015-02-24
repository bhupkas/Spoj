/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"

using namespace std;

typedef long long LL;
#define inf 100000000

LL n,N;
struct node 
	{
		LL setto,incr,sum,sums;
	};
typedef struct node Node;
Node segtree[400005];

void fun(LL idx)
	{
		segtree[idx].setto=inf;
		segtree[idx].incr=0;
		segtree[idx].sum=segtree[2*idx+1].sum + segtree[2*idx+2].sum;
		segtree[idx].sums=segtree[2*idx+1].sums + segtree[2*idx+2].sums;
	}

void build(LL idx)
	{
		if(idx>=N)	return;
		build(2*idx+1);
		build(2*idx+2);
		fun(idx);
	}

void update_set(LL l,LL r,LL cl,LL cr,LL idx, LL y,LL incr)
	{
		if(r<cl||l>cr)	
			{
				segtree[idx].incr=incr;
				update_incr(cl,cr,cl,cr,idx,incr);
			}
		if(cl>=l && cr<=r)		
			{
				segtree[idx].setto=y;
				segtree[idx].incr=0;
				segtree[idx].sum=y*(cr-cl+1);
				segtree[idx].sums=y*segtree[idx].sum;
				return;
			}
		LL mid=(cl_cr)/2;
		update_set(l,r,cl,mid,2*idx+1,y,segtree[idx].incr);
		update_set(l,r,mid+1,r,2*idx+2,y.segtree[idx].incr);
		fun(idx);	
	}

void update_incr(LL l,LL r,LL cl,LL cr,LL idx, LL x)
	{
		if(r<cl||l>cr)		return;	
		if(cl>=l && cr<=r)		
			{
				segtree[idx].setto=inf;
				segtree[idx].incr+=x;
				segtree[idx].sums+=x*x*((cr-cl+1)>>1)+(x*segtree[idx].sum)<<1;
				segtree[idx].sum+=x*(cr-cl+1);
				return;
			}
		LL mid=(cl_cr)/2;
		update_set(l,r,cl,mid,2*idx+1,y);
		update_set(l,r,mid+1,r,2*idx+2,y);
		fun(idx);	
	}

pair<LL,LL> query(LL l,LL r,LL cl,LL cr,LL idx)
	{	
		pair<LL,LL> p1,p2;
		if(r<cl||l>cr)	return make_pair(0,0);
		if(cl>=l && cr<=r)		return make_pair(segtree[idx].sums,cr-cl+1);
		LL mid=(cl+cr)/2;
		p1=query(l,r,cl,mid,2*idx+1);
		p2=query(l,r,mid+1,cr,2*idx+2);
	}

int main()
	{
		LL t,i,j,Q,temp,p,q,x,y;
		cin>>t;
		while(t--)	
			{
				cin>>n>>Q;
				N=1;
				while(N<n)	N<<=1;
				for(i=N;i<2*N-1;i++)
					{
						cin>>temp;
						segtree[i].setto=inf;
						segtree[i].incr=0;
						segtree[i].sum=temp;
						segtree[i].sums=temp*temp;
					}	
				build(0);
				while(Q--)
					{
						cin>>temp;
						if(temp==0)
							{
									cin>>p>>q>>y;
									p--;q--;
									update_set(p+N-1,q+N-1,0,2*N-1,0,y,segtree[0].incr);
							}			
					}
			}
		return 0;
	}