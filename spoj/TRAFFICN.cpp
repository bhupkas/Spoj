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

int dis[10005];
vector < pair < int , int > > adj[10005],rev[10005];
vector < pair < pair < int , int > , int > > pro;
int dis1[10005];

int main()
{
   pre();
   int t;
   cin >> t;
   
   while(t--)
   {
   		int n,m,k,s,t;
   		scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);
   		s--;
   		t--;
   		REP(i,m)
   		{
   			int x,y,co;
   			scanf("%d %d %d",&x,&y,&co);
   			adj[x-1].PB(MP(y-1,co));
   			rev[y-1].PB(MP(x-1,co));
   		}

   		REP(i,k)
   		{
   			int x,y,co;
   			scanf("%d %d %d",&x,&y,&co);
   			pro.PB(MP(MP(x-1,y-1),co));
   		}
   		
   		REP(i,n)	dis[i] = INF;
   		set < pair <int , int >  >myset;
   		set < pair <int , int >  > :: iterator it;
   		dis[s] = 0;
   		myset.insert(MP(0,s));
   		
   		while(!myset.empty())
		{
			int te4,si;
			it=myset.begin();
			te4=(*it).second;
			si=adj[te4].size();
			myset.erase(myset.begin());
			REP(j,si)
				{
				if(dis[te4]+adj[te4][j].second < dis[adj[te4][j].first])	
					{
					if(myset.find(MP(dis[adj[te4][j].first],adj[te4][j].first))!=myset.end())
						myset.erase(MP(dis[adj[te4][j].first],adj[te4][j].first));
					dis[adj[te4][j].first]=dis[te4]+adj[te4][j].second;
					myset.insert(MP(dis[adj[te4][j].first],adj[te4][j].first));
					}
				}
		}
		
		REP(i,n)	dis1[i] = INF;
		set < pair <int , int >  >myset1;
   		set < pair <int , int >  > :: iterator it1;
   		dis1[t] = 0;
   		myset1.insert(MP(0,t));
   		while(!myset1.empty())
		{
			int te41,si1;
			it1=myset1.begin();
			te41=(*it1).second;
			si1=rev[te41].size();
			myset1.erase(myset1.begin());
			REP(j,si1)
				{
				if(dis1[te41]+rev[te41][j].second < dis1[rev[te41][j].first])	
					{
					if(myset1.find(MP(dis1[rev[te41][j].first],rev[te41][j].first))!=myset1.end())
						myset1.erase(MP(dis1[rev[te41][j].first],rev[te41][j].first));
					dis1[rev[te41][j].first]=dis1[te41]+rev[te41][j].second;
					myset1.insert(MP(dis1[rev[te41][j].first],rev[te41][j].first));
					}
				}
		}

		int ans = dis[t];
		REP(i,k)		ans = min(ans, min(dis[pro[i].first.first] + dis1[pro[i].first.second] + pro[i].second,dis[pro[i].first.second] + dis1[pro[i].first.first] + pro[i].second));
		if(ans == INF)	ans = -1;   		
		printf("%d\n",ans);
		REP(i,n)	adj[i].clear() , rev[i].clear();
		pro.clear();
   }
   return 0;
}