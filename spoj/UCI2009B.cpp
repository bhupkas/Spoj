/* bhupkas */

#include "stdio.h"
#include "iostream"
#include "string.h"
#include "vector"
#include "map"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)
#define PB		push_back

int M[1004];
bool P[1005];
vector<int> p;

void pre()
	{
		int i,j;
		FOR(i,0,1001)	P[i]=true;
		P[0]=P[1]=false;
		for(i=2;i*i<1001;i++)
			{
				if(P[i])
					{
						for(j=i;j<=1001/i;j++)
							P[i*j]=false;
					}
			}
		FOR(i,2,1001)
			if(P[i])	
				p.PB(i);
				
		i=0;
		for(i=0;i<p.size();i++)
			{
				for(j=1;j<=1001/p[i];j++)
					M[p[i]*j]=p[i];
			}
	}

vector<int> fun(int n)
	{
		vector<int> re;
		while(n!=1)
			{
				re.PB(M[n]);
				n/=M[n];
			}
		return re; 
	}

int main()
	{
		pre();
		int t,n,i,j;
		vector<int> v;
		map<int,int> mymap;
		map<int,int>::iterator it;
		cin>>t;
		while(t--)
			{
				mymap.clear();
				cin>>n;
				if(n==0)	{cout<<1<<endl;	continue;}
				if(n!=1)	cout<<"A^"<<n<<"+";
				else		cout<<"A+";
				FOR(i,1,n)
					{
						v.clear();
						v=fun(n-i+1);
						FOR(j,0,v.size())	
							mymap[v[j]]++;
						v.clear();
						v=fun(i);
						FOR(j,0,v.size())	
							mymap[v[j]]--;
						for(it=mymap.begin();it!=mymap.end();it++)
							{
								if((*it).second==0)	continue;
								cout<<(*it).first;
								if((*it).second>1)	cout<<"^"<<(*it).second;
								cout<<"x";
							}
						if(n-i!=1)	cout<<"A^"<<n-i;
						else		cout<<"A";
						if(i!=1)	cout<<"B^"<<i;
						else		cout<<"B";
						cout<<"+";	
					}
				if(n!=1)	cout<<"B^"<<n<<endl;
				else		cout<<"B"<<endl;
			}
		return 0;
	}
