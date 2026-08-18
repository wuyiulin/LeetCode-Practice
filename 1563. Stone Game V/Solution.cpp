class Solution {
private:
    int dfs(vector<int>& stoneValue, vector<vector<int>>& dp, vector<int>& prefix, int l, int r)
    {
        if(l >= r)
            return 0;
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int maxScore = 0, ls = 0, rs = prefix[r + 1] - prefix[l];

        for(int sp=l; sp<r; sp++)
        {
            ls += stoneValue[sp];
            rs -= stoneValue[sp];
            if(ls < rs)
            {
                if(maxScore > ls * 2)
                    continue;
                maxScore = max(maxScore, ls + dfs(stoneValue, dp, prefix, l, sp));
            }
            else if(ls > rs)
            {
                if(maxScore > rs * 2)
                    break;
                maxScore = max(maxScore, rs + dfs(stoneValue, dp, prefix, sp + 1, r));
            }
            else
            {
                maxScore = max({maxScore, ls + dfs(stoneValue, dp, prefix, l, sp), rs + dfs(stoneValue, dp, prefix, sp + 1, r)});
            }
        }

        dp[l][r] = maxScore;

        return maxScore;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for(int i=0; i<n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return dfs(stoneValue, dp, prefix, 0, n - 1);
    }
};