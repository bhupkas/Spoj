/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "algorithm"
#include "stdlib.h"

using namespace std;

#define FOR(i,a,b)	for(i=a;i<b;i++)

int calc(string str)
	{
		int i,ans=0,si=str.size();
		for(i=0;i<si;i++)
			ans=ans*10+str[i]-'0';
		return ans;
	}

int main()
	{
		int n,i,a,b,c,t;
		cin>>t;
		string str1,str2,str3;
		string temp="ma";
		getchar();
		while(t--)	
			{
				cin>>str1;
				getchar();getchar();getchar();
				cin>>str2;
				getchar();getchar();getchar();
				cin>>str3;
				getchar();
				std::size_t found = str1.find(temp);
				if(found!=std::string::npos)
					{
						c=calc(str3);
						b=calc(str2);
						a=c-b;
						cout<<a<<" + "<<b<<" = "<<c<<endl;
						continue;
					}
				found = str2.find(temp);
				if(found!=std::string::npos)
					{
						c=calc(str3);
						a=calc(str1);
						b=c-a;
						cout<<a<<" + "<<b<<" = "<<c<<endl;	
						continue;
					}
				found = str3.find(temp);
				if(found!=std::string::npos)
					{
						a=calc(str1);
						b=calc(str2);
						c=a+b;
						cout<<a<<" + "<<b<<" = "<<c<<endl;
					}
			}
		return 0;
	}