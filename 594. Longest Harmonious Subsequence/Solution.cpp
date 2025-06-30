class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        int n = nums.size(), res = 0, l = 0, r = 0;
        sort(nums.begin(), nums.end());
        for(int r=1; r<n; r++)
        {
            if(nums[r] - nums[l] == 1)
                res = max(res, r - l + 1);
            while(nums[l] + 1 < nums[r])
                l++;
        }

        return res;
    }
};