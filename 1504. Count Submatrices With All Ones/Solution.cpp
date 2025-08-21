class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        int res = 0;

        for(int r=1; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                if(mat[r][c])
                    mat[r][c] += mat[r-1][c];
            }
        }
        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                int h = mat[r][c];
                for(int k=c; k>=0; k--)
                {
                    if(!mat[r][k])
                        break;
                    h = min(h, mat[r][k]);
                    res += h;
                }
            }
        }

        return res;
    }
};