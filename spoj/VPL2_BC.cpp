/* bhupkas */

#include "stdio.h"
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)
#define LL			long long
#define MAX			100005

int A[6150][6150],n,m;

int dx[]={-1,1,0,0,1,-1,-1,1};
int dy[]={0,0,-1,1,1,-1,1,-1};

bool check(int x,int y)
	{
		if(x>=0 && x<n && y>=0 && y<m)	return true;
		return false;
	}
int main()
	{
		int i,j,tc,t,k,X[MAX+5],Y[MAX+5],x,y;
		cin>>t;
		FOR(tc,1,t+1)
			{
				scanf("%d %d %d",&n,&m,&k);
				FOR(i,0,n)	FOR(j,0,m)	A[i][j]=0;
				FOR(i,0,k)	
					{
						cin>>X[i]>>Y[i];
						A[X[i]][Y[i]]=-1;
					}
				FOR(i,0,k)
					{
						FOR(j,0,8)
							{
								x=X[i]+dx[j];
								y=Y[i]+dy[j];
								if(check(x,y) && A[x][y]!=-1)
									{
										A[x][y]++;	
									}
							}					
					}
				cout<<"Scenario #"<<tc<<":"<<endl;
				FOR(i,0,n)
					{
						FOR(j,0,m)
							{
								if(A[i][j]==-1)		printf("*");
								else 	if(A[i][j]==0)	printf("-");
								else			printf("%d",A[i][j]);
							}
						printf("\n");
					}
			}
		return 0;
	}
