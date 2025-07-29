class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
        unordered_map<int, vector<int>> table;
        int maxOr = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        int n = nums.size();
        vector<int> res(n, 0);
        for(int i=0; i<n; i++)
        {
            int num = nums[i], idx = 0;
            while(num)
            {
                if(num & 1)
                    table[idx].push_back(i);
                num >>= 1;
                idx++;
            }
        }
        for(int i=0; i<n; i++)
        {
            int maxOrC = maxOr;
            int num = nums[i], dist = 1;
            for(int bit=0; maxOrC>0; bit++)
            {
                if((maxOrC & 1) && !(num & 1))
                {
                    auto it = upper_bound(table[bit].begin(), table[bit].end(), i);
                    if(it != table[bit].end())
                        dist = max(dist, *it - i + 1);
                }
                maxOrC >>= 1;
                num >>= 1;
            }
            res[i] = dist;
        }

        return res;
    }
};