/* bhupkas */

#include "bits/stdc++.h"

using namespace std;

#define MAXN 5005

vector < int > adj[MAXN + 5];
vector < int > rev[MAXN + 5];

int SCC[MAXN + 5];

bool visi[MAXN + 5];

int cnt;

vector < int > v;

int read() 
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

void dfs1(int vertex)
{	
	visi[vertex] = true;
	for(int i = 0 ; i < adj[vertex].size() ; i++)
	{	
		int curr = adj[vertex][i];
		if(!visi[curr])		dfs1(curr);
	}
	v.push_back(vertex);
}

void dfs2(int vertex)
{
	visi[vertex] = true;
	SCC[vertex] = cnt;
	for(int i = 0 ; i < rev[vertex].size() ; i++)
	{
		int curr = rev[vertex][i];
		if(!visi[curr])	dfs2(curr);
	}
}

bool B[5005];

int main()
{
	int n,m;
	while(1)
	{
		cnt = 0;
		v.clear();
		n = read();
		if(!n)	break;
		m = read();
		for(int i = 0 ; i < n ; i++)	adj[i].clear() , rev[i].clear();
		for(int i = 0 ; i < m ; i++)
		{
			int u,v;
			u = read();
			v = read();
			u--;
			v--;
			adj[u].push_back(v);
			rev[v].push_back(u);
		}
		memset(visi,false,sizeof(visi));
		for(int i = 0 ; i < n ; i++)	if(!visi[i])	dfs1(i);				
		reverse(v.begin(),v.end());
		memset(visi,false,sizeof(visi));
		for(int i = 0 ; i < n ; i++)
		{
			B[cnt] = true;
			if(!visi[v[i]])	dfs2(v[i]);		
			cnt++;	
		}
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < adj[i].size() ; j++)
			{
				if(SCC[adj[i][j]] != SCC[i] )	
				{
					B[SCC[i]] = false;
					break;
				}
			}
		}	
		for(int i = 0 ; i < n ; i++)	
			if(B[SCC[i]])	cout << i + 1 << " ";
		cout << endl;
	}
	return 0;
}
