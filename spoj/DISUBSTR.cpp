/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

const int N = 100005;

string str;

struct node
{
	int a,b,idx;
};

typedef struct node Node;

bool cmp(Node N1, Node N2)
{
	if(N1.a == N2.a)	return N1.b < N2.b;
	else	return N1.a < N2.a;
}	

int P[18][N];
Node L[N];

int n;

int stp;

map < int , int > mymap;

int T[N];

void suffix()
{
	n = str.size();
	for(int i = 0 ; i < n ; ++i)	P[0][i] = (int)(str[i] - 'a');
	for(int i = 0 ; i < n ; ++i)	T[i] = P[0][i];
	sort(T,T+n);
	int co = 0;
	mymap[T[0]] = co , co++;
	for(int i = 1 ; i < n ; ++i)	if(T[i] != T[i-1])	mymap[T[i]] = co , co++;
	for(int i = 0 ; i < n ; ++i)	P[0][i] = mymap[P[0][i]];
	bool foo = true;
	int cnt;
	for(stp = 1 , cnt = 1 ;cnt < n ; stp++ , cnt <<= 1 )
	{
		for(int i = 0 ; i < n ; ++i)
		{
			L[i].a = P[stp-1][i];
			L[i].b = i + cnt < n ? P[stp-1][i+cnt] : -1;
			L[i].idx = i;
		}
		sort(L,L+n,cmp);
		P[stp][L[0].idx] = 0;
		for(int i = 1 ; i < n ; ++i)
		{
			if(L[i].a == L[i-1].a && L[i].b == L[i-1].b)	P[stp][L[i].idx] = P[stp][L[i-1].idx] ;
			else	P[stp][L[i].idx] = i;
		}	
	}
}

int findLCP (int x, int y)
{
    int ret = 0;
    if (x == y)
        return n - x;

    for (int k = stp - 1; k >= 0 && x < n && y < n; k--)
    {
        if (P[k][x] == P[k][y])
        {
            x += (1 << k);
            y += (1 << k);
            ret += (1 << k);
        }
    }

    return ret;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> str;
		suffix();
		
		int ans = (n * (n + 1) ) / 2;
		for(int i = 0 ; i < n - 1 ; ++i)
			ans -= findLCP(L[i].idx,L[i+1].idx);
		cout << ans << endl;
	}
	return 0;
}
