/* bhupkas */

#include "bits/stdc++.h"

using namespace std;

int A[20005];
int B[20005];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{	
		int n,k;
		cin >> n >> k;
		for(int i = 0 ; i < n ; i++)	cin >> A[i];
		for(int i = 0 ; i < n ; i++)	B[i] = A[i] & A[(i - 1 + n) % n] & A[(i + 1)%n] ;
		if(k == 1)
		{
			for(int i = 0; i < n ; i++)	cout << B[i] << " ";
			cout << endl;
			continue;
		}
		else
		{
			for(int i = 0 ; i < n ; i++)	A[i] = B[i] & B[(i - 1 + n) % n] & B[(i + 1)%n] ;
			for(int i = 0; i < n ; i++)	cout << A[i] << " ";
			cout << endl;		
		}
	}
	return 0;
}
