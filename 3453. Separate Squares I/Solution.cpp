using LL = long long;
class Solution {
private:
    double helper(double tar, vector<vector<int>>& squares)
    {
        int i = 0, n = squares.size();
        double res = 0.0;
        for(const auto& s : squares)
        {
            if(s[1] + s[2] <= tar)
                res += (1LL * s[2] * s[2]);
            else if(s[1] < tar && s[1] + s[2] > tar)
                res += ((tar - s[1]) * s[2]);
        }

        return res;
    }
public:
    double separateSquares(vector<vector<int>>& squares) 
    {
        int n = squares.size();
        double bottom = 1e9 + 7.0, top = -1.0;
        LL total = 0;
        for(const auto& s : squares)
        {
            total += (1LL * s[2] * s[2]);
            bottom = min(bottom, (double)s[1]);
            top = max(top, (double)s[1] + (double)s[2]);
        }
        double half = total*1.0/2;
            
        
        int cnt = 47;
        while(bottom < top && cnt)
        {
            double mid = (top - bottom)/2 + bottom;
            if(helper(mid, squares) >= half)
                top = mid;
            else
                bottom = mid;

            cnt--;
        }

        return top;
    }
};