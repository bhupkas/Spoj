/* bhupkas */

#include "bits/stdc++.h"

using namespace std;

#define NMAX 30005

struct node
{
	int ht,sal,num;
};

typedef struct node Node;

int B[NMAX + 5] , S[NMAX + 5];

Node N[NMAX + 5];

int read() {
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

bool cmp(Node N1, Node N2)
{	
	if(N1.ht == N2.ht)	return N1.sal < N2.sal;
	return N1.ht < N2.ht;	
}

map < int , int > mymap;

int main()
{	
	int t;
	t = read();
	int idxx,ht,sal;
	set < pair < int , int > > ss;
	set < pair < int , int > > :: iterator it , it1;
	while(t--)
	{	
		ss.clear();
		mymap.clear();
		int n,q;
		n = read();
		q = read();
		for(int i = 0 ; i < n ; i++)
		{
			idxx = read();
			sal = read();
			ht = read();
			N[i].num = idxx;
			N[i].ht = ht;
			N[i].sal = sal; 
		}	
		sort(N,N+n,cmp);
		memset(S,0,sizeof(S));
		ss.insert(make_pair(N[n-1].sal,n-1));
		B[n-1] = -1;
		for(int i = n - 2 ; i >= 0 ; i--)
		{
			ss.insert(make_pair(N[i].sal,i));
			it = ss.find(make_pair(N[i].sal,i));
			it++;
			B[i] = (*it).second;	
		}
		for(int i = 0 ; i < n - 1 ; i++)
			S[B[i]] += S[i] + 1 , mymap[N[i].num] = i;
		mymap[N[n-1].num] = n - 1;
		int j;
		while(q--)
		{
			idxx = read();
			j = mymap[idxx];
			if(B[j] == -1)	printf("0 ");
			else		printf("%d ",N[B[j]].num);
			printf("%d\n",S[j]);
		}
	}
	return 0;
}
