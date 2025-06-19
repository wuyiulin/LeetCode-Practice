class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int res = 1, pre = nums[0], n = nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i] > pre + k)
            {
                pre = nums[i];
                res++;
            }
        }

        return res;
    }
};