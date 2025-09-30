class Solution {
private:
    int dfs(vector<int>& values, vector<vector<int>>& dp, int l, int r)
    {
        if(dp[l][r] != -1)
            return dp[l][r];
        if(l + 1 == r)
            return dp[l][r] = 0;
        int res = INT_MAX;
        for(int k=l+1; k<r; k++)
            res = min(res, values[l] * values[k] * values[r] + dfs(values, dp, l, k) + dfs(values, dp, k, r));
        dp[l][r] = res;

        return res;
    }
public:
    int minScoreTriangulation(vector<int>& values) 
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return dfs(values, dp, 0, n-1);    
    }
};