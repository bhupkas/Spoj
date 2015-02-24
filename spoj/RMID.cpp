/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "deque"
#include "algorithm"
#include "vector"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define PB		push_back
#define PF		push_front 
#define POB		pop_back
#define POF		pop_front

int main()
	{
		int te,n,i,j,si1=0,si2=0;
		deque<int> q1,q2;
		q1.clear();
		q2.clear();
		while(scanf("%d",&n)!=EOF)
			{
				if(n==0)
					{	
						q1.clear();
						q2.clear();
						printf("\n");
						si1=0;
						si2=0;
					}
				else if(n==-1)	
					{
						printf("%d\n",q1.back());
						q1.POB();
						si1--;
						if(si1!=si2)	
							{
								te=q2.front();
								q2.POF();
								si2--;
								q1.PB(te);
								si1++;								
							}
					}
				else
					{
						if(!si1)	
							{
								q1.PB(n);
								si1++;
							}
						else if(si1==si2)
							{
								te=q2.front();
								q2.POF();
								q1.PB(te);
								q2.PB(n);
								si1++;
							}
						else
							{
								q2.PB(n);
								si2++;
							}
					}
				//cout<<q1.size()<<" "<<q2.size()<<endl;
			}
		return 0;
	}
