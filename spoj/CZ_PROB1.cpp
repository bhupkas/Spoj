/* Team name: Omega
*  Problem name:CZ_PROB1 spoj
*/
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cstring>

using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef vector <int> VI;
typedef vector <double> VD;
typedef vector<string> VS;
typedef vector <VI> VVI;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;
typedef vector <PII > VPII;
typedef pair <double, double> PDD;
typedef vector <PDD> VPDD;
 
const double EPS = 1e-9;
const int MOD = int(1e9) + 7;
 
#define SZ(a) int((a).size())
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FILL(a, v) memset(a, v, sizeof(a));
 
#define DEBUG(x) cout<<#x<<" :"<<x<<endl;
 
 
template <class T>
void  printV (vector<T> a) {
        REP (i, SZ(a)) cout<<a[i]<<" ";
        cout<<endl;
}
 
template <class T>
void  printA (T a[],int n) {
        REP (i, n) cout<<a[i]<<" ";
        cout<<endl;
}
 
template <class T>
void  printVV (vector<vector<T> > a) {
        REP (i, SZ(a)) {
                REP(j,SZ(a[0])) cout<<a[i][j]<<" ";
                cout<<endl;
        }
}
 
template <class T>
void  printAA (T a[],int n) {
        REP (i, n) {
                REP (j,n) cout<<a[i]<<" ";
                cout<<endl;
        }
}
 
///////////////////////////////////////////////////////////////////////////////////
 
bool P[10005];
VI p;
VI SP2;

void pre(){
        set<int> temp;
        FILL(P,true);
        P[0]=P[1]=false;
        for(int i=2;i*i<10005;i++){
                if(P[i]){
                        for(int j=i;j<=10005/i;j++){
                                P[i*j]=false;
                        }
                }
        }
        REP(i,10005){
                if(P[i])        p.PB(i);
        }
        REP(i,100){
                for(int j=0;i*i+j*j<10000;j++){
                        if(P[i*i+j*j])  temp.insert(i*i+j*j);
                }
        }
        set<int>::iterator it;
        for(it=temp.begin();it!=temp.end();it++)
                SP2.PB((*it));
}


int main() {
        //INPUT ("input.txt");
        //OUTPUT ("output.txt");
        pre();
        int T,n,k;
        scanf ("%d",&T);
        LL ans=0;
        while (T--) {
                cin>>n>>k;
                ans=0;
                if(k==1)        ans=1;
                else if(k==2){
                        ans=1+SP2[n-1]/2;
                }
                else{
                        for(int i=SP2[n-1];i>=1;i-=3){
                                ans+=(1+i/2);
                        }
                }
                cout<<ans<<endl;
        }      
        return 0;
}