class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) 
    {
        for(int i=0; i+2*k<= nums.size(); i++)
        {
            int j = i + 1;
            for(; j<i+k; j++)
            {
                if(nums[j] <= nums[j - 1])
                {
                    i = j - 1;
                    break;
                }
            }
            if(j != i + k)
                continue;
            j++;
            for(; j<i+2*k; j++)
            {
                if(nums[j] <= nums[j - 1])
                {
                    i = j - k - 1;
                    break;
                }
            }
            if(j == i + 2 * k)
                return true;
        }    

        return false;
    }
};