/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

vector < int > adj[100005];

int T[100005];

int D[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i = 0 ; i < m ; ++i)
	{
		int u,v;
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		D[v-1]++;
	}
	set < int > s;
	set < int > :: iterator it;
	for(int i = 0 ; i < n ; ++i)	if(D[i] == 0)	s.insert(i);
	int cnt = 0;
	if(s.empty())
	{
		puts("Sandro fails.");
		return 0;
	}
	while(!s.empty())
	{
		it = s.begin();
		T[cnt++] = (*it);
		for(int i = 0 ; i < adj[(*it)].size() ; ++i)
		{
			D[adj[(*it)][i]]--;
			if(D[adj[(*it)][i]] == 0)	s.insert(adj[(*it)][i]);
		}
		s.erase(it);
	}
	if(cnt != n)
	{
		puts("Sandro fails.");
		return 0;
	}
	for(int i = 0 ; i < n ; ++i)	cout << T[i] + 1<< " ";
	cout << endl;
	return 0;
}
