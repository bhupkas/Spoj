#include"iostream"
#include"stdio.h"
#include"vector"
#include"algorithm"
#include"map"
#include"string.h"
#include"string"
#include"math.h"
using namespace std;
typedef long long LL;
int C[]={1,0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38};
int main()
	{
		LL ans,curr;
		int tc,t,base,i,j,len,k;
		char S[70];
		map<char,int> mymap;
		cin>>t;
		getchar();
		for(tc=1;tc<=t;tc++)
			{
				ans=0;
				mymap.clear();
				scanf("%s",S);
				len=strlen(S);
				for(i=0;i<len;i++)
						mymap[S[i]]=-1;						
				base=mymap.size();
				if(base==1)	base++;
				k=0;
				for(i=0;i<len;i++)
					{
						if(mymap[S[i]]==-1)
							{
								mymap[S[i]]=C[k];
								k++;
							}
						ans=ans*base+mymap[S[i]];
					}
				cout<<"Case #"<<tc<<": "<<ans<<endl;
			}
		return 0;
	}
