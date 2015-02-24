/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

const int N = 105;

const int INF = (1<<30);

string B[N];
int D[N][N][3];

int n,m;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int x,y;

bool ok(int xk , int yk)
{
	return (xk >= 0 && xk < n & yk >= 0 && yk < m);
}

int bfs()
{
	if(x == n - 1 || x == 0 || y == m - 1 || y == 0)	return 0;
	D[x][y][0] = 0;
	queue < int > Q;
	Q.push(x) , Q.push(y) , Q.push(0);
	int r,c,s,rk,ck,sk;
	while(!Q.empty())
	{
		r = Q.front() , Q.pop();
		c = Q.front() , Q.pop();
		s = Q.front() , Q.pop();
		for(int i = 0 ; i < 4 ; ++i)
		{
			rk = r + dx[i];
			ck = c + dy[i];
			if(ok(rk,ck) && B[rk][ck] != 'W')
			{	
				if(s != 1 && B[rk][ck] == 'D')	continue;
				if(rk == n - 1 || rk == 0 || ck == m - 1 || ck == 0)	return D[r][c][s] + 1;
				if(B[rk][ck] == 'O')	sk = 1;
				else if(B[rk][ck] == 'C')	sk = 2;
				else	sk = s;
				if(D[rk][ck][sk] > D[r][c][s] + 1) 
				{
					Q.push(rk) , Q.push(ck) , Q.push(sk);
					D[rk][ck][sk] = D[r][c][s] + 1;
				}
			}
		}
	}
	return -2;
}

int main()
{
	while(1)
	{
		cin >> n >> m;
		if(n + m == -2)	break;
		for(int i = 0 ; i < n ; ++i)	cin >> B[i];
		for(int i = 0 ; i < n ; ++i)	
			for(int j = 0 ; j < m ; ++j)	
				D[i][j][0] = D[i][j][1] = D[i][j][2] = INF;
		for(int i = 0 ; i < n ; ++i)	for(int j = 0 ; j < m ; ++j)	if(B[i][j] == 'H')	x = i , y = j;
		
		cout << bfs() + 1 << endl;
		
	}
	return 0;
}
