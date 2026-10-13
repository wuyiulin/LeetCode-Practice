class Solution {
using LL = long long;
public:
    long long maxAlternatingSum(vector<int>& nums) {
        LL res = 0;
        int n = nums.size();
        for(auto& num : nums)
            num = abs(num);
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=0; i<n/2; i++)
        {
            res += ((LL)nums[i] * nums[i]);
            res -= (nums[n - i - 1] * nums[n - i - 1]);
        }
        if(n % 2)
            res += ((LL)nums[n / 2] * nums[n / 2]);

        return res;
    }
};