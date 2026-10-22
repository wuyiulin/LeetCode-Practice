class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX;
        bool inc = true, dec = true;

        for(int i=0; i<n; i++)
        {
            int nx = (nums[(i + 1) % n]);
            if(nx != (nums[i] + 1) % n)
                inc = false;
            if(nx != (nums[i] - 1 + n) % n)
                dec = false;
        }

        int k = nums[0];

        if(inc)
            res = !k ? 0 : min(n - k, k + 2);
        if(dec)
            res = min(res, k == n - 1 ? 1 : min(k + 2, n - k));

        return res == INT_MAX ? -1 : res;
    }
};