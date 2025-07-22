class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_map<int, int> table;
        int l = 0, r = 0, n = nums.size();
        int res = 0, curr = 0;
        while(r < n)
        {
            if(!table[nums[r]])
            {
                curr += nums[r];
                res = max(res, curr);
                table[nums[r]]++;
            }
            else
            {
                while(table[nums[r]])
                {
                    curr -= nums[l];
                    table[nums[l]]--;
                    l++;
                }
                table[nums[r]]++;
                curr += nums[r];
                res = max(res, curr);
            }

            r++;
        }

        return res;

    }
};