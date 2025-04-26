class Solution
{
using LL = long long;
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        
        int minIdx = -1, maxIdx = -1;
        int n = nums.size();
        long long res = 0;
        
        int l = 0, r = 0;
        while (r < n)
        {
            if (nums[r] < minK || nums[r] > maxK)
            {
                minIdx = -1;
                maxIdx = -1;
                l = r + 1;
            }
            if (nums[r] == minK) minIdx = r;
            if (nums[r] == maxK) maxIdx = r;
            if (minIdx != -1 && maxIdx != -1)
                res += min(minIdx, maxIdx) - l + 1;
            r++;
        }

        return res;
    }
};