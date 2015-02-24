/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

typedef long long LL;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define S(n)	scanf("%d",&n)

int TP[255][255];
int LP[255][255];

int main()
	{
		int i,j,k,l,n,m,a,b,cnt=0;
		S(n);S(m);
		int A[255][255];
		FOR(i,0,n)	FOR(j,0,n)	S(A[i][j]);
		S(a);S(b);
		FOR(i,0,m)	TP[0][i]=A[0][i];
		FOR(i,1,n)		FOR(j,0,m)		TP[i][j]=TP[i-1][j] + A[i][j];
		FOR(i,0,n)	LP[i][0]=A[i][0];
		FOR(i,1,m)	FOR(j,0,n)	LP[j][i]=LP[j][i-1]+A[j][i];
		int dp[255][255],temp;
		dp[0][0]=A[0][0];
		FOR(i,1,n)	dp[i][0]=TP[i][0];
		FOR(i,1,m)	dp[0][i]=LP[0][i];
		FOR(i,1,n)	FOR(j,1,m)	dp[i][j]=LP[i][j]+dp[i-1][j];
		FOR(i,0,n)
			{
				FOR(j,0,m)
					{
						FOR(k,i,n)
							{
								FOR(l,j,m)
									{
										if(i==0 && j==0)	temp=dp[k][l];
										else if(i==0)		temp=dp[k][l]-dp[k][j-1];
										else if(j==0)		temp=dp[k][l]-dp[i-1][l];
										else				temp=dp[k][l]+dp[i-1][j-1]-dp[k][j-1]-dp[i-1][l];
										if(temp<=b && temp>=a)	cnt++;
									}
							}
					}
			}
		printf("%d\n",cnt);
		return 0;
	}