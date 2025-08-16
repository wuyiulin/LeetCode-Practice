class Solution {
public:
    int sortPermutation(vector<int>& nums) 
    {
        int res = -1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != i)
                res &= nums[i];
        }

        return max(0, res);
    }
};