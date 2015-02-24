/* bhupkas */
#include"iostream"
#include"stdio.h"
#include"math.h"
typedef long long LL;
using namespace std;
int main()
	{
		
		LL tc,t,n,i,j,cnt;
		bool flag;
		cin>>t;
		for(tc=1;tc<=t;tc++)
			{
				cnt=0;
				i=2;
				cin>>n;
				if(n<9)
					{
						cout<<"Case #"<<tc<<":"<<endl;
						cout<<"For n="<<n<<" there is no almost square factorisation."<<endl;
						continue;
					}
				while((i*i-1)*(i*i-1)<=n)
					{
						if(n%(i*i-1)==0)	
							{
								//cout<<"here";
								j=(LL)sqrt(n/(i*i-1)+1);
								if(j*j == n/(i*i-1)+1)
									{
										cnt++;
										if(cnt==1)
											{
												cout<<"Case #"<<tc<<":"<<endl<<n;
												cout<<"=("<<i<<"^2-1)*("<<j<<"^2-1)";
											}
										else
											{
												cout<<"=("<<i<<"^2-1)*("<<j<<"^2-1)";	
											}	
									}
							}
						i++;
					}
				if(cnt==0)	
					{
						cout<<"Case #"<<tc<<":"<<endl;
						cout<<"For n="<<n<<" there is no almost square factorisation."<<endl;
					}
				else	cout<<endl;
			}

		return 0;
	}
