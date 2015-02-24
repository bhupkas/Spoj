#include"iostream"
#include"stdio.h"
#include"algorithm"
using namespace std;
int main()
	{
		int tc,t,i,j,n,A[1015];
		long long dp[1015];
		cin>>t;
		bool flag;
		for(tc=1;tc<=t;tc++)
			{
				cin>>n;
				if(n==0)	{cout<<"Case "<<tc<<": 0"<<endl;continue;}
				for(i=0;i<n;i++)	cin>>A[i];
				dp[0]=A[0];
				if(n==1)	{cout<<"Case "<<tc<<": "<<A[0]<<endl;continue;}
				dp[1]=max(A[0],A[1]);
				if(dp[1]==A[1])	flag=true;
				else			flag=false;
				for(i=2;i<n;i++)
					{
						if(flag)
							{
								dp[i]=max(dp[i-2]+A[i],dp[i-1]);
								if(dp[i]==dp[i-2]+A[i])	flag=true;
								else	flag=false;
							}
						else
							{
								dp[i]=max(dp[i-1]+A[i],dp[i-2]+A[i]);
								flag=true;
							}
					}
				cout<<"Case "<<tc<<": "<<dp[n-1]<<endl;
			}
		return 0;
	}