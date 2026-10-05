class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0, p = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                p *= 2;
            else
            {
                p /= 2;
                if (s[i - 1] == '(')
                    res += p;
            }
        }
        return res;
    }
};