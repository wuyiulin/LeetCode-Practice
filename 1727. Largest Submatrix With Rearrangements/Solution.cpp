class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        for(int j=0; j<n; j++)
        {
            for(int i=1; i<m; i++)
            {
                if(matrix[i][j])
                    matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
        for(int i=0; i<m; i++)
        {
            sort(matrix[i].begin(), matrix[i].end());
            for(int j=0; j<n; j++)
            {
                res = max(res, (n - j) * matrix[i][j]);
            }
        }

        return res;
    }
};