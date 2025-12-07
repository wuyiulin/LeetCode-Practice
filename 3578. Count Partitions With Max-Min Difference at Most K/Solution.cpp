using LL = long long;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) 
    {
        const int  mod = 1e9 + 7;
        int n = nums.size();
        vector<LL> dp(n + 1, 0), prefix(n + 1, 0);
        dp[0] = 1;
        prefix[0] = 1;

        deque<int> dqMax, dqMin;
        int l = 1;

        for(int r=1; r<n+1; r++)
        {
            int curr = nums[r - 1];
            while(!dqMax.empty() && nums[dqMax.back()] <= curr)
                dqMax.pop_back();
            dqMax.push_back(r - 1);
            while(!dqMin.empty() && nums[dqMin.back()] >= curr)
                dqMin.pop_back();
            dqMin.push_back(r - 1);

            while(!dqMax.empty() && !dqMin.empty() && nums[dqMax.front()] - nums[dqMin.front()] > k)
            {
                if(!dqMax.empty() && dqMax.front() == l - 1)
                    dqMax.pop_front();
                if(!dqMin.empty() && dqMin.front() == l - 1)
                    dqMin.pop_front();
                l++;
            }

            int s = prefix[r - 1] - ((l >= 2) ? prefix[l - 2] : 0);
            dp[r] = (s % mod + mod) % mod;
            prefix[r] = (prefix[r - 1] + dp[r]) % mod;
        }

        return dp[n];
    }
};