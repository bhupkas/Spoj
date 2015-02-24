/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

vector < pair < LL , LL > > adj[1000005];

LL D[1000005];

#define INF (LL)(1e18)

int main()
{
	LL t;
	cin >> t;
	while(t--)
	{
		LL n,m;
		cin >> n >> m;
		for(LL i = 0 ; i < n ; ++i)	adj[i].clear();
		for(LL i = 0 ; i < m ; ++i)
		{	
			int a,b,c;
			cin >> a >> b >> c;
			adj[a-1].push_back(make_pair(b-1,c));
		}
		LL src,dst;
		cin >> src >> dst;
		src--;
		dst--;
		for(LL i = 0 ; i < n ; ++i)	D[i] = INF;
		D[src] = 0;
		set < pair < LL , LL > > s;
		set < pair < LL , LL > > :: iterator it,it1;
		s.insert(make_pair(0,src));
		while(!s.empty())
		{
			it = s.begin();
			s.erase(it);
			LL curr = (*it).second;
			for(LL i = 0 ; i < adj[curr].size() ; ++i)
			{
				if(D[curr] + adj[curr][i].second < D[adj[curr][i].first])
				{
					it1 = s.find(make_pair(D[adj[curr][i].first],adj[curr][i].first));
					if(it1 != s.end())	s.erase(it1);
					D[adj[curr][i].first] = D[curr] + adj[curr][i].second;
					s.insert(make_pair(D[curr] + adj[curr][i].second , adj[curr][i].first));
				}
			}
		}
		if(D[dst] == INF)	puts("NO");
		else	cout << D[dst] << endl;
	}
	return 0;
}
