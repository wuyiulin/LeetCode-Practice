class Solution {
using LL = long long;
public:
    int zigZagArrays(int n, int l, int r) 
    {
        const int m = r - l + 1, mod = 1e9 + 7;
        LL res = 0;
        // dir, x
        LL dp[2*m];
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<m; i++)
        {
            dp[2*i] = m - i - 1; // 下降
            dp[2*i+1] = i;       // 上升
        }
        n-=2;
        while(n--)
        {
            LL curr[2*m];
            int prefix = 0, suffix = 0;
            memset(curr, 1, sizeof(curr));
            for(int i=0; i<m; i++)
            {
                curr[2*i+1] = prefix;
                prefix = (prefix + dp[2*i]) % mod;
            }
            for(int i=m-1; i>=0; i--)
            {
                curr[2*i] = suffix;
                suffix = (suffix + dp[2*i+1]) % mod;
            }
            copy(curr, curr + 2*m, dp);
        }
        for(const auto& d : dp)
            res = (res + d) % mod;

        return res;
    }
};