class Solution {
using LL = long long;
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<LL>> dp(k + 1, vector<LL>(n, 0));
        vector<vector<LL>> prefix(k + 1, vector<LL>(n, 0));

        dp[0][0] = 1;
        prefix[0][0] = 1;
        for (int i = 1; i < n; i++) {
            dp[0][i] = 1;
            prefix[0][i] = (prefix[0][i - 1] + dp[0][i]) % MOD;
        }

        for (int i = 1; i <= k; i++) 
        {
            for (int j = 1; j < n; j++) 
            {
                dp[i][j] = (dp[i][j - 1] + prefix[i - 1][j - 1]) % MOD;
                prefix[i][j] = (prefix[i][j - 1] + dp[i][j]) % MOD;
            }
        }
        return dp[k][n - 1];
    }
};