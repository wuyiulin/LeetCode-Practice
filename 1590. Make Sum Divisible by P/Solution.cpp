class Solution {
using LL = long long;
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int n = nums.size();
        int res = n, curr = 0;
        unordered_map<int, int> table;
        table[0] = -1;
        LL red = accumulate(nums.begin(), nums.end(), 0LL) % p;
        if(!red)
            return 0;
        for(int i=0; i<n; i++)
        {
            curr = (curr + nums[i]) % p;
            int tar = (curr - red + p) % p;
            if(table.count(tar))
                res = min(res, i - table[tar]);
            table[curr] = i;
        }
        return res == n ? -1 : res;
    }
};