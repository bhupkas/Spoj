/* bhupkas */
#include"stdio.h"
#include"iostream"
using namespace std;
int main()
	{
		int tem,tc,t,v1,s1,s,v2,s2,i,j;
		double t1,t2;
		long long ans;
		cin>>t;
		for(tc=1;tc<=t;tc++)
			{
				ans=0;
				cin>>s>>s1>>v1>>s2>>v2;
				t1=(double)(v1)/(double)(s1);
				t2=(double)(v2)/(double)(s2);
				if(t1>t2)
					{
						ans+=(s/s1)*v1;
						tem=s-(s/s1)*s1;
						ans+=v2*(tem/s2);
						tem=s-(s/s1)*s1-(s/s2)*s2;
											
					}
				else
					{
						ans+=(s/s2)*v2;
						tem=s-(s/s2)*s2;
						ans+=v1*(tem/s1);
						tem=s-(s/s1)*s1-(s/s2)*s2;
											
					}
				cout<<"Case #"<<tc<<": "<<ans<<endl;
			}
		return 0;
	}