class Solution {
public:
    int specialTriplets(vector<int>& nums) 
    {
        const int MOD = 1e9 + 7;
        int n = nums.size(), res = 0;
        unordered_map<int, int> table;
        unordered_map<int, int> ctable;
        for(const auto& c : nums)
            table[c]++;
        for(const auto& c : nums)
            {
                int l = 0, r = 0;
                table[c]--;
                if(ctable.count(c*2))
                {
                    l = ctable[c*2];
                }
                if(table.count(c*2))
                {
                    r = table[c*2];
                }
                ctable[c]++;
                res = (res + 1LL * l * r % MOD) % MOD;
            }

        return res;
    }
};