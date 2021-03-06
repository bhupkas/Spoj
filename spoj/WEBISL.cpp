/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

#define SIZE 100005

vector < int > adj[SIZE],rev[SIZE];

int n,m;

vector < int > v;

bool B[SIZE];

int cnt;

vector < int > SCC[SIZE];

int FINAL[SIZE];

void dfs(int x)
{
        B[x] = true;
        for(int i = 0 ; i < adj[x].size() ; ++i)
                if(!B[adj[x][i]])        dfs(adj[x][i]);
        v.push_back(x);
}

void dfs1(int x)
{
        SCC[cnt].push_back(x);
        B[x] = true;
        for(int i = 0 ; i < rev[x].size() ; ++i)
                if(!B[rev[x][i]])        dfs1(rev[x][i]);
}

int main()
{       
        cin >> n >> m;
        for(int i = 0 ; i < m ; ++i)
        {
                int u1,v1;
                cin >> u1 >> v1;
                adj[u1].push_back(v1);
                rev[v1].push_back(u1);
        }
        for(int i = 0 ; i < n ; ++i)    B[i] = false;
        for(int i = 0 ; i < n ; ++i)    if(!B[i])       dfs(i);
        cnt = 0 ;
        for(int i = 0 ; i < n ; ++i)    B[i] = false;
        reverse(v.begin() , v.end());
        for(int i = 0 ; i < v.size() ; ++i)
        {
                if(!B[v[i]])    
                {
                        dfs1(v[i]);
                        cnt++;
                }
        }
        for(int i = 0 ; i < cnt ; ++i)  sort(SCC[i].begin() , SCC[i].end());
        for(int i = 0 ; i < cnt ; ++i)
                for(int j = 0 ; j < SCC[i].size() ; ++j)
                        FINAL[SCC[i][j]] = SCC[i][0];
        for(int i = 0 ; i < n ; ++i)    cout << FINAL[i] << endl;
        return 0;
}
