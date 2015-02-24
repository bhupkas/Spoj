#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
using namespace std;
vector<int> v;
bool P[100000];
void pre()
	{
		int i,j;
		for(i=0;i<100000;i++)	P[i]=true;
		P[0]=P[1]=false;
		for(i=2;i*i<100000;i++)
			{
				if(P[i])
					{
						for(j=i;j<=100000/i;j++)
							P[i*j]=false;
					}
			}
		for(i=2;i<100000;i++)
			if(P[i])	v.push_back(i);
	}
int main()
	{
		pre();
		int a,b,n,i,k,j,co=0,ans=0,co1;
		scanf("%d %d %d",&a,&b,&n);
		if(n==1)
			{
				if(a==1)
					{
						printf("1\n");
						return 0;
					}
				else
					{
						printf("0\n");
						return 0;
					}
			}
		for(k=a;k<=b;k++)
			{
				i=k;
				ans=1;
				for(j=0;v[j]*v[j]<=i;j++)
					{
						co1=0;
						if(i%v[j]==0)
							{
								while(i%v[j]==0)
									{
										co1++;
										i/=v[j];
									}
							}
						ans*=(co1+1);
					}
				if(i!=1)	ans*=2;
				if(ans==n)	co++;
			}
		cout<<co<<endl;
		return 0;
	}