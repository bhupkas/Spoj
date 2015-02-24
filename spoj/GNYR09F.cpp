/* bhupkas */
#include"iostream"
#include"stdio.h"
using namespace std;
int A[2][102][102];
void pre()
	{
		int i,j,k;
		for(i=0;i<2;i++)
			for(j=0;j<102;j++)
					A[i][0][j]=0;
		A[0][1][0]=1;
		A[1][1][0]=1;
		for(i=0;i<2;i++)
			for(j=1;j<102;j++)
				A[i][1][j]=0;
		for(i=2;i<102;i++)
			{
				for(j=0;j<i;j++)
					{
						A[0][i][j]=A[0][i-1][j]+A[1][i-1][j];
						if(j)	A[1][i][j]=A[0][i-1][j]+A[1][i-1][j-1];
						else	A[1][i][j]=A[0][i-1][j];
					}
			}
	}
int main()
	{
		pre();
		int t,tc,n,i,j,k;
		cin>>t;
		while(t--)
			{
				cin>>tc>>n>>k;
				cout<<tc<<" "<<A[0][n][k]+A[1][n][k]<<endl;
			}
		return 0;
	}