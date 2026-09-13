class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<uint32_t> A(n, 0), B(n, 0);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(img1[i][j])
                    A[i] |= 1u << j;
                if(img2[i][j])
                    B[i] |= 1u << j;
            }
        
        uint32_t mask = (1u << n) - 1;
        int res = 0;
        for(int dr =-(n - 1); dr<=n-1; dr++)
            for(int dc=-(n-1); dc<=n-1; dc++)
            {
                int curr = 0;
                for(int ci=0; ci<n; ci++)
                {
                    int oi = ci - dr;
                    if(oi < 0 || oi >= n)
                        continue;
                    uint32_t row = dc >= 0 ? (A[oi] << dc) & mask : (A[oi] >> -dc);
                    curr += __builtin_popcount(row & B[ci]);
                }

                res = max(res, curr);
            }
        
        return res;
    }
};