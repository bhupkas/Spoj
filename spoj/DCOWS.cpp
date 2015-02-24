/* bhupkas */
#include"stdio.h"
#include"iostream"
#include"vector"
#include"algorithm"
#include"string.h"
using namespace std;
#define inf 1e9
typedef long long LL;
LL dp[5005][5005];
vector<LL> A,B;
LL calc(int i,int j)
	{
		if(dp[i][j]!=-1)	return dp[i][j];
		if(j<i)	return dp[i][j]=inf;
		if(i==j)
			{
				if(i==0)	return dp[i][j]=abs(A[0]-B[0]);
				else
					return dp[i][j]=calc(i-1,j-1)+abs(A[i]-B[j]);
			}
		else if(i==0)
			{
				return dp[i][j]=min(calc(i,j-1),abs(A[i]-B[j]));
			}
		else
			{
				return dp[i][j]=min(calc(i,j-1),calc(i-1,j-1)+abs(A[i]-B[j]));
			}
	}
int main()
	{
		int n,m,i,j,t;
		LL te;
		memset(dp,-1,sizeof(dp));
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)	{scanf("%lld",&te);	A.push_back(te);}
		for(j=0;j<m;j++)	{scanf("%lld",&te);	B.push_back(te);}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		cout<<calc(n-1,m-1)<<endl;
		return 0;
	}