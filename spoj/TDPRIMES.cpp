#include"iostream"
#include"stdio.h"
#include"vector"
using namespace std;
#define SIZE 100000005
void pre()
	{
	vector<bool> A;
	int i,j;
	for(i=0;i<SIZE;i++)	A.push_back(true);
	A[0]=A[1]=false;
	for(i=2;i*i<SIZE;i++)
		{	
		if(A[i])
			{
			for(j=i;j<=SIZE/i;j++)	A[i*j]=false;
			}
		}
	}
int main()
	{
	pre();
	
	return 0;
	}
