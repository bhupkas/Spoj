/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "math.h"
#include "algorithm"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define PI		acos(-1)

int main()
	{
		double r,n;
		double te,ans;
		cin>>r>>n;
		while(r && n)
			{
				r=(double)r;
				n=(double)n;
				te=(double)90/n;
				te=sin(te*PI/180.0);
				//te*=2;
				ans=r/te;
				printf("%.2lf\n",ans);	
				cin>>r>>n;
			}
		return 0;
	}
