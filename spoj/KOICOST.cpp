/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

typedef long long LL;

const LL N = (LL)(1e5 + 5);

const int mod = (LL)(1e9);

struct node 
{
	LL a,b,c;
};

typedef struct node Node;

Node E[N];

LL A[N];

LL n,m;

bool cmp(Node N1 , Node N2)
{
	return N1.c > N2.c;
}

LL P[N];

LL S[N];

LL find(LL a)
{
	if(P[a] == a)	return a;
	LL p = find(P[a]);
	return P[a] = p ;
}

void uni(LL a , LL b)
{
	LL p1 = find(a);
	LL p2 = find(b);
	if(S[p1] > S[p2])
	{
		P[p2] = p1;
		S[p1] += S[p2];
		S[p2] = 0;
	}
	else
	{
		P[p1] = p2;
		S[p2] += S[p1];
		S[p1] = 0;
	}
}

int main()
{
	scanf("%lld %lld ", &n ,&m);
	if(m == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0 ; i < m ; ++i)
	{
		scanf("%lld %lld %lld",&E[i].a,&E[i].b,&E[i].c);
		E[i].a--;
		E[i].b--;
	}
	
	sort(E,E+m,cmp);

	for(int i = 0 ; i < n ; ++i)	P[i] = i , S[i] = 1;
	
	A[m-1] = (E[m-1].c) % mod;
	for(int i = m - 2 ; i >= 0 ; --i)	A[i] = (A[i + 1] + E[i].c) % mod;	
	
	LL re = 0 ;
	
	LL a,b;
	
	for(int i = 0 ; i < m ; ++i)
	{
		a = find(E[i].a);
		b = find(E[i].b);
		if(a != b)
		{
			re = ( re + ( ( (S[a] * S[b]) % mod ) * A[i] ) % mod ) % mod;
			uni(E[i].a,E[i].b);	
		}
	}
	cout << re % mod<< endl;
	return 0;
}
