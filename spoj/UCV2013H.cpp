/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)

int cnt,n,m;
int A[255][255];
map<int,int> mymap;
map<int,int>::iterator it;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

bool check(int x,int y)
	{
		if(x>=0 && x<n && y>=0 && y<m)	return true;
		return false;
	}

void dfs(int x,int y)
	{
		cnt++;
		A[x][y]=0;
		int i,xk,yk;
		FOR(i,0,4)
			{
				xk=x+dx[i];
				yk=y+dy[i];
				if(check(xk,yk) && A[xk][yk]==1)
					dfs(xk,yk);
			}
	}	

int main()
	{
		int cc,i,j;
		cin>>n>>m;
		while(n && m)
			{
				cc=0;
				mymap.clear();
				FOR(i,0,n)
					FOR(j,0,m)	
						cin>>A[i][j];
				FOR(i,0,n)	
					{
						FOR(j,0,m)
							{
								if(A[i][j]==1)	
									{
										cnt=0;
										cc++;
										dfs(i,j);
										mymap[cnt]++;
									}
							}	
					}
				cout<<cc<<endl;
				for(it=mymap.begin();it!=mymap.end();it++)
					cout<<(*it).first<<" "<<(*it).second<<endl;
				cin>>n>>m;
			}
		return 0;
	}
