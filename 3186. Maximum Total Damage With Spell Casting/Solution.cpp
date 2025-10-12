class Solution {
using LL = long long;
using PIL = pair<int, LL>;
public:
    long long maximumTotalDamage(vector<int>& power) 
    {
        map<int, LL> table;
        vector<PIL> v;
        LL res = 0;
        int n = power.size();
        for(const auto& p : power)
            table[p] += p;
        for(auto& t : table)
            v.push_back({t.first, t.second});
        int m = v.size();
        vector<LL> dp(m, 0);
        dp[0] = v[0].second;
        res = v[0].second;
        
        for(int i=1; i<m; i++)
        {
            int tar = v[i].first - 3;
            LL tmp = v[i].second;
            auto it = upper_bound(v.begin(), v.end(), tar, 
                [](int value, const PIL& elem)
                {
                    return value < elem.first;
                });
            if(it != v.begin())
            {
                int idx = (it - v.begin()) - 1;
                tmp += dp[idx];
            }

            dp[i] = max(dp[i - 1], tmp);
            res = max(res, dp[i]);
        }

        return res;
    }
};