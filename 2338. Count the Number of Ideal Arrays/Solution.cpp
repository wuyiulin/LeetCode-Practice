class Solution {
private:
    long long powMOD(long long x, long long p, long long MOD)
    {
        long long res = 1;
        while(p)
        {
            
            if(p&1) res = res * x % MOD;
            x = (x * x) % MOD;
            p >>= 1;
        }

        return res;
    }
    long long C(int x, int y, vector<long long>& fact, vector<long long>& inv, long long MOD)
    {
        if(x<y || y<0) return 0;
        return fact[x] * inv[y] % MOD * inv[x - y] % MOD;
    }

public:
    int idealArrays(int n, int maxValue) 
    {
        const int MOD = 1e9 + 7;
        vector<int> spf(maxValue + 1, 0);
        for(int i=2; i<=maxValue; i++)
        {
            if(!spf[i])
            {
                for(int j=i; j<=maxValue; j+=i)
                {
                    if(!spf[j]) spf[j] = i;
                }
            }
        }
        unordered_map<int, unordered_map<int, int>> pfs;
        for(int i=2; i<=maxValue; i++)
        {
            int x = i;
            while(x > 1)
            {
                pfs[i][spf[x]]++;
                x /= spf[x];
            }
        }

        int ext = n + 100;
        vector<long long> fact(ext, 1), inv(ext, 1);
        for(int i=2; i<ext; i++) fact[i] = fact[i - 1] * i % MOD;
        inv[ext - 1] = powMOD(fact[ext - 1], MOD - 2, MOD);
        for(int i=ext-2; i>=0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;

        long long res = 0;

        for(int i=1; i<=maxValue; i++)
        {
            long long curr = 1;
            for(auto&[p, cnt] : pfs[i])
            {
                curr = curr * C(cnt + n - 1, cnt, fact, inv, MOD) % MOD;
            }

            res = (res + curr) % MOD;
        }

        return res;
    }
};

