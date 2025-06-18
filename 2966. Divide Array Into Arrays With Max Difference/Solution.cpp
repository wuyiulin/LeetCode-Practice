class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {};
        if(n < 3) 
            return res;
        for(int i=0; i<n-2; i=i+3)
        {
            if((nums[i+2] - nums[i+1]) > k || (nums[i+2] - nums[i]) > k || (nums[i+1] - nums[i]) > k)
                return vector<vector<int>>{};
            res.push_back({nums[i], nums[i+1], nums[i+2]});
        }

        return res;
    }
};