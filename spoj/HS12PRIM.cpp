#include"iostream"
#include"stdio.h"
#include"vector"
using namespace std;
int main()
	{
		vector<int> v;
		int i,j=0;
		for(i=0;i<=50000000;i++)
			v.push_back(1e9);
		cout<<v.size()<<endl;
		return 0;
	}