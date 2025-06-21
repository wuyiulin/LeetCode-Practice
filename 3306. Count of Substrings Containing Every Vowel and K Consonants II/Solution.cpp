class Solution {
    public:
        int minimumDeletions(string word, int k) 
        {
            int res = INT_MAX;
            unordered_map<char, int> table;
            for(const auto& c : word)
                table[c]++;
            for(auto& [_, tar] : table)
            {
                int diff = 0;
                for(auto& [_, curr] : table)
                { 
                    if(curr - tar > k)
                        diff += (curr - tar - k); 
                    else if(curr < tar)
                        diff += curr;
                }
                res = min(res, diff);
            }
    
            return res;
        }
    };