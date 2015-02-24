#include"iostream"
#include"math.h"
#include"stdio.h"
#include"algorithm"
using namespace std;
int main()
	{
		long long t,n,i,j;
		cin>>t;
		double t1,t2;
		while(t--)
			{
				cin>>n;
				n++;
				t1=(double)(sqrt(2*n));
				//cout<<t1<<endl;
				t1=(double)(0.5)+t1;
				//cout<<t1<<endl;
				t2=floor(t1);
				cout<<(long long)t2<<endl;
			}
		return 0;
	}