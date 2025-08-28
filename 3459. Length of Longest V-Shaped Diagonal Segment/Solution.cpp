class Solution {
    vector<vector<int>> dirs = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    int m, n;
private:
    bool isVaild(vector<vector<int>>& grid, int m, int n, int r, int c, int newR, int newC)
    {
        if(newR<0 || newR>=m || newC<0 || newC>=n)
            return false;
        if(grid[newR][newC] !=  2 && grid[r][c] == 1)
            return false;
        if(grid[newR][newC] !=  0 && grid[r][c] == 2)
            return false;
        if(grid[newR][newC] !=  2 && grid[r][c] == 0)
            return false;
        
        return true;
    }
    int dfs(vector<vector<int>>& grid, int (&dp)[501][501][4][2], int r, int c, int d, int t)
    {
        if(dp[r][c][d][t])
            return dp[r][c][d][t];
        int res = 1;
        int newR = r + dirs[d][0], newC = c + dirs[d][1];
        if(isVaild(grid, m, n, r, c, newR, newC))
            res = max(res, dfs(grid, dp, newR, newC, d, t) + 1);
        if(t)
        {
            int d2 = (d + 1) % 4;
            int nextR = r + dirs[d2][0], nextC = c + dirs[d2][1];
            if(isVaild(grid, m, n, r, c, nextR, nextC))
                res = max(res, dfs(grid, dp, nextR, nextC, d2, 0) + 1);
        }
        dp[r][c][d][t] = res;

        return res;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) 
    {   
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        int dp[501][501][4][2];
        memset(dp, 0, sizeof(dp));
        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                if(grid[r][c] == 1)
                {
                    res = max(res, dfs(grid, dp, r, c, 0, 1));
                    res = max(res, dfs(grid, dp, r, c, 1, 1));
                    res = max(res, dfs(grid, dp, r, c, 2, 1));
                    res = max(res, dfs(grid, dp, r, c, 3, 1));
                }
            }
        }

        return res;
    }
};