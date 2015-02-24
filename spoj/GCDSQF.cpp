/* bhupkas */
#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
#include"string.h"
#include"string"
using namespace std;
vector<int> p;
#define SIZE 10000
bool P[SIZE];
long long gcd(long long a,long long b)
{
	if(a%b==0)	return b;
	return gcd(b,a%b);
}
void pre()
	{
		int i,j;
		for(i=0;i<SIZE;i++)	P[i]=true;
		P[0]=P[1]=false;
		for(i=2;i*i<SIZE;i++)
			{
				if(P[i])
				{
					for(j=i;j<=SIZE/i;j++)
						P[i*j]=false;
				}
			}
		for(i=2;i<SIZE;i++)
			if(P[i])	p.push_back(i);
	}
int main()
	{
		pre();
		int t,si,len1,len2,i,co;
		long long gc,l1,l2,lcm,tem;
		char S1[1005],S2[1005];
		vector<int> ans;
		scanf("%d",&t);
		getchar();
		bool flag;
		long long temp=1;
		//for(int i=0;i<1000;i++)
			//temp*=p[i];
		//cout<<temp<<endl;
		while(t--)
			{
				//getchar();
				scanf("%s",S1);
				//getchar();
				scanf("%s",S2);
				len1=strlen(S1);
				len2=strlen(S2);
				if(len1<len2)
					{
						for(i=len1;i<len2;i++)
							S1[i]='0';
						S1[i]='\0';
					}
				else
					{
						for(i=len2;i<len1;i++)
							S2[i]='0';
						S2[i]='\0';
					}
				len1=strlen(S1);
				len2=strlen(S2);
				lcm=1;
				l1=l2=1;
				for(i=0;i<len1;i++)
					{	
						if((S1[i]-'0')&1)	l1*=p[i];
						if((S2[i]-'0')&1)	l2*=p[i];
						if((S1[i]-'0')&1 || (S2[i]-'0')&1)	lcm*=p[i];
					}

				gc=gcd(max(l1+l2,lcm),min(l1+l2,lcm));
				tem=gc;
				if(gc==1)	{cout<<"relatively prime"<<endl;	continue;}
				for(i=0;p[i]<=gc;i++)
					{
						if(gc==1)	break;
						co=0;
						if(gc%p[i]==0)
							{
								while(gc%p[i]==0)
									{
										gc/=p[i];
										co++;
									}
							}
						if(co>1)	break;
						ans.push_back(co);
					}
				if(co>1)	{cout<<tem<<endl;	continue;}
				for(i=0;i<ans.size();i++)
					cout<<ans[i];
				cout<<endl;
			}
		return 0;	
	}