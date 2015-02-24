#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
int N;
#define SIZE 100005
struct node	
	{
		int mval,sum;
	};
typedef struct node Node;
Node segtree[4*SIZE+10];
int A[2*SIZE+5];
void build(int idx)
	{
		if(idx>=N-1)
			{
				segtree[idx].mval=A[idx-N+1];
				segtree[idx].sum=0;
				return;
			}
		build(2*idx+1);
		build(2*idx+2);
		segtree[idx].mval=max(segtree[2*idx+1].mval,segtree[2*idx+2].mval);
		segtree[idx].sum=max(max(segtree[2*idx+1].sum,segtree[2*idx+2].sum),segtree[2*idx+1].mval+segtree[2*idx+2].mval);
	}
void update(int pos,int x,int cl,int cr,int idx)
	{
		if(pos==idx)
			{
				segtree[idx].mval=x;
				return;
			}
		if(cl>pos || cr<pos)	return;
		int mid=(cl+cr)/2;
		update(pos,x,cl,mid,2*idx+1);
		update(pos,x,mid+1,cr,2*idx+2);
		segtree[idx].mval=max(segtree[2*idx+1].mval,segtree[2*idx+2].mval);
		segtree[idx].sum=max(max(segtree[2*idx+1].sum,segtree[2*idx+2].sum),segtree[2*idx+1].mval+segtree[2*idx+2].mval);	
	}
Node query(int l,int r,int cl,int cr,int idx)
	{
		Node K;
		int mid=(cl+cr)/2;
		if(cl>=l && cr<=r)	return segtree[idx];
		if(r<=mid)
                return query(l,r,cl,mid,2*idx+1);
        else if(l>mid)
                return query(l,r,mid+1,cr,2*idx+2);
		Node K1,K2;
		K1=query(l,r,cl,mid,2*idx+1);
		K2=query(l,r,mid+1,cr,2*idx+2);
		K.mval=max(K1.mval,K2.mval);
		K.sum=max(max(K1.sum,K2.sum),K1.mval+K2.mval);	
		return K;
	}
int main()
	{
		int n,i,j,q,b,x,y;
		char ch;
		scanf("%d",&n);
		N=1;
		Node ans;
		while(N<n)	N<<=1;
		for(i=0;i<n;i++)	scanf("%d",&A[i]);
		for(i=n;i<N;i++)	A[i]=0;
		build(0);
		scanf("%d",&q);
		while(q--)
			{
				scanf(" %c",&ch);
				if(ch=='Q')
					{
						scanf("%d %d",&x,&y);
						x--;
						y--;
						ans=query(x+N-1,y+N-1,N-1,2*N-2,0);
						printf("%d\n",ans.sum);
					}
				else
					{
						scanf("%d %d",&i,&x);
						i--;
						update(i+N-1,x,N-1,2*N-2,0);		
					}
			}
		return 0;
	}