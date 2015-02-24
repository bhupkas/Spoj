/* bhupkas */
#include"iostream"
#include"stdio.h"
#include"map"
#include"string.h"
#include"algorithm"
using namespace std;
map<int,int> mymap;
bool P[100000002];
void pre()
	{
		int i,j;
		memset(P,true,sizeof(P));
		P[0]=P[1]=false;
		mymap[1]=1;
		for(i=2;i*i<100000002;i++)	
			{
				if(P[i])
					{

					}
			}
	}
int main()
	{
		pre();
	}