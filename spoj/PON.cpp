/* bhupkas */

#include "iostream"
#include "stdio.h"
#include "algorithm"

using namespace std;


long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}


long long int modulo(long long int a,long long int n,long long int p){ //a^n%p
    long long int extra=1,aa=a;
    while(n>0){
        if(n%2==1){
            extra=mulmod(extra,aa,p);
            n--;
        }
        else{
            aa=mulmod(aa,aa,p);
            n=n>>1;
        }
    }
    return extra;
}

bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int main()
	{
		long long  t,n;
		cin>>t;
		while(t--)
			{
				cin>>n;
				if(Miller(n,3))	cout<<"YES"<<endl;
				else			cout<<"NO"<<endl;
			}
		return 0;
	}