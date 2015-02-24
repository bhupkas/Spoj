#include"iostream"
#include"stdio.h"
#include"string.h"
#include"string"
#include"vector"
#include"algorithm"
using namespace std;
int main()	
	{
		string str[11];
		char S[300];
		char A[11];
		string ans;
		long long n,n1;
		int k,len,len1,i,j;
		while(scanf("%lld",&n)>0)
			{
				len1=0;
				n1=n;
				while(n1)
					{
						n1/=10;
						len1++;
					}
				A[len1]='\0';
				for(i=len1-1;i>=0;i--)
					{
						A[i]=n%10+'0';
						n/=10;
					}
				scanf("%s",S);
				len=strlen(S);
				len1=strlen(A);
				i=0;
				bool flag=true,oo=true;
				ans.clear();
				for(i=0;i<10;i++)
					str[i].clear();
				i=0;
				k=1;
				while(i<len)
					{
						while(k<=len1 && i<len)
							{
								if(k&1)
									{
										if(flag)
											{
												str[k-1].push_back(S[i]);
												if(i==len-1)
													break;
												str[k-1].push_back(S[i+1]);
												i+=2;
												k++;				
											}
										else
											{
												str[k-1].push_back(S[i]);
												i++;
												k++;
											}
									}					
								else
									{
										if(flag)
											{
												str[k-1].push_back(S[i]);
												i++;
												k++;
											}
										else
											{
												str[k-1].push_back(S[i]);
												if(i==len-1)
													break;
												str[k-1].push_back(S[i+1]);
												i+=2;
												k++;					
											}
									}
							}
						if(flag)	flag=false;
						else		flag=true;
						k=1;
					}
				for(i=1;i<=len1;i++)
					{
						for(j=0;j<len1;j++)
							{
								if(A[j]-'0'==i)	ans.append(str[j]);	
							}
					}
				cout<<ans<<endl;
			}
		return 0;
	}