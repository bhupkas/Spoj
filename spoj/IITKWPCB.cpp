/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

int main()
{
	int t;
	cin >> t;
	LL n;
	while(t--)
	{
		cin >> n;
		LL ans = n/2;
		while(__gcd(n,ans) != 1)	ans--;
		cout << ans << endl;
	}
	return 0;
}
