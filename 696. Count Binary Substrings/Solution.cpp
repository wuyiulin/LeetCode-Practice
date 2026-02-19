class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int pre = 0, curr = 1, res = 0;
        int n = s.size();
        for(int i=1; i<n; i++)
        {
            if(s[i] == s[i - 1])
                curr++;
            else
            {
                pre = curr;
                curr = 1;
            }

            if(pre >= curr)
                res++;
        }

        return res;
    }
};