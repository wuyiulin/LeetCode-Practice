class Solution {
using LL = long long;
private:
    int countParts(const string& s, int i, bool change, unsigned mask, unsigned newBit, int k, unordered_map<LL, int>& table)
    {
        unsigned newMask = mask | newBit;
        if(__builtin_popcount(newMask) > k)
            return 1 + helper(s, i + 1, change, newBit, k, table);
        return helper(s, i + 1, change, newMask, k, table);
    }

    int helper(const string& s, int i, bool change, unsigned mask, int k, unordered_map<LL, int>& table)
    {
        if(i == s.size())
            return 0;
        LL key = (static_cast<LL>(i) << 32) | static_cast<LL>(change ? 1 : 0) << 31 | mask;
        const auto it = table.find(key);
        if( it != table.end())
            return it->second;

        unsigned Bit = 1u << (s[i] - 'a');
        int res = countParts(s, i, change, mask, Bit, k, table);

        if(change)
        {
            for(int j=0; j<26; j++)
            {
                unsigned bit = 1u << j;
                if(bit == Bit)
                    continue;
                res = max(res, countParts(s, i, false, mask, bit, k, table));
            }
        }

        table[key] = res;
        return res;
    }
public:
    int maxPartitionsAfterOperations(string s, int k) 
    {
        unordered_map<LL, int> table;
        return helper(s, 0, true, 0u, k, table) + 1;
    }
};