class Solution {
private:
    int calPrefix(vector<vector<int>>& mat, int& r1, int& c1, int& r2, int& c2, bool mode)
    {
        int res = 0, n = mat[0].size();
        if(mode)
        {
            res = mat[r2][c2];
            if(r1 > 0 && c1 > 0)
                res -= mat[r1 - 1][c1 - 1];
        }
        else if(!mode)
        {
            res = mat[r2][c2];
            if(r1 > 0 && c1 < n - 1)
                res -= mat[r1 - 1][c1 + 1];
        }

        return res;
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> lr = grid, rl = grid;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i > 0 && j > 0)
                    lr[i][j] += lr[i - 1][j - 1];
                if(i > 0 && j < n - 1)
                    rl[i][j] += rl[i - 1][j + 1];
            }
        }

        set<int> s;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                s.insert(grid[i][j]);
                if(s.size() > 3)
                    s.erase(s.begin());
                
                for(int w=1; w<min(m, n); w++)
                {
                    int topR = i - w, topC = j;
                    int bottomR = i + w, bottomC = j;
                    int leftR = i, leftC = j - w;
                    int rightR = i, rightC = j + w;

                    if(topR < 0 || bottomR >= m || leftC < 0 || rightC >= n)
                        break;
                
                    int v1 = calPrefix(lr, topR, topC, rightR, rightC, true);
                    int v2 = calPrefix(lr, leftR, leftC, bottomR, bottomC, true);
                    int v3 = calPrefix(rl, topR, topC, leftR, leftC, false);
                    int v4 = calPrefix(rl, rightR, rightC, bottomR, bottomC, false);
                    int val = v1 + v2 + v3 + v4 - grid[topR][topC] - grid[bottomR][bottomC] - grid[leftR][leftC] - grid[rightR][rightC];

                    s.insert(val);
                    if(s.size() > 3)
                        s.erase(s.begin());
                }
            }
        }
        vector<int> res(s.rbegin(), s.rend());

        return res;
    }
};