class Solution {
using LL = long long;
using PLL = pair<LL, LL>;
public:
    long long maxSubarraySum(vector<int>& nums, int k) 
    {
        LL maxVal = LLONG_MIN;
        int n = nums.size();
        bool f = false;
        vector<LL> table(n + 1, 0), reds(k, LLONG_MAX); // CurrMin
        reds[0] = 0;
        for(int i=1; i<n+1; i++)
        {
            table[i] = (table[i - 1] + nums[i - 1]);
        }
            
        for(int i=1; i<n+1; i++)
        {
            int r = i % k;
            if(reds[r] != LLONG_MAX)
            {
                maxVal = max(maxVal, table[i] - reds[r]);
                f = true;
            }
            reds[r] = min(reds[r], table[i]);
        }

        return f ? maxVal : 0;
    }
};