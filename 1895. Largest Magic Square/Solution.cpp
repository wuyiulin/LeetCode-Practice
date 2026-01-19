class Solution {
private:
    bool isMagic(vector<vector<int>>& pr, vector<vector<int>>& pc, vector<vector<int>>& d1, vector<vector<int>>& d2, int x, int r, int c)
    {
        int val = d1[r + x][c + x] - d1[r][c];
        if(val != d2[r + x][c] - d2[r][c + x])
            return false;
        for(int i=0; i<x; i++)
        {   
            if(val != pr[r + i][c + x] - pr[r + i][c])
                return false;
            if(val != pc[r + x][c + i] - pc[r][c + i])
                return false;
        }

        return true;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> pr(m, vector<int>(n + 1, 0));
        vector<vector<int>> pc(m + 1, vector<int>(n, 0));
        vector<vector<int>> d1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> d2(m + 1, vector<int>(n + 1, 0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                pr[i][j + 1] = pr[i][j] + grid[i][j];
                pc[i + 1][j] = pc[i][j] + grid[i][j];
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j] = d2[i][j + 1] + grid[i][j];
            }
        }
        int res = 1;
        for (int x = min(m, n); x > 1; x--) 
        {
            for (int i = 0; i <= m - x; i++) 
            {
                for (int j = 0; j <= n - x; j++) 
                {
                    if (isMagic(pr, pc, d1, d2, x, i, j)) 
                        return x;
                }
            }
        }

        return res;
    }
};