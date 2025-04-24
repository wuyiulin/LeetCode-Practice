class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        unordered_set<int> s;
        for(const auto& num : nums) s.insert(num);
        int vaild = s.size();
        unordered_map<int, int> table;
        int l = 0, r = 0, n = nums.size();
        int res = 0;
        while(r < n)
        {
            table[nums[r]]++;
            while(table.size() == vaild)
            {
                res += n - r;
                if(!(--table[nums[l]])) table.erase(nums[l]);
                l++;
            }
            r++;
        }
        
        return res;
    }
};

