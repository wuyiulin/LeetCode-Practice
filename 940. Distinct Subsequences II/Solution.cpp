class Solution {
using LL = long long;
public:
    int distinctSubseqII(string s) {
        int n = s.size(), mod = 1e9 + 7;
        long long dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 2;
        int table[26];
        fill(table, table + 26, -1);
        table[s[0] -'a'] = 0;
        for(int i=1; i<n; i++)
        {
            int curr = s[i] - 'a';
            dp[i] = (2 * dp[i - 1]) % mod;
            if(table[curr] != -1)
            {
                int last = table[curr];
                LL prev = last == 0 ? 1 : dp[last - 1];
                dp[i] = (dp[i] - prev + mod) % mod;
            }
            table[curr] = i;
        }

        return (int)(dp[n - 1] - 1 + mod) % mod;
    }
};