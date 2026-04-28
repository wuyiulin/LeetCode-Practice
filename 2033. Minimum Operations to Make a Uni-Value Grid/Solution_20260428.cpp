class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        int m = grid.size(), n = grid[0].size();
        if(m*n == 1)
            return 0;
        vector<int> v(m*n, 0);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                v[i*n + j] = grid[i][j];
        auto midPtr = v.begin() + m*n / 2;
        nth_element(v.begin(), midPtr, v.end());
        int res = 0, tar = *midPtr;
        for(const int val : v)
        {
            int curr = abs(tar - val);
            if(curr % x)
                return -1;
            res += (curr / x);
        }

        return res;
    }
};
