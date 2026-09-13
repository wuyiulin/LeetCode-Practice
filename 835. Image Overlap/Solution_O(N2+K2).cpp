class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), res = 0;
        vector<pair<int, int>> A, B;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(img1[i][j])
                    A.push_back({i, j});
                if(img2[i][j])
                    B.push_back({i, j});
            }
        vector<int> cnt(60*64, 0);
        for(auto& [ax, ay] : A)
            for(auto [bx, by] : B)
                res = max(res, ++cnt[(ax - bx + n) << 6 | (ay - by + n)]);
        
        return res;
    }
};