class Solution {
public:
    string smallestSubsequence(string s) {
        int last[26], n = s.size();
        bool vis[26];
        fill(last, last + 26, 0);
        fill(vis, vis + 26, false);
        string res = "";
        
        for(int i=0; i<n; i++)
            last[s[i] - 'a'] = i;
        
        for(int i=0; i<n; i++)
        {
            char c = s[i];
            if(vis[c - 'a'])
                continue;
            while(!res.empty() && res.back() > c && last[res.back() - 'a'] > i)
            {
                vis[res.back() - 'a'] = false;
                res.pop_back();
            }

            res += c;
            vis[c - 'a'] = true;
        }

        return res;
    }
};