/* bhupkas */

#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

#define MOD (LL)(1e9 + 7)

#define NMAX 100005

vector < int > v[NMAX + 5];

int read () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


LL modpow(LL a , LL b)
{
	LL re = 1LL;
	while(b)
	{
		if(b & 1)	
		{
			re = (re * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;		
	}
	if(re < 0)	re += MOD;
	return re;
}

void pre()
{
	for(int i = 1 ; i <= NMAX ; i++)
	{
		for(int j = i ; j <= NMAX ; j += i)
		{
			v[j].push_back(i);
		}
	}
}

int main()
{
	pre();
	int A[NMAX+5];
	int a,b,k;
	int t;
	LL re = 0;
	t = read();
	while(t--)
	{
		re = 0;
		memset(A,0,sizeof(A));
		a = read();
		b = read();
		k = read();
		for(int i = a ; i <= b ; ++i)
		{
			for(int j = 0 ; j < v[i].size() ; ++j)
			{
				A[v[i][j]]++;
			}	
		}
		for(int i = 1 ; i <= b ; i++)
		{
			LL val = modpow(i,k);
			re = re + ((LL)A[i] * val) % MOD;
			if(re > MOD)	re -= MOD;
			if(re < 0)	re += MOD;
		}
		printf("%lld\n",re);
	}
	return 0;
}
