/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

#define MAX		255
#define FOR(i,a,b)	for(i=a;i<b;i++)

int n,m;
char S[MAX+5][MAX+5];
bool B[MAX+5][MAX+5];
int A[MAX+5][MAX+5];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int co1,co2;
bool flag;

bool check(int x,int y)
	{
		if(x>=1 && x<=n && y<=m && y>=1)	return true;
		return false;
	}

void dfs(int x,int y)
	{
		int i,j,k,xk,yk;
		if(A[x][y]==2)	co1++;
		if(A[x][y]==3)	co2++;
		B[x][y]=true;
		FOR(i,0,4)
			{
				xk=x+dx[i];
				yk=y+dy[i];
				if(!check(xk,yk))	flag=true;
				else
					{
						if(!B[xk][yk] && A[xk][yk]!=1)
							dfs(xk,yk);	
					}
			}
	}

int main()
	{
		int ans1=0,ans2=0,i,j,k;
		cin>>n>>m;
		getchar();
		FOR(i,0,n)	scanf("%s",S[i]);
		FOR(i,0,n)
			{
				FOR(j,0,m)
					{
						if(S[i][j]=='.')	A[i+1][j+1]=0;
						else if(S[i][j]=='#')	A[i+1][j+1]=1;
						else if(S[i][j]=='k')	A[i+1][j+1]=2;
						else			A[i+1][j+1]=3;			
					}
			}
		FOR(i,0,m+2)
			A[0][i]=A[n+1][i]=-1;
		FOR(i,0,n+2)
			A[i][0]=A[i][m+1]=-1;
		FOR(i,0,n+2)	FOR(j,0,m+2)	B[i][j]=false;
		FOR(i,1,n+1)
			{
				FOR(j,1,m+1)
					{
						if(A[i][j]!=1 && !B[i][j])	
							{	
								co1=0;
								co2=0;
								flag=false;
								dfs(i,j);
								if(flag)	
									{
										ans1+=co1;
										ans2+=co2;
									}
								else
									{
										if(co1>co2)	
											ans1+=co1;	
										else
											ans2+=co2;
									}
							}
					}
			}
		cout<<ans1<<" "<<ans2<<endl;
		return 0;
	}
