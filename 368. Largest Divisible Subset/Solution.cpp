class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                if(nums[j] % nums[i] == 0)
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        int end = *max_element(dp.begin(), dp.end());
        vector<int> res = {};
        for(int i=n-1; i>=0; i--)
        {
            if(dp[i] == end && (res.empty() || res.back() % nums[i] == 0))
            {
                res.push_back(nums[i]);
                end--;
            }
        }

        return res;
    }
};

