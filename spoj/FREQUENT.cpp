#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
#define SIZE 400000
struct node
	{
		int maxco,maxval,lco,lval,rco,rval;
	};
int N;
typedef struct node Node;
Node segtree[4*SIZE+10];
int A[2*SIZE+10];
void build(int idx)
	{
		if(idx>=N-1)
			{
				segtree[idx].maxco=segtree[idx].lco=segtree[idx].rco=1;
				segtree[idx].rval=segtree[idx].lval=segtree[idx].maxval=A[idx-N+1];
				return;
			}
		build(2*idx+1);
		build(2*idx+2);
		segtree[idx].lval=segtree[2*idx+1].lval;
		segtree[idx].lco=segtree[2*idx+1].lco;
		if(segtree[2*idx+1].lval==segtree[2*idx+2].lval)
				segtree[idx].lco=segtree[2*idx+1].lco+segtree[2*idx+2].lco;
		segtree[idx].rval=segtree[2*idx+2].rval;
		segtree[idx].rco=segtree[2*idx+2].rco;
		if(segtree[2*idx+1].rval==segtree[2*idx+2].rval)
				segtree[idx].rco=segtree[2*idx+1].rco+segtree[2*idx+2].rco;
		if(segtree[2*idx+1].maxco>=segtree[2*idx+2].maxco)
			{
				segtree[idx].maxco=segtree[2*idx+1].maxco;
				segtree[idx].maxval=segtree[2*idx+1].maxval;
			}
		if(segtree[2*idx+1].maxco<segtree[2*idx+2].maxco)
			{
				segtree[idx].maxco=segtree[2*idx+2].maxco;
				segtree[idx].maxval=segtree[2*idx+2].maxval;
			}
		if(segtree[2*idx+1].rval==segtree[2*idx+2].lval && segtree[idx].maxco<segtree[2*idx+1].rco+segtree[2*idx+2].lco)
			{
				segtree[idx].maxval=segtree[2*idx+1].rval;
				segtree[idx].maxco=segtree[2*idx+1].rco+segtree[2*idx+2].lco;
			}
	}
Node query(int l,int r,int cl,int cr,int idx)
	{
		if(cl>=l && cr<=r)	return segtree[idx];
		int mid=(cl+cr)/2;
		Node K1,K2,K;
		if(r<=mid)
                return query(l,r,cl,mid,2*idx+1);
        else if(l>mid)
                return query(l,r,mid+1,cr,2*idx+2);
        K1=query(l,r,cl,mid,2*idx+1);
		K2=query(l,r,mid+1,cr,2*idx+2);
		K.lval=K1.lval;
		K.lco=K1.lco;
		if(K1.lval==K2.lval)
				K.lco=K1.lco+K2.lco;
		K.rval=K2.rval;
		K.rco=K2.rco;
		if(K1.rval==K2.rval)
				K.rco=K1.rco+K2.rco;
		if(K1.maxco>=K2.maxco)
			{
				K.maxco=K1.maxco;
				K.maxval=K1.maxval;
			}
		if(K1.maxco<K2.maxco)
			{
				K.maxco=K2.maxco;
				K.maxval=K2.maxval;
			}
		if(K1.rval==K2.lval && K.maxco<K1.rco+K2.lco)
			{
				K.maxval=K1.rval;
				K.maxco=K1.rco+K2.lco;
			}
		return K;
	}
int main()
	{
		int t=1,n,q,x,y,i,j;
		scanf("%d",&n);
		while(n!=0)
			{
				cin>>q;
				N=1;
				while(N<n)	N<<=1;
				for(i=0;i<n;i++)	scanf("%d",&A[i]);
				for(i=n;i<N;i++)	A[i]=A[i-1]+1;
				build(0);
				Node ans;
				while(q--)
					{
						scanf("%d %d",&x,&y);
						x--;
						y--;
						ans=query(x+N-1,y+N-1,N-1,2*N-2,0);
						printf("%d\n",ans.maxco);
					}
				scanf("%d",&n);
			}
		return 0;
	}