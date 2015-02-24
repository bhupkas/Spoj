/* bhupkas */

#include "bits/stdc++.h"

using namespace std;

int D[205][205];

#define INF 100000000

int Q[1005];

int memo[1005][205][205];

int main()
{
	int t;
	cin >> t;
	int n,l;
	while(t--)
	{
		cin >> l >> n;
		for(int i = 0 ; i < l ; i++)	for(int j = 0 ; j < l ; j++)	D[i][j] = INF;
		for(int i = 0 ; i < l ; i++)	for(int j = 0 ; j < l ; j++)	cin >> D[i][j];
		for(int i = 0 ; i < n ; i++)	cin >> Q[i];
		for(int k = 0 ; k < l ; k++)
			for(int i = 0 ; i < l ; i++)
				for(int j = 0 ; j < l ; j++)
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
		for(int i = 0 ; i < l ; i++)	D[i][i] = 0;
		for(int i = 0 ; i < n ; i++)	for(int j = 0 ; j < l ; j++)	for(int k = 0 ; k < l ; k++)	memo[i][j][k] = INF;
		memo[0][1][2] = D[0][Q[0]];
		memo[0][0][2] = D[1][Q[0]];
		memo[0][0][1] = D[2][Q[0]];		
		memo[0][2][1] = D[0][Q[0]];
		memo[0][2][0] = D[1][Q[0]];
		memo[0][1][0] = D[2][Q[0]];
		for(int i = 1 ; i < n ; i++)
		{
			for(int j = 0 ; j < l ; j++)
			{
				for(int k = 0 ; k < l ; k++)
				{
					if(k == j)	continue;
					memo[i][j][k] = min(memo[i][j][k] , memo[i-1][j][k] + D[Q[i-1]][Q[i]]);
					memo[i][Q[i-1]][k] = min(memo[i][j][k] , memo[i-1][j][k] + D[j][Q[i]]);
					memo[i][j][Q[i-1]] = min(memo[i][j][k] , memo[i-1][j][k] + D[k][Q[i]]);
					memo[i][k][j] = memo[i][j][k];
					memo[i][k][Q[i-1]] = memo[i][Q[i-1]][k];
					memo[i][Q[i-1]][j] = memo[i][j][Q[i-1]];
				}
			}
		}
		for(int i = 0 ; i < n ; i++)
		{	
			for(int j = 0 ; j < l ; j++)
			{	
				for(int k = 0 ; k < l ; k++)
					cout << memo[i][j][k] << " ";
				cout << endl;
			}
			cout << endl;
		}
		int re = INF;
		for(int i = 0 ; i < l ; i++)	for(int j = 0 ; j < l ; j++)	re = min(re,memo[n-1][i][j]);
		cout << re << endl;
	}
	return 0;
}
