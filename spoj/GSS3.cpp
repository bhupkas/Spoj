/* bhupkas */
#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
#define SIZE 50005
typedef long long  LL;
#define BUF 4096 // block size on my disk is 4KBs
char ibuf[BUF];
LL ipt = BUF;
LL read() {
while (ipt < BUF && ibuf[ipt] < '0') ipt++;
if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
}
LL n = 0;
while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
}
return n;
}
struct node
	{
		LL sum,lval,rval,maxv;
	};
typedef struct node Node;
Node segtree[4*SIZE+4];
LL A[2*SIZE];
void build(LL idx,LL N)
	{
		if(idx>=N-1)
			{
				segtree[idx].sum=segtree[idx].lval=segtree[idx].rval=segtree[idx].maxv=A[idx-N+1];
				return;
			}
		build(2*idx+1,N);
		build(2*idx+2,N);
		segtree[idx].sum=segtree[2*idx+1].sum+segtree[2*idx+2].sum;
		segtree[idx].maxv=max(max(segtree[2*idx+1].maxv,segtree[2*idx+2].maxv),segtree[2*idx+1].rval+segtree[2*idx+2].lval);
		segtree[idx].lval=max(segtree[2*idx+1].lval,segtree[2*idx+1].sum+segtree[2*idx+2].lval);
		segtree[idx].rval=max(segtree[2*idx+2].rval,segtree[2*idx+2].sum+segtree[2*idx+1].rval);
	}
Node query(LL l,LL r,LL cl,LL cr,LL idx)
	{
		Node N;
		N.maxv=-1;
		N.lval=N.rval=N.sum=0;
		LL mid=(cl+cr)/2;
		if(cl>=l && cr<=r)	return segtree[idx];
		if(r<=mid)
                return query(l,r,cl,mid,2*idx+1);
        else if(l>mid)
                return query(l,r,mid+1,cr,2*idx+2);
		Node N1,N2;
		N1=query(l,r,cl,mid,2*idx+1);
		N2=query(l,r,mid+1,cr,2*idx+2);
		N.sum=N1.sum+N2.sum;
		N.maxv=max(max(N1.maxv,N2.maxv),N1.rval+N2.lval);
		N.lval=max(N1.lval,N1.sum+N2.lval);
		N.rval=max(N2.rval,N1.rval+N2.sum);
		return N;
	}
void update(LL x,LL y,LL cl,LL cr,LL idx)
	{
		if(idx==x)
			{
				segtree[idx].sum=segtree[idx].lval=segtree[idx].rval=segtree[idx].maxv=y;
				return;	
			}
		if(cl>x || cr<x)	return;
		LL mid=(cl+cr)/2;
		update(x,y,cl,mid,2*idx+1);
		update(x,y,mid+1,cr,2*idx+2);
		segtree[idx].sum=segtree[2*idx+1].sum+segtree[2*idx+2].sum;
		segtree[idx].maxv=max(max(segtree[2*idx+1].maxv,segtree[2*idx+2].maxv),segtree[2*idx+1].rval+segtree[2*idx+2].lval);
		segtree[idx].lval=max(segtree[2*idx+1].lval,segtree[2*idx+1].sum+segtree[2*idx+2].lval);
		segtree[idx].rval=max(segtree[2*idx+2].rval,segtree[2*idx+2].sum+segtree[2*idx+1].rval);
	}
int main()
	{
		LL n,i,j,q,N,l,r,b,x,y;
		scanf("%lld",&n);
		N=1;
		Node ans;
		while(N<n)	N<<=1;
		for(i=0;i<n;i++)	cin>>A[i];
		for(i=n;i<N;i++)	A[i]=0;
		build(0,N);
		scanf("%lld",&q);
		while(q--)
			{
				scanf("%lld",&b);
				if(b)
					{
						scanf("%lld %lld",&l,&r);
						l--;
						r--;
						ans=query(l+N-1,r+N-1,N-1,2*N-2,0);
						printf("%lld\n",ans.maxv);
					}
				else
					{
						scanf("%lld %lld",&x,&y);
						x--;
						update(x+N-1,y,N-1,2*N-2,0);
					}
			}
		return 0;
	}