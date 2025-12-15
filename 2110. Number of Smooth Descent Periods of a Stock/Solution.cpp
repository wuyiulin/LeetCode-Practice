class Solution {
using LL = long long;
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        int l = 0, r = 0, n = prices.size();
        LL res = 0;
        while(l<n)
        {
            r = l + 1;
            while(r<n && prices[r] == prices[r-1] - 1)
                r++;
            int tar = (r - l);
            res += ((1LL * tar * (tar + 1)) / 2);
            l = r;
        }

        return res;
    }
};