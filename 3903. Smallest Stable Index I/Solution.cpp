class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int sufMin[n], currMax = 0;
        fill(sufMin, sufMin + n, INT_MAX);
        sufMin[n - 1] = nums[n - 1];
        for(int i=n-2; i>=0; i--)
            sufMin[i] = min(sufMin[i + 1], nums[i]);
        for(int i=0; i<n; i++)
        {
            currMax = max(currMax, nums[i]);
            if(currMax - sufMin[i] <= k)
                return i;
        }

        return -1;
    }
};