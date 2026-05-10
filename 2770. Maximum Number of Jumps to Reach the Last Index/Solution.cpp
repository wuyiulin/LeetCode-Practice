class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int dp[n];
        fill(&dp[0], &dp[0] + n, -1);
        dp[0] = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(dp[j] != -1 && abs(nums[i] - nums[j]) <= target)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return dp[n - 1];
    }
};