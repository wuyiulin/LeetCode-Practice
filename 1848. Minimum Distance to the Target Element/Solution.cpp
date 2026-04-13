class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) 
    {
        int n = nums.size(), res = 1000;
        for(int i=0; i<n; i++)
        {
            int dist = abs(i - start);
            if(i > start && dist > res)
                break;
            if(nums[i] == target)
                res = min(res, dist);
        }    

        return res;
    }
};