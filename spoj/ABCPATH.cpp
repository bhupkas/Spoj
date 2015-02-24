/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"
#include "string.h"
#include "string"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)

char S[60][60];
int A[60][60];
bool visited[60][60];

int dx[]={0,-1,1};
int dy[]={0,-1,1};
int dp[60][60];

int len(int i,int j,int cnt)
	{
		int k,l,re;
		re=1;
		FOR(k,0,3)
			{
				FOR(l,0,3)
					{
						if(A[i+dx[k]][j+dy[l]]==cnt+1)	
							{
								if(dp[i+dx[k]][j+dy[l]]==-1)			dp[i+dx[k]][j+dy[l]]=len(i+dx[k],j+dy[l],cnt+1);
								re=max(re,dp[i+dx[k]][j+dy[l]]+1);
							}
					}
			}
		return re;
	}	

int main()
	{
		int casen=0,n,m,i,j,ans;
		cin>>n>>m;
		while(1)
			{
				if(n==0 && m==0)	break;
				casen++;
				ans=0;
				getchar();
				FOR(i,0,n)	scanf("%s",S[i]);
				FOR(i,0,n+2)	FOR(j,0,m+2)	dp[i][j]=-1;
				FOR(i,0,n+2)
					{
						A[i][0]=-1;
						A[i][m+1]=-1;
					}
				FOR(i,0,m+2)
					{
						A[0][i]=-1;
						A[n+1][i]=-1;
					}
				FOR(i,1,n+1)
					{
						FOR(j,1,m+1)
							{
								A[i][j]=S[i-1][j-1]-'A';
							}
					}
				FOR(i,1,n+1)
					{
						FOR(j,1,m+1)
							{
								if(A[i][j]==0)	
									{
										ans=max(ans,len(i,j,0));
									}
							}
					}
				cout<<"Case "<<casen<<": "<<ans<<endl; 
				cin>>n>>m;
			}
		return 0;
	}