/* bhupkas */

#include "stdio.h"
#include "iostream"
#include "string"
#include "string.h"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)
int L[1005][1005];

int lcs(char S1[],char S2[])
	{
		int l1,l2,i,j;
		l1=strlen(S1);
		l2=strlen(S2);
		for (i=0; i<=l1; i++)
		   	{
			    for (j=0; j<=l2; j++)
			     {
			       if (i == 0 || j == 0)
				 L[i][j] = 0;
			  
			       else if (S1[i-1] == S2[j-1])
				 L[i][j] = L[i-1][j-1] + 1;
			  
			       else
				 L[i][j] = max(L[i-1][j], L[i][j-1]);
			     }
			}
		return L[l1][l2];
	}

int main()
	{
		
		int i,j,l1,l2,re;
		char S1[1005],S2[1005];
		scanf("%s",S1);
		
		while(1)
			{
				if(S1[0]=='#')	break;
				scanf("%s",S2);
				l1=strlen(S1);
				l2=strlen(S2);
				re=lcs(S1,S2);
				cout<<(l1-re)*15 + (l2-re)*30<<endl;
				scanf("%s",S1);	
			}
		return 0;
	}
