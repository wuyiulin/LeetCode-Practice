class Solution {
using LL = long long;
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(), nums.end());
        int lo = 0, up = 0;
        LL res = 0;
        for(int i=0; i<nums.size(); i++)
        {
            lo = lower - nums[i]; up = upper - nums[i];
            int L = lower_bound(nums.begin() + i + 1, nums.end(), lo) - nums.begin();
            int R = upper_bound(nums.begin() + i + 1, nums.end(), up) - nums.begin();
            res += (R - L);
        }

        return res;
    }
};

