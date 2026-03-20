class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size(), ks = k*k;
        vector<vector<int>> res(m-k+1, vector<int>(n-k+1, 0));
        int vals[ks];
        memset(vals, 0, sizeof(vals));

        for(int i=0; i<m-k+1; i++)
        {
            for(int j=0; j<n-k+1; j++)
            {
                bool f = true;
                int idx = 0, minDiff = 2 * 1e5 + 1;
                for(int ik=i; ik<i+k; ik++)
                    for(int jk=j; jk<j+k; jk++)
                        vals[idx++] = grid[ik][jk];
                sort(vals, vals + ks);
                for(int q=1; q<ks; q++)
                {
                    int curr = vals[q] - vals[q - 1];
                    if(curr > 0)
                        minDiff = min(minDiff, curr);
                    if(minDiff == 1)
                        break;
                }
                res[i][j] = minDiff == 2 * 1e5 + 1 ? 0 : minDiff;

            }
        }

        return res;
    }
};