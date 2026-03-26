class Solution {
using LL = long long;
private:
    vector<vector<int>> rotate(vector<vector<int>>& mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                res[j][i] = mat[i][j];    

        return res;
    }
    bool helper(const vector<vector<int>>& mat)
    {
        LL ts = 0, bs = 0;
        unordered_map<LL, int> cntT, cntB;
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++)
        {
            for(int val : mat[i])
            {
                bs += val;
                cntB[val]++;
            }
        }

        for(int i=0; i<m-1; i++)
        {
            for(const int val : mat[i])
            {
                ts += val;
                bs -= val;
                cntT[val]++;
                cntB[val]--;
            }

            if(ts == bs)
                return true;
            else
            {
                if(ts > bs)
                {
                    LL tar = ts - bs;
                    if(cntT[tar] > 0)
                    {
                        if((i+1 >= 2 && n >= 2) || (i == 0 && (mat[0][0] == tar || mat[0][n - 1] == tar)) || (n == 1 && (mat[0][0] == tar || mat[i][0] == tar)))
                            return true;
                    }
                }
                else
                {
                    LL tar = bs - ts;
                    if(cntB[tar] > 0)
                    {
                        if((m - i - 1 >= 2 && n >= 2) || (i == m - 2 && (mat[i + 1][0] == tar || mat[i + 1][n - 1] == tar)) || (n == 1 && (mat[i + 1][0] == tar || mat[m - 1][0] == tar))) 
                            return true;
                    }
                }
            }
        }

        return false;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        return helper(grid) || helper(rotate(grid));
    }
};