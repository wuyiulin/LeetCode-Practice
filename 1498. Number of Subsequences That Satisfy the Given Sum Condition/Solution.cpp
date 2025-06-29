class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        int res = 0, MOD = 1e9 + 7, n = nums.size();
        int l = 0, r = n - 1;
        sort(nums.begin(), nums.end());
        vector<int> p(n, 1);
        
        for(int i=1; i<n; i++)
            p[i] = p[i-1] * 2 % MOD;
        
        while(l <= r)
        {
            if(nums[l] + nums[r] <= target)
            {
                res = (res + p[r - l]) % MOD;
                l++;
            }
            else
                r--;
        }

        return res;
    }
};