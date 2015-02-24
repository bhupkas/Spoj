#include <bits/stdc++.h>

using namespace std;

struct entry
{
    int nr[2];
    int p;
};

bool cmp (entry a, entry b)
{
    if (a.nr[0] == b.nr[0])
        return a.nr[1] < b.nr[1];
    else
        return a.nr[0] < b.nr[0];
}

const int MAXN = 100000;
const int MAXLOG = 17;

string s;
entry L[MAXN];
int P[MAXLOG][MAXN];

int stp, cnt;
int N;

int findLCP (int x, int y)
{
    int ret = 0;
    if (x == y)
        return N - x;

    for (int k = stp - 1; k >= 0 && x < N && y < N; k--)
    {
        if (P[k][x] == P[k][y])
        {
            x += (1 << k);
            y += (1 << k);
            ret += (1 << k);
        }
    }

    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
	cin >> s;
        N = s.size();

        for (int i = 0; i < N; i++)
            P[0][i] = (int) (s[i] - 'a');
	
	bool foo = true;
        for (stp = 1, cnt = 1; ; stp ++, cnt *= 2,foo = true)
        {
            // compute L
            for (int i = 0; i < N; i++)
            {
                L[i].nr[0] = P[stp - 1][i];
                L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
                L[i].p = i;
            }

            sort (L, L + N, cmp);
	
		for(int i = 0 ; i < N ; ++i) cout << L[i].p << " ";
		cout << endl;

		P[stp][L[0].p] = 0;

            for (int i = 1; i < N; i++)
            {
                if (L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1])
                    P[stp][L[i].p] = P[stp][L[i - 1].p] , foo = false;
                else
                    P[stp][L[i].p] = i;
            }
            if(foo)	
           	{
           		stp++;
           		break;
           	}
        }

        /*
        for (int i = 0; i < N; i++)
            cout << L[i].p << " ";
        cout << endl;
        */
        

        int ans = N * (N + 1) / 2;

        for (int i = 0; i + 1 < N; i++)
        {
            ans -= findLCP (L[i].p, L[i + 1].p);
        }

        cout << ans << endl;
    }

    return 0;
}

