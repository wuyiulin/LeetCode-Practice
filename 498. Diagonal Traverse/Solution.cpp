class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> res = {};
        int con = 0, cnt = 0, r = 0, c = 0;
        while(cnt < m+n-1)
        {
            vector<int> tmp = {};
            int i = 0;
            while(r-i>=0 && r-i<m && c+i>=0 && c+i<n)
            {
                tmp.push_back(mat[r-i][c+i]);
                i++;
            }
            if(con)
                reverse(tmp.begin(), tmp.end());
            con ^= 1;
            res.insert(res.end(), tmp.begin(), tmp.end());

            int newR = r + 1, newC = c;
            if(newR<0 || newR>=m || newC<0 || newC>=n)
                newR = r, newC = c + 1;
            r = newR;
            c = newC;
            cnt++;
        }

        return res;
        
    }
};