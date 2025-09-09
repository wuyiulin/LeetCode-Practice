class Solution {
using LL = long long;
const int mod = 1e9 + 7;
private:
    int helper(LL x)
    {
        x %= mod;
        if(x < 0)
            x += mod;
        
        return x;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        int p[2001], table[2001];
        memset(table, 0, sizeof(table));
        memset(p, 0, sizeof(p));
        table[1 + delay] = 1;
        table[1 + forget] = -1;
        p[1] = 1;
        int res = 1, share = 0;
        
        for(int d=2; d<=n; d++)
        {
            share = helper(1LL * share + table[d]);
            p[d] = share;
            if(p[d])
            {
                table[d + delay] = helper(1LL * table[d + delay] + p[d]);
                table[d + forget] = helper(1LL * table[d + forget] - p[d]);
            }

            res = helper(res + p[d]);
            if(d - forget >= 1)
                res = helper(res - p[d - forget]);
        }

        return res;
    }
};