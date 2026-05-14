class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        int n = nums.size();
        if(n < 2)
            return false;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++)
        {
            if(i && nums[i - 1] == nums[i] || nums[i] != i + 1)
                return false;
        }

        return (nums[n - 2] == nums[n - 1]);
    }
};