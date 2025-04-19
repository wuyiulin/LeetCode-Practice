class Solution {
private:
    string helper(string& s)
    {
        string t = "";
        int preIdx = 0, currIdx = 1;
        while(currIdx <= s.size())
        {
            if(currIdx != s.size() && s[currIdx] == s[preIdx]) currIdx++;
            else if(currIdx == s.size() || s[currIdx] != s[preIdx])
            {
                int p = currIdx - preIdx;
                string ps = to_string(p);
                t += (ps + s[preIdx]);
                preIdx = currIdx;
                currIdx++;
            }
        }
        
        return t;
    }
public:
    string countAndSay(int n) 
    {
        string s = "1";
        for(int i=1; i<n; i++) s = helper(s);

        return s;
    }
};

