class Solution {
using LL = long long;
private:
    LL fastPow(LL val, int p)
    {
        LL res = 1;
        while(p)
        {
            if(p&1)
                res = res * val % MOD;
            val = val * val % MOD;
            p >>= 1;
        }

        return res;
    }

    void init(int n)
    {
        fact.resize(n + 1), inv.resize(n + 1);
        fact[0] = 1;
        for(int i=1; i<=n; i++)
            fact[i] = fact[i - 1] * i % MOD;
        inv[n] = fastPow(fact[n], MOD - 2);
        for(int i=n-1; i>=0; i--)
            inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
    
    LL C(LL n, int k)
    {
        if(k < 0 || k > n)
            return 0;
        
        return fact[n] * inv[n-k] % MOD * inv[k] % MOD;
    }
public:
    const int MOD = 1e9 + 7;
    vector<LL> fact, inv;
    int countGoodArrays(int n, int m, int k) 
    {
        init(n);
        LL res = C(n-1, k);
        res = res * m % MOD;
        res = res * fastPow(m - 1, n - 1 - k) % MOD;

        return res;
    }
};