/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "deque"
#include "vector"
#include "string.h"

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL>	VLL;
typedef deque<int> DQI;
typedef deque<LL>	DQLL;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define S(n)		scanf("%d",&n)
#define SLL(n)		scanf("%lld",&n)
#define P(n)		printf("%d\n",n)
#define PLL(n)		printf("%lld\n",n)
#define PB(n)		push_back(n)
#define SS(s)		scanf("%s",s)
#define PII			pair<int,int>
#define DQPII		deque<PII>
#define MP(i,j)		make_pair(i,j)

int A[8][8][8][8];
bool B[8][8];

bool check(int i,int j)
	{
		if(i>7 || j>7 || i<0 || j<0)	return false;
		return true;
	}
void pre()
	{
		int i,j,k,l,di;
		PII temp;
		DQPII q;
		FOR(i,0,8)	FOR(j,0,8)	FOR(k,0,8)	FOR(l,0,8)	A[i][j][k][l]=0;
		FOR(i,0,8)
			{
				FOR(j,0,8)
					{
						A[i][j][i][j]=0;
						FOR(k,0,8)	FOR(l,0,8)	B[k][l]=false;
						q.PB(MP(i,j));
						k=i;
						l=j;
						B[i][j]=true;
						int co=0;
						while(!q.empty())
							{
								co++;
								k=q.front().first;
								l=q.front().second;
								q.pop_front();
								di=A[i][j][k][l];
								if(check(k+2,l+1) && B[k+2][l+1]==false)	
										{
											B[k+2][l+1]=true;
											A[i][j][k+2][l+1]=di+1;
											q.push_back(MP(k+2,l+1));
										}
								if(check(k+1,l+2) && B[k+1][l+2]==false)	
										{
											B[k+1][l+2]=true;
											A[i][j][k+1][l+2]=di+1;
											q.push_back(MP(k+1,l+2));
										}
								if(check(k-2,l-1) && B[k-2][l-1]==false)	
										{
											B[k-2][l-1]=true;
											A[i][j][k-2][l-1]=di+1;
											q.push_back(MP(k-2,l-1));
										}
								if(check(k-1,l-2) && B[k-1][l-2]==false)	
										{
											B[k-1][l-2]=true;
											A[i][j][k-1][l-2]=di+1;
											q.push_back(MP(k-1,l-2));
										}
								if(check(k+2,l-1) && B[k+2][l-1]==false)	
										{
											B[k+2][l-1]=true;
											A[i][j][k+2][l-1]=di+1;
											q.push_back(MP(k+2,l-1));
										}
								if(check(k-2,l+1) && B[k-2][l+1]==false)	
										{
											B[k-2][l+1]=true;
											A[i][j][k-2][l+1]=di+1;
											q.push_back(MP(k-2,l+1));
										}
								if(check(k+1,l-2) && B[k+1][l-2]==false)	
										{
											B[k+1][l-2]=true;
											A[i][j][k+1][l-2]=di+1;
											q.push_back(MP(k+1,l-2));
										}
								if(check(k-1,l+2) && B[k-1][l+2]==false)	
										{
											B[k-1][l+2]=true;
											A[i][j][k-1][l+2]=di+1;
											q.push_back(MP(k-1,l+2));
										}
							}
					}
			}
	}

int main()
	{
		pre();
		int t,n,i,j;
		S(t);
		char str1[5],str2[5];
		getchar();
		while(t--)
			{
				SS(str1);
				SS(str2);
				P(A[str1[1]-'1'][str1[0]-'a'][str2[1]-'1'][str2[0]-'a']);
			}	
		return 0;
	}