#include <bits/stdc++.h>

using namespace std;
 
#define SZ(a) int((a).size())
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define BSC(A, x) (lower_bound(ALL(A), x) - A.begin())
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(all(c),x) != (c).end()) // present in a container or not.
#define MP make_pair
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define REP1(i,n) for(int _n=n, i=1;i<=_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<_b;++i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define FF first
#define SS second
#define INPUT(a) freopen (a, "r", stdin)
#define OUTPUT(a) freopen (a, "w", stdout)
#define FORD(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define FILL(a, v) memset(a, v, sizeof(a));
#define DREP(a)                 sort(ALL(a)); a.erase(unique(ALL(a)),a.end()) // will make the vector unique and sorted order
#define DEBUG(args...)          {dbg,args; cerr<<endl;}
#define INF                     (int)1e9
#define LINF                    (long long)1e18

typedef long long LL;
typedef long double LD;
typedef vector <int> VI;
typedef vector <LL> VLL;
typedef vector <double> VD;
typedef vector<string> VS;
typedef vector <VI> VVI;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;
typedef vector <PII > VPII;
typedef pair <double, double> PDD;
typedef vector <PDD> VPDD;

struct debugger { template<typename T> debugger& operator , (const T& v) {  cerr<<v<<" ";    return *this;  } } dbg;

template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS rv; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) rv.PB(s.substr(p, np - p)); p = np + 1;} if (p < SZ(s)) rv.PB(s.substr(p)); return rv;}

void print(VI v, int sz = -1) { if (sz == -1) sz = SZ(v); cerr << "["; if (sz) cerr << v[0]; FOR (i, 1, sz) cerr << ", " << v[i]; cerr << "]" << endl; }
void print(VD v, int sz = -1) { if (sz == -1) sz = SZ(v); cerr << "["; if (sz) cerr << v[0]; FOR (i, 1, sz) cerr << ", " << v[i]; cerr << "]" << endl; }
void print(VS v, int sz = -1) { if (sz == -1) sz = SZ(v); cerr << "["; if (sz) cerr << v[0]; FOR (i, 1, sz) cerr << ", " << v[i]; cerr << "]" << endl; }
void print (PII v) { cerr << "{ " << v.FF << ", " << v.SS << " }"; }
void print (VPII v, int sz = -1) { if (sz == -1) sz = SZ(v); cerr << "[ "; if (sz) print (v[0]); FOR (i, 1, sz) { cerr << ", "; print (v[i]);} cerr << "]" << endl;}
void print(VVI v, int sz1 = -1, int sz2 = -1) { if (sz1 == -1) sz1 = SZ(v); if (sz2 == -1) sz2 = SZ(v[0]); cerr << "[ ---" << endl;if (sz1) cerr << " ", print(v[0], sz2);FOR(i, 1, sz1) cerr << " ", print(v[i], sz2);    cerr << "--- ]\n";}

const double EPS = 1e-9;
const int MOD = int(1e9) + 7;
const double PI = acos(-1.0); //M_PI;

/////////////////////////////////////////////////////////////////

void pre()
{

}

int main()
{
   pre();
   int n;
   cin >> n;
   {
	   VI adj[10005];
	   REP(i,n-1)
	   {
	   		int x,y;
	   		cin >> x >> y;
	   		adj[x-1].PB(y-1);
	   		adj[y-1].PB(x-1);
	   }
	   deque <int> q;
	   bool visi[10005];
	   int dis[10005];
	   REP(i,n)	visi[i] = false;
	   REP(i,n)	dis[i] = INF;
	   q.PB(0);
	   dis[0] = 0;
	   while(!q.empty())
	   {
	   		int curr = q.front();
	   		q.pop_front();
	   		visi[curr] = true;
	   		REP(i,adj[curr].size())
	   		{
	   			if(!visi[adj[curr][i]])
	   			{
	   				dis[adj[curr][i]] = dis[curr] + 1;
	   				q.PB(adj[curr][i]);
	   			}
	   		}	
	   }
	   q.clear();
	   int ma = -1,oo = 0;
	   REP(i,n)	 		if(dis[i] > ma)	oo = i , ma = dis[i];
	   REP(i,n)	visi[i] = false;
	   REP(i,n)	dis[i] = INF;
	   q.PB(oo);
	   dis[oo] = 0;
	   while(!q.empty())
	   {
	   		int curr = q.front();
	   		q.pop_front();
	   		visi[curr] = true;
	   		REP(i,adj[curr].size())
	   		{
	   			if(!visi[adj[curr][i]])
	   			{
	   				dis[adj[curr][i]] = dis[curr] + 1;
	   				q.PB(adj[curr][i]);
	   			}
	   		}	
	   }
	   ma = -1;
	   REP(i,n)	ma = max(ma,dis[i]);
	   cout << ma << endl;	
   }
   
   return 0;
}