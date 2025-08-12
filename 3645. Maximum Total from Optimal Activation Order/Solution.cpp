class Solution {
using LL = long long;
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) 
    {
        int n = value.size();
        LL res = 0;
        unordered_map<int, vector<int>> table;
        for(int i=0; i<n; i++)
        {
            int key = limit[i], val = value[i];
            if(!table.count(key))
                table[key] = {};
            table[key].push_back(val);
        }
        for(auto& [key, vals] : table)
        {
            nth_element(vals.begin(), vals.begin() + min(key, (int)vals.size()), vals.end(), greater<int>());
            res += accumulate(vals.begin(), vals.begin() + min(key, (int)vals.size()), 0LL);
        }

        return res;
    }
};