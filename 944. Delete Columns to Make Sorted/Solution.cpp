class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int res = 0;
        int n = strs[0].size();
        vector<char> curr(n, 'a' - 1);
        unordered_set<int> s; 
        for(const auto& str : strs)
        {
            for(int i=0; i<n; i++)
            {
                if(s.count(i))
                    continue;
                if(curr[i] > str[i])
                {
                    res++;
                    s.insert(i);
                }
                    
                curr[i] = str[i];
            }
        }

        return res;
    }
};