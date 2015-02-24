/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "vector"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)
#define PP			pair<int,int>
#define MP			make_pair
#define fi			first
#define se			second
#define	MAX			(int)1<<21

PP A[MAX+5];
int n,m,x,y;

void init(int idx)
	{
		if(idx>= (1<<n)-1)	return;
		init(2*idx+1);
		init(2*idx+2);
		A[idx].se=max(A[2*idx+1].se,A[2*idx+2].se);
		if(A[idx].se==A[2*idx+1].se)	A[idx].fi=A[2*idx+1].fi;
		else				A[idx].fi=A[2*idx+2].fi;		
	}

int main()
	{
		int i,j,te,ans;
		char ch;
		scanf("%d %d",&n,&m);
		FOR(i,0,1<<n)
			{
				scanf("%d",&te);
				A[(1<<n)-1 +i].fi=i+1;
				A[(1<<n)-1 +i].se=te;
			}
		init(0);
		while(m--)	
			{
				getchar();
				ch=(char)getchar();
				if(ch=='W')	
					{
						printf("%d\n",A[0].fi);
					}
				else if(ch=='R')
					{
						getchar();
						scanf("%d %d",&x,&y);
						x= x+ (1<<n) -2;
						A[x].se=y;
						while(x)
							{
								te=(x-1)/2;
								A[te].se=max(A[2*te+1].se,A[2*te+2].se);
								if(A[te].se==A[2*te+1].se)	A[te].fi=A[2*te+1].fi;
								else				A[te].fi=A[2*te+2].fi;		
								x=(x-1)/2;
							}
						
					}
				else
					{
						getchar();
						scanf("%d",&x);
						ans=0;
						te=x;
						x= x+ (1<<n) -2;
						while(A[x].fi==te && x)
							{
								ans++;
								x=(x-1)/2;
							}
						ans--;
						if(A[0].fi==te)		ans++;
						printf("%d\n",ans);
					}
				//FOR(i,0,(1<<(n+1))-1)
					//cout<<A[i].fi<<" "<<A[i].se<<endl;
			}
		return 0;
	}
