/* bhupkas */

#include "bits/stdc++.h"

using namespace std;

#define MAXN 505

#define INF 1000000000

int M[MAXN + 5][MAXN + 5];
int memo[MAXN + 5][MAXN + 5];

int main()
{
	int n,kk,t;
	cin >> n >> kk >> t;
	int A[505];
	for(int i = 1 ; i <= n ; i++)	cin >> A[i];
	for(int i = 1 ; i <= n ; i++)
	{
		M[i][i] = A[i];
		for(int j = i + 1 ; j <= n ; j++)
		{
			M[i][j] = min(M[i][j-1] , A[j]);
		}
	}	
	for(int i = 0 ; i <= n ; i++)	for(int j = 0 ; j <= kk ; j++)	memo[i][j] = -1 * INF;
	for(int i = 0 ; i <= n ; i++)	memo[i][0] = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = max(1,i - t + 1) ; j <= i ; j++)
		{
			for(int k = 0 ; k < kk ; k++)   
			{
				memo[i][k + 1] = max(memo[i][k + 1] , memo[j - 1][k] + M[j][i] * (i - j + 1));	
				memo[i][k + 1] = max(memo[i][k + 1] , memo[i - 1][k + 1]);
			}
		}
	}
	int re = -1;
	for(int i = 0 ; i <= n ; i++)	re = max(re , memo[i][kk]);
	cout << re << endl;
	return 0;
}
