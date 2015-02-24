/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)

bool B[100005];
int A[100005][10];

int main()
{
	int num,i,j,a,b,t,d,r;	
	FOR(i,0,100005)		FOR(j,0,10)	A[i][j]=0;
	A[1][1]=1;
	FOR(i,0,100005)	B[i]=false;
	B[1]=true;
	FOR(i,2,1001)
		{
			for(j=1;j<=100001/(i*i);j++)
				B[i*i*j]=true;
		}
	
	FOR(i,2,100001)
	{
		if(!B[i])			
			{
				num=i;
				while(num)
					{
						A[i][num%10]=1;
						num/=10;					
					}
			}
			FOR(j,0,10)
				A[i][j]=A[i][j]+A[i-1][j];
		
	}	
	cin>>t;
	while(t--)
		{
			cin>>a>>b>>d;		
			cout<<A[b][d]-A[a-1][d]<<endl;
		}
	return 0;
}
