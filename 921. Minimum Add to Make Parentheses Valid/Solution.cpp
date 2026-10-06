class Solution {
public:
    int minAddToMakeValid(string s) {
        int l = 0, res = 0;
        for(const char& c : s)
        {
            if(c == '(')
                l++;
            else
            {
                if(l)
                    l--;
                else
                    res++;
            }
        }

        return l + res;
    }
};