class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int curr = 1;
        while(curr <= (1<<30))
        {
            string cs = to_string(curr);
            sort(cs.begin(), cs.end());
            if(cs == s)
                return true;
            if(curr == (1<<30))
                break;
            curr <<= 1;
        }

        return false;
    }
};