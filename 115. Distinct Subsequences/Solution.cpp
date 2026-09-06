class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        unsigned long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i=1; i<=m; i++)
        {
            for(int j=n; j>=1; j--)
            {
                dp[j] = s[i - 1] == t[j - 1] ? dp[j] + dp[j - 1] : dp[j];
            }
        }

        return dp[n];
    }
};