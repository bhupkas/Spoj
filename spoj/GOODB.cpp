#include"iostream"
#include"stdio.h"
using namespace std;
typedef long long LL;
#define SIZE 110
LL F[SIZE];
#define m (LL)(1e9+7)
void pre()
	{
		F[0]=1;
		F[1]=1;
		for(int i=2;i<=109; i++) 
			F[i] = (-(m/i) * F[m % i]) % m + m;
	}
int main()
	{
		pre();	
		int i,n,w,r,t;
		cin>>n>>w>>r>>t;
		LL ans=1;
		for(i=1;i<=n;i++)
			ans= (ans*i)%m;
		for(i=1;i<=w;i++)
			ans = (ans * F[i])%m;
		for(i=1;i<=r;i++)
			ans = (ans * F[i])%m;
		for(i=1;i<=t;i++)
			ans = (ans * F[i])%m;
		cout<<(ans+m)%m<<endl;
		return 0;
	}