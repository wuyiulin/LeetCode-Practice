class Solution {
using LL = long long;
public:
    long long minArraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        LL curr = 0;
        for(int i=1; i<=n; i++)
        {
            curr += nums[i - 1];
            prefix[i] = (int)(curr % k);
        }

        vector<LL> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        vector<LL> remainder(k, LLONG_MAX);
        remainder[0] = 0;

        for(int i=0; i<n; i++)
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1LL*nums[i]);
            dp[i + 1] = min(dp[i + 1], remainder[prefix[i + 1]]);
            remainder[prefix[i + 1]] = min(remainder[prefix[i + 1]], dp[i + 1]);
        }

        return dp[n];
    }
};