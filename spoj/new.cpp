/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

const int N = 1000;

struct node
{
	int a,b,idx;
};

typedef struct node Node;

Node L[N];
Node T1[N],T2[N];
int C1[N],C2[N];

int n;

void radixsort()
{
	for(int i = 0 ; i < n ; ++i)	L[i].b++;
	for(int i = 0 ; i <= n ; ++i)	C1[i] = C2[i] = 0;
	for(int i = 0 ; i < n ; ++i)	C1[L[i].b]++;
	for(int i = 1 ; i <= n ; ++i)	C1[i] += C1[i-1];
	for(int i = n - 1; i >= 0 ; --i)
	{
		T1[C1[L[i].b]-1].a = L[i].a; 
		T1[C1[L[i].b]-1].b = L[i].b;
		T1[C1[L[i].b]-1].idx = L[i].idx;
		C1[L[i].b]--;
	}
	
	for(int i = 0 ; i < n ; ++i)	cout << T1[i].a << " " << T1[i].b << " " << T1[i].idx << endl;
	cout << endl;
	
	for(int i = 0 ; i < n ; ++i)	C2[T1[i].a]++;
	for(int i = 1 ; i <= n ; ++i)	C2[i] += C2[i-1];
	for(int i = 0 ; i <= n ; ++i)	cout << C2[i] << " ";
	cout << endl;
	for(int i = n - 1 ; i >= 0 ; --i)
	{	
		T2[C2[T1[i].a]-1].a = T1[i].a;
		T2[C2[T1[i].a]-1].b = T1[i].b;
		T2[C2[T1[i].a]-1].idx = T1[i].idx;
		C2[T1[i].a]--; 
	}
	for(int i = 0 ; i < n ; ++i)	L[i] = T2[i];
}

int main()
{
	cin >> n;
	for(int i = 0 ; i < n ; ++i)	cin >> L[i].a >> L[i].b , L[i].idx = i;
	radixsort();
	for(int i = 0 ; i < n ; ++i)	cout << L[i].a << " " << L[i].b << " " << L[i].idx << endl;
	return 0;
}
