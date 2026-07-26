class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN, last = 0;
        sort(nums.begin(), nums.end(), greater());

        if(nums[n - 1] < 0 && nums[n - 2] < 0)
            last = nums[n - 1] * nums[n - 2] * nums[0];

        res = nums[0] * nums[1] * nums[2];

        return res > last ? res : last;
    }
};