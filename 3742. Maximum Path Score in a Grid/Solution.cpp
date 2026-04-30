class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        int fc = (grid[0][0] != 0);
        if(fc <= k)
            dp[0][0][fc] = grid[0][0];

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (i == 0 && j == 0) 
                    continue;

                int cc = (grid[i][j] != 0);

                for (int c = 0; c <= k; c++) 
                {
                    int nc = c + cc;
                    if (nc > k) 
                        continue;

                    if (i > 0 && dp[i - 1][j][c] != -1)
                        dp[i][j][nc] = max(dp[i][j][nc], grid[i][j] + dp[i - 1][j][c]);
                    
                    if (j > 0 && dp[i][j - 1][c] != -1)
                        dp[i][j][nc] = max(dp[i][j][nc], grid[i][j] + dp[i][j - 1][c]);
                }
            }
        }

        int res = -1;
        for (int i = 0; i <= k; i++)
            res = max(res, dp[m - 1][n - 1][i]);

        return res;
    }
};