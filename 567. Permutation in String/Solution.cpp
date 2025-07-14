class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.size(), m = s2.size();
        if(n > m)
            return false;
        unordered_map<char, int> table, curr;
        for(auto& s : s1)
            table[s]++;
        for(int i=0; i<n; i++)
            curr[s2[i]]++;
        if(curr == table)
            return true;
        for(int i=n; i<m; i++)
        {
            curr[s2[i-n]]--;
            if(!curr[s2[i-n]])
                curr.erase(s2[i-n]);
            curr[s2[i]]++;
            if(curr == table)
                return true;
        }

        return false;
    }
};