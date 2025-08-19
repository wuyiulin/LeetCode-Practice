class Solution {
using LL = long long;
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        LL res = 0;
        int n = nums.size(), i = 0;
        while(i<n)
        {
            LL cnt = 0;
            while(i<n && !nums[i])
            {
                cnt++;
                i++;
            }
            if(cnt)
            {
                res += (((1 + cnt) * cnt) / 2);
                continue;
            }
            i++;
        }
    
        return res;
    }
};