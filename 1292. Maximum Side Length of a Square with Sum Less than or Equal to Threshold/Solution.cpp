class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + mat[i][j];
            }
        }

        int b = 0, t = min(m, n), res = 0;

        while(b < t)
        {
            bool f = false;
            int mid = (t - b) / 2 + b + 1;
            for(int i=0; i+mid<m+1 && !f; i++)
            {
                for(int j=0; j+mid<n+1; j++)
                {
                    int val = ps[i + mid][j + mid] - ps[i][j + mid] - ps[i + mid][j] + ps[i][j];
                    if(val <= threshold)
                    {
                        f = true;
                        break;
                    }
                }
            }
            if(f)
                b = mid;
            else
                t = mid - 1;
        }
        
        return b;
    }
};