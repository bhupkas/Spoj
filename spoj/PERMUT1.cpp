/* bhupkas */
#include"iostream"
#include"stdio.h"
using namespace std;
typedef long long LL;
int dp[15][100];
int count(int n, int k)
{
	if(n == 0)
		return 0;
	if(k == 0)
		return 1;
	if(dp[n][k] != -1)
		return dp[n][k];
	int val = 0;
	for(int i = 0; i < n && k-i >= 0; i++)
		val += count(n-1,k-i);
	dp[n][k]=val;
	return val;
}
int main()
	{
		int i,j,n,k,t,l,m;
		for(i=0;i<15;i++)	
			for(j=0;j<100;j++)	dp[i][j]=-1;
		cin>>t;
		while(t--)
			{
				cin>>n>>k;
				cout<<count(n,k)<<endl;
			}
		return 0;
	}