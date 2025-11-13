class Solution {
public:
    int maxOperations(string s) 
    {
        int res = 0, n = s.size(), ones = 0;
        bool state = false;
        for(int i=0; i<n ; i++)
        {
            if(s[i] - '0')
            {
                state = true;
                ones++;
            }
            else
            {
                if(state)
                    res += ones;
                state = false;
            }
        }

        return res;
    }
};