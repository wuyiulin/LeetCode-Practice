class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) 
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> prefix(m, vector<int>(n, 0));

        int r = INT_MAX, c = INT_MAX;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int top = i - 1 >= 0 ? prefix[i - 1][j] : 0;
                int left = j - 1 >= 0 ? prefix[i][j - 1] : 0;
                int tl = (i - 1 >= 0 && j - 1 >= 0) ? prefix[i - 1][j - 1] : 0;
                prefix[i][j] = top + left - tl + (grid[i][j] == 'X' ? 1 : grid[i][j] == 'Y' ? -1 : 0);
                if(grid[i][j] != '.')
                {
                    r = min(r, i);
                    c = min(c, j);
                }
                if(prefix[i][j] == 0 && (i >= r && j >= c))
                    res++;
            }
        }

        return res;
    }
};