class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "", target = "";
        bool replace = false;
        unordered_map<string, string> mp;
        for(const auto& k : knowledge)
            mp[k[0]] = k[1];
        for(const auto& c : s)
        {
            if(c == '(')
            {
                replace = true;
            }
            else if(c == ')')
            {
                if(mp.count(target))
                    res += mp[target];
                else
                    res += '?';
                target = "";
                replace = false;
            }
            else if(replace)
            {
                target += c;
            }
            else
                res += c;
        }

        return res;
    }
};