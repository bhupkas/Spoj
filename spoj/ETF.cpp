/* bhupkas */

#include "stdio.h"
#include "iostream"

using namespace std;

#define SIZE 1000010

int phi[SIZE+5];

void pre()
	{
		int i,j;
		for(i=2,phi[1]=1; i<SIZE; i++)
			{
				if(!phi[i])
				{
					phi[i] = i-1;
					for(j=(i<<1); j<SIZE; j+=i)
					{
						if(!phi[j]) phi[j] = j;
						phi[j] = phi[j]/i*(i-1);
					}
				}
			}
	}
int main()
	{
		pre();
		int t,n;
		cin>>t;
		while(t--)
			{
				cin>>n;
				cout<<phi[n]<<endl;
			}
		return 0;
	}
