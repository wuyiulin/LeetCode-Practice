class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        long long res = 0;
        int n = nums.size();
        vector<int> r(n, 0);
        vector<int> l(n, 0);
        r[n-1] = nums[n-1];
        l[0] = nums[0];
        for(int i=n-2; i>=0; i--) r[i] = max(r[i + 1], nums[i]);
        for(int i=1; i<n; i++) l[i] = max(l[i - 1], nums[i]);
        for(int i=1; i<n-1; i++)
        {
            res = max(res, 1LL * (l[i - 1] - nums[i]) * r[i + 1]);
        }

        return res;
    }
};

