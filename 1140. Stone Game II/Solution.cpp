class Solution {
private:
    int helper(vector<vector<int>>& dp, vector<int>& suffix, int l, int m, int n)
    {
        if(l >= n)
            return 0;
        if(l + 2 * m >= n)
            return suffix[l];
        if(dp[l][m] != -1)
            return dp[l][m];
        
        int best = 0;

        for(int X=1; X<=2*m; X++)
            best = max(best, suffix[l] - helper(dp, suffix, l + X, max(m, X), n));

        return dp[l][m] = best;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for(int i=0; i<n+1; i++)
            for(int j=0; j<n+1; j++)
                dp[i][j] = -1;
        
        return helper(dp, suffix, 0, 1, n);
    }
};