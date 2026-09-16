class Solution {
using LL = long long;
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<LL> dp(n, 1);
        vector<LL> prefix(n, 0);
        prefix[0] = 1;
        for (int j = 1; j < n; j++)
            prefix[j] = (prefix[j - 1] + dp[j]) % MOD;

        for (int i = 1; i <= k; i++) {
            vector<LL> ndp(n, 0), npre(n, 0);   
            for (int j = 1; j < n; j++) 
            {
                ndp[j]  = (ndp[j - 1] + prefix[j - 1]) % MOD;
                npre[j] = (npre[j - 1] + ndp[j]) % MOD;
            }
            dp = move(ndp);
            prefix = move(npre);
        }
        
        return dp[n - 1];
    }
};