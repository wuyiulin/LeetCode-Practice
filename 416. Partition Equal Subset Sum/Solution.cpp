class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        const int half = !(sum % 2) ? sum / 2 : 0;
        if(!half) return false;
        vector<bool> dp(half + 1, false);
        dp[0] = true; 
        for(const int num : nums)
            for(int j=half; j>=num; j--)
            if(dp[j - num]) dp[j] = true;

        return dp[half];
    }
};

