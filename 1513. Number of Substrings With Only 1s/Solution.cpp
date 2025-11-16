class Solution {
public:
    int numSub(string s) 
    {
        int r = 0, n = s.size(), res = 0; 
        long long MOD = 1e9 + 7;
        for(int l=0; l<n; l++)
        {
            if(s[l] == '1')
            {
                r = l;
                while(r<n && s[r] == '1')
                {
                    if(s[r] == '1')
                        r++;
                }
                res += int((1LL * (r - l + 1) * (r - l) / 2) % MOD);
                l = r - 1;
            }
        }

        return res;
    }
};