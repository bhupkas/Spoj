/* bhupkas */

#include "bits/stdc++.h"

using namespace std;

#define INF 100000000

int dis[105][105];

int n,m,b;

struct node
{
	int u,v,b;
};

typedef struct node Node;

vector < Node > parcels;

vector < int > perm;

int main()
{
	int t;
	scanf("%d",&t);
	int z,u,v,d,b,source,val;
	int re;
	Node N;
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&b);
		b--;
		source = b;
		for(int i = 0 ; i < n ; i++)	for(int j = 0 ; j < n ; j++)	dis[i][j] = INF;
		for(int i = 0 ; i < m ; i++)
		{
			scanf("%d %d %d",&u,&v,&d);
			u--;
			v--;
			dis[u][v] = d;
			dis[v][u] = d;
		}
		for(int k = 0 ; k < n ; k++)
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < n ; j++)	
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
		scanf("%d",&z);
		for(int i = 0 ; i < z ; i++)
		{
			scanf("%d %d %d",&u,&v,&b);
			u--;
			v--;
			N.u = u;
			N.v = v;
			N.b = b;
			parcels.push_back(N);
		}	
		perm.clear();
		parcels.clear();
		re = INF;
		for(int i = 0 ; i < n ; i++)	dis[i][i] = 0;
		for(int i = 0 ; i < z ; i++)	for(int j = 0 ; j < parcels[i].b ; j++)	perm.push_back(i);
		int cnt = 0;
		do
		{
			val = 0;
			val += dis[source][parcels[perm[0]].u];
			for(int i = 0 ; i < perm.size() - 1 ; i++)	
				val += dis[parcels[perm[i]].u][parcels[perm[i]].v] + dis[parcels[perm[i]].v][parcels[perm[i+1]].u];
			val += dis[parcels[perm[perm.size()-1]].u][parcels[perm[perm.size()-1]].v] + dis[parcels[perm[perm.size()-1]].v][source];
			re = min(re,val);		
		}while(next_permutation(perm.begin(),perm.end()));
		printf("%d\n",re);
	}
	return 0;
}
