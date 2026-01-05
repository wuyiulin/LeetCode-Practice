class Solution {
using LL = long long;
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        int m = INT_MAX, cnt = 0;
        LL res = 0;
        bool f = false;
        for(const auto& row : matrix)
        {
            for(const auto& it : row)
            {
                if(it < 0)
                    cnt++;
                if(abs(it) < m)
                    m = abs(it);
                if(!it)
                    f = true;
                res += abs(it);    
            }
        }

        if(cnt % 2 && !f)
            res -= 2*m;

        return res;
    }
};