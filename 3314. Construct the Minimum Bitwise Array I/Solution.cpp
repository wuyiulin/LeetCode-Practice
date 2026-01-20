class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) 
    {
        int n = nums.size();
      
        for (int i=0; i<n; i++) 
        {
            bool f = false;
            if(nums[i] != 2)
            {
                for (int bitPos = 1; bitPos < 32; bitPos++) 
                {
                    if (((nums[i] >> bitPos) & 1) ^ 1) 
                    {
                        nums[i] = (nums[i] ^ (1 << (bitPos - 1)));
                        f = true;
                        break;
                    }
                }
            }
            if(!f)
                nums[i] = -1; 
        }
      
        return nums;
    }
};