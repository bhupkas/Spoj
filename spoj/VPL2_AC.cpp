/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "string.h"
#include "string"
#include "algorithm"
#include "map"
#include "vector"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define PB		push_back

int main()
	{
		int tc,t,c,l,i,j,ans,temp;
		vector<int> v;
		map<char,int> mymap;
		mymap['G']=0;
		mymap['R']=1;
		mymap['Y']=2;
		mymap['B']=3;
		mymap['O']=4;
		cin>>t;
		char S[1000005];
		FOR(tc,1,t+1)
			{
				v.clear();
				cin>>c;
				getchar();
				scanf("%s",S);
				l=strlen(S);
				FOR(i,1,l)
					v.PB(abs(mymap[S[i]]-mymap[S[i-1]]));
				j=0;
				temp=0;
				ans=-1;
				//FOR(i,0,v.size())	cout<<v[i]<<" ";
				//cout<<endl;
				FOR(i,0,l-1)
					{
						while(j<l-1)
							{
								if(temp+v[j]>c)	break;
								else		{temp+=v[j];	j++;}	
							}
						ans=max(ans,j-i+1);
						//cout<<j<<endl;
						if(j>i)				temp-=v[i];
						if(i==j)			temp=0;
						if(i>=j)			j=i+1;
					}
				printf("Scenario #%d: %d\n",tc,ans);
			}
		return 0;
	}
