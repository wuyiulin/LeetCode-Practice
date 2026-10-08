class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size(), cnt = 0, w = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(' && cnt++ > 0)
                s[w++] = s[i];
            else if(s[i] == ')' && --cnt > 0)
                s[w++] = s[i];
        }

        s.resize(w);

        return s;
    }
};