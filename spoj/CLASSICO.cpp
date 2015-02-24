/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "vector"

using namespace std;

#define FOR(i,a,b)		for(i=a;i<b;i++)
#define vi			vector<int>
#define PB			push_back

int main()	
	{	
		int t,tc,i,j,n,curr,ma;
		int A[2005];
		vi v(11);
		cin>>t;
		FOR(tc,1,t+1)
			{
				v.clear();
				cin>>n;
				FOR(i,0,n)	cin>>A[i];
				if(n<11)
					cout<<"Case "<<tc<<": go home!"<<endl;
				else
					{
						curr=-1;
						FOR(i,0,11)
							{	
								ma=-1;
								FOR(j,curr+1,n-10+i)
									{
										if(A[j]>ma)	
											{
												curr=j;
												ma=A[j];
											}	
									}
								v.PB(ma);		
							}	
						cout<<"Case "<<tc<<": ";	
						FOR(i,0,10)	cout<<v[i]<<" ";
						cout<<v[10]<<endl;
					}
			}
		return 0;
	}
