/* bhupkas */

/* BIPARTITE GRAPH */

#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "vector"
#include "queue"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)
#define PB				push_back
#define vi 				vector<int>    
#define PF				pop_front
#define F 				front

vi v[2005];
int color[2005];

bool bfs(int x)
	{
		color[x]=0;
		deque<int> q;
		q.PB(x);
		int i,curr;
		while(!q.empty())
			{
				curr=q.F();
				q.PF();
				for(i=0;i<v[curr].size();i++)
					{
						if(color[v[curr][i]]==-1)	
							{
								color[v[curr][i]]=1-color[curr];
								q.PB(v[curr][i]);
							}
						else if(color[v[curr][i]]==color[curr])	return false;
					}
			}
		return true;
	}

int main()
	{
		int t,tc,i,j,x,y,n,m,curr;
		cin>>t;
		FOR(tc,1,t+1)
			{
				scanf("%d %d",&n,&m);
				FOR(i,0,n)	{color[i]=-1;	v[i].clear();}
				FOR(i,0,m)
					{
						scanf("%d %d",&x,&y);
						x--;
						y--;
						v[x].PB(y);
						v[y].PB(x);
					}
				FOR(i,0,n)
					{
						if(color[i]==-1)	if(!bfs(i))	break;;
					}
				printf("Scenario #%d:\n",tc);
				if(i!=n)	printf("Suspicious bugs found!\n");
				else		printf("No suspicious bugs found!\n");
			}
		return 0;
	}