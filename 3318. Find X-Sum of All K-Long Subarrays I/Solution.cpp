class Solution {
using PII = pair<int, int>;
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) 
    {
        int n = nums.size();
        vector<int> res(n-k+1, 0);
        unordered_map<int, int> mp;
        for(int j=0; j<k; j++)
            mp[nums[j]]++;
        for(int i=0; i<n-k+1; i++)
        {
            if(i)
            {
                int outVal = nums[i - 1];
                int inVal  = nums[i + k - 1];

                if (--mp[outVal] == 0)
                {
                    mp.erase(outVal);
                }
                mp[inVal]++;                
            }
            vector<PII> table(mp.begin(), mp.end());
            sort(table.begin(), table.end(), [](const auto& a, const auto& b)
            {
                if(a.second == b.second)
                {
                    return a.first > b.first;
                }

                return a.second > b.second;
            });
            vector<int> l = {};
            int ts = table.size();
            for(int i=0; i<min(x, ts); i++)
            {
                l.insert(l.end(), table[i].second, table[i].first);
            }
            res[i] = accumulate(l.begin(), min(l.end(), l.begin() + k), 0);
        
        }    

        return res;
    }
};