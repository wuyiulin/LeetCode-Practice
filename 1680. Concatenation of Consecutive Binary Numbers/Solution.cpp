class Solution {
public:
    int concatenatedBinary(int n) 
    {
        long long res = 1;
        const int mod = 1e9 + 7;
        int cl = 1;
        for(int i=2; i<=n; i++)
        {
            if((i & (i - 1)) == 0)
                cl++;
            res = (((res <<= cl) % mod) + i) % mod;
        }

        return (int)res;
    }
};