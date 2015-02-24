/* Team name: Omega
*  Problem name: LIS2 spoj
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
const double PI = acos(-1.0); //M_PI;
 
#define SZ(a) int((a).size())
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define BSC(A, x) (lower_bound(ALL(A), x) - A.begin())
#define ERS(A, P) A.erase(A.begin() + P)
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define NOT_PRESENT(c,x) (find(all(c),x) != (c).end())
#define MP make_pair
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<_b;++i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define FI first
#define SE second
#define INPUT(a) freopen (a, "r", stdin)
#define OUTPUT(a) freopen (a, "w", stdout)
#define MAXN 100000
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
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
 
int N,n;
int segtree[4*MAXN+5];
VPII inp,store;
int beg[4*MAXN+5];
int end[4*MAXN+5];

void make_seg(int left,int right,int index)      {
        beg[index] = left;
        end[index] = right;
        if(left == right)       return;
        int mid =(left + right)/2;
        make_seg(left, mid, 2*index+1);
        make_seg(mid+1, right, 2*index +2);
}

void update(int pos,int idx,int val)   {
        if(pos == idx)  {
                segtree[pos] = val;
                return;
        }
        
}

int query(int idx, int ql, int qr)     {

}

int search(int low,int high,PII a)      {
        int mid=(low + high)/2;
        while(low<=high)        {
                if(mid == n-1)    return mid;
                else if((inp[mid].FI < a.FI && inp[mid].SE < a. SE) && !((inp[mid+1].FI < a.FI && inp[mid+1].SE < a. SE) ))     return mid;        
                else if( (inp[mid].FI < a.FI && inp[mid].SE < a. SE) )  low= mid + 1;
                else                                                    high=mid - 1;
                mid=(low + high)/2;
        }
}

int search1(int low,int high,PII a)     {
        int mid=(low+high)/2;
        while(low<=high)        {
                if(inp[mid].FI == a.FI && inp[mid].SE == a.SE)        return mid;
                else if( (inp[mid].FI < a.FI && inp[mid].SE < a. SE) )  low= mid + 1;
                else                                                    high=mid - 1;
                mid = (low + high)/2;
        }
}

int main() {
        //INPUT ("input.txt");
        //OUTPUT ("output.txt");
        int idx,ans=-1,k,temp,x,y,idx1;
        scanf ("%d",&n);
        N=1;
        while(N<n)      N<<=1;
        make_seg(0,N-1,0);
        REP(i,n){
                cin>>x>>y;
                inp.PB(MP(x,y));
                store.PB(MP(x,y));
        }
        sort(ALL(inp));
        FILL(segtree,0);
        REP(i,n)        {
                idx=search(0,n-1,store[i]);
                idx1=search1(0,n-1,store[i]);
                //temp=query(0,N-1,0,0,idx);
                //update(0,N-1,0,temp+1,idx1,idx1);
        }
        cout<<segtree[0]<<endl;
        return 0;
}