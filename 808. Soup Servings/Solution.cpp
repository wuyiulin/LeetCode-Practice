class Solution {
private:
    double dfs(vector<vector<double>>& dp, int a, int b)
    {
        if (a <= 0 && b <= 0) 
            return 0.5;
        if (a <= 0) 
            return 1.0;
        if (b <= 0) 
            return 0.0;
        if (dp[a][b] >= 0) 
            return dp[a][b];

        dp[a][b] = 0.25 * (
            dfs(dp, a - 4, b) +
            dfs(dp, a - 3, b - 1) +
            dfs(dp, a - 2, b - 2) +
            dfs(dp, a - 1, b - 3));

        return dp[a][b];
    }
public:
    double soupServings(int n) 
    {
        if (n >= 4800) return 1.0;

        int N = (n + 24) / 25;
        vector<vector<double>> dp(N + 1, vector<double>(N + 1, -1));

        return dfs(dp, N, N);
    }
};