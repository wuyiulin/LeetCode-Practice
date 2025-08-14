class Solution {
using LL = long long;
public:
    int numberOfWays(int n, int x) 
    {
        int mod = 1e9 + 7;
        vector<LL> dp(n + 1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=n; j>=pow(i, x); j--)
            {
                dp[j] = dp[j] + dp[j - pow(i, x)];
            }
        }

        return dp[n] % mod;
    }
};