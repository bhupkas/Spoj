#include"iostream"
#include"stdio.h"
#include"string.h"
#include"string"
#include"math.h"
using namespace std;
char S[105][105];
bool A[105][105][10];
bool dfs(int pos,int x,int y,bool localfl[][105])
	{
	localfl[x][y]=true;
	//cout<<x<<" "<<y<<" "<<pos<<endl;
	int i,j;
	if(pos==9)	return true;
	if(pos==0)
		{
		for(i=-1;i<=1;i++)
			{
			for(j=-1;j<=1;j++)
				{
				if(i==j && i==0)	continue;
				if(S[x+i][y+j]=='L'  && A[x+i][y+j][pos+1] && !localfl[x+i][y+j])	{   if(dfs(pos+1,x+i,y+j,localfl))   return true; else {A[x+i][y+j][pos+1]=false;   localfl[x+i][y+j]=false;}} 
				}
			}  
		}
	if(pos==1)
		{
		for(i=-1;i<=1;i++)
			{
			for(j=-1;j<=1;j++)
				{
				if(i==j && i==0)	continue;
				if(S[x+i][y+j]=='L'  && A[x+i][y+j][pos+1] && !localfl[x+i][y+j])	{   if(dfs(pos+1,x+i,y+j,localfl))   return true; else {A[x+i][y+j][pos+1]=false;   localfl[x+i][y+j]=false;}} 
				}
			}  
		}
	if(pos==2)
		{
		for(i=-1;i<=1;i++)
			{
			for(j=-1;j<=1;j++)
				{
				if(i==j && i==0)	continue;
				if(S[x+i][y+j]=='I'  && A[x+i][y+j][pos+1] && !localfl[x+i][y+j])	{   if(dfs(pos+1,x+i,y+j,localfl))   return true; else {A[x+i][y+j][pos+1]=false;   localfl[x+i][y+j]=false;}} 
				}
			}  
		}
	if(pos==3)
		{
		for(i=-1;i<=1;i++)
			{
			for(j=-1;j<=1;j++)
				{
				if(i==j && i==0)	continue;
				if(S[x+i][y+j]=='Z'  && A[x+i][y+j][pos+1] && !localfl[x+i][y+j])	{   if(dfs(pos+1,x+i,y+j,localfl))   return true; else {A[x+i][y+j][pos+1]=false;   localfl[x+i][y+j]=false;}} 
				}
			}  
		}
	if(pos==4)
		{
		for(i=-1;i<=1;i++)
			{
			for(j=-1;j<=1;j++)
				{
				if(i==j && i==0)	continue;
				if(S[x+i][y+j]=='Z'  && A[x+i][y+j][pos+1] && !localfl[x+i][y+j])	{   if(dfs(pos+1,x+i,y+j,localfl))   return true; else {A[x+i][y+j][pos+1]=false;   localfl[x+i][y+j]=false;}} 
				}
			}  
		}
	if(pos==5)
		{
		for(i=-1;i<=1;i++)
			{
			for(j=-1;j<=1;j++)
				{
				if(i==j && i==0)	continue;
				if(S[x+i][y+j]=='W'  && A[x+i][y+j][pos+1] && !localfl[x+i][y+j])	{   if(dfs(pos+1,x+i,y+j,localfl))   return true; else {A[x+i][y+j][pos+1]=false;   localfl[x+i][y+j]=false;}} 
				}
			}  
		}
	if(pos==6)
		{
		for(i=-1;i<=1;i++)
			{
			for(j=-1;j<=1;j++)
				{
				if(i==j && i==0)	continue;
				if(S[x+i][y+j]=='E'  && A[x+i][y+j][pos+1] && !localfl[x+i][y+j])	{   if(dfs(pos+1,x+i,y+j,localfl))   return true; else {A[x+i][y+j][pos+1]=false;   localfl[x+i][y+j]=false;}} 
				}
			}  
		}
	if(pos==7)
		{
		for(i=-1;i<=1;i++)
			{
			for(j=-1;j<=1;j++)
				{
				if(i==j && i==0)	continue;
				if(S[x+i][y+j]=='L'  && A[x+i][y+j][pos+1] && !localfl[x+i][y+j])	{   if(dfs(pos+1,x+i,y+j,localfl))   return true; else {A[x+i][y+j][pos+1]=false;   localfl[x+i][y+j]=false;}} 
				}
			}  
		}
	if(pos==8)
		{
		for(i=-1;i<=1;i++)
			{
			for(j=-1;j<=1;j++)
				{
				if(i==j && i==0)	continue;
				if(S[x+i][y+j]=='L'  && A[x+i][y+j][pos+1] && !localfl[x+i][y+j])	{   if(dfs(pos+1,x+i,y+j,localfl))   return true; else {A[x+i][y+j][pos+1]=false;   localfl[x+i][y+j]=false;}} 
				}
			}  
		}
	return false;
	}
int main()
	{
	int t,r,c,i,j,k;
	cin>>t;
	bool flag;
	//getchar();
	while(t--)	
		{
		flag=false;
		getchar();
		cin>>r>>c;
		for(i=0;i<=c+1;i++)	{S[0][i]='*';S[r+1][i]='*';}
		for(i=0;i<=r+1;i++)	{S[i][0]='*';S[i][c+1]='*';}
		for(i=1;i<=r;i++)
			{
			scanf("%s",S[i]+1);
			}
		for(i=1;i<=r;i++)
			{
			for(j=1;j<=c;j++)
				{
				for(k=0;k<10;k++)
					A[i][j][k]=true;
				}
			}
		for(i=1;i<=r;i++)
			{
			for(j=1;j<=c;j++)
				{
				if(S[i][j]=='A')
					{
					bool localfl[105][105];		
					memset(localfl,0,105*105);		
					if(dfs(0,i,j,localfl))		{flag=true;	break;}
					}
				}
			if(flag)	break;
			}
		if(i>r&&j>c)
			printf("NO\n");
		else
			printf("YES\n");
		}
	return 0;
	}
