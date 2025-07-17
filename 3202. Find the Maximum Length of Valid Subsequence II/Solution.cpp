class Solution {
public:
    int maximumLength(vector<int>& nums, int k) 
    {
        int n = nums.size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(k, 0));
        vector<int> last(k, -1);
        for(int i=0; i<n; i++)
        {
            for(int tar=0; tar<k; tar++)
            {
                int c = (tar - nums[i]%k + k) % k;
                int cIdx = last[c];
                if(cIdx != -1)
                {
                    dp[i][tar] = dp[cIdx][tar] + 1;
                    res = max(res, dp[i][tar]);
                }
                else
                    dp[i][tar] = 1;
            }
            last[nums[i] % k] = i;
        }

        return res;
    }
};