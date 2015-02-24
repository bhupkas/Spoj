/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

vector < int > pre(string str)
{
	int n; 
	n = str.size();
	vector < int > re(n);
	re[0] = re[1] = 0;
	for(int i = 2 ; i <= n ; ++i)
	{
		int k = re[i-1];
		while(k && str[i] != str[k])	k = re[k];
		if(str[i] == str[k])	re[i] = k + 1;
		else	re[i] = 0;
	}
	return re;
}

int main()
{
	int 
	return 0;
}
