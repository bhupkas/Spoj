/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

int dp1[2005],dp2[2005];

int W[2005];

int C[2005];

int cap,n;

int main()
{
        cin >> cap >> n;
        for(int i = 0 ; i < n ; ++i)    cin >> W[i] >> C[i];
        for(int i = 1 ; i <= n ; ++i)
        {
                for(int j = 0 ; j <= cap ; ++j)
                {
                        if(i & 1)
                        {
                                dp2[j] = dp1[j];
                                if(W[i-1] <= j)   dp2[j] = max(dp1[j] , dp1[j-W[i-1]] + C[i-1]);
                        }
                        else
                        {
                                dp1[j] = dp2[j];
                                if(W[i-1] <= j) dp1[j] = max(dp2[j] , dp2[j-W[i-1]] + C[i-1]);      
                        }
                }
        }
        if(n & 1)       cout << dp2[cap] << endl;
        else    cout << dp1[cap] << endl;
        return 0;
}
