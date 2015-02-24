/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"
#include "string.h"
#include "set"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)
#define PB			push_back
#define PP			pair<int,int>
#define POPP			pair< pair <int,int>,int >
#define MP			make_pair
#define INF			(int)1e9
#define I			insert
#define F			first
#define S			second

int dx[]={1,2,1,2,-1,-2,-1,-2};
int dy[]={2,1,-2,-1,2,1,-2,-1};

vector<POPP> cost[8][8];

bool check(int x,int y)
	{
		if(x>=0 && x<=7 && y<=7 && y>=0)	return true;
		return 	false;
	}
	
void pre()
	{
		int i,j,k,l,xk,yk;
		FOR(i,0,8)
			{
				FOR(j,0,8)
					{
						FOR(k,0,8)
							{
								xk=i+dx[k];
								yk=j+dy[k];
								if(check(xk,yk))
									cost[i][j].PB(MP(MP(xk,yk),(xk*i+yk*j)));
							}
					}
			}
	}	
	
int main()
	{
		int i,j,k,a,b,c,d,curr,si,xk,yk;
		pre();
		int dis[8][8];
		set<POPP> myset;
		set<POPP>::iterator it;
		while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
			{	
				FOR(i,0,8)	FOR(j,0,8)	dis[i][j]=INF;
				dis[a][b]=0;
				myset.I(MP(MP(a,b),0));
	
	while(!myset.empty())
		{
			it=myset.begin();
			xk=(*it).F.F;
			yk=(*it).F.S;			
			si=cost[xk][yk].size();
			myset.erase(myset.begin());
			FOR(j,0,si)
				{
				if(dis[xk][yk]+cost[xk][yk][j].S < dis[cost[xk][yk][j].F.F][cost[xk][yk][j].F.S])	
					{
					if(myset.find(MP(MP(cost[xk][yk][j].F.F,cost[xk][yk][j].F.S),dis[cost[xk][yk][j].F.F][cost[xk][yk][j].F.S]))!=myset.end())
					myset.erase((MP(MP(cost[xk][yk][j].F.F,cost[xk][yk][j].F.S),dis[cost[xk][yk][j].F.F][cost[xk][yk][j].F.S])));
					dis[cost[xk][yk][j].F.F][cost[xk][yk][j].F.S]=dis[xk][yk]+cost[xk][yk][j].S;
					myset.I(MP(MP(cost[xk][yk][j].F.F,cost[xk][yk][j].F.S),dis[cost[xk][yk][j].F.F][cost[xk][yk][j].F.S]));
					}
				}
		}	
			if(dis[c][d]==INF)	cout<<-1<<endl;
			else			cout<<dis[c][d]<<endl;
			}
		return 0;
	}
