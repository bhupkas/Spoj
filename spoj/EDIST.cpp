/* bhupkas */

using namespace std;

#include "bits/stdc++.h"

int dp[2002][2002];

int main()
{
        int t;
        string str1,str2;
        cin >> t;
        int n,m;
        while(t--)
        {
                cin >> str1 >> str2;
                n = str1.size();
                m = str2.size();
                for(int i = 0 ; i <= n ; ++i)   dp[i][0] = i;
                for(int j = 0 ; j <= m ; ++j)   dp[0][j] = j;
                for(int i = 1 ; i <= n ; ++i)
                {
                        for(int j = 1 ; j <= m ; ++j)
                        {
                                dp[i][j] =  min(dp[i-1][j] , dp[i][j-1]) + 1;
                                if(str1[i-1] == str2[j-1])      dp[i][j] = min(dp[i][j] , dp[i-1][j-1]);
                                else    dp[i][j] = min(dp[i][j] , dp[i-1][j-1] + 1);
                        }
                }
                cout << dp[n][m] << endl;
        }
        return 0;
}
