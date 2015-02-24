#include"iostream"
#include"stdio.h"
using namespace std;
int dp[15];
void pre()	
	{
		int i,j;
		for(i=0;i<15;i++)	dp[i]=0;
		dp[0]=0;
		dp[1]=1;
		dp[2]=6;
		//dp[3]=6;
		//dp[4]=90;
		for(i=3;i<15;i++)
			{
				for(j=2;j<i-1;j++)
					{
						dp[i]+=dp[j]*dp[i-j];
					}
				dp[i]+=dp[i-1];
			} 
	}
int main()
	{
		pre();
		cout<<dp[3]<<" "<<dp[4]<<endl;
		return 0;
	}