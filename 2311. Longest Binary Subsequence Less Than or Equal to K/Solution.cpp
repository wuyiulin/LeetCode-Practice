class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int zeros = 0;
        for(const auto& c : s)
            if(c == '0')
                zeros++;
        int val = 0, ones = 0, power = 1, n = s.size();
        for(int i=n-1; i>=0 && val < k; i--)
        {
            if(s[i] == '1' && val + power <= k)
            {    
                val += power;
                ones++;
            }
            power *= 2;
            if(power > k)
                break;
        }

        return zeros + ones;
    }
};