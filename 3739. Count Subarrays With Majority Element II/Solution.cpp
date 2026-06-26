class Solution {
using LL = long long;
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        LL res = 0, accu = 0, freq = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(const auto& num : nums)
        {
            if(num == target)
            {
                accu++;
                freq += mp[accu - 1];
            }
            else
            {
                accu--;
                freq -= mp[accu];
            }
            mp[accu]++;
            res += freq;
        }

        return res;
    }
};