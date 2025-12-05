class Solution {
public:
    int countPartitions(vector<int>& nums) 
    {
        int n = nums.size(), res = 0;
        for(int i=1; i<n; i++)
            nums[i] += nums[i - 1];
            

        for(int i=0; i<n-1; i++)
        {
            int curr = nums[n - 1] - 2 * nums[i];
            if(!(curr % 2))
                res++;
        }

        return res;
    }
};