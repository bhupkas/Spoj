/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

int n,m;

vector < pair < int , int > > v;

int main()
{
	int t;
	cin >> t;
	int ans;
	int temp;
	int flag[2];
	while(t--)
	{
		v.clear();
		ans = 0;
		cin >> m >> n;
		for(int i = 0 ; i < m - 1 ; ++i)
		{
			cin >> temp;
			v.push_back(make_pair(temp,0));
		}
		for(int i = 0 ; i < n - 1 ; ++i)
		{
			cin >> temp;
			v.push_back(make_pair(temp,1));
		}
		flag[0] = flag[1] = 1;
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		for(int i = 0 ; i < m + n - 2 ; ++i)
			ans += flag[v[i].second] * v[i].first , flag[(v[i].second + 1) % 2]++;
		cout << ans << endl;
	}
	return 0;
}
