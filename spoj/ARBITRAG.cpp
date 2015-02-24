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

int n;
map < string , int > mymap;
int m;
char S[1005],S1[1005];
vector < pair < int , double > > adj[35];
bool ans;
int color[35];

int start;
void dfs(int vertex,double cost)
{
	color[vertex] = 1;
	REP(i,adj[vertex].size())
	{
		int curr = adj[vertex][i].first;
		if(color[curr] == 0)	dfs(curr,cost * adj[vertex][i].second);
		else if(color[curr] == 1 && start == curr)		if(fabs(cost * adj[vertex][i].second - EPS) > 1.0)	ans = true;
	}
	color[vertex] = 2;
}

int main()
{
   pre();
   int co;
   int t = 0;
   while(1)
   {
   		t++;
   		ans = false;
   		co = 0;
   		scanf("%d",&n);
   		if(!n)	break;
   		string str;
   		REP(i,n)	cin >> str , mymap[str] = co++;
   		cin >> m;
   		getchar();
   		double cost;
   		string temp1,temp2;
   		REP(i,m)	
   		{
   			temp1.clear();
   			temp2.clear();
   			scanf("%s %lf %s",S,&cost,S1);
   			int l1 = strlen(S) , l2 = strlen(S1);
   			REP(i,l1)	temp1.PB(S[i]);
   			REP(i,l2)	temp2.PB(S1[i]);	
   			adj[mymap[temp1]].PB(MP(mymap[temp2],cost));
   		}
 		REP(i,n)	if(!ans)	memset(color,0,sizeof(color)) , start = i , dfs(i,1.0);
   		REP(i,n)	adj[i].clear();
   		mymap.clear();
   		if(ans)	printf("Case %d: Yes \n",t);
   		else	printf("Case %d: No\n",t );
   }
   return 0;
}