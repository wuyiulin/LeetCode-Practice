class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        vector<int> ref(n + 1, 0);
        for(const auto& q : queries)
        {
            ref[q[0]]++;
            ref[q[1] + 1]--;
        }

        int curr = 0;
        for(int i=0; i<n; i++)
        {
            curr += ref[i];
            if(curr < nums[i]) return false;
        }

        return true;
    }
};