class Solution {
using LL = long long;
public:
    int countTrapezoids(vector<vector<int>>& points) 
    {
        int res = 0, mod = 1e9 + 7;
        vector<LL> prefix;
        unordered_map<int, LL> table;
        for(vector<int>& pt : points)
            table[pt[1]]++;
        
        for(auto it = table.begin(); it != table.end(); it++)
        {
            it->second = it->second * (it->second - 1) / 2;
            prefix.push_back(it->second);
            if(prefix.size() >= 2)
                prefix.back() += prefix[prefix.size() - 2]; 
        }
        for(int i=prefix.size()-1; i>0; i--)
        {
            LL val = (prefix[i] - prefix[i - 1]) * (prefix[i - 1]);
            res += (int)(val % mod);
            res %= mod;
        }

        return res;
    }
};