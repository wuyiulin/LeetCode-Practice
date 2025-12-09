class Solution {
using LL = long long;
public:
    int specialTriplets(vector<int>& nums) 
    {
        int res = 0;
        const int mod = 1e9 + 7;
        unordered_map<int, int> total, prev;
        for(const auto& num : nums)
            total[num]++;
        for(const auto& num : nums)
        {
            int tar = num * 2;
            LL curr = 0;
            if(prev.count(tar) && total[tar] - prev[tar] > 0)
            {
                int next = total[tar] - prev[tar];
                if(!tar)
                    next -= 1;
                curr = 1LL * prev[tar] * (next);
            }
            prev[num]++;
            res += (curr % mod);
            res %= mod;
        }

        return res;
    }
};