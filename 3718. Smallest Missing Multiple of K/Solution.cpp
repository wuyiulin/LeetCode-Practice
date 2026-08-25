class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), p = 1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] > k*p)
                break;
            if(nums[i] == k*p)
                p++;
        }

        return k*p;
    }
};