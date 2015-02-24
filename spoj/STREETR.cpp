/* bhupkas */
#include"algorithm"
#include"stdio.h"
#include"iostream"
using namespace std;

int a[100001];

inline int gcd(int a, int b) 
	{
		while(b) 
			b ^= a ^= b ^= a %= b;
		return a;
	}

int main() {
	int n, i, g, cnt;
	cin>>n;
	for(i = 0; i < n; i++) cin>>a[i];
	sort(a, a + n);
	g = a[1] - a[0], cnt = 0;
	for(i = 1; i < n; i++) g = gcd(g, a[i] - a[i-1]);
	for(i = 1; i < n; i++) cnt += (a[i] - a[i-1]) / g - 1;
	cout<<cnt<<endl;
	return 0;
}