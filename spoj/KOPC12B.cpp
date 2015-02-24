/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

const int mod = (long long)(1e9 + 7);

typedef long long LL;

const int N = (int)(2e6 + 5);

LL F[N];

LL modpow(LL a , LL b , LL mod)
{
	LL re = 1;
	while(b)
	{
		if(b & 1)	re = (re * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return re;
}

LL inv(LL a)
{	
	return modpow(a,mod-2,mod);
}

void pre()
{
	F[0] = 1;
	for(int i = 1 ; i < N ; ++i)	F[i] = (F[i-1] * i) % mod;
}

int main()
{
	pre();
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		LL re = F[2*n];
		re = (re * inv(F[n])) % mod;
		re = (re * inv(F[n])) % mod;
		re = (re * n) % mod;
		re = (re * inv(2)) % mod;
		cout << re << endl; 
	}
	return 0;
}
