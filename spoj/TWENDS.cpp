/* bhupkas */
#include"stdio.h"
#include"iostream"
#include"algorithm"
using namespace std;
int A[1002][1002];
int B[1002];
int solve(int i,int j)	
	{
		if(A[i][j]!=-1)	return A[i][j];
		int ans1,ans2;
		if(i==j)
			{
				A[i][j]=B[i];
				return B[i];
			}

		if(j==i+1)	
			{
				A[i][j]=max(B[i],B[j])-min(B[i],B[j]);
				return A[i][j];
			}
		ans1=-10000;
		ans2=-10000;
		if(B[i+1]>=B[j])
			{
				ans1=max(ans1,solve(i+2,j)+B[i]-B[i+1]);
			}
		else
			{
				ans1=max(ans1,solve(i+1,j-1)+B[i]-B[j]);
			}
		if(B[i]>=B[j-1])
			{
				ans2=max(ans2,solve(i+1,j-1)+B[j]-B[i]);
			}
		else
			{
				ans2=max(ans2,solve(i,j-2)+B[j]-B[j-1]);
			}
		A[i][j]=max(ans1,ans2);
		return A[i][j];
	}
int main()
	{
		int n,i,j,tc=1,ans;
		cin>>n;
		while(n)
			{
				for(i=0;i<n;i++)	for(j=0;j<n;j++)	A[i][j]=-1;
				for(i=0;i<n;i++)
						cin>>B[i];
				printf("In game %d, the greedy strategy might lose by as many as %d points.\n", tc, solve(0,n-1));
				tc++;
				cin>>n;
			}
		return 0;
	}