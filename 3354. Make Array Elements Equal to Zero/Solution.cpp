class Solution {
public:
    int countValidSelections(vector<int>& nums) 
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size(), pref = 0, res = 0;
        for(int i=0; i<n; i++)
        {
            if(2 * pref - 1 > total)
                break;
            if(i)
                pref += nums[i - 1];
            if(!nums[i])
            {
                int redundant = total - pref;
                if(abs(pref - redundant) == 1)
                    res++;
                else if(pref == redundant)
                    res += 2;
            }
            
        }

        return res;
    }
};