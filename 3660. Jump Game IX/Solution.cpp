class Solution {
public:
    vector<int> maxValue(vector<int>& nums) 
    {
        int n = nums.size(), suf = INT_MAX;
        vector<int> prev(n, nums[0]), res(n, 0);
        for(int i=1; i<n; i++)
            prev[i] = max(prev[i - 1], nums[i]);
        for(int i=n-1; i>=0; i--)
        {
            res[i] = prev[i] > suf ? res[i + 1] : prev[i];
            suf = min(suf, nums[i]);
        }     

        return res;
    }
};