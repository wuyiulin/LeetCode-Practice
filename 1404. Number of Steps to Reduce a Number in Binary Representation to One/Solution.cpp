class Solution {
public:
    int numSteps(string s) 
    {
        int res = 0, pre = 0, n = s.size();
        for(int i=n-1; i>0; i--)
        {
            if((s[i] - '0') ^ pre == 1)
            {
                res += 1;
                pre = 1;
            }
            res += 1;
        }

        return res + pre;
    }
};