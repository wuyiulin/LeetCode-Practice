class Solution {
private:
    int getTR(vector<vector<int>>& fruits)
    {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][n - 1] = fruits[0][n - 1];
        vector<vector<int>> dirs = {{1, -1}, {1, 0}, {1, 1}};
        for(int r=0; r<n; r++)
        {
            for(int c=0; c<n; c++)
            {
                if(r >= c && !(r == n - 1 && c == n - 1))
                    continue;
                for(const auto& dir : dirs)
                {
                    int newR = r - dir[0], newC = c - dir[1];
                    if(newR < 0 || newR >= n || newC < 0 || newC >= n)
                        continue;
                    if(newR < newC && newC < n - 1 - newR)
                        continue;
                    dp[r][c] = max(dp[r][c], dp[newR][newC] + fruits[r][c]);
                }
            }
        }

        return dp[n - 1][n - 1];
    }

    int getBL(vector<vector<int>>& fruits)
    {
        int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[n - 1][0] = fruits[n - 1][0];
        vector<vector<int>> dirs = {{-1, 1}, {0, 1}, {1, 1}};
        for(int c=0; c<n; c++)
        {
            for(int r=0; r<n; r++)
            {
                if(r <= c && !(r == n - 1 && c == n - 1))
                    continue;
                for(const auto& dir : dirs)
                {
                    int newR = r - dir[0], newC = c - dir[1];
                    if(newR < 0 || newR >= n || newC < 0 || newC >= n)
                        continue;
                    if(newC < newR && newR < n - 1 - newC)
                        continue;
                    dp[r][c] = max(dp[r][c], dp[newR][newC] + fruits[r][c]);
                }
            }
        }

        return dp[n - 1][n - 1];
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) 
    {
        vector<vector<int>> tr = {{1, -1}, {1, 0}, {1, 1}};
        vector<vector<int>> bl = {{-1, 1}, {0, 1}, {1, 1}};
        int res = 0, n = fruits.size();
        for(int i=0; i<n; i++)
            res += fruits[i][i];
        res += getTR(fruits);
        res += getBL(fruits);

        return res - 2 * fruits[n - 1][n - 1];
    }
};