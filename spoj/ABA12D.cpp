#include"stdio.h"
#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;
#define FOR(i,a,b)	for(i=a;i<b;i++)
typedef long long LL;
int A[1000005];
bool P[1000005];
bool V[1000005];
vector<int> p;
#define BUF 4096 // block size on my disk is 4KBs
char ibuf[BUF];
int ipt = BUF;
int read() {
while (ipt < BUF && ibuf[ipt] < '0') ipt++;
if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
}
int n = 0;
while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
}
return n;
}
void pri()
	{
		int i,j;
		FOR(i,0,1000005)	P[i]=true;
		P[0]=P[1]=false;
		for(i=2;i*i<1000005;i++)
			{
				for(j=i;j<=1000005/i;j++)
					P[i*j]=false;
			}
		FOR(i,2,1000005)	if(P[i])	p.push_back(i);
	}
int pow(int a,int b)
	{
		if(b==0)	return 1;
		if(b==1)	return a;
		int re;
		re=pow(a,b/2);
		if(b&1)	return re*re*a;
		return 	re*re;
	}
bool isprime(LL a)
	{
		if(a==0 || a==1)	return false;
		LL i;
		for(i=0;p[i]*p[i]<=a;i++)
			if(a%p[i]==0)	return false;
		return true;
	}
bool sumisprime(int a)
	{
		if(a==0||a==1)	return false;
		int a1=a,i,j,count,temp;
		LL sum=1;
		for(i=0;p[i]*p[i]<=a1;i++)
			{
				if(a%p[i]==0)
					{
						count=0;
						while(a%p[i]==0)
							{
								count++;
								a/=p[i];
							}
						temp=((pow(p[i],count+1)-1)/(p[i]-1));
						sum*=temp;
					}	
			}
		if(a!=1)	
			{
				sum*=(a+1);
			}
		//cout<<sum<<endl;
		if(sum<1000005)	
			{
				if(P[sum])	return true;
				return	false;
			}
		if(isprime(sum))	return true;
		return false;
	}
void pre()
	{
		int i,j=0;
		FOR(i,1,1000005)
			{
				if(sumisprime(i))	++j;	
				A[i]=j;
			}
	}
int main()
	{
		int t,a,b,i;
		t=read();
		FOR(i,0,1000005)	V[i]=false;
		pri();
		pre();
		A[0]=0;
		FOR(i,1,1000005)	
			{
				if(sumisprime(i))	cout<<i<<endl;
			}
		t=0;
		while(t--)
			{
				a=read();b=read();
				printf("%d\n",A[b]-A[a-1]);
			}
		return 0;
	}