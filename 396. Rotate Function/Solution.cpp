class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int n = nums.size(), res = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        for(int i=0; i<n; i++)
            res += i * nums[i];
        int prev = res;
        for(int i=1; i<n; i++)
        {
            int shift = ((n - i) + n) % n;
            int curr = prev + total - n * nums[shift];
            res = max(res, curr);
            prev = curr;
        }   

        return res;
    }
};