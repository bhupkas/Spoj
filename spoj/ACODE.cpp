/* bhupkas */
#include"iostream"
#include"stdio.h"
#include"string.h"
#include"string"
using namespace std;
int main()
	{
		long long dp[5005];
		char S[5005];
		long long  i,j,l;
		scanf("%s",S);
		while(!(S[0]=='0' && strlen(S)==1))
			{
				l=strlen(S);
				dp[0]=1;
				i=1;
				while(i<l)
					{
						if(S[i]=='0')
							{
								if(i==1)	dp[i]=1;
								else		dp[i]=dp[i-2];	
							}
						else if(((S[i-1]-'0')*10 + (S[i]-'0'))<=26 && S[i-1]!='0')
							{if(i==1)	dp[i]=1+dp[i-1];	else	dp[i]=dp[i-2]+dp[i-1];}
						else dp[i]=dp[i-1];
						i++;
					}
				cout<<dp[l-1]<<endl;
				scanf("%s",S);
			}
		return 0;
	}