class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0, res = 0;
        unordered_map<int, int> mp;
        for(int l=0; l<n; l++)
        {
            while(r < n && mp[nums[r]] < k)
            {
                res = max(res, r - l + 1);
                mp[nums[r]]++;
                r++;
            }
            if(mp[nums[l]] > 0)
                mp[nums[l]]--;
        }

        return res;
    }
};