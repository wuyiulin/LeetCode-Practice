class Solution {
public:
using LL = long long;
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) 
    {
        unordered_map<int, LL> rec;
        int cnt = 0;
        LL res = 0;
        rec[0] = 1;
        for(const auto& num : nums)
        {
            cnt += (num % modulo == k);
            int curr = (cnt % modulo);
            int tar = (curr - k + modulo) % modulo;
            res += rec[tar];
            rec[curr]++;
        }

        return res;
    }
};