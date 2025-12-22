class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int n = strs.size(), m = strs[0].size(), res = m - 1, k = 0;
        vector<int> dp(m, 1);
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                for (k = 0; k < n; k++) 
                {
                    if (strs[k][j] > strs[k][i]) 
                        break;
                }
                if (k == n && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
            res = min(res, m - dp[i]);
        }

        return res;
    }
};