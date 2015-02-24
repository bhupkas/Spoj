/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "math.h"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)

int main()
	{
		int i,j,tc,T,p0,p1,t0,p;
		double t,te1,te2;
		cin>>T;
		FOR(tc,1,T+1)
			{
				cin>>p0>>p1>>t0>>p;
				te1=log((double)(p)/(double)(p0));
				te2=log((double)(p1)/(double)(p0));
				t=(double)(t0)*(te1/te2);
				printf("Scenario #%d: %.2lf\n",tc,t);
			}
		return 0;
	}
