/* bhupkas */
#include"iostream"
#include"stdio.h"
#include"set"
#include"algorithm"
using namespace std;
#define MOD 1000000007
typedef long long LL;
inline void fastRead_int(LL *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}
int main()
	{
		set<LL> s1,s2;
		LL i,j,ans,t,n,M,F,a,b,c;
		set<LL>::iterator it;
		fastRead_int(&t);
		while(t--)
			{
				s1.clear();s2.clear();
				fastRead_int(&a);fastRead_int(&b);fastRead_int(&c);fastRead_int(&n);
				ans=1;
				s1.insert(1);
				M=1;
				for(i=2;i<=n;i++)
					{
						F=((a*M)%MOD + (b*i)%MOD + c%MOD)%MOD;
						ans = (ans + F)%MOD;
						if(s1.size()>s2.size())
							{
								it=s1.end();
								it--;
								if(F>=(*it))	{s2.insert(F);}
								else
									{
										s2.insert((*it));
										s1.erase(it);
										s1.insert(F);
									}
							}
						else
							{
								it=s1.end();
								it--;
								if(F<=(*it))
									s1.insert(F);
								else
									{
										it=s2.begin();
										s1.insert((*it));
										s2.erase(it);
										s2.insert(F);	
									}
							}	
						it=s1.end();
						it--;
						M=(*it);
					}
				printf("%lld\n",ans);
			}
		return 0;
	}