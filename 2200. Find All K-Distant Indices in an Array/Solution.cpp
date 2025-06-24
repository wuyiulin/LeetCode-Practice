class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        int n = nums.size(), status = 0;
        vector<int> res = {}, table(n + 1, 0);
        for(int i=0; i<n; i++)
        {
            if(nums[i] == key)
            {
                table[max(0, i-k)] += 1;
                table[min(n, i + k + 1)] -= 1;
            }
        }

        for(int i=0; i<n; i++)
        {
            status += table[i];
            if(status)
                res.push_back(i);
        }

        sort(res.begin(), res.end());

        return res;
    }
};