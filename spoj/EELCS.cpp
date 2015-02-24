/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

int T[20][20];

int main()
{
	int n,m;
	string A,B;
	cin >> A >> B;
	n = A.size();
	m = B.size();
	for(int i = 0 ; i <= n ; ++i)	T[i][0] = 0;
	for(int j = 0 ; j <= m ; ++j)	T[0][j] = 0;
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= m ; ++j)
		{
			if(A[i-1] == B[j-1])
				T[i][j] = T[i-1][j-1] + 1;
			else	T[i][j] = max(T[i-1][j],T[i][j-1]);
		}
	}
	cout << T[n][m] << endl;
	return 0;
}
