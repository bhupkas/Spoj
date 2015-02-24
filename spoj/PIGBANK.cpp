/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

#define INF (int)(1e9 + 7)

int n,tot;

int P[505];
int W[505];
int A[10005];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int t1,t2;
		cin >> t1 >> t2;
		tot = t2 - t1;
		cin >> n;
		for(int i = 0 ; i < n ; ++i)
			cin >> P[i] >> W[i];
		for(int i = 0 ; i <= tot ; ++i)	A[i] = INF;
		A[0] = 0;
		for(int i = 1 ; i <= tot ; ++i)
			for(int j = 0 ; j < n ; ++j)
				if(i - W[j] >= 0)	A[i] = min(A[i],A[i-W[j]]+P[j]);
		if(A[tot] != INF)
			cout << "The minimum amount of money in the piggy-bank is " << A[tot];
		else cout << "This is impossible";
		cout << "." << endl;
	}
	return 0;
}
