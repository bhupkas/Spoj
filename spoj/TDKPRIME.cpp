#include"iostream"
#include"stdio.h"
#include"vector"
using namespace std;
#define SIZE 87000000
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
vector<int> v;
void pre()
	{
	vector<bool> A;
	int i,j;
	for(i=0;i<SIZE;i++)	A.push_back(true);
	A[0]=A[1]=false;
	for(i=2;i*i<SIZE;i++)
		{	
		if(A[i])
			{
			for(j=i;j<=SIZE/i;j++)	A[i*j]=false;
			}
		}
	v.push_back(2);
	for(i=3;i<SIZE;i+=2)
		if(A[i])	v.push_back(i);	
	}
int main()
	{
	pre();
	int q,k;
	q=read();
	while(q--)	
		{
		k=read();
		printf("%d\n",v[k-1]);
		}
	return 0;
	}
