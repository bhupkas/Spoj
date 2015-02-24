/* bhupkas */
#include"iostream"
#include"stdio.h"
#include"map"
using namespace std;
typedef long long LL;
#define MOD (LL)(1e9+7)
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b&1){
            x = (x+y)%c;
        }
        y = (y<<1)%c;
        b /= 2;
    }	
    return x%c;
}
long long int expon(long long int a,long long int n,long long int p){ //a^n%p
	long long int extra=1,aa=a;
	while(n>0){
	if(n&1){
		extra=mulmod(extra,aa,p);
		n--;
	}
	else{
		aa=mulmod(aa,aa,p);
		n=n>>1;
		}
	}
	return extra;
}
#define BUF 4096 
char ibuf[BUF];
LL ipt = BUF;
LL read() {
while (ipt < BUF && ibuf[ipt] < '0') ipt++;
if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
}
LL n = 0;
while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
}
return n;
}
int main()
	{
		LL t,i,j,n;
		t=read();
		while(t--)
			{
				n=read();
				if(n==1 || n==2 || n==3|| n==4)	{printf("%lld\n",n);	continue;}
				else if(n==5)	{printf("6\n");	continue;}	
				else if(n==6)	{printf("9\n");	continue;}
				if(n%3==0)
					printf("%lld\n",expon(3,n/3,MOD));
				else if(n%3==1)
						printf("%lld\n",(expon(3,n/3-1,MOD)<<2)%MOD);
				else
						printf("%lld\n",((expon(3,n/3,MOD))<<1)%MOD);
			}
		return 0;
	}