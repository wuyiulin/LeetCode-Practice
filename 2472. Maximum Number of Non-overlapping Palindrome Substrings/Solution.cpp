class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size(), res = 0, prev = -1;
        for(int i=0; i<2*n-1; i++)
        {
            // 0 1 2 3 4
            // x x x x x
            int l = i/2, r = l + (i & 1);
            while(l > prev && r < n && s[l] == s[r])
            {
                if(r - l + 1 >= k)
                {
                    res++;
                    prev = r;
                    break;
                }
                l--;
                r++;
            }
        }
    
        return res;
    }
};