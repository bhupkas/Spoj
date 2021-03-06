/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "vector"
#include "set"
#include "map"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)
#define MAX			2015
#define PP			pair<int,int>
#define I			insert

int main()
	{
		int A[MAX+5],l,t,i,j,n,m,c,r,d;
		cin>>t;
		set<int> myset;
		set<int>::iterator it1,it;
		map<int,int> mymap;
		while(t--)
			{
				mymap.clear();
				myset.clear();
				cin>>l>>n;
				FOR(i,0,2*l+5)	A[i]=0;
				FOR(i,0,n)
					{
						cin>>c>>r>>d;
						A[c-r]+=d;
						A[c+r+1]-=d;						
					}
				FOR(i,1,l+1)
					A[i]+=A[i-1];
				FOR(i,2,l+1)
					A[i]+=A[i-1];
				FOR(i,1,l+1)
					myset.I(A[i]);
				for(i=l;i>0;i--)
					mymap[A[i]]=i;
				cin>>m;
				while(m--)
					{
						cin>>d;
						it=myset.upper_bound(d);
						if(it==myset.end())
							{
								it--;
								if((*it)==d)	{cout<<l<<endl;}
								else	cout<<"Bloon leakage"<<endl;
							}
						else
							{
								if(it==myset.begin())	cout<<mymap[(*it)]<<endl;
								else 
									{
										it1=it;
										it--;
										if((*it)==d)	cout<<mymap[(*it)]<<endl;
										else		cout<<mymap[(*it1)]<<endl;
									}
									
							}
					}
			}
		return 0;
	}	
