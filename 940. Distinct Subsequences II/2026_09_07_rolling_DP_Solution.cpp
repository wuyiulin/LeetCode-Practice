class Solution {
using LL = long long;
public:
    int distinctSubseqII(string s) {
        int n = s.size(), mod = 1e9 + 7;
        LL dp[2];
        memset(dp, 0, sizeof(dp));
        dp[0] = 2;
        LL table[26];
        fill(table, table + 26, -1);
        table[s[0] -'a'] = 1;
        for(int i=1; i<n; i++)
        {
            int curr = s[i] - 'a';
            dp[1] = (2 * dp[0]) % mod;
            if(table[curr] != -1)
            {
                LL last = table[curr];
                dp[1] = (dp[1] - last + mod) % mod;
            }
            table[curr] = dp[0];
            dp[0] = dp[1];
        }

        return (int)(dp[0] - 1 + mod) % mod;
    }
};